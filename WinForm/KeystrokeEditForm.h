#pragma once

namespace Macros {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for KeystrokeEditForm
	/// </summary>
	public ref class KeystrokeEditForm : public System::Windows::Forms::Form
	{
	public:
		KeystrokeEditForm(void)
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
		~KeystrokeEditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Key_Label;
	private: System::Windows::Forms::Label^ SpecKey_Label;
	private: System::Windows::Forms::Label^ Delay_Label;
	protected:


	private: System::Windows::Forms::Button^ Ok_Button;
	private: System::Windows::Forms::ComboBox^ Key_ComboBox;
	private: System::Windows::Forms::ComboBox^ SpecKey_ComboBox;
	private: System::Windows::Forms::TextBox^ Delay_TextBox;




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
			this->Key_Label = (gcnew System::Windows::Forms::Label());
			this->SpecKey_Label = (gcnew System::Windows::Forms::Label());
			this->Delay_Label = (gcnew System::Windows::Forms::Label());
			this->Ok_Button = (gcnew System::Windows::Forms::Button());
			this->Key_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SpecKey_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Delay_TextBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Key_Label
			// 
			this->Key_Label->AutoSize = true;
			this->Key_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Key_Label->Location = System::Drawing::Point(12, 18);
			this->Key_Label->Name = L"Key_Label";
			this->Key_Label->Size = System::Drawing::Size(48, 20);
			this->Key_Label->TabIndex = 9;
			this->Key_Label->Text = L"Key: ";
			// 
			// SpecKey_Label
			// 
			this->SpecKey_Label->AutoSize = true;
			this->SpecKey_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SpecKey_Label->Location = System::Drawing::Point(12, 58);
			this->SpecKey_Label->Name = L"SpecKey_Label";
			this->SpecKey_Label->Size = System::Drawing::Size(112, 20);
			this->SpecKey_Label->TabIndex = 10;
			this->SpecKey_Label->Text = L"Special Key: ";
			// 
			// Delay_Label
			// 
			this->Delay_Label->AutoSize = true;
			this->Delay_Label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Delay_Label->Location = System::Drawing::Point(12, 92);
			this->Delay_Label->Name = L"Delay_Label";
			this->Delay_Label->Size = System::Drawing::Size(107, 20);
			this->Delay_Label->TabIndex = 11;
			this->Delay_Label->Text = L"Delay (MS): ";
			// 
			// Ok_Button
			// 
			this->Ok_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Ok_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Ok_Button->Location = System::Drawing::Point(12, 134);
			this->Ok_Button->Name = L"Ok_Button";
			this->Ok_Button->Size = System::Drawing::Size(460, 30);
			this->Ok_Button->TabIndex = 12;
			this->Ok_Button->Text = L"OK";
			this->Ok_Button->UseVisualStyleBackColor = true;
			// 
			// Key_ComboBox
			// 
			this->Key_ComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Key_ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Key_ComboBox->FormattingEnabled = true;
			this->Key_ComboBox->Location = System::Drawing::Point(66, 9);
			this->Key_ComboBox->Name = L"Key_ComboBox";
			this->Key_ComboBox->Size = System::Drawing::Size(406, 34);
			this->Key_ComboBox->TabIndex = 13;
			// 
			// SpecKey_ComboBox
			// 
			this->SpecKey_ComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->SpecKey_ComboBox->Font = (gcnew System::Drawing::Font(L"Verdana", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SpecKey_ComboBox->FormattingEnabled = true;
			this->SpecKey_ComboBox->Location = System::Drawing::Point(130, 49);
			this->SpecKey_ComboBox->Name = L"SpecKey_ComboBox";
			this->SpecKey_ComboBox->Size = System::Drawing::Size(342, 34);
			this->SpecKey_ComboBox->TabIndex = 14;
			// 
			// Delay_TextBox
			// 
			this->Delay_TextBox->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->Delay_TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Delay_TextBox->Location = System::Drawing::Point(125, 89);
			this->Delay_TextBox->Name = L"Delay_TextBox";
			this->Delay_TextBox->Size = System::Drawing::Size(347, 26);
			this->Delay_TextBox->TabIndex = 15;
			// 
			// KeystrokeEditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 176);
			this->Controls->Add(this->Delay_TextBox);
			this->Controls->Add(this->SpecKey_ComboBox);
			this->Controls->Add(this->Key_ComboBox);
			this->Controls->Add(this->Ok_Button);
			this->Controls->Add(this->Delay_Label);
			this->Controls->Add(this->SpecKey_Label);
			this->Controls->Add(this->Key_Label);
			this->MaximumSize = System::Drawing::Size(1000, 215);
			this->MinimumSize = System::Drawing::Size(500, 215);
			this->Name = L"KeystrokeEditForm";
			this->Text = L"Edit Keystroke";
			this->Load += gcnew System::EventHandler(this, &KeystrokeEditForm::KeystrokeEditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void KeystrokeEditForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
