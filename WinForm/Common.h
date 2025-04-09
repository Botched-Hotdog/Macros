#pragma once
#include "../Settings/Settings.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class KeyItem  // Cannot Store KeystrokeEntry on MacroEditForm Becasue its not a Managed Type
{
public:
	BYTE KeyCode = 0;
	BYTE SpecialKeyCode = 0;

	String^ KeyName;
	String^ SpecialKeyName;

	DWORD MSDelay = 0;

	virtual String^ ToString() override
	{
		if (SpecialKeyCode != 0)
		{
			return SpecialKeyName + " + " + KeyName;
		}
		else
		{
			return KeyName;
		}
	}

	KeyItem() : KeyCode(0), SpecialKeyCode(0), KeyName(nullptr), SpecialKeyName(nullptr) , MSDelay(0) {};
};

// Came From Interoperability Section at https://en.wikipedia.org/wiki/C%2B%2B/CLI
String^ ConvertToManagedString(std::string str);
String^ ConvertToManagedString(const char* charPtr);
std::string ConvertToUnmanagedString(String^ managed);