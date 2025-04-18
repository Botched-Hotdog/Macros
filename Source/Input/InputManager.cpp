#include "./InputManager.h"

using namespace std;

InputManager::InputManager()
{
	std::memset(RegInput, 0, sizeof(RegInput));
	std::memset(SpecInput, 0, sizeof(SpecInput));
}
InputManager::~InputManager()
{
	std::memset(RegInput, 0, sizeof(RegInput));
	std::memset(SpecInput, 0, sizeof(SpecInput));
}


void InputManager::SetMouseFlags(DWORD* DownFlag, DWORD* UpFlag, const BYTE Key)
{
	switch (Key)
	{
	case 1:
		*DownFlag = MOUSEEVENTF_LEFTDOWN;
		*UpFlag = MOUSEEVENTF_LEFTUP;
		break;
	case 2:
		*DownFlag = MOUSEEVENTF_RIGHTDOWN;
		*UpFlag = MOUSEEVENTF_RIGHTUP;
		break;
	case 4:
		*DownFlag = MOUSEEVENTF_MIDDLEDOWN;
		*UpFlag = MOUSEEVENTF_MIDDLEUP;
		break;
	case 5:
	case 6:
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


bool InputManager::MakeSpecialInput(const BYTE SpecialKey, const BYTE Key)
{
	const WORD SpecialKeyCode = static_cast<WORD>(SpecialKey);
	const WORD KeyCode = static_cast<WORD>(Key);
	
	if (!IsSpecialKey(SpecialKeyCode))
	{
		// either SpecialKey or Key is Invalid
		return false;
	}

	DWORD InputType = NULL;
	DWORD DownFlag = NULL;
	DWORD UpFlag = NULL;

	if (KeyCode > 6) // Keyboard
	{
		InputType = INPUT_KEYBOARD;
		DownFlag = 0;
		UpFlag = KEYEVENTF_KEYUP;

	}
	else // Mouse
	{
		InputType = INPUT_MOUSE;
		SetMouseFlags(&DownFlag, &UpFlag, Key);
	}

	std::memset(SpecInput, 0, sizeof(SpecInput));

	SpecInput[0].type = INPUT_KEYBOARD;
	SpecInput[0].ki.wVk = SpecialKeyCode;

	SpecInput[1].type = InputType;
	SpecInput[1].ki.wVk = KeyCode;
	SpecInput[1].ki.dwFlags = DownFlag;
	
	SpecInput[2].type = InputType;
	SpecInput[2].ki.wVk = KeyCode;
	SpecInput[2].ki.dwFlags = UpFlag;

	SpecInput[3].type = INPUT_KEYBOARD;
	SpecInput[3].ki.wVk = SpecialKeyCode;
	SpecInput[3].ki.dwFlags = KEYEVENTF_KEYUP;

	UINT uS = SendInput(4, SpecInput, sizeof(INPUT));
	return (uS == 4);
}

bool InputManager::MakeInput(const BYTE Key)
{
	if (Key == 0) return false;

	const WORD KeyCode = static_cast<WORD>(Key);
	DWORD InputType = NULL;
	DWORD DownFlag = NULL;
	DWORD UpFlag = NULL;

	if (KeyCode > 6) // Keyboard
	{
		InputType = INPUT_KEYBOARD;
		DownFlag = 0;
		UpFlag = KEYEVENTF_KEYUP;
		
	}
	else // Mouse
	{
		InputType = INPUT_MOUSE;
		SetMouseFlags(&DownFlag, &UpFlag, Key);
	}

	std::memset(RegInput, 0, sizeof(RegInput));

	RegInput[0].type = InputType;
	RegInput[1].type = InputType;

	if (InputType == INPUT_KEYBOARD)
	{
		RegInput[0].ki.wVk = KeyCode;
		RegInput[1].ki.wVk = KeyCode;

		RegInput[0].ki.dwFlags = DownFlag;
		RegInput[1].ki.dwFlags = UpFlag;
	}
	else // INPUT_MOUSE
	{
		RegInput[0].mi.dwFlags = DownFlag;
		RegInput[1].mi.dwFlags = UpFlag;
	}

	UINT uS = SendInput(2, RegInput, sizeof(INPUT));
	return (uS == 2);
}
