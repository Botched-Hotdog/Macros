#pragma once
#include "Common.h"
#include "KeystrokeEditForm.h"


namespace Macros {

	using namespace System;
	using namespace System::Collections::Generic;
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
	private: System::Windows::Forms::ListView^ KeyStrokes_List;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ Remove_Button;
	private: System::Windows::Forms::Button^ Add_Button;
	private: System::Windows::Forms::Button^ Ok_Button;
	private: System::Windows::Forms::ComboBox^ Hotkey_ComboBox;
	private: System::Windows::Forms::CheckBox^ Loops_CheckBox;


	private: System::Windows::Forms::Label^ Hotkey_Label;
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
			this->KeyStrokes_List = (gcnew System::Windows::Forms::ListView());
			this->Remove_Button = (gcnew System::Windows::Forms::Button());
			this->Add_Button = (gcnew System::Windows::Forms::Button());
			this->Ok_Button = (gcnew System::Windows::Forms::Button());
			this->Hotkey_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Loops_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->Hotkey_Label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// KeyStrokes_List
			// 
			this->KeyStrokes_List->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->KeyStrokes_List->HideSelection = false;
			this->KeyStrokes_List->Location = System::Drawing::Point(13, 49);
			this->KeyStrokes_List->Name = L"KeyStrokes_List";
			this->KeyStrokes_List->Size = System::Drawing::Size(334, 230);
			this->KeyStrokes_List->TabIndex = 0;
			this->KeyStrokes_List->UseCompatibleStateImageBehavior = false;
			this->KeyStrokes_List->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MacroEditForm::KeyStrokes_List_MouseDoubleClick);
			// 
			// Remove_Button
			// 
			this->Remove_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Remove_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Remove_Button->Location = System::Drawing::Point(353, 85);
			this->Remove_Button->Name = L"Remove_Button";
			this->Remove_Button->Size = System::Drawing::Size(119, 30);
			this->Remove_Button->TabIndex = 3;
			this->Remove_Button->Text = L"Remove";
			this->Remove_Button->UseVisualStyleBackColor = true;
			this->Remove_Button->Click += gcnew System::EventHandler(this, &MacroEditForm::Remove_Button_Click);
			// 
			// Add_Button
			// 
			this->Add_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Add_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Add_Button->Location = System::Drawing::Point(353, 49);
			this->Add_Button->Name = L"Add_Button";
			this->Add_Button->Size = System::Drawing::Size(119, 30);
			this->Add_Button->TabIndex = 4;
			this->Add_Button->Text = L"Add / Edit";
			this->Add_Button->UseVisualStyleBackColor = true;
			this->Add_Button->Click += gcnew System::EventHandler(this, &MacroEditForm::Add_Button_Click);
			// 
			// Ok_Button
			// 
			this->Ok_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Ok_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ok_Button->Location = System::Drawing::Point(353, 249);
			this->Ok_Button->Name = L"Ok_Button";
			this->Ok_Button->Size = System::Drawing::Size(119, 30);
			this->Ok_Button->TabIndex = 5;
			this->Ok_Button->Text = L"OK";
			this->Ok_Button->UseVisualStyleBackColor = true;
			this->Ok_Button->Click += gcnew System::EventHandler(this, &MacroEditForm::Ok_Button_Click);
			// 
			// Hotkey_ComboBox
			// 
			this->Hotkey_ComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Hotkey_ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hotkey_ComboBox->FormattingEnabled = true;
			this->Hotkey_ComboBox->Location = System::Drawing::Point(88, 8);
			this->Hotkey_ComboBox->Name = L"Hotkey_ComboBox";
			this->Hotkey_ComboBox->Size = System::Drawing::Size(259, 34);
			this->Hotkey_ComboBox->TabIndex = 6;
			this->Hotkey_ComboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &MacroEditForm::Hotkey_ComboBox_SelectionChangeCommitted);
			// 
			// Loops_CheckBox
			// 
			this->Loops_CheckBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Loops_CheckBox->AutoSize = true;
			this->Loops_CheckBox->CheckAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->Loops_CheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Loops_CheckBox->Location = System::Drawing::Point(353, 12);
			this->Loops_CheckBox->Name = L"Loops_CheckBox";
			this->Loops_CheckBox->Size = System::Drawing::Size(61, 20);
			this->Loops_CheckBox->TabIndex = 7;
			this->Loops_CheckBox->Text = L"Loop";
			this->Loops_CheckBox->UseVisualStyleBackColor = true;
			// 
			// Hotkey_Label
			// 
			this->Hotkey_Label->AutoSize = true;
			this->Hotkey_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hotkey_Label->Location = System::Drawing::Point(12, 17);
			this->Hotkey_Label->Name = L"Hotkey_Label";
			this->Hotkey_Label->Size = System::Drawing::Size(70, 20);
			this->Hotkey_Label->TabIndex = 8;
			this->Hotkey_Label->Text = L"Hotkey:";
			// 
			// MacroEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 291);
			this->Controls->Add(this->Hotkey_Label);
			this->Controls->Add(this->Loops_CheckBox);
			this->Controls->Add(this->Hotkey_ComboBox);
			this->Controls->Add(this->Ok_Button);
			this->Controls->Add(this->Add_Button);
			this->Controls->Add(this->Remove_Button);
			this->Controls->Add(this->KeyStrokes_List);
			this->MaximumSize = System::Drawing::Size(1000, 600);
			this->MinimumSize = System::Drawing::Size(500, 330);
			this->Name = L"MacroEditForm";
			this->Text = L"Edit Macro";
			this->Load += gcnew System::EventHandler(this, &MacroEditForm::MacroEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: BYTE SelectedHotKey;
	private: List<KeyItem^>^ TempKeystrokes;

	private: void Redraw()
	{
		KeyStrokes_List->Items->Clear();
		
		for (int i = 0; i < TempKeystrokes->Count; i++)
		{
			KeyItem^ Keystroke = TempKeystrokes[i];

			ListViewItem^ lvi = gcnew ListViewItem(Keystroke->ToString());
			lvi->Tag = i;
			lvi->SubItems->Add(ConvertToManagedString(std::to_string(Keystroke->MSDelay)));
			KeyStrokes_List->Items->Add(lvi);
		}
	}

	private: void LoadKeystrokesFromSettings()
	{
		std::vector<KeystrokeEntry> SafeKeystrokesCopy;
		if (GlobalSettings.GetSafeKeystrokeList(SelectedHotKey, SafeKeystrokesCopy))
		{
			for (const KeystrokeEntry& Entry : SafeKeystrokesCopy)
			{
				KeyItem^ NewItem = gcnew KeyItem;
				
				NewItem->KeyCode = Entry.KeyCode;
				NewItem->SpeicalKeyCode = Entry.SpecialKeyCode;

				NewItem->KeyName = ConvertToManagedString(Entry.KeyName);
				NewItem->SpecialKeyName = ConvertToManagedString(Entry.SpecialKeyName);

				TempKeystrokes->Add(NewItem);
			}
		}
	}

	private: System::Void MacroEditForm_Load(System::Object^ sender, System::EventArgs^ e) 
	{
		KeyStrokes_List->FullRowSelect = true;
		KeyStrokes_List->GridLines = true;

		TempKeystrokes = gcnew List<KeyItem^>();
		if (SelectedHotKey != 0) LoadKeystrokesFromSettings();

		Redraw();
	}


	private: System::Void Add_Button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		KeystrokeEditForm^ EditWindow = gcnew KeystrokeEditForm;

		if (KeyStrokes_List->SelectedItems->Count == 1)  // Something Is Selected. Edit it
		{
			auto item = KeyStrokes_List->SelectedItems[0];
			//EditWindow->SelectedHotKey = (BYTE)item->Tag;  // Let Window Know What we Are Editing
		}

		System::Windows::Forms::DialogResult Result = EditWindow->ShowDialog();  // Open Window
		if (Result == System::Windows::Forms::DialogResult::OK)
		{
			Redraw();
		}
	}
	private: System::Void Remove_Button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (KeyStrokes_List->SelectedItems->Count == 1)  // Ensure Only One Selection
		{
			auto item = KeyStrokes_List->SelectedItems[0];
			BYTE SelectedIndex = (BYTE)item->Tag;

			TempKeystrokes->RemoveAt(SelectedIndex);
			Redraw();
		}
		else  // Error. nothing to remove
		{
			// Do Error Popup or something
		}
	}

	private: System::Void Ok_Button_Click(System::Object^ sender, System::EventArgs^ e) 
	{	
		bool Conds = true; // Check for valid inputs
		
		if (Conds)
		{
			Macro NewMacro;
			NewMacro.Loops = Loops_CheckBox->Checked;
			NewMacro.HotKey = SelectedHotKey;

			NewMacro.Actions.reserve(TempKeystrokes->Count);
			for each (KeyItem^ Keystroke in TempKeystrokes)
			{
				KeyStroke NewKey;
				NewKey.Key = static_cast<EKeys>(Keystroke->KeyCode);
				NewKey.SpecialKey = static_cast<EKeys>(Keystroke->SpeicalKeyCode);
				NewKey.MSDelay = Keystroke->MSDelay;

				NewMacro.Actions.push_back(NewKey);
			}
			

			if (GlobalSettings.AddMacro(NewMacro))
			{
				DialogResult = System::Windows::Forms::DialogResult::OK;
				Close();
			}
		}
		
		// Write to INI
	}
	

	private: System::Void Hotkey_ComboBox_SelectionChangeCommitted(System::Object^ sender, System::EventArgs^ e) 
	{

	}


	private: System::Void KeyStrokes_List_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		KeystrokeEditForm^ EditWindow = gcnew KeystrokeEditForm;

		if (KeyStrokes_List->SelectedItems->Count == 1)  // Something Is Selected. Edit it
		{
			auto item = KeyStrokes_List->SelectedItems[0];
			// EditWindow->SelectedHotKey = (BYTE)item->Tag;  // Let Window Know What we Are Editing
		}

		System::Windows::Forms::DialogResult Result = EditWindow->ShowDialog();  // Open Window
		if (Result == System::Windows::Forms::DialogResult::OK)
		{
			Redraw();
		}
	}
};
}
