#pragma once
#include <vector>

namespace DirectionOfArrival {

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
	
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numD;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numM;

	private: System::Windows::Forms::Button^ buttonCOMPARE;

	private: System::Windows::Forms::Button^ buttonESPRIT;

	private: System::Windows::Forms::Button^ buttonMUSIC;
	private: System::Windows::Forms::GroupBox^ groupBox3;


	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::NumericUpDown^ numSnapshots;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ numSNR;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::DataGridView^ dataGridView2;


	private:System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numSNR_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numSnapshots_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numM_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numD_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void RunDOAAnalysis(System::String^ methodType);
	private: System::Void buttonMUSIC_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonESPRIT_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCOMPARE_Click(System::Object^ sender, System::EventArgs^ e);
	private: void WriteDataToFile(std::vector<double> spectrum, std::vector<double> esprit_angles);
	private: void StartPythonProcess(System::String^ mode);
	
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->numSnapshots = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numSNR = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numD = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numM = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonMUSIC = (gcnew System::Windows::Forms::Button());
			this->buttonCOMPARE = (gcnew System::Windows::Forms::Button());
			this->buttonESPRIT = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSnapshots))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSNR))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numM))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DarkGray;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->groupBox4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(250, 644);
			this->panel1->TabIndex = 0;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numSnapshots);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Controls->Add(this->numSNR);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox4->Location = System::Drawing::Point(25, 244);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(200, 182);
			this->groupBox4->TabIndex = 3;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Налаштування середовища";
			// 
			// numSnapshots
			// 
			this->numSnapshots->BackColor = System::Drawing::Color::Gray;
			this->numSnapshots->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numSnapshots->Location = System::Drawing::Point(15, 135);
			this->numSnapshots->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			this->numSnapshots->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numSnapshots->Name = L"numSnapshots";
			this->numSnapshots->Size = System::Drawing::Size(120, 30);
			this->numSnapshots->TabIndex = 2;
			this->numSnapshots->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(11, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(98, 18);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Snapshots";
			// 
			// numSNR
			// 
			this->numSNR->BackColor = System::Drawing::Color::Gray;
			this->numSNR->Location = System::Drawing::Point(15, 71);
			this->numSNR->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 0 });
			this->numSNR->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, System::Int32::MinValue });
			this->numSNR->Name = L"numSNR";
			this->numSNR->Size = System::Drawing::Size(120, 30);
			this->numSNR->TabIndex = 0;
			this->numSNR->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(11, 50);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(168, 18);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Сигнал/шум (SNR)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(11, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(222, 27);
			this->label3->TabIndex = 3;
			this->label3->Text = L"1. Введіть дані";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Silver;
			this->button1->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(29, 569);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 53);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Очистити параметри";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->radioButton2);
			this->groupBox2->Controls->Add(this->radioButton1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(25, 432);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 113);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Джерела сигналів";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(15, 80);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(123, 22);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Випадкові";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &MainForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(15, 47);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(173, 22);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Ручне введення";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numD);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->numM);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(25, 56);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 173);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Парамери решітки";
			// 
			// numD
			// 
			this->numD->BackColor = System::Drawing::Color::Gray;
			this->numD->DecimalPlaces = 2;
			this->numD->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numD->Location = System::Drawing::Point(15, 134);
			this->numD->Name = L"numD";
			this->numD->Size = System::Drawing::Size(120, 30);
			this->numD->TabIndex = 2;
			this->numD->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(11, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 18);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Відстань (d)";
			// 
			// numM
			// 
			this->numM->BackColor = System::Drawing::Color::Gray;
			this->numM->Location = System::Drawing::Point(15, 71);
			this->numM->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->numM->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numM->Name = L"numM";
			this->numM->Size = System::Drawing::Size(120, 30);
			this->numM->TabIndex = 0;
			this->numM->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
			this->numM->ValueChanged += gcnew System::EventHandler(this, &MainForm::numM_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(11, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(158, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"К-сть антен (М)";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::DarkGray;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Controls->Add(this->groupBox3);
			this->panel2->Controls->Add(this->buttonMUSIC);
			this->panel2->Controls->Add(this->buttonCOMPARE);
			this->panel2->Controls->Add(this->buttonESPRIT);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel2->Location = System::Drawing::Point(250, 344);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(928, 300);
			this->panel2->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(17, 10);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(238, 22);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Кореляційна матриця";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(340, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(544, 27);
			this->label4->TabIndex = 4;
			this->label4->Text = L"2. Оберіть метод та оцініть результати";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(21, 47);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(284, 219);
			this->dataGridView1->TabIndex = 4;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dataGridView2);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(494, 47);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(407, 225);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Результати оцінки кутів";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(6, 41);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 62;
			this->dataGridView2->RowTemplate->Height = 28;
			this->dataGridView2->Size = System::Drawing::Size(395, 178);
			this->dataGridView2->TabIndex = 0;
			// 
			// buttonMUSIC
			// 
			this->buttonMUSIC->BackColor = System::Drawing::Color::SteelBlue;
			this->buttonMUSIC->Font = (gcnew System::Drawing::Font(L"Courier New", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonMUSIC->Location = System::Drawing::Point(342, 47);
			this->buttonMUSIC->Name = L"buttonMUSIC";
			this->buttonMUSIC->Size = System::Drawing::Size(143, 51);
			this->buttonMUSIC->TabIndex = 0;
			this->buttonMUSIC->Text = L"MUSIC";
			this->buttonMUSIC->UseVisualStyleBackColor = false;
			this->buttonMUSIC->Click += gcnew System::EventHandler(this, &MainForm::buttonMUSIC_Click);
			// 
			// buttonCOMPARE
			// 
			this->buttonCOMPARE->BackColor = System::Drawing::Color::Silver;
			this->buttonCOMPARE->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCOMPARE->Location = System::Drawing::Point(342, 215);
			this->buttonCOMPARE->Name = L"buttonCOMPARE";
			this->buttonCOMPARE->Size = System::Drawing::Size(143, 51);
			this->buttonCOMPARE->TabIndex = 2;
			this->buttonCOMPARE->Text = L"Зрівняти методи";
			this->buttonCOMPARE->UseVisualStyleBackColor = false;
			this->buttonCOMPARE->Click += gcnew System::EventHandler(this, &MainForm::buttonCOMPARE_Click);
			// 
			// buttonESPRIT
			// 
			this->buttonESPRIT->BackColor = System::Drawing::Color::Crimson;
			this->buttonESPRIT->Font = (gcnew System::Drawing::Font(L"Courier New", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonESPRIT->Location = System::Drawing::Point(342, 106);
			this->buttonESPRIT->Name = L"buttonESPRIT";
			this->buttonESPRIT->Size = System::Drawing::Size(143, 51);
			this->buttonESPRIT->TabIndex = 1;
			this->buttonESPRIT->Text = L"ESPRIT";
			this->buttonESPRIT->UseVisualStyleBackColor = false;
			this->buttonESPRIT->Click += gcnew System::EventHandler(this, &MainForm::buttonESPRIT_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Silver;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->richTextBox2);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(250, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(928, 344);
			this->panel3->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Courier New", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(16, 12);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(526, 22);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Панель обчислювальних процесів та логування";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::Gainsboro;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox2->Location = System::Drawing::Point(0, 50);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(924, 290);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 644);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MainForm";
			this->Text = L"Оцінка кутів приходу сигналів";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSnapshots))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSNR))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numM))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	












};
}
