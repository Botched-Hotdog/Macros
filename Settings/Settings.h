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
struct KeystrokeEntry : MacroEntry
{
	BYTE SpecialKeyCode;
	std::string SpecialKeyName;

	DWORD MSDelay;
};


class Settings
{
protected:	
	std::vector<Macro> Macros;
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
	bool OverrideMacro(const Macro& NewMacro); // Searches By Hotkey and replaces

	bool IsValidHotKey(const BYTE Hotkey); // Check If Hotkey Is Bound
	bool GetSafeMacro(const BYTE Hotkey, Macro& CopyAdress); // Get Copy Of Macro For Specified Hotkey
	bool GetSafeMacroList(std::vector<MacroEntry>& CopyAdress);
	bool GetSafeKeystrokeList(const BYTE Hotkey, std::vector<KeystrokeEntry>& CopyAdress);

	bool IsEditingMacros() { return bIsEditing; };
	void SetEditingMacros(const bool Value) { bIsEditing = Value; };
private:
	Macro* FindMacroByHotKey(const BYTE Hotkey);

	const KeyLookup KeyLookupTable[256] = {  // Keycode will map straight to Name
			{ "Invalid", 0},
			{ "Left Mouse Button", 1}, { "Right Mouse Button", 1},
			{ "Control-break processing", 0}, { "Middle Mouse Button", 1},
			{ "X1 Mouse Button", 1}, { "X2 Mouse Button", 1},

			{ "Reserved", 0},

			{ "Backspace", 1},
			{ "Tab", 1},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Clear", 0},
			{ "Enter", 1},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Shift", 1},
			{ "Control", 1},
			{ "Alt", 1},
			{ "Pause", 0},
			{ "Caps Lock", 1}
			,
			{ "IME Kana mode", 0},
			{ "IME On", 0},
			{ "IME Junja mode", 0},
			{ "IME final mode", 0},
			{ "IME Hanja mode", 0},
			{ "IME Off", 0},

			{ "Escape", 0},

			{ "IME convert", 0},
			{ "IME nonconvert", 0},
			{ "IME accept", 0},
			{ "IME mode change request", 0},

			{ "Spacebar", 1},
			{ "Page Up", 1},
			{ "Page Down", 1},
			{ "End", 1},
			{ "Home", 1},
			{ "Left Arrow", 1},
			{ "Up Arrow", 1},
			{ "Right Arrow", 1},
			{ "Down Arrow", 1},
			{ "Select", 1},
			{ "Print", 0},
			{ "Execute", 0},
			{ "Print Screen", 0},
			{ "Insert", 1},
			{ "Delete", 1},
			{ "Help", 1},

			{ "0", 1},	{ "1", 1}, { "2", 1}, { "3", 1},
			{ "4", 1}, { "5", 1}, { "6", 1}, { "7", 1},
			{ "8", 1}, { "9", 1},

			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},

			{ "A", 1}, { "B", 1}, { "C", 1}, { "D", 1}, { "E", 1}, { "F", 1},
			{ "G", 1}, { "H", 1}, { "I", 1}, { "J", 1}, { "K", 1}, { "L", 1},
			{ "M", 1}, { "N", 1}, { "O", 1}, { "P", 1}, { "Q", 1}, { "R", 1},
			{ "S", 1}, { "T", 1}, { "U", 1}, { "V", 1}, { "W", 1}, { "X", 1},
			{ "Y", 1}, { "Z", 1},

			{ "Left Windows Key", 1},
			{ "Right Windows Key", 1},
			{ "Applications Key", 0},
			{ "Reserved", 0},
			{ "Sleep", 0},

			{ "Numeric Keypad 0", 1}, { "Numeric Keypad 1", 1}, { "Numeric Keypad 2", 1}, { "Numeric Keypad 3", 1},
			{ "Numeric Keypad 4", 1}, { "Numeric Keypad 5", 1},	{ "Numeric Keypad 6", 1}, { "Numeric Keypad 7", 1},
			{ "Numeric Keypad 8", 1}, { "Numeric Keypad 9", 1},

			{ "Multiply", 0},
			{ "Add", 0},
			{ "Separator", 0},
			{ "Subtract", 0},
			{ "Decimal", 0},
			{ "Divide", 0},

