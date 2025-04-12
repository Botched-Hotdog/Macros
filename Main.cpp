#include "./WinForm/MainForm.h"
#include "./Input/InputThread.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args)
{	
	InputThread BackgroundProcess;

	if (BackgroundProcess.RunThread())
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Macros::MainForm form;
		Application::Run(% form);

		BackgroundProcess.StopThread();
	}
}