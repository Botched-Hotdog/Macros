#include "./BackgroundProcess.h"
#include "../Settings/Settings.h"
#include <chrono>


bool BackgroundProcess::RunThread()
{
	bool Success = false;

	if (GlobalSettings.Initialize("Settings.txt"))
	{
		Success = true;
		bShouldThreadRun = true;
		Thread = std::thread(ThreadEntry, this);
	}

	return Success;
}
void BackgroundProcess::StopThread()
{
	bShouldThreadRun = false;

	if (Thread.joinable()) // This waits for thread to stop
	{
		Thread.join();
	}
}

void BackgroundProcess::ThreadEntry(BackgroundProcess* This)
{
	if (This) This->ThreadBody();
}
void BackgroundProcess::ThreadBody()
{
	
	while (bShouldThreadRun)
	{
		if (!GlobalSettings.IsEditingMacros())
		{
			BYTE KeyPress = CheckForHotkey();
			if (KeyPress != 0)  // Valid?
			{
				ProceessMacro(KeyPress);
			}
		}
	
		if (bShouldThreadRun)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
	}
}


BYTE BackgroundProcess::CheckForHotkey()
{
	BYTE CurrentKeyboardState[256] = { 0 };
	BYTE KeyCode = 0;

	GetKeyState(0);
	if (GetKeyboardState(CurrentKeyboardState))
	{
		// Check for differences
		if (std::memcmp(OldKeyBoardState, CurrentKeyboardState, sizeof(OldKeyBoardState)) != 0)
		{		
			for (int i = 1; (i < 0x7F) && bShouldThreadRun; ++i) // US keyboard
			{	
				// 8th bit determines up or down https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate?redirectedfrom=MSDN
				if ((CurrentKeyboardState[i] & 0x80) && !(OldKeyBoardState[i] & 0x80))  // Down, but wasnt down last time around. this will run anytime a change happens
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


void BackgroundProcess::ProceessMacro(const BYTE Hotkey)
{
	Macro MacroCopy;
	KeyStroke CurrentKeyStroke;

	if (GlobalSettings.GetMacroCopy(Hotkey, MacroCopy))
	{
		GlobalSettings.SetRunningMacro(Hotkey);

		std::chrono::time_point<std::chrono::system_clock> LastExecution;
		std::chrono::time_point<std::chrono::system_clock> CurrentTime;
		CurrentTime = LastExecution = std::chrono::system_clock::now();
		
		int MacroSize = MacroCopy.Actions.size(); 
		int CurrentIndex = 0;
		
		while ((CurrentIndex < MacroSize) && bShouldThreadRun)
		{
			CurrentTime = std::chrono::system_clock::now();
			double MS_ElapsedSinceExecution = std::chrono::duration_cast<std::chrono::milliseconds>(CurrentTime - LastExecution).count();
			if (MS_ElapsedSinceExecution >= MacroCopy.Actions[CurrentIndex].MSDelay)
			{
				PlayKey(MacroCopy.Actions[CurrentIndex]);
				CurrentIndex++;

				LastExecution = std::chrono::system_clock::now();
			}

			if (CurrentIndex >= MacroSize)
			{
				if (MacroCopy.Loops)
				{
					CurrentIndex = 0;
				}
				else
				{
					break; // Finished!
				}
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));

			if (GlobalSettings.IsEditingMacros())
			{
				break; // Finished
			}
			
			BYTE KeyPress = CheckForHotkey();
			if (KeyPress != 0)
			{
				if (KeyPress == MacroCopy.HotKey) // Cancel
				{
					break; // Finished!
				}
				else  // Another Hotkey was pressed change directions and do this one.
				{
					const int LastIndex = (CurrentIndex < 1) ? MacroSize - 1 : CurrentIndex - 1;  // reach around back if looped

					if (KeyPress != MacroCopy.Actions[LastIndex].Key)  // Make Sure Our Macro Didn't Enter Another Hotkey
					{
						if (GlobalSettings.GetMacroCopy(KeyPress, MacroCopy))
						{
							GlobalSettings.SetRunningMacro(KeyPress);
							
							MacroSize = MacroCopy.Actions.size();
							CurrentIndex = 0;
						}
					}
				}
			}
		}

		GlobalSettings.SetRunningMacro(0);
	}
}


void BackgroundProcess::PlayKey(const KeyStroke Key)
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
