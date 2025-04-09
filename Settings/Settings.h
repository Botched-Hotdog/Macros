#pragma once
#include "../Input/KeyData.h"
#include "../SimpleIni/SimpleIni.h"
#include <vector>
#include <shared_mutex>
#include <Windows.h>

struct MacroEntry  // Used By Main Form To Display Current Hotkeys
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


class Settings
{
protected:	
	std::vector<Macro> Macros;
	BYTE RunningMacro;
	bool bIsEditing;

	CSimpleIniA IniManager;
	WCHAR FilePathToINI;

	std::shared_mutex ProtectSettings;
public:
	// bool Initialize(WCHAR* FileName);
	// bool WriteToIni();
	// bool ReadFromIni();

	bool AddMacro(const Macro& NewMacro);
	bool RemoveMacro(const BYTE Hotkey);
	bool OverrideMacro(const BYTE ExistingHotkey, const Macro& NewMacro); // Searches By Hotkey and replaces

	bool IsValidHotKey(const BYTE Hotkey); // Check If Hotkey Is Bound
	bool DoesMacroLoop(const BYTE Hotkey);

	inline bool IsMacroRunning(const BYTE Hotkey) const { return RunningMacro == Hotkey; };
	void SetRunningMacro(const BYTE Hotkey) { RunningMacro = Hotkey; };
	inline bool IsEditingMacros() const { return bIsEditing; };
	void SetEditingMacros(const bool Value) { bIsEditing = Value; };

	bool GetMacroCopy(const BYTE Hotkey, Macro& CopyAddress); // Get Copy Of Macro For Specified Hotkey
	bool GetExistingMacrosCopy(std::vector<MacroEntry>& CopyAddress);
	bool GetKeystrokesFromMacroCopy(const BYTE Hotkey, std::vector<KeystrokeEntry>& CopyAddress);

	bool GetValidKeystrokes(std::vector<MacroEntry>& CopyAddress);
	bool GetValidHotKeys(std::vector<MacroEntry>& CopyAddress);
	bool GetValidSpecialKeys(std::vector<MacroEntry>& CopyAddress);


private:
	Macro* FindMacroByHotKey(const BYTE Hotkey);

