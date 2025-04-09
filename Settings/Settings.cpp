#include "Settings.h"

Settings GlobalSettings;


Macro* Settings::FindMacroByHotKey(const BYTE Hotkey)
{
	Macro* Result = nullptr;

	for (Macro& ExistingMacro : Macros)
	{
		if (Hotkey == static_cast<BYTE>(ExistingMacro.HotKey))
		{
			Result = &ExistingMacro;
			break;
		}
	}

	return Result;
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
		if (Hotkey == static_cast<BYTE>(Macros[i].HotKey))
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
		if (Hotkey == static_cast<BYTE>(ExistingMacro.HotKey))
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
		if (Hotkey == static_cast<BYTE>(ExistingMacro.HotKey))
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
		if (Hotkey == static_cast<BYTE>(ExistingMacro.HotKey))
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
			BYTE KeyCode = static_cast<BYTE>(ExistingKeystroke.Key);
			BYTE SpecialKeyCode = static_cast<BYTE>(ExistingKeystroke.SpecialKey);

			KeystrokeEntry NewEntry;

			NewEntry.KeyCode = static_cast<BYTE>(KeyCode);
			NewEntry.KeyName = KeyLookupTable[KeyCode].Name;

			NewEntry.SpecialKeyCode = static_cast<BYTE>(SpecialKeyCode);
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
