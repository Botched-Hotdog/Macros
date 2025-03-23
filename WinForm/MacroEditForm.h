#pragma once

namespace Macros {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MacroEditForm
	/// </summary>
	public ref class MacroEditForm : public System::Windows::Forms::Form
	{
	public:
		MacroEditForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MacroEditForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MacroEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 291);
			this->MaximumSize = System::Drawing::Size(1000, 600);
			this->MinimumSize = System::Drawing::Size(500, 330);
			this->Name = L"MacroEditForm";
			this->Text = L"Edit Macro";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
