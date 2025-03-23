#include "Settings.h"

Settings GlobalSettings;

bool Settings::AddMacro(const Macro& NewMacro)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (!OverrideMacro(NewMacro))
	{
		Macros.push_back(NewMacro);
		Success = true;
	}

	return Success;
}
bool Settings::OverrideMacro(const Macro& NewMacro)
{
	bool Success = false;

	if (Macro* FoundMacro = FindMacroByHotKey(NewMacro.HotKey))
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

bool Settings::GetSafeMacro(const BYTE Hotkey, Macro& CopyAdress)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	for (const Macro& ExistingMacro : Macros)
	{
		if (Hotkey == static_cast<BYTE>(ExistingMacro.HotKey))
		{
			CopyAdress = ExistingMacro;  // Copy
			
			Success = true;
			break;
		}
	}

	return Success;
}

bool Settings::GetSafeMacroList(std::vector<MacroEntry>& CopyAdress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	CopyAdress.reserve(Macros.size());

	for (const Macro& ExistingMacro : Macros)
	{
		if (!KeyLookupTable[ExistingMacro.HotKey].bIsValid) continue;

		MacroEntry NewEntry;
		NewEntry.KeyCode = ExistingMacro.HotKey;
		NewEntry.KeyName = KeyLookupTable[ExistingMacro.HotKey].Name;


		CopyAdress.push_back(NewEntry);
	}

	return Success;
}

bool Settings::GetSafeKeystrokeList(const BYTE Hotkey, std::vector<KeystrokeEntry>& CopyAdress)
{
	bool Success = true;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (Macro* ExistingMacro = FindMacroByHotKey(Hotkey))
	{
		CopyAdress.reserve(ExistingMacro->Actions.size());
		
		for (const KeyStroke& ExistingKeystroke : ExistingMacro->Actions)
		{
			BYTE KeyCode = static_cast<BYTE>(ExistingKeystroke.Key);
			BYTE SpecialKeyCode = static_cast<BYTE>(ExistingKeystroke.SpecialKey);

			KeystrokeEntry NewEntry;

			NewEntry.KeyCode = static_cast<BYTE>(KeyCode);
			NewEntry.KeyName = KeyLookupTable[KeyCode].Name;

			NewEntry.SpecialKeyCode = static_cast<BYTE>(KeyCode);
			NewEntry.SpecialKeyName = KeyLookupTable[KeyCode].Name;

			NewEntry.MSDelay = ExistingKeystroke.MSDelay;


			CopyAdress.push_back(NewEntry);
		}

		Success = t
	}

	return Success;
}

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
