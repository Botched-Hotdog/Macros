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
	Settings* SettingsReference;

	void ProcessKeys(const std::vector<KeyStroke>& Keys);
	void PlayKey(const KeyStroke Key);
public:
	InputThread(Settings* SettingRef);

	__inline bool IsThreadRunning() { return bShouldThreadRun; };
	__inline void SetThreadHandlerReference(Settings* NewReference) { SettingsReference = NewReference; };

	void RunThread();
	void StopThread();

	static void ThreadEntry(InputThread* This); // static function is required to use thread. std::thread(StaticFunction, this) 
	void ThreadBody();

};

