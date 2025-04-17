#include "./Settings.h"
#include "../Common.h"
#include <fstream>

#include <sstream>

Settings GlobalSettings;


Macro* Settings::FindMacroByHotKey(const BYTE Hotkey)
{
	Macro* Result = nullptr;

	for (Macro& ExistingMacro : Macros)
	{
		if (Hotkey == ExistingMacro.HotKey)
		{
			Result = &ExistingMacro;
			break;
		}
	}

	return Result;
}


bool Settings::Initialize(const char* FileName)
{
	bool Success = false;
	
	if (FileName)
	{
		IniFile = FileName;
		if (ReadFromFile())
		{
			Success = true;
		}
	}

	return Success;
}

bool Settings::WriteToFile()
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);	
	
	std::ofstream OutputFile;
	OutputFile.open(IniFile);
	if (OutputFile.is_open())
	{
		for (const Macro ExistingMacro : Macros)
		{
			OutputFile << "\n[ " + std::to_string(ExistingMacro.HotKey) + ' ' + std::to_string(ExistingMacro.Loops);
			
			for (const KeyStroke ExistingKeyStroke : ExistingMacro.Actions)
			{
				OutputFile << "\n- " +
					std::to_string(ExistingKeyStroke.SpecialKey) + ' ' +
					std::to_string(ExistingKeyStroke.Key) + ' ' +
					std::to_string(ExistingKeyStroke.MSDelay);
			}

			OutputFile << "\n]";
		}
		
		Success = true;
		OutputFile.close();
	}
	
	return Success;
}

bool Settings::ReadFromFile()
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	std::ifstream InputFile;
	InputFile.open(IniFile);
	if (InputFile.is_open())
	{
		Macros.clear();

		Macro NewEntry;

		NewEntry.Actions.clear();
		NewEntry.HotKey = 0;
		NewEntry.Loops = false;

		std::string Line;
		while (std::getline(InputFile, Line))
		{
			if (Line[0] == '[')  // Macro Start
			{			
				std::stringstream Stream(Line);
				
				char Discard;
				bool bLoops;
				int HotKey;

				Stream >> Discard >> HotKey >> bLoops;

				NewEntry.HotKey = HotKey;
				NewEntry.Loops = bLoops;
			}
			else if (Line[0] == ']')  // Macro End
			{
				Macros.push_back(NewEntry);

				NewEntry.Actions.clear();
				NewEntry.HotKey = 0;
				NewEntry.Loops = false;
			}
			else if (Line[0] == '-')  // Keystroke Entry
			{
				std::stringstream Stream(Line);

				char Discard;
				int KeyCode;
				int SpecialKeyCode;
				DWORD MSDelay;

				Stream >> Discard >> SpecialKeyCode >> KeyCode >> MSDelay;

				KeyStroke NewKeystroke;
				NewKeystroke.SpecialKey = SpecialKeyCode;
				NewKeystroke.Key = KeyCode;
				NewKeystroke.MSDelay = MSDelay;

				NewEntry.Actions.push_back(NewKeystroke);
			}
		}

		Success = true;
		InputFile.close();
	}

	return Success;
}


bool Settings::AddMacro(const Macro& NewMacro)
{
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (!OverrideMacro(NewMacro.HotKey, NewMacro))
	{
		Macros.push_back(NewMacro);
	}

	return true;
}
bool Settings::OverrideMacro(const BYTE ExistingHotkey, const Macro& NewMacro)
{
	bool Success = false;

	if (Macro* FoundMacro = FindMacroByHotKey(ExistingHotkey))
	{
		FoundMacro->Actions.clear();

		*FoundMacro = NewMacro;
		Success = true;
	}

	return Success;
}

bool Settings::RemoveMacro(const BYTE Hotkey)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (int i = 0; i < Macros.size(); i++)
	{
		if (Hotkey == Macros[i].HotKey)
		{
			Macros.erase(Macros.begin() + i);

			Success = true;
			break;
		}
	}

	return Success;
}


