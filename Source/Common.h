#pragma once
#include "./Settings/Settings.h"
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

public ref class ListItem
{
public:
	virtual String^ ToString() override = 0;
};


public ref class KeyItem : public ListItem
{
public:
	BYTE KeyCode;
	String^ KeyName;

	KeyItem();

	virtual String^ ToString() override;
};
public ref class KeystrokeItem : public KeyItem
{
public:
	BYTE SpecialKeyCode;
	String^ SpecialKeyName;
	DWORD MSDelay = 0;

	KeystrokeItem();

	virtual String^ ToString() override;
};


struct MacroEntry
{
	BYTE KeyCode;
	std::string KeyName;
};
struct KeystrokeEntry : public MacroEntry
{
	BYTE SpecialKeyCode;
	std::string SpecialKeyName;

	DWORD MSDelay;
};

// Came From Interoperability Section at https://en.wikipedia.org/wiki/C%2B%2B/CLI
String^ ConvertToManagedString(std::string str);
String^ ConvertToManagedString(const char* charPtr);
std::string ConvertToUnmanagedString(String^ managed);