			{ "F1", 1},	{ "F2", 1},	{ "F3", 1},	{ "F4", 1},	{ "F5", 1},
			{ "F6", 1},	{ "F7", 1},	{ "F8", 1},	{ "F9", 1},	{ "F10", 1},
			{ "F11", 1}, { "F12", 1}, { "F13", 1}, { "F14", 1}, { "F15", 1},
			{ "F16", 1}, { "F17", 1}, { "F18", 1}, { "F19", 1}, { "F20", 1},
			{ "F21", 1}, { "F22", 1}, { "F23", 1}, { "F24", 1},

			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},

			{ "Num Lock", 1},
			{ "Scroll Lock", 1},

			{ "= key on numpad", 0},
			{ "Unregister word", 0},
			{ "Register word", 0},
			{ "Left OYAYUBI", 0},
			{ "Right OYAYUBI", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},
			{ "Unassigned", 0},

			{ "Left SHIFT key", 1},	{ "Right SHIFT key", 1},
			{ "Left CONTROL key", 1}, { "Right CONTROL key", 1},
			{ "Left ALT key", 1}, { "Right ALT key", 1},

			{ "Browser Back key", 0}, { "Browser Forward key", 0},
			{ "Browser Refresh key", 0}, { "Browser Stop key", 0},
			{ "Browser Search key", 0},	{ "Browser Favorites key", 0},
			{ "Browser Start and Home key", 0},

			{ "Volume Mute key", 0}, { "Volume Down key", 0}, { "Volume Up key", 0},

			{ "Next Track key", 0}, { "Previous Track key", 0},
			{ "Stop Media key", 0},	{ "Play/Pause Media key", 0},
			{ "Start Mail key", 0},	{ "Select Media key", 0},

			{ "Start Application 1 key", 0},
			{ "Start Application 2 key", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ ";: key US", 0},
			{ "+ key US", 0},
			{ ", key US", 0},
			{ "- key US", 0},
			{ ". key US", 0},
			{ "/? key US", 0},
			{ "~ key US", 0},
			{ "Reserved", 0},
			{ "Reserved", 0},
			{ "VK_GAMEPAD_A", 0}, { "VK_GAMEPAD_B", 0},	{ "VK_GAMEPAD_X", 0}, { "VK_GAMEPAD_Y", 0},
			{ "VK_GAMEPAD_RIGHT_SHOULDER", 0}, { "VK_GAMEPAD_LEFT_SHOULDER", 0}, { "VK_GAMEPAD_LEFT_TRIGGER", 0},
			{ "VK_GAMEPAD_RIGHT_TRIGGER", 0}, { "VK_GAMEPAD_DPAD_UP", 0}, { "VK_GAMEPAD_DPAD_DOWN", 0},
			{ "VK_GAMEPAD_DPAD_LEFT", 0}, { "VK_GAMEPAD_DPAD_RIGHT", 0}, { "VK_GAMEPAD_MENU", 0},
			{ "VK_GAMEPAD_VIEW", 0}, { "VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON", 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON", 0},
			{ "VK_GAMEPAD_LEFT_THUMBSTICK_UP", 0}, { "VK_GAMEPAD_LEFT_THUMBSTICK_DOWN", 0}, { "VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT", 0},
			{ "VK_GAMEPAD_LEFT_THUMBSTICK_LEFT", 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_UP", 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN", 0},
			{ "VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT", 0}, { "VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT", 0},
			{ "[{ for US", 0},
			{ "\\| for US", 0},
			{ "]} for US", 0},
			{ "'\" for US", 0},
			{ "Undefined", 0},
			{ "Reserved", 0},
			{ "'AX' key on Japanese AX kbd", 0},
			{ "<> or \\| on RT 102-key kbd", 0},
			{ "Help key on ICO", 0},
			{ "00 key on ICO", 0},
			{ "VK_PROCESSKEY", 0},
			{ "VK_ICO_CLEAR", 0},
			{ "VK_PACKET", 0},
			{ "Unassigned", 0},
			{ "VK_OEM_RESET", 0}, { "VK_OEM_JUMP", 0}, { "VK_OEM_PA1", 0}, { "VK_OEM_PA2", 0}, { "VK_OEM_PA3", 0}, { "VK_OEM_WSCTRL", 0},
			{ "VK_OEM_CUSEL", 0}, { "VK_OEM_ATTN", 0}, { "VK_OEM_FINISH", 0}, { "VK_OEM_COPY", 0}, { "VK_OEM_AUTO", 0}, { "VK_OEM_ENLW", 0},
			{ "VK_OEM_BACKTAB", 0},
			{ "VK_ATTN", 0}, { "VK_CRSEL", 0}, { "VK_EXSEL", 0}, { "VK_EREOF", 0},
			{ "VK_PLAY", 0}, { "VK_ZOOM", 0}, { "VK_NONAME", 0}, { "VK_PA1", 0},
			{ "VK_OEM_CLEAR", 0},
			{ "Reserved", 0}
	};
};

extern Settings GlobalSettings;