bool Settings::IsValidHotKey(const BYTE Hotkey)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (const Macro& ExistingMacro : Macros)
	{
		if (Hotkey == ExistingMacro.HotKey)
		{
			Success = true;
			break;
		}
	}

	return Success;
}

bool Settings::DoesMacroLoop(const BYTE Hotkey)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (const Macro& ExistingMacro : Macros)
	{
		if (Hotkey == ExistingMacro.HotKey)
		{
			Success = ExistingMacro.Loops;
			break;
		}
	}

	return Success;
}


bool Settings::GetMacroCopy(const BYTE Hotkey, Macro& CopyAddress)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (const Macro& ExistingMacro : Macros)
	{
		if (Hotkey == ExistingMacro.HotKey)
		{
			CopyAddress = ExistingMacro;  // Copy
			
			Success = true;
			break;
		}
	}

	return Success;
}

bool Settings::GetExistingMacrosCopy(std::vector<MacroEntry>& CopyAddress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	CopyAddress.reserve(Macros.size());

	for (const Macro& ExistingMacro : Macros)
	{
		if (!KeyLookupTable[ExistingMacro.HotKey].bIsValidHotKey) continue;

		MacroEntry NewEntry;
		NewEntry.KeyCode = ExistingMacro.HotKey;
		NewEntry.KeyName = KeyLookupTable[ExistingMacro.HotKey].Name;


		CopyAddress.push_back(NewEntry);
	}

	return Success;
}

bool Settings::GetKeystrokesFromMacroCopy(const BYTE Hotkey, std::vector<KeystrokeEntry>& CopyAddress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (Macro* ExistingMacro = FindMacroByHotKey(Hotkey))
	{
		CopyAddress.reserve(ExistingMacro->Actions.size());
		
		for (const KeyStroke& ExistingKeystroke : ExistingMacro->Actions)
		{
			BYTE KeyCode = ExistingKeystroke.Key;
			BYTE SpecialKeyCode = ExistingKeystroke.SpecialKey;

			KeystrokeEntry NewEntry;

			NewEntry.KeyCode = KeyCode;
			NewEntry.KeyName = KeyLookupTable[KeyCode].Name;

			NewEntry.SpecialKeyCode = SpecialKeyCode;
			NewEntry.SpecialKeyName = KeyLookupTable[SpecialKeyCode].Name;

			NewEntry.MSDelay = ExistingKeystroke.MSDelay;


			CopyAddress.push_back(NewEntry);
		}

		Success = true;
	}

	return Success;
}


bool Settings::GetValidKeystrokes(std::vector<MacroEntry>& CopyAddress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (int i = 1; i < 0x7F; ++i) // Don't need to go thru all the keys
	{
		if (KeyLookupTable[i].bIsValidKeystroke)
		{
			MacroEntry NewEntry;
			NewEntry.KeyName = KeyLookupTable[i].Name;
			NewEntry.KeyCode = i;

			CopyAddress.push_back(NewEntry);
		}
	}

	return Success;
}

bool Settings::GetValidHotKeys(std::vector<MacroEntry>& CopyAddress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (int i = 1; i < 0x7F; ++i) // Don't need to go thru all the keys
	{
		if (KeyLookupTable[i].bIsValidHotKey)
		{
			MacroEntry NewEntry;
			NewEntry.KeyName = KeyLookupTable[i].Name;
			NewEntry.KeyCode = i;

			CopyAddress.push_back(NewEntry);
		}
	}

	return Success;
}

bool Settings::GetValidSpecialKeys(std::vector<MacroEntry>& CopyAddress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (int i = 1; i < 0x7F; ++i) // Don't need to go thru all the keys
	{
		if (KeyLookupTable[i].bIsSpecialKey)
		{
			MacroEntry NewEntry;
			NewEntry.KeyName = KeyLookupTable[i].Name;
			NewEntry.KeyCode = i;

			CopyAddress.push_back(NewEntry);
		}
	}

	return Success;
}
