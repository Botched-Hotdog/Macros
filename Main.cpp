#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Macros::MainForm form;
	Application::Run(% form);
}