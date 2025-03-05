#pragma once
#include "KeyData.h"
// #include <Windows.h>

class InputManager
{
protected:

	void SetMouseFlags(DWORD* DownFlag, DWORD* UpFlag, const EKeys Key);
	bool IsSpecialKey(const WORD KeyCode);
public:

	// Used For Inputs Such as: CTRL + "Key" | SHIFT + "Key" (Capital Letters). Returns True For Success
	bool MakeSpecialInput(const EKeys SpecialKey, const EKeys Key, const DWORD MSDelay);
	
	// Returns True For Success
	bool MakeInput(const EKeys Key, const DWORD MSDelay);
};

