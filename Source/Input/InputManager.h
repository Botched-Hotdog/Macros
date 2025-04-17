#pragma once
#include "./KeyData.h"


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


	// Used For Inputs Such as: CTRL + "Key" | SHIFT + "Key" (Capital Letters).
	bool MakeSpecialInput(const BYTE SpecialKey, const BYTE Key);
	
	// Used For Basic Key and Mouse Inputs.
	bool MakeInput(const BYTE Key);
};

