#include "Settings.h"

Settings GlobalSettings;

bool Settings::AddMacro(const Macro& NewMacro)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (!IsValidHotKey(NewMacro.HotKey))
	{
		Macros.push_back(NewMacro);
		Success = true;
	}

	return Success;
}

bool Settings::RemoveMacro(const BYTE Hotkey)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (Macro* FoundMacro = FindMacroByHotKey(Hotkey))
	{

	}

	return Success;
}

bool Settings::OverrideMacro(const Macro& NewMacro)
{
	bool Success = false;
	std::unique_lock<std::shared_mutex> lock(ProtectSettings);

	if (Macro* FoundMacro = FindMacroByHotKey(NewMacro.HotKey))
	{
		*FoundMacro = NewMacro;
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
