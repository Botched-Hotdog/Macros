#pragma once
#include <thread>
#include "InputManager.h"

class InputThread
{
protected:
	InputManager InputManager;
	ActionList List;
	std::thread Thread;

	bool bShouldThreadRun;

public:
	void SetTaskList();
	void ClearTaskList();

	void RunThread();
	void StopThread();
	void ThreadBody();
};

