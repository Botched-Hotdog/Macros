#pragma once

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
	private: System::Windows::Forms::ListBox^ Actions_List;
	protected:
	private: System::Windows::Forms::Button^ Add_Button;
	private: System::Windows::Forms::Button^ Remove_Button;
	private: System::Windows::Forms::CheckBox^ Loop_CheckBox;
	private: System::Windows::Forms::Button^ Start_Button;
	private: System::Windows::Forms::Button^ Stop_Button;


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
			this->Actions_List = (gcnew System::Windows::Forms::ListBox());
			this->Add_Button = (gcnew System::Windows::Forms::Button());
			this->Remove_Button = (gcnew System::Windows::Forms::Button());
			this->Loop_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->Start_Button = (gcnew System::Windows::Forms::Button());
			this->Stop_Button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Actions_List
			// 
			this->Actions_List->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Actions_List->FormattingEnabled = true;
			this->Actions_List->Location = System::Drawing::Point(12, 12);
			this->Actions_List->Name = L"Actions_List";
			this->Actions_List->Size = System::Drawing::Size(334, 199);
			this->Actions_List->TabIndex = 0;
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
			this->Add_Button->Text = L"Add";
			this->Add_Button->UseVisualStyleBackColor = true;
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
			// 
			// Loop_CheckBox
			// 
			this->Loop_CheckBox->AutoSize = true;
			this->Loop_CheckBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Loop_CheckBox->Location = System::Drawing::Point(12, 217);
			this->Loop_CheckBox->Name = L"Loop_CheckBox";
			this->Loop_CheckBox->Size = System::Drawing::Size(61, 20);
			this->Loop_CheckBox->TabIndex = 3;
			this->Loop_CheckBox->Text = L"Loop";
			this->Loop_CheckBox->UseVisualStyleBackColor = true;
			// 
			// Start_Button
			// 
			this->Start_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Start_Button->Location = System::Drawing::Point(12, 249);
			this->Start_Button->Name = L"Start_Button";
			this->Start_Button->Size = System::Drawing::Size(200, 30);
			this->Start_Button->TabIndex = 4;
			this->Start_Button->Text = L"Start";
			this->Start_Button->UseVisualStyleBackColor = true;
			// 
			// Stop_Button
			// 
			this->Stop_Button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Stop_Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stop_Button->Location = System::Drawing::Point(272, 249);
			this->Stop_Button->Name = L"Stop_Button";
			this->Stop_Button->Size = System::Drawing::Size(200, 30);
			this->Stop_Button->TabIndex = 5;
			this->Stop_Button->Text = L"Stop";
			this->Stop_Button->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(484, 291);
			this->Controls->Add(this->Stop_Button);
			this->Controls->Add(this->Start_Button);
			this->Controls->Add(this->Loop_CheckBox);
			this->Controls->Add(this->Remove_Button);
			this->Controls->Add(this->Add_Button);
			this->Controls->Add(this->Actions_List);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->MaximumSize = System::Drawing::Size(1000, 600);
			this->MinimumSize = System::Drawing::Size(500, 330);
			this->Name = L"MainForm";
			this->Text = L"Macros";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
