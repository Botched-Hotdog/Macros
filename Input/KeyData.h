#pragma once
#include <windows.h>
#include <vector>  // TODO: remove when ActionList is relocated

// Copied From https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
enum class EKeys : BYTE
{
    // Mouse Buttons
    LeftMouse = 0x01,       // VK_LBUTTON
    RightMouse = 0x02,      // VK_RBUTTON
    MiddleMouse = 0x04,     // VK_MBUTTON
    XMouse1 = 0x05,        // VK_XBUTTON1 (Mouse Button 3)
    XMouse2 = 0x06,        // VK_XBUTTON2 (Mouse Button 4)

    // Keyboard Keys
    Backspace = 0x08,       // VK_BACK
    Tab = 0x09,            // VK_TAB
    Enter = 0x0D,          // VK_RETURN
    Shift = 0x10,          // VK_SHIFT
    Control = 0x11,        // VK_CONTROL
    Alt = 0x12,           // VK_MENU (Alt Key)
    Pause = 0x13,         // VK_PAUSE
    CapsLock = 0x14,      // VK_CAPITAL

    // IME Keys
    Kana = 0x15,          // VK_KANA / VK_HANGUL
    Junja = 0x17,         // VK_JUNJA
    Final = 0x18,         // VK_FINAL
    Hanja = 0x19,         // VK_HANJA / VK_KANJI

    // Escape Key
    Escape = 0x1B,        // VK_ESCAPE

    // Conversion Keys
    Convert = 0x1C,       // VK_CONVERT
    NonConvert = 0x1D,    // VK_NONCONVERT
    Accept = 0x1E,        // VK_ACCEPT
    ModeChange = 0x1F,    // VK_MODECHANGE

    // Space and Navigation Keys
    Space = 0x20,         // VK_SPACE
    PageUp = 0x21,        // VK_PRIOR
    PageDown = 0x22,      // VK_NEXT
    End = 0x23,          // VK_END
    Home = 0x24,         // VK_HOME
    LeftArrow = 0x25,    // VK_LEFT
    UpArrow = 0x26,      // VK_UP
    RightArrow = 0x27,   // VK_RIGHT
    DownArrow = 0x28,    // VK_DOWN
    Select = 0x29,       // VK_SELECT
    Print = 0x2A,        // VK_PRINT
    Execute = 0x2B,      // VK_EXECUTE
    PrintScreen = 0x2C,  // VK_SNAPSHOT
    Insert = 0x2D,       // VK_INSERT
    Delete = 0x2E,       // VK_DELETE
    Help = 0x2F,         // VK_HELP

    // Number Keys
    Key0 = 0x30, Key1 = 0x31, Key2 = 0x32, Key3 = 0x33,
    Key4 = 0x34, Key5 = 0x35, Key6 = 0x36, Key7 = 0x37,
    Key8 = 0x38, Key9 = 0x39,

    // Letter Keys (A-Z)
    A = 0x41, B = 0x42, C = 0x43, D = 0x44, E = 0x45, F = 0x46,
    G = 0x47, H = 0x48, I = 0x49, J = 0x4A, K = 0x4B, L = 0x4C,
    M = 0x4D, N = 0x4E, O = 0x4F, P = 0x50, Q = 0x51, R = 0x52,
    S = 0x53, T = 0x54, U = 0x55, V = 0x56, W = 0x57, X = 0x58,
    Y = 0x59, Z = 0x5A,

    // Modifier Keys
    LeftWindows = 0x5B,    // VK_LWIN
    RightWindows = 0x5C,   // VK_RWIN
    Applications = 0x5D,   // VK_APPS

    // Sleep Key
    Sleep = 0x5F,         // VK_SLEEP

    // Numpad Keys
    Numpad0 = 0x60, Numpad1 = 0x61, Numpad2 = 0x62, Numpad3 = 0x63,
    Numpad4 = 0x64, Numpad5 = 0x65, Numpad6 = 0x66, Numpad7 = 0x67,
    Numpad8 = 0x68, Numpad9 = 0x69,

    Multiply = 0x6A,     // VK_MULTIPLY
    Add = 0x6B,         // VK_ADD
    Separator = 0x6C,   // VK_SEPARATOR
    Subtract = 0x6D,    // VK_SUBTRACT
    Decimal = 0x6E,     // VK_DECIMAL
    Divide = 0x6F,      // VK_DIVIDE

    // Function Keys
    F1 = 0x70, F2 = 0x71, F3 = 0x72, F4 = 0x73, F5 = 0x74,
    F6 = 0x75, F7 = 0x76, F8 = 0x77, F9 = 0x78, F10 = 0x79,
    F11 = 0x7A, F12 = 0x7B, F13 = 0x7C, F14 = 0x7D, F15 = 0x7E,
    F16 = 0x7F, F17 = 0x80, F18 = 0x81, F19 = 0x82, F20 = 0x83,
    F21 = 0x84, F22 = 0x85, F23 = 0x86, F24 = 0x87,

    // Lock Keys
    NumLock = 0x90,     // VK_NUMLOCK
    ScrollLock = 0x91,  // VK_SCROLL

    // Special Keys
    LeftShift = 0xA0, RightShift = 0xA1,
    LeftControl = 0xA2, RightControl = 0xA3,
    LeftAlt = 0xA4, RightAlt = 0xA5,

    BrowserBack = 0xA6, BrowserForward = 0xA7,
    BrowserRefresh = 0xA8, BrowserStop = 0xA9,
    BrowserSearch = 0xAA, BrowserFavorites = 0xAB,
    BrowserHome = 0xAC,

    VolumeMute = 0xAD, VolumeDown = 0xAE, VolumeUp = 0xAF,

    MediaNextTrack = 0xB0, MediaPreviousTrack = 0xB1,
    MediaStop = 0xB2, MediaPlayPause = 0xB3,

    LaunchMail = 0xB4, LaunchMediaSelect = 0xB5,
    LaunchApp1 = 0xB6, LaunchApp2 = 0xB7,

    // Misc Keys
    OEM1 = 0xBA, OEMPlus = 0xBB, OEMComma = 0xBC,
    OEMMinus = 0xBD, OEMPeriod = 0xBE, OEM2 = 0xBF, OEM3 = 0xC0,
    OEM4 = 0xDB, OEM5 = 0xDC, OEM6 = 0xDD, OEM7 = 0xDE, OEM8 = 0xDF,

    // Reserved / Unknown Keys
    Undefined = 0x00
};

struct KeyLookup
{
    const char* Name;
    bool bIsValid; // Not all keys should be accessible
};
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


struct KeyStroke
{
    EKeys SpecialKey;
    EKeys Key;
    DWORD MSDelay;

    KeyStroke() : SpecialKey(EKeys::Undefined),  Key(EKeys::Undefined), MSDelay(5) {}
};


class ActionList
{
protected:
    bool Loops;
    std::vector<KeyStroke> Contents;
public:
    ActionList() = default;
    ActionList(std::vector<KeyStroke>* NewContents, bool bDoesLoop)
    { 
        Contents = *NewContents;
        Loops = bDoesLoop;
    };

	__inline std::vector<KeyStroke>* GetContentsReference() { return &Contents; };

    __inline void AddAction(KeyStroke NewAction, int Location) { Contents.insert(Contents.begin() + Location, NewAction); };
    __inline void AddAction(KeyStroke NewAction) { Contents.push_back(NewAction); };

    __inline void RemoveAction(int Location) { Contents.erase(Contents.begin() + Location); };
    __inline void ClearActions() { Contents.clear(); };
};
