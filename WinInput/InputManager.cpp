#include "InputManager.h"
#include <Windows.h>

using namespace std;

void InputManager::MakeMouseInput(int Code, double Delay)
{
	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = Code;
	
	SendInput(1, &Input, sizeof(Input));
	ZeroMemory(&Input, sizeof(Input));
}

void InputManager::MakeKeyInput(char Key, double Delay)
{
	INPUT Input = { 0 };
	Input.type = INPUT_KEYBOARD;
	Input.ki.wVk = VkKeyScanA(Key);

	SendInput(1, &Input, sizeof(Input));
	ZeroMemory(&Input, sizeof(Input));

	Input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &Input, sizeof(Input));
}
