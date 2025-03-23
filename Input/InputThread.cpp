#include "InputThread.h"
#include "../Settings/Settings.h"
#include <chrono>


InputThread::InputThread()
{
	
}

bool InputThread::RunThread()
{
	bool Success = true;

	//if (GlobalSettings.Initalize("Enter INI Here"))
	bShouldThreadRun = true;
	Thread = std::thread(ThreadEntry, this);

	return Success;
}
void InputThread::StopThread()
{
	bShouldThreadRun = false;

	if (Thread.joinable()) // This waits for thread to stop
	{
		Thread.join();
	}
}

void InputThread::ThreadEntry(InputThread* This)
{
	if (This) This->ThreadBody();
}
void InputThread::ThreadBody()
{
	while (bShouldThreadRun)
	{
		BYTE KeyPress = CheckForHotkey();
		if (KeyPress != 0)  // Valid?
		{
			ProceessMacro(KeyPress);
		}
	
		if (bShouldThreadRun)
		{
			Sleep(10);
		}
	}
}

BYTE InputThread::CheckForHotkey()
{
	BYTE CurrentKeyboardState[256] = { 0 };
	BYTE KeyCode = 0;

	if (GetKeyboardState(CurrentKeyboardState))
	{
		// Check for differences
		if (std::memcmp(OldKeyBoardState, CurrentKeyboardState, sizeof(OldKeyBoardState)) != 0)
		{
			// check if a macro is running and if so make sure the input didnt originate from the macro
			// if (GlobalSetting.IsMacroRunning())
			
			for (int i = 1; (i < 0x7F) && bShouldThreadRun; ++i) // US keyboard
			{	
				// 8th bit determines up or down https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate?redirectedfrom=MSDN
				if ((OldKeyBoardState[i] & 0x80) && !(CurrentKeyboardState[i] & 0x80))  // Down, but wasnt down last time around. this will run anytime a change happens
				{
					if (GlobalSettings.IsValidHotKey(i))
					{
						KeyCode = i;
						break;
					}
				}
			}

			std::memcpy(OldKeyBoardState, CurrentKeyboardState, sizeof(OldKeyBoardState));  // Copy Over Keyboard Check
		}
	}

	return KeyCode;
}


void InputThread::ProceessMacro(const BYTE Hotkey)
{
	Macro SafeMacroCopy;
	KeyStroke CurrentKeyStroke;

	if (GlobalSettings.GetSafeMacro(Hotkey, SafeMacroCopy))
	{
		std::chrono::time_point<std::chrono::system_clock> LastExecution;
		std::chrono::time_point<std::chrono::system_clock> CurrentTime;
		LastExecution = std::chrono::system_clock::now();
		
		int MacroSize = SafeMacroCopy.Actions.size();
		int CurrentIndex = 0;
		
		while ((CurrentIndex < MacroSize) && bShouldThreadRun)
		{
			double MS_ElapsedSinceExecution = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - LastExecution).count();
			if (MS_ElapsedSinceExecution > SafeMacroCopy.Actions[CurrentIndex].MSDelay)
			{
				PlayKey(SafeMacroCopy.Actions[CurrentIndex]);
				CurrentIndex++;
			}

			if (CurrentIndex >= MacroSize)
			{
				if (SafeMacroCopy.Loops)
				{
					CurrentIndex = 0;
				}
				else
				{
					break; // Finished!
				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			BYTE KeyPress = CheckForHotkey();
			if (KeyPress != 0)
			{
				if (KeyPress == static_cast<BYTE>(SafeMacroCopy.HotKey)) // Cancel
				{
					break; // Finished!
				}
				else  // Another Hotkey was pressed change directions and do this one.
				{
					if (KeyPress != static_cast<BYTE>(SafeMacroCopy.Actions[CurrentIndex - 1].Key))  // Make Sure Our Macro Didn't Enter Another Hotkey
					{
						if (GlobalSettings.GetSafeMacro(KeyPress, SafeMacroCopy))
						{
							int MacroSize = SafeMacroCopy.Actions.size();
							int CurrentIndex = 0;
						}
					}
				}
			}
		}
	}
}

void InputThread::PlayKey(const KeyStroke Key)
{
	bool Success = false;
	
	if (InputManager::IsSpecialKey(static_cast<WORD>(Key.SpecialKey)))
	{
		Success = InputManager.MakeSpecialInput(Key.SpecialKey, Key.Key);
	}
	else
	{
		Success = InputManager.MakeInput(Key.Key);
	}

	if (Success)
	{
		// do something idk
	}
}
