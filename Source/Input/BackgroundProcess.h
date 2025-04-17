#pragma once
#include <thread>
#include "./InputManager.h"


class BackgroundProcess
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
	BackgroundProcess() = default;

	__inline bool IsThreadRunning() const { return bShouldThreadRun; };

	bool RunThread();
	void StopThread();

	static void ThreadEntry(BackgroundProcess* This); // static function is required to use thread. std::thread(StaticFunction, this) 
	void ThreadBody();
};

