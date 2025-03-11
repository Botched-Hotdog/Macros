#include "InputThread.h"
#include "../Settings/Settings.h"

InputThread::InputThread(Settings* SettingRef)
{
	SettingsReference = SettingRef;
}

void InputThread::RunThread()
{
	if (SettingsReference)
	{
		bShouldThreadRun = true;
		Thread = std::thread(ThreadEntry, this);
	}
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
		if (SettingsReference)
		{
			BYTE HotKey = static_cast<int>(SettingsReference->GetHotkey());
			bool IsUserEditingSettings = SettingsReference->IsUserEditing();

			if (!IsUserEditingSettings && GetAsyncKeyState(HotKey))  // Hotkey pressed
			{
				std::vector<KeyStroke> ActionListCopy = SettingsReference->GetSafeActionList();

				ProcessKeys(ActionListCopy);
			}
		}
		else
		{
			bShouldThreadRun = false;
		}

	
		if (bShouldThreadRun)
		{
			Sleep(10);
		}
	}
}


void InputThread::ProcessKeys(const std::vector<KeyStroke>& Keys)
{
	while (bShouldThreadRun)
	{

	}
}

void InputThread::PlayKey(const KeyStroke Key)
{
	bool Success = false;
	
	if (InputManager::IsSpecialKey(static_cast<WORD>(Key.SpecialKey)))
	{
		Success = InputManager.MakeSpecialInput(Key.SpecialKey, Key.Key, Key.MSDelay);
	}
	else
	{
		Success = InputManager.MakeInput(Key.Key, Key.MSDelay);
	}

	if (Success)
	{
		// do something idk
	}
}
