#include "Common.h"

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
