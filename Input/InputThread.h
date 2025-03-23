#pragma once
#include <thread>
#include "InputManager.h"

class Settings;

class InputThread
{
protected:
	InputManager InputManager;
	std::thread Thread;

	bool bShouldThreadRun;

	BYTE OldKeyBoardState[256];
	BYTE CheckForHotkey();

	void ProceessMacro(const BYTE Hotkey);
	void PlayKey(const KeyStroke Key);


public:
	InputThread();

	__inline bool IsThreadRunning() { return bShouldThreadRun; };

	bool RunThread();
	void StopThread();

	static void ThreadEntry(InputThread* This); // static function is required to use thread. std::thread(StaticFunction, this) 
	void ThreadBody();
};

