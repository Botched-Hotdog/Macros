#include "InputManager.h"

using namespace std;

void InputManager::SetMouseFlags(DWORD* DownFlag, DWORD* UpFlag, const EKeys Key)
{
	switch (Key)
	{
	case EKeys::LeftMouse:
		*DownFlag = MOUSEEVENTF_LEFTDOWN;
		*UpFlag = MOUSEEVENTF_LEFTUP;
		break;
	case EKeys::RightMouse:
		*DownFlag = MOUSEEVENTF_RIGHTDOWN;
		*UpFlag = MOUSEEVENTF_RIGHTUP;
		break;
	case EKeys::MiddleMouse:
		*DownFlag = MOUSEEVENTF_MIDDLEDOWN;
		*UpFlag = MOUSEEVENTF_MIDDLEUP;
		break;
	case EKeys::XMouse1:
	case EKeys::XMouse2:
		*DownFlag = MOUSEEVENTF_XDOWN;
		*UpFlag = MOUSEEVENTF_XUP;
		break;
	default:
		break;
	}
}
bool InputManager::IsSpecialKey(const WORD KeyCode)
{
	bool Cond1 = (KeyCode > 15 && KeyCode < 19);
	bool Cond2 = (KeyCode > 159 && KeyCode < 166);
	bool Cond3 = (KeyCode == 91 || KeyCode == 92);
	bool Cond4 = (KeyCode == 20);
	bool Cond5 = (KeyCode == 144 || KeyCode == 145);

	return Cond1 || Cond2 || Cond3 || Cond4 || Cond5;
}

bool InputManager::MakeSpecialInput(const EKeys SpecialKey, const EKeys Key, const DWORD MSDelay)
{
	const WORD SpecialKeyCode = static_cast<WORD>(SpecialKey);
	const WORD KeyCode = static_cast<WORD>(Key);
	
	if (!IsSpecialKey(SpecialKeyCode) || KeyCode < 7)
	{
		// either SpecialKey or Key is Invalid
		return false;
	}

	Sleep(MSDelay);

	INPUT Input[4] = {};
	ZeroMemory(Input, sizeof(Input));

	Input[0].type = INPUT_KEYBOARD;
	Input[0].ki.wVk = SpecialKeyCode;
	Input[0].ki.dwFlags = KEYEVENTF_EXTENDEDKEY;

	Input[0].type = INPUT_KEYBOARD;
	Input[0].ki.wVk = KeyCode;
	Input[0].ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
	
	Input[0].type = INPUT_KEYBOARD;
	Input[0].ki.wVk = KeyCode;
	Input[0].ki.dwFlags = KEYEVENTF_KEYUP;

	Input[0].type = INPUT_KEYBOARD;
	Input[0].ki.wVk = SpecialKeyCode;
	Input[0].ki.dwFlags = KEYEVENTF_KEYUP;

	UINT uS = SendInput(4, Input, sizeof(INPUT));
	return (uS == 4);
}

bool InputManager::MakeInput(const EKeys Key, const DWORD MSDelay)
{
	if (Key == EKeys::Undefined) return false;

	const WORD KeyCode = static_cast<WORD>(Key);
	DWORD InputType = NULL;
	DWORD DownFlag = NULL;
	DWORD UpFlag = NULL;

	if (KeyCode > 6) // Keyboard
	{
		InputType = INPUT_KEYBOARD;
		DownFlag = KEYEVENTF_EXTENDEDKEY;
		UpFlag = KEYEVENTF_KEYUP;
		
	}
	else // Mouse
	{
		InputType = INPUT_MOUSE;
		SetMouseFlags(&DownFlag, &UpFlag, Key);
	}

	Sleep(MSDelay);
	
	INPUT Input[2] = {};
	ZeroMemory(Input, sizeof(Input));

	Input[0].type = InputType;
	Input[1].type = InputType;

	if (InputType == INPUT_KEYBOARD)
	{
		Input[0].ki.wVk = KeyCode;
		Input[1].ki.wVk = KeyCode;

		Input[0].ki.dwFlags = DownFlag;
		Input[1].ki.dwFlags = UpFlag;
	}
	else // INPUT_MOUSE
	{
		Input[0].mi.dwFlags = DownFlag;
		Input[1].mi.dwFlags = UpFlag;
	}

	UINT uS = SendInput(2, Input, sizeof(INPUT));
	return (uS == 2);
}
