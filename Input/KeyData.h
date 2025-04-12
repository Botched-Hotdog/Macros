#pragma once
#include <windows.h>
#include <vector>

struct KeyStroke
{
    BYTE SpecialKey;
    BYTE Key;
    DWORD MSDelay;

    KeyStroke() : SpecialKey(0),  Key(0), MSDelay(5) {}
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
