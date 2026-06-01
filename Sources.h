#pragma once

namespace DirectionOfArrival {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Sources
	/// </summary>
	public ref class Sources : public System::Windows::Forms::Form
	{
	public:
		Sources(void)
		{
			InitializeComponent();
			UpdateGrid();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Sources()
		{
			if (components)
			{
				delete components;
			}
		}

		//оголошення елементів інтерфейсу
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::NumericUpDown^ numK;
	public: System::Windows::Forms::DataGridView^ dgvAngles;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSource;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colAngle;
	private: System::Windows::Forms::Button^ btnApply;
	private: System::Windows::Forms::Button^ btnCancel;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->numK = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dgvAngles = (gcnew System::Windows::Forms::DataGridView());
			this->colSource = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colAngle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnApply = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numK))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAngles))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->numK);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(360, 70);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Загальні параметри";
			// 
			// numK
			// 
			this->numK->Location = System::Drawing::Point(268, 28);
			this->numK->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numK->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numK->Name = L"numK";
			this->numK->Size = System::Drawing::Size(70, 28);
			this->numK->TabIndex = 1;
			this->numK->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->numK->ValueChanged += gcnew System::EventHandler(this, &Sources::numK_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(196, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Кількість джерел \r\n";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dgvAngles);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 88);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(360, 202);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Кути приходу (DOA)";
			// 
			// dgvAngles
			// 
			this->dgvAngles->AllowUserToAddRows = false;
			this->dgvAngles->AllowUserToDeleteRows = false;
			this->dgvAngles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvAngles->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->colSource,
					this->colAngle
			});
			this->dgvAngles->Location = System::Drawing::Point(15, 30);
			this->dgvAngles->Name = L"dgvAngles";
			this->dgvAngles->RowHeadersVisible = false;
			this->dgvAngles->RowHeadersWidth = 62;
			this->dgvAngles->RowTemplate->Height = 28;
			this->dgvAngles->Size = System::Drawing::Size(330, 145);
			this->dgvAngles->TabIndex = 0;
			// 
			// colSource
			// 
			this->colSource->HeaderText = L"Джерело";
			this->colSource->MinimumWidth = 8;
			this->colSource->Name = L"colSource";
			this->colSource->ReadOnly = true;
			this->colSource->Width = 140;
			// 
			// colAngle
			// 
			this->colAngle->HeaderText = L"Кут (градуси)";
			this->colAngle->MinimumWidth = 8;
			this->colAngle->Name = L"colAngle";
			this->colAngle->Width = 160;
			// 
			// btnApply
			// 
			this->btnApply->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnApply->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnApply->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnApply->Location = System::Drawing::Point(65, 305);
			this->btnApply->Name = L"btnApply";
			this->btnApply->Size = System::Drawing::Size(158, 35);
			this->btnApply->TabIndex = 2;
			this->btnApply->Text = L"Застосувати";
			this->btnApply->UseVisualStyleBackColor = true;
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnCancel->Location = System::Drawing::Point(229, 305);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(143, 35);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"Скасувати";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// Sources
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnApply);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Sources";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Налаштування джерел сигналів";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numK))->EndInit();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvAngles))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		//метод для оновлення кількості рядків у таблиці в залежності від обраного K
	private: void UpdateGrid() {
		int K = (int)numK->Value;
		dgvAngles->RowCount = K;

		for (int i = 0; i < K; i++) {
			dgvAngles->Rows[i]->Cells[0]->Value = L"Джерело №" + (i + 1).ToString();
			if (dgvAngles->Rows[i]->Cells[1]->Value == nullptr) {
				dgvAngles->Rows[i]->Cells[1]->Value = L"0";
			}
		}
	}

	private: System::Void numK_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		UpdateGrid();
	}

};
}