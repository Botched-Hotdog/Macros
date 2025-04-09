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

struct KeyStroke
{
    EKeys SpecialKey;
    EKeys Key;
    DWORD MSDelay;

    KeyStroke() : SpecialKey(EKeys::Undefined),  Key(EKeys::Undefined), MSDelay(5) {}
};

struct Macro
{
    BYTE HotKey;
    
    bool Loops;
    std::vector<KeyStroke> Actions;
};

struct KeyLookup
{
    const char* Name;
    bool bIsValidKeystroke;
    bool bIsValidHotKey;
    bool bIsSpecialKey;
};
