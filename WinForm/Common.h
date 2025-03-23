#pragma once
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;

ref class KeyItem
{
public:
	BYTE KeyCode = 0;
	String^ Name;

public:
	virtual String^ ToString() override
	{
		return Name;
	}
};


// Came From Interoperability Section at https://en.wikipedia.org/wiki/C%2B%2B/CLI

String^ ConvertToManagedString(std::string str)
{
	return gcnew String(msclr::interop::marshal_as<String^>(str.c_str()));
}

String^ ConvertToManagedString(const char* charPtr)
{
	return gcnew String(msclr::interop::marshal_as<String^>(charPtr));
}

std::string ConvertToUnmanagedString(String^ managed)
{
	return marshal_as<std::string>(managed);
}