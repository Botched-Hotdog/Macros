#pragma once
#include "Common.h"
#include "MacroEditForm.h"


namespace Macros {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ Add_Button;
	private: System::Windows::Forms::Button^ Remove_Button;
	private: System::Windows::Forms::ListView^ Macros_List;








	protected:

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
			this->Add_Button = (gcnew System::Windows::Forms::Button());
			this->Remove_Button = (gcnew System::Windows::Forms::Button());
			this->Macros_List = (gcnew System::Windows::Forms::ListView());
			this->SuspendLayout();
			// 
			// Add_Button
			// 
			this->Add_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Add_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add_Button->Location = System::Drawing::Point(353, 13);
			this->Add_Button->Name = L"Add_Button";
			this->Add_Button->Size = System::Drawing::Size(119, 30);
			this->Add_Button->TabIndex = 1;
			this->Add_Button->Text = L"Add / Edit";
			this->Add_Button->UseVisualStyleBackColor = true;
			this->Add_Button->Click += gcnew System::EventHandler(this, &MainForm::Add_Button_Click);
			// 
			// Remove_Button
			// 
			this->Remove_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Remove_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Remove_Button->Location = System::Drawing::Point(353, 53);
			this->Remove_Button->Name = L"Remove_Button";
			this->Remove_Button->Size = System::Drawing::Size(119, 30);
			this->Remove_Button->TabIndex = 2;
			this->Remove_Button->Text = L"Remove";
			this->Remove_Button->UseVisualStyleBackColor = true;
			this->Remove_Button->Click += gcnew System::EventHandler(this, &MainForm::Remove_Button_Click);
			// 
			// Macros_List
			// 
			this->Macros_List->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Macros_List->HideSelection = false;
			this->Macros_List->Location = System::Drawing::Point(12, 12);
			this->Macros_List->Name = L"Macros_List";
			this->Macros_List->Size = System::Drawing::Size(335, 267);
			this->Macros_List->TabIndex = 3;
			this->Macros_List->UseCompatibleStateImageBehavior = false;
			this->Macros_List->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::Macros_List_MouseDoubleClick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(484, 291);
			this->Controls->Add(this->Macros_List);
			this->Controls->Add(this->Remove_Button);
			this->Controls->Add(this->Add_Button);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MaximumSize = System::Drawing::Size(1000, 600);
			this->MinimumSize = System::Drawing::Size(500, 330);
			this->Name = L"MainForm";
			this->Text = L"Macros";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void Redraw()
	{
		Macros_List->Items->Clear();

		std::vector<MacroEntry> AvaliableMacros;
		if (GlobalSettings.GetSafeMacroList(AvaliableMacros))
		{
			for (const MacroEntry& ExistingMacro : AvaliableMacros)
			{
				ListViewItem^ lvi = gcnew ListViewItem(ConvertToManagedString(std::to_string(ExistingMacro.KeyCode)));
				lvi->Tag = ExistingMacro.KeyCode;
				lvi->SubItems->Add(ConvertToManagedString(ExistingMacro.KeyName));
				Macros_List->Items->Add(lvi);
			}
		}
	}

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		Macros_List->FullRowSelect = true;
		Macros_List->GridLines = true;

		Redraw();
	}


	private: System::Void Macros_List_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		if (Macros_List->SelectedItems->Count == 1)  // Ensure Only One Selection
		{
			auto item = Macros_List->SelectedItems[0];

			MacroEditForm^ EditWindow = gcnew MacroEditForm;
			EditWindow->SelectedHotKey = (BYTE) item->Tag;  // Let Window Know What we Are Editing

			GlobalSettings.SetEditingMacros(true);
			System::Windows::Forms::DialogResult Result = EditWindow->ShowDialog();  // Open Window
			if (Result == System::Windows::Forms::DialogResult::OK)
			{
				GlobalSettings.SetEditingMacros(false);
				Redraw();
			}
		}
	}

	private: System::Void Remove_Button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (Macros_List->SelectedItems->Count == 1)  // Ensure Only One Selection
		{
			auto item = Macros_List->SelectedItems[0];
			BYTE SelectedHotkey = (BYTE)item->Tag;

			if (SelectedHotkey != 0)
			{
				// MAKE SURE MACRO ISNT RUNNING -----------------------------------------------------------------------------------------------
				// if (GlobalSetting.IsMacroActve(SelectedHotkey))
				
				if (GlobalSettings.RemoveMacro(SelectedHotkey))
				{
					Redraw();
				}
				else // Macro Wasnt Found And Therfore Not Removed
				{
					// Do Error Popup or something
				}
			}
		}
		else  // Error. nothing to remove
		{
			// Do Error Popup or something
		}
	}

	private: System::Void Add_Button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		MacroEditForm^ EditWindow = gcnew MacroEditForm;
		
		if (Macros_List->SelectedItems->Count == 1)  // Something Is Selected. Edit it
		{
			auto item = Macros_List->SelectedItems[0];
			EditWindow->SelectedHotKey = (BYTE)item->Tag;  // Let Window Know What we Are Editing
		}

		GlobalSettings.SetEditingMacros(true);
		System::Windows::Forms::DialogResult Result = EditWindow->ShowDialog();  // Open Window
		if (Result == System::Windows::Forms::DialogResult::OK)
		{
			GlobalSettings.SetEditingMacros(false);
			Redraw();
		}
	}
};
}
