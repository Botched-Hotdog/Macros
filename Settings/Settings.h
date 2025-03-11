#pragma once
#include "../Input/KeyData.h"
#include <vector>
#include <Windows.h>

// Middle Man for Background and UI
class Settings
{
protected:	
	BYTE Hotkey;
	bool bLoops;
	ActionList Actions;

	bool bIsUserEditing;
public:
	__inline bool DoesMacroLoop() const { return bLoops; };
	__inline bool IsUserEditing() const { return bIsUserEditing; };
	__inline void SetLoop(const bool Enabled) { bLoops = Enabled; };

	__inline const BYTE GetHotkey() const { return Hotkey; };
	__inline std::vector<KeyStroke> GetSafeActionList() { return *Actions.GetContentsReference(); };
};

