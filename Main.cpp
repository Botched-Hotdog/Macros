#include "MainForm.h"
#include "InputManager.h"

using namespace System;
using namespace System::Windows::Forms;
void Main(array<String^>^ args)
{
	InputManager NewMangager;
	
	if (NewMangager.MakeSpecialInput(EKeys::Shift, EKeys::B, 3000))
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Macros::MainForm form;
		Application::Run(% form);
	}
}