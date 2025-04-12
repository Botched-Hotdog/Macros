#pragma once
#include "KeyData.h"
// #include <Windows.h>

class InputManager
{
protected:
	// Saves Creating an and destroying an object every input
	INPUT RegInput[2] = {};
	INPUT SpecInput[4] = {};

	void SetMouseFlags(DWORD* DownFlag, DWORD* UpFlag, const BYTE Key);
public:
	InputManager();
	~InputManager();

	static bool IsSpecialKey(const WORD KeyCode);


	// Used For Inputs Such as: CTRL + "Key" | SHIFT + "Key" (Capital Letters). Returns True For Success
	bool MakeSpecialInput(const BYTE SpecialKey, const BYTE Key);
	
	// Used For Basic Key and Mouse Inputs. Returns True For Success
	bool MakeInput(const BYTE Key);
};

