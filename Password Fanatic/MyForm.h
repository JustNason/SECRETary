#pragma once
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include "encrypter.h"
#include "filesystems.h"
#include "passwordgenerator.h"
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>

namespace PasswordGenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr;
	using namespace msclr::interop;

	char charactersLowercase[26] = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
	};

	char charactersUpercase[26] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	char charactersSpecial[31] = {
		'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '-', '+',
		'=', '{', '}', '[', ']', '\\', '|', ':', ';', '"', '<', '>', ',',
		'.', '?', '/', '`', '~'
	};

	char charactersNumbers[10] = {
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
	};

	std::string key;

	int keyLength = 10;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TrackBar^ characterSlider;
	private: System::Windows::Forms::Label^ characterLabel;




	private: System::Windows::Forms::CheckBox^ checkBoxCL;
	private: System::Windows::Forms::Label^ includeLabel;


	private: System::Windows::Forms::CheckBox^ checkBoxNum;

	private: System::Windows::Forms::CheckBox^ checkBoxSC;
	private: System::Windows::Forms::Button^ buttonSave;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ passwordLabel;





	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ directoryLabel;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ selectFolderButton;
	private: System::Windows::Forms::FolderBrowserDialog^ openPWDirectory;

	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ keyBox;
	private: System::Windows::Forms::OpenFileDialog^ openKeyDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveKeyDialog;











	protected:



	protected:






	protected:




























	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->characterSlider = (gcnew System::Windows::Forms::TrackBar());
			this->characterLabel = (gcnew System::Windows::Forms::Label());
			this->checkBoxCL = (gcnew System::Windows::Forms::CheckBox());
			this->includeLabel = (gcnew System::Windows::Forms::Label());
			this->checkBoxNum = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxSC = (gcnew System::Windows::Forms::CheckBox());
			this->buttonSave = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->selectFolderButton = (gcnew System::Windows::Forms::Button());
			this->directoryLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->keyBox = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openPWDirectory = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->openKeyDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveKeyDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->characterSlider))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(797, 60);
			this->panel1->TabIndex = 0;
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Dock = System::Windows::Forms::DockStyle::Right;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(735, 0);
			this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(62, 60);
			this->button3->TabIndex = 2;
			this->button3->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Dock = System::Windows::Forms::DockStyle::Left;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(250, 0);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button2->Size = System::Drawing::Size(250, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L" USB_01";
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Crimson;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Dock = System::Windows::Forms::DockStyle::Left;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button1->Size = System::Drawing::Size(250, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L" Create Password";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// characterSlider
			// 
			this->characterSlider->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->characterSlider->Cursor = System::Windows::Forms::Cursors::NoMoveHoriz;
			this->characterSlider->Location = System::Drawing::Point(104, 487);
			this->characterSlider->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->characterSlider->Maximum = 50;
			this->characterSlider->Minimum = 8;
			this->characterSlider->Name = L"characterSlider";
			this->characterSlider->Size = System::Drawing::Size(275, 56);
			this->characterSlider->TabIndex = 2;
			this->characterSlider->Value = 8;
			this->characterSlider->ValueChanged += gcnew System::EventHandler(this, &MyForm::characterSlider_ValueChanged);
			// 
			// characterLabel
			// 
			this->characterLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->characterLabel->AutoSize = true;
			this->characterLabel->Location = System::Drawing::Point(26, 451);
			this->characterLabel->Name = L"characterLabel";
			this->characterLabel->Size = System::Drawing::Size(214, 21);
			this->characterLabel->TabIndex = 3;
			this->characterLabel->Text = L"Password Length: 0 Characters";
			// 
			// checkBoxCL
			// 
			this->checkBoxCL->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->checkBoxCL->AutoSize = true;
			this->checkBoxCL->Checked = true;
			this->checkBoxCL->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxCL->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBoxCL->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBoxCL->Location = System::Drawing::Point(36, 415);
			this->checkBoxCL->Name = L"checkBoxCL";
			this->checkBoxCL->Size = System::Drawing::Size(115, 22);
			this->checkBoxCL->TabIndex = 5;
			this->checkBoxCL->Text = L"Capital Letters";
			this->checkBoxCL->UseVisualStyleBackColor = true;
			this->checkBoxCL->Click += gcnew System::EventHandler(this, &MyForm::checkBoxCL_Click);
			// 
			// includeLabel
			// 
			this->includeLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->includeLabel->AutoSize = true;
			this->includeLabel->Location = System::Drawing::Point(27, 379);
			this->includeLabel->Name = L"includeLabel";
			this->includeLabel->Size = System::Drawing::Size(60, 21);
			this->includeLabel->TabIndex = 6;
			this->includeLabel->Text = L"Include:";
			// 
			// checkBoxNum
			// 
			this->checkBoxNum->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->checkBoxNum->AutoSize = true;
			this->checkBoxNum->Checked = true;
			this->checkBoxNum->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxNum->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBoxNum->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBoxNum->Location = System::Drawing::Point(296, 415);
			this->checkBoxNum->Name = L"checkBoxNum";
			this->checkBoxNum->Size = System::Drawing::Size(83, 22);
			this->checkBoxNum->TabIndex = 7;
			this->checkBoxNum->Text = L"Numbers";
			this->checkBoxNum->UseVisualStyleBackColor = true;
			this->checkBoxNum->Click += gcnew System::EventHandler(this, &MyForm::checkBoxNum_Click);
			// 
			// checkBoxSC
			// 
			this->checkBoxSC->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->checkBoxSC->AutoSize = true;
			this->checkBoxSC->Checked = true;
			this->checkBoxSC->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxSC->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkBoxSC->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBoxSC->Location = System::Drawing::Point(153, 415);
			this->checkBoxSC->Name = L"checkBoxSC";
			this->checkBoxSC->Size = System::Drawing::Size(142, 22);
			this->checkBoxSC->TabIndex = 8;
			this->checkBoxSC->Text = L"Special Characters";
			this->checkBoxSC->UseVisualStyleBackColor = true;
			this->checkBoxSC->Click += gcnew System::EventHandler(this, &MyForm::checkBoxSC_Click);
			// 
			// buttonSave
			// 
			this->buttonSave->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->buttonSave->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonSave->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->buttonSave->Location = System::Drawing::Point(30, 542);
			this->buttonSave->Margin = System::Windows::Forms::Padding(3, 3, 3, 30);
			this->buttonSave->Name = L"buttonSave";
			this->buttonSave->Size = System::Drawing::Size(741, 50);
			this->buttonSave->TabIndex = 9;
			this->buttonSave->Text = L"Save to USB";
			this->buttonSave->UseVisualStyleBackColor = true;
			this->buttonSave->Click += gcnew System::EventHandler(this, &MyForm::buttonSave_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(407, 487);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 21);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Password:";
			// 
			// passwordLabel
			// 
			this->passwordLabel->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->passwordLabel->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->passwordLabel->Location = System::Drawing::Point(406, 494);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(363, 39);
			this->passwordLabel->TabIndex = 11;
			this->passwordLabel->Text = L"Generate a Password...";
			this->passwordLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->passwordLabel->Click += gcnew System::EventHandler(this, &MyForm::passwordLabel_Click);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(407, 455);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(147, 21);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Username (optional):";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->textBox1->Location = System::Drawing::Point(575, 451);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(193, 28);
			this->textBox1->TabIndex = 15;
			this->textBox1->Text = L"John Smith";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->textBox1->Enter += gcnew System::EventHandler(this, &MyForm::textBox1_Enter);
			this->textBox1->Leave += gcnew System::EventHandler(this, &MyForm::textBox1_Leave);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(520, 380);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 21);
			this->label5->TabIndex = 16;
			this->label5->Text = L"Name the Password";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->textBox2->Location = System::Drawing::Point(408, 408);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(360, 28);
			this->textBox2->TabIndex = 17;
			this->textBox2->Text = L"https://www.abc.xyz/";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->Enter += gcnew System::EventHandler(this, &MyForm::textBox2_Enter);
			this->textBox2->Leave += gcnew System::EventHandler(this, &MyForm::textBox2_Leave);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(30, 489);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(68, 28);
			this->numericUpDown1->TabIndex = 18;
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown1_ValueChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->selectFolderButton);
			this->groupBox1->Controls->Add(this->directoryLabel);
			this->groupBox1->Controls->Add(this->groupBox2);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Location = System::Drawing::Point(30, 83);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(738, 277);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Saved Passwords:";
			// 
			// listBox1
			// 
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->BackColor = System::Drawing::Color::White;
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 21;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Username: EW@#", L"Password: ESWSEWR", L"", L"Username: EW@#",
					L"Password: ESWSEWR", L"", L"Username: EW@#", L"Password: ESWSEWR"
			});
			this->listBox1->Location = System::Drawing::Point(45, 56);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(230, 147);
			this->listBox1->TabIndex = 22;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(317, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(174, 21);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Saving To/Reading From:";
			// 
			// selectFolderButton
			// 
			this->selectFolderButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->selectFolderButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->selectFolderButton->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 7.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->selectFolderButton->Location = System::Drawing::Point(573, 34);
			this->selectFolderButton->Name = L"selectFolderButton";
			this->selectFolderButton->Size = System::Drawing::Size(141, 30);
			this->selectFolderButton->TabIndex = 20;
			this->selectFolderButton->Text = L"Select Folder";
			this->selectFolderButton->UseVisualStyleBackColor = true;
			this->selectFolderButton->Click += gcnew System::EventHandler(this, &MyForm::selectFolderButton_Click);
			// 
			// directoryLabel
			// 
			this->directoryLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->directoryLabel->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->directoryLabel->Location = System::Drawing::Point(397, 67);
			this->directoryLabel->Name = L"directoryLabel";
			this->directoryLabel->Size = System::Drawing::Size(317, 21);
			this->directoryLabel->TabIndex = 0;
			this->directoryLabel->Text = L"Please select a folder.";
			this->directoryLabel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// groupBox2
			// 
			this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(21, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox2->Size = System::Drawing::Size(271, 230);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			// 
			// groupBox3
			// 
			this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox3->Controls->Add(this->keyBox);
			this->groupBox3->Controls->Add(this->button6);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Location = System::Drawing::Point(319, 92);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(395, 165);
			this->groupBox3->TabIndex = 25;
			this->groupBox3->TabStop = false;
			// 
			// keyBox
			// 
			this->keyBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->keyBox->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->keyBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->keyBox->Location = System::Drawing::Point(62, 34);
			this->keyBox->Name = L"keyBox";
			this->keyBox->Size = System::Drawing::Size(314, 28);
			this->keyBox->TabIndex = 20;
			this->keyBox->Text = L"Open or Generate Key";
			this->keyBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->keyBox->TextChanged += gcnew System::EventHandler(this, &MyForm::keyBox_TextChanged);
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(20, 109);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(357, 30);
			this->button6->TabIndex = 28;
			this->button6->Text = L"Generate Key";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(207, 73);
		 this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(169, 30);
			this->button5->TabIndex = 27;
			this->button5->Text = L"Save as .key";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(20, 73);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(181, 30);
			this->button4->TabIndex = 26;
			this->button4->Text = L"Open .key File";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 21);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Key:";
			// 
			// openKeyDialog
			// 
			this->openKeyDialog->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(797, 622);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->checkBoxNum);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->buttonSave);
			this->Controls->Add(this->checkBoxSC);
			this->Controls->Add(this->includeLabel);
			this->Controls->Add(this->checkBoxCL);
			this->Controls->Add(this->characterLabel);
			this->Controls->Add(this->characterSlider);
			this->Controls->Add(this->panel1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Bahnschrift SemiCondensed", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HelpButton = true;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"Password Pro";
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Activated);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->characterSlider))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

		//}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		button2->BackColor = System::Drawing::Color::Crimson;
		button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)));
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->BackColor = System::Drawing::Color::Crimson;
		button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
			static_cast<System::Int32>(static_cast<System::Byte>(25)));
	}

	private: System::Void textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == L"") {
			textBox2->Text = L"https://www.abc.xyz/";
		}
	}
	private: System::Void textBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == L"John Smith") {
			textBox1->Text = L"";
		}
	}
	private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == L"") {
			textBox1->Text = L"John Smith";
		}
	}
	private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == L"https://www.abc.xyz/") {
			textBox2->Text = L"";
		}
	}

	private: System::Void characterSlider_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		characterLabel->Text = L"Password Length: " + characterSlider->Value + L" Characters";
		numericUpDown1->Value = characterSlider->Value;
		generatePassword();
	}
		   void generatePassword() {

			   std::string password = "";

			   char characters[93] = {
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
				   ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
			   };

			   int characterArrayLength = 0;

			   for (int i = 0; i < 26; i++) {
				   characters[i] = charactersLowercase[i];
			   }
			   characterArrayLength += 26;

			   if (checkBoxCL->Checked) {
				   for (int i = 1; i < 26; i++) {
					   characters[i + characterArrayLength] = charactersUpercase[i];
				   }
				   characterArrayLength += 26;
			   }
			   if (checkBoxSC->Checked) {
				   for (int i = 0; i < 31; i++) {
					   characters[i + characterArrayLength] = charactersSpecial[i];
				   }
				   characterArrayLength += 31;
			   }
			   if (checkBoxNum->Checked) {
				   for (int i = 0; i < 10; i++) {
					   characters[i + characterArrayLength] = charactersNumbers[i];
				   }
				   characterArrayLength += 10;
			   }

			   //label1->Text = System::Convert::ToString(characterArrayLength);


			   for (int i = 0; i < characterSlider->Value; i++) {
				   std::random_device rd;
				   std::mt19937 gen(rd());
				   std::uniform_int_distribution<> distrib(0, characterArrayLength - 1);

				   int randomValue = distrib(gen);

				   password += characters[randomValue];
			   }

			   passwordLabel->Text = gcnew String(password.c_str());

		   }
	private: System::Void MyForm_Activated(System::Object^ sender, System::EventArgs^ e) {
		generatePassword();
	}
	private: System::Void numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		characterSlider->Value = static_cast<int>(numericUpDown1->Value);
	}
	private: System::Void checkBoxCL_Click(System::Object^ sender, System::EventArgs^ e) {
		generatePassword();
	}
	private: System::Void checkBoxSC_Click(System::Object^ sender, System::EventArgs^ e) {
		generatePassword();
	}
	private: System::Void checkBoxNum_Click(System::Object^ sender, System::EventArgs^ e) {
		generatePassword();
	}
	private: System::Void passwordLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void selectFolderButton_Click(System::Object^ sender, System::EventArgs^ e) {
		openPWDirectory->ShowDialog();
		directoryLabel->Text = openPWDirectory->SelectedPath;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		key = generateKey(keyLength);
		keyBox->Text = gcnew String(key.c_str());
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		openKeyDialog->Filter = "KEY File(*.key)|*.key|All files (*.*)|*.*";
		System::Windows::Forms::DialogResult result = openKeyDialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK) {
			// convert managed String^ filename to std::string and read the file
			std::string filename = msclr::interop::marshal_as<std::string>(openKeyDialog->FileName);
			key = readFile(filename);
			keyBox->Text = gcnew String(key.c_str());
		}
	}
	private: System::Void keyBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		saveKeyDialog->Filter = "KEY File(*.key)|*.key|All files (*.*)|*.*";
		saveKeyDialog->FileName = "my.key";
		System::Windows::Forms::DialogResult result = saveKeyDialog->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::OK) {
			std::string filename = msclr::interop::marshal_as<std::string>(saveKeyDialog->FileName);

			if (key.empty()) {
				System::Windows::Forms::MessageBox::Show("No key generated to save.", "Save Key", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
				return;
			}

			std::ofstream outputFile(filename, std::ios::binary);
			if (outputFile.is_open()) {
				outputFile << key;
				outputFile.close();
				System::Windows::Forms::MessageBox::Show("Key successfully saved to:\n" + saveKeyDialog->FileName, "Save Key", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
			}
			else {
				System::Windows::Forms::MessageBox::Show("Unable to open file for writing:\n" + saveKeyDialog->FileName, "Save Key Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			}
		}
	}
	};
}
