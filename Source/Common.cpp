#include "./Common.h"

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



KeyItem::KeyItem()
{
	KeyCode = 0;
	KeyName = nullptr;
}
String^ KeyItem::ToString()
{
	return KeyName;
}


KeystrokeItem::KeystrokeItem() : KeyItem()
{
	SpecialKeyCode = 0;
	SpecialKeyName = nullptr;
	MSDelay = 0;
}
String^ KeystrokeItem::ToString()
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
