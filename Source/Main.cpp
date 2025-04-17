#include "./WinForm/MainForm.h"
#include "./Input/BackgroundProcess.h"

using namespace System;
using namespace System::Windows::Forms;

void Main(array<String^>^ args)
{	
	BackgroundProcess Process;

	if (Process.RunThread())
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Macros::MainForm form;
		Application::Run(% form);

		Process.StopThread();
	}
}