	const KeyLookup KeyLookupTable[256] = {  // Keycode will map straight to Name
			{ "Invalid", 0, 0, 0},
			{ "Left Mouse Button", 1, 1, 0}, { "Right Mouse Button", 1, 1, 0},
			{ "Control-break processing", 0, 0, 0}, { "Middle Mouse Button", 1, 1, 0},
			{ "X1 Mouse Button", 1, 1, 0}, { "X2 Mouse Button", 1, 1, 0},

			{ "Reserved", 0, 0, 0},

			{ "Backspace", 1, 1, 0},
			{ "Tab", 1, 1, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Clear", 0, 0, 0},
			{ "Enter", 1, 1, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Shift", 1, 1, 1},
			{ "Control", 1, 1, 1},
			{ "Alt", 1, 1, 1},
			{ "Pause", 0, 0, 0},
			{ "Caps Lock", 1, 1, 1}
			,
			{ "IME Kana mode", 0, 0, 0},
			{ "IME On", 0, 0, 0},
			{ "IME Junja mode", 0, 0, 0},
			{ "IME final mode", 0, 0, 0},
			{ "IME Hanja mode", 0, 0, 0},
			{ "IME Off", 0, 0, 0},

			{ "Escape", 0, 0, 0},

			{ "IME convert", 0, 0, 0},
			{ "IME nonconvert", 0, 0, 0},
			{ "IME accept", 0, 0, 0},
			{ "IME mode change request", 0, 0, 0},

			{ "Spacebar", 1, 1, 0},
			{ "Page Up", 1, 1, 0},
			{ "Page Down", 1, 1, 0},
			{ "End", 1, 1, 0},
			{ "Home", 1, 1, 0},
			{ "Left Arrow", 1, 1, 0},
			{ "Up Arrow", 1, 1, 0},
			{ "Right Arrow", 1, 1, 0},
			{ "Down Arrow", 1, 1, 0},
			{ "Select", 1, 1, 0},
			{ "Print", 0, 0, 0},
			{ "Execute", 0, 0, 0},
			{ "Print Screen", 0, 0, 0},
			{ "Insert", 1, 1, 0},
			{ "Delete", 1, 1, 0},
			{ "Help", 1, 1, 0},

			{ "0", 1, 1, 0},	{ "1", 1, 1, 0}, { "2", 1, 1, 0}, { "3", 1, 1, 0},
			{ "4", 1, 1, 0}, { "5", 1, 1, 0}, { "6", 1, 1, 0}, { "7", 1, 1, 0},
			{ "8", 1, 1, 0}, { "9", 1, 1, 0},

			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},

			{ "A", 1, 1, 0}, { "B", 1, 1, 0}, { "C", 1, 1, 0}, { "D", 1, 1, 0}, { "E", 1, 1, 0}, { "F", 1, 1, 0},
			{ "G", 1, 1, 0}, { "H", 1, 1, 0}, { "I", 1, 1, 0}, { "J", 1, 1, 0}, { "K", 1, 1, 0}, { "L", 1, 1, 0},
			{ "M", 1, 1, 0}, { "N", 1, 1, 0}, { "O", 1, 1, 0}, { "P", 1, 1, 0}, { "Q", 1, 1, 0}, { "R", 1, 1, 0},
			{ "S", 1, 1, 0}, { "T", 1, 1, 0}, { "U", 1, 1, 0}, { "V", 1, 1, 0}, { "W", 1, 1, 0}, { "X", 1, 1, 0},
			{ "Y", 1, 1, 0}, { "Z", 1, 1, 0},

			{ "Left Windows Key", 1, 1, 1},
			{ "Right Windows Key", 1, 1, 1},
			{ "Applications Key", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Sleep", 0, 0, 0},

			{ "Numeric Keypad 0", 1, 1, 0}, { "Numeric Keypad 1", 1, 1, 0}, { "Numeric Keypad 2", 1, 1, 0}, { "Numeric Keypad 3", 1, 1, 0},
			{ "Numeric Keypad 4", 1, 1, 0}, { "Numeric Keypad 5", 1, 1, 0},	{ "Numeric Keypad 6", 1, 1, 0}, { "Numeric Keypad 7", 1, 1, 0},
			{ "Numeric Keypad 8", 1, 1, 0}, { "Numeric Keypad 9", 1, 1, 0},

			{ "Multiply", 0, 0, 0},
			{ "Add", 0, 0, 0},
			{ "Separator", 0, 0, 0},
			{ "Subtract", 0, 0, 0},
			{ "Decimal", 0, 0, 0},
			{ "Divide", 0, 0, 0},

			{ "F1", 1, 1, 0},	{ "F2", 1, 1, 0},	{ "F3", 1, 1, 0},	{ "F4", 1, 1, 0},	{ "F5", 1, 1, 0},
			{ "F6", 1, 1, 0},	{ "F7", 1, 1, 0},	{ "F8", 1, 1, 0},	{ "F9", 1, 1, 0},	{ "F10", 1, 1, 0},
			{ "F11", 1, 1, 0}, { "F12", 1, 1, 0}, { "F13", 1, 1, 0}, { "F14", 1, 1, 0}, { "F15", 1, 1, 0},
			{ "F16", 1, 1, 0}, { "F17", 1, 1, 0}, { "F18", 1, 1, 0}, { "F19", 1, 1, 0}, { "F20", 1, 1, 0},
			{ "F21", 1, 1, 0}, { "F22", 1, 1, 0}, { "F23", 1, 1, 0}, { "F24", 1, 1, 0},

			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},

			{ "Num Lock", 1, 1, 1},
			{ "Scroll Lock", 1, 1, 1},

			{ "= key on numpad", 0, 0, 0},
			{ "Unregister word", 0, 0, 0},
			{ "Register word", 0, 0, 0},
			{ "Left OYAYUBI", 0, 0, 0},
			{ "Right OYAYUBI", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},

			{ "Left SHIFT key", 1, 1, 0},	{ "Right SHIFT key", 1, 1, 0},
			{ "Left CONTROL key", 1, 1, 0}, { "Right CONTROL key", 1, 1, 0},
			{ "Left ALT key", 1, 1, 0}, { "Right ALT key", 1, 1, 0},

			{ "Browser Back key", 0, 0, 0}, { "Browser Forward key", 0, 0, 0},
			{ "Browser Refresh key", 0, 0, 0}, { "Browser Stop key", 0, 0, 0},
			{ "Browser Search key", 0, 0, 0},	{ "Browser Favorites key", 0, 0, 0},
			{ "Browser Start and Home key", 0, 0, 0},

			{ "Volume Mute key", 0, 0, 0}, { "Volume Down key", 0, 0, 0}, { "Volume Up key", 0, 0, 0},

			{ "Next Track key", 0, 0, 0}, { "Previous Track key", 0, 0, 0},
			{ "Stop Media key", 0, 0, 0},	{ "Play/Pause Media key", 0, 0, 0},
			{ "Start Mail key", 0, 0, 0},	{ "Select Media key", 0, 0, 0},

			{ "Start Application 1 key", 0, 0, 0},
			{ "Start Application 2 key", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ ";: key US", 0, 0, 0},
			{ "+ key US", 0, 0, 0},
			{ ", key US", 0, 0, 0},
			{ "- key US", 0, 0, 0},
			{ ". key US", 0, 0, 0},
			{ "/? key US", 0, 0, 0},
			{ "~ key US", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "VK_GAMEPAD_A", 0, 0, 0}, { "VK_GAMEPAD_B", 0, 0, 0},	{ "VK_GAMEPAD_X", 0, 0, 0}, { "VK_GAMEPAD_Y", 0, 0, 0},
			{ "VK_GAMEPAD_RIGHT_SHOULDER", 0, 0, 0}, { "VK_GAMEPAD_LEFT_SHOULDER", 0, 0, 0}, { "VK_GAMEPAD_LEFT_TRIGGER", 0, 0, 0},
			{ "VK_GAMEPAD_RIGHT_TRIGGER", 0, 0, 0}, { "VK_GAMEPAD_DPAD_UP", 0, 0, 0}, { "VK_GAMEPAD_DPAD_DOWN", 0, 0, 0},
			{ "VK_GAMEPAD_DPAD_LEFT", 0, 0, 0}, { "VK_GAMEPAD_DPAD_RIGHT", 0, 0, 0}, { "VK_GAMEPAD_MENU", 0, 0, 0},
			{ "VK_GAMEPAD_VIEW", 0, 0, 0}, { "VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON", 0, 0, 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON", 0, 0, 0},
			{ "VK_GAMEPAD_LEFT_THUMBSTICK_UP", 0, 0, 0}, { "VK_GAMEPAD_LEFT_THUMBSTICK_DOWN", 0, 0, 0}, { "VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT", 0, 0, 0},
			{ "VK_GAMEPAD_LEFT_THUMBSTICK_LEFT", 0, 0, 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_UP", 0, 0, 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN", 0, 0, 0},
			{ "VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT", 0, 0, 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT", 0, 0, 0},
			{ "[{ for US", 0, 0, 0},
			{ "\\| for US", 0, 0, 0},
			{ "]} for US", 0, 0, 0},
			{ "'\" for US", 0, 0, 0},
			{ "Undefined", 0, 0, 0},
			{ "Reserved", 0, 0, 0},
			{ "'AX' key on Japanese AX kbd", 0, 0, 0},
			{ "<> or \\| on RT 102-key kbd", 0, 0, 0},
			{ "Help key on ICO", 0, 0, 0},
			{ "00 key on ICO", 0, 0, 0},
			{ "VK_PROCESSKEY", 0, 0, 0},
			{ "VK_ICO_CLEAR", 0, 0, 0},
			{ "VK_PACKET", 0, 0, 0},
			{ "Unassigned", 0, 0, 0},
			{ "VK_OEM_RESET", 0, 0, 0}, { "VK_OEM_JUMP", 0, 0, 0}, { "VK_OEM_PA1", 0, 0, 0}, { "VK_OEM_PA2", 0, 0, 0}, { "VK_OEM_PA3", 0, 0, 0}, { "VK_OEM_WSCTRL", 0, 0, 0},
			{ "VK_OEM_CUSEL", 0, 0, 0}, { "VK_OEM_ATTN", 0, 0, 0}, { "VK_OEM_FINISH", 0, 0, 0}, { "VK_OEM_COPY", 0, 0, 0}, { "VK_OEM_AUTO", 0, 0, 0}, { "VK_OEM_ENLW", 0, 0, 0},
			{ "VK_OEM_BACKTAB", 0, 0, 0},
			{ "VK_ATTN", 0, 0, 0}, { "VK_CRSEL", 0, 0, 0}, { "VK_EXSEL", 0, 0, 0}, { "VK_EREOF", 0, 0, 0},
			{ "VK_PLAY", 0, 0, 0}, { "VK_ZOOM", 0, 0, 0}, { "VK_NONAME", 0, 0, 0}, { "VK_PA1", 0, 0, 0},
			{ "VK_OEM_CLEAR", 0, 0, 0},
			{ "Reserved", 0, 0, 0}
	};
};

extern Settings GlobalSettings;