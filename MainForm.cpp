#include "MainForm.h"
#include "Sources.h"
#include <fstream>
#include "Methods.h"  
#include "Signals.h"


using namespace System;
using namespace System::Windows::Forms;

std::vector<double> global_angles = { -30.0, 45.0 };

// метод зміни кількості антен
System::Void DirectionOfArrival::MainForm::numM_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    int M = (int)numM->Value;

    dataGridView1->Columns->Clear();

    dataGridView1->ColumnCount = M;
    dataGridView1->RowCount = M;

    for (int i = 0; i < M; i++) {
        dataGridView1->Columns[i]->Width = 40;
        dataGridView1->Columns[i]->Name = (i + 1).ToString();
    }
}

//методу обробки зміни кроку решітки
System::Void DirectionOfArrival::MainForm::numD_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    double d = Convert::ToDouble(numD->Value);

    if (d <= 0) {
        MessageBox::Show("відстань між антенами повинна бути більшою за 0", "помилка введення", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        numD->Value = System::Decimal(0.5); // повертаємо дефолтне значення
    }
}
// метод зміни значення SNR
System::Void DirectionOfArrival::MainForm::numSNR_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    double snr = Convert::ToDouble(numSNR->Value);

    if (snr < -40 || snr > 100) {
        MessageBox::Show("рівень SNR виходить за межі стандартного моделювання",
            "попередження", MessageBoxButtons::OK, MessageBoxIcon::Warning);
    }
}

// метод зміни кількості відліків
System::Void DirectionOfArrival::MainForm::numSnapshots_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
    int snapshots = (int)numSnapshots->Value;
    int M = (int)numM->Value; 

    if (snapshots <= 0) {
        MessageBox::Show("кількість відліків повинна бути більшою за 0",
            "помилка введення", MessageBoxButtons::OK, MessageBoxIcon::Error);
        numSnapshots->Value = 100; 
        return;
    }

    // бажано щоб кількість відліків була більшою за кількість антен 
    if (snapshots < M) {
        MessageBox::Show("кількість відліків менша за кількість антен "
            "це може знизити точність оцінки кутів алгоритмами",
            "рекомендація", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}
System::Void DirectionOfArrival::MainForm::radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton1->Checked) {
        DirectionOfArrival::Sources^ sourcesForm = gcnew DirectionOfArrival::Sources();
        if (sourcesForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            int K = (int)sourcesForm->numK->Value;
            global_angles.clear();

            for (int i = 0; i < K; i++) {
                double angle = Convert::ToDouble(sourcesForm->dgvAngles->Rows[i]->Cells[1]->Value);
                global_angles.push_back(angle);
            }
            MessageBox::Show("кути успішно збережено та передано в алгоритм", "успішно", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
        else {
            radioButton2->Checked = true;
        }
    }
}

//метод для випадкових кутів
System::Void DirectionOfArrival::MainForm::radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton2->Checked) {
        MessageBox::Show("кути приходу сигналів будуть згенеровані випадковим чином",
            "random", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

//обчислення
System::Void DirectionOfArrival::MainForm::RunDOAAnalysis(System::String^ methodType) {
    int M = (int)numM->Value;
    double d = Convert::ToDouble(numD->Value);
    double snr = Convert::ToDouble(numSNR->Value);
    int snapshots = (int)numSnapshots->Value;

    std::vector<double> angles = global_angles;

    int D = angles.size();

    richTextBox2->Clear();
    dataGridView2->Rows->Clear();
    dataGridView2->ColumnCount = 2;
    dataGridView2->Columns[0]->Name = L"Справжній кут";
    dataGridView2->Columns[1]->Name = L"Оцінка " + methodType;

    richTextBox2->AppendText("запуск алгоритму " + methodType + " ===\n");
    richTextBox2->AppendText("Кількість антен (M): " + M.ToString() + ", SNR: " + snr.ToString() + ", Відліків: " + snapshots.ToString() + "\n");
    richTextBox2->AppendText("Генерація сигналів\n");

    //генерація
    SignalGenerator sg(M, d);
    MatrixXcd X = sg.generateData(angles, snr, snapshots);
    MatrixXcd R = sg.computeCorrelationMatrix(X);

    richTextBox2->AppendText("кореляційна матриця R (" + M.ToString() + "x" + M.ToString() + ") обчислена\n");

    // виведення кореляційної матриці
    dataGridView1->RowCount = M;
    dataGridView1->ColumnCount = M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            double realPart = std::round(R(i, j).real() * 1000.0) / 1000.0;
            double imagPart = std::round(R(i, j).imag() * 1000.0) / 1000.0;
            System::String^ cellVal = realPart.ToString();
            if (imagPart >= 0) cellVal += "+";
            cellVal += imagPart.ToString() + "i";
            dataGridView1->Rows[i]->Cells[j]->Value = cellVal;
        }
    }


    SubspaceMethods methods;

    std::vector<double> spectrum;
    std::vector<double> espritAngles;

    //мьюзік (або порівняти)
    if (methodType == "MUSIC" || methodType == "COMPARE") {
        richTextBox2->AppendText("Виконується пошук спектру методом MUSIC\n");
        spectrum = methods.computeMUSIC(R, M, d, D);
    }

    //ЕСПРІТ (або порівняти)
    if (methodType == "ESPRIT" || methodType == "COMPARE") {
        richTextBox2->AppendText("Виконується оцінка кутів методои ESPRIT\n");
        espritAngles = methods.computeESPRIT(R, M, d, D);

        //таблиця результатів
        for (int i = 0; i < D; i++) {
            double estAngle = (i < espritAngles.size()) ? espritAngles[i] : 0.0;
            cli::array<System::String^>^ row = gcnew cli::array<System::String^>{
                angles[i].ToString() + "°",
                    System::Math::Round(estAngle, 2).ToString() + "°"
            };
            dataGridView2->Rows->Add(row);
        }
    }

    richTextBox2->AppendText("Експорт даних та запуск візуалізації\n");
    WriteDataToFile(spectrum, espritAngles);
    StartPythonProcess(methodType);
}
//запис даних у файл для пайтона
void DirectionOfArrival::MainForm::WriteDataToFile(std::vector<double> spectrum, std::vector<double> esprit_angles) {
    std::ofstream file("plot_data.txt");
    if (!file.is_open()) {
        MessageBox::Show("Не вдалося створити файл з даними", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return;
    }

    //запис всфх знач. для мьюзік в один рядок з пробілами
    for (size_t i = 0; i < spectrum.size(); ++i) {
        file << spectrum[i];
        if (i < spectrum.size() - 1) file << " ";
    }
    file << "\n"; //наступний рядок

    //запис всіх знач для еспріт
    if (esprit_angles.empty()) {
        file << "999.0"; //типу заглушка
    }
    else {
        for (size_t i = 0; i < esprit_angles.size(); ++i) {
            file << esprit_angles[i];
            if (i < esprit_angles.size() - 1) file << " ";
        }
    }
    file << "\n";

    file.close();
}

//запуск пайтон скрипта
void DirectionOfArrival::MainForm::StartPythonProcess(System::String^ mode) {
    System::Diagnostics::Process^ myProcess = gcnew System::Diagnostics::Process();

    myProcess->StartInfo->FileName = "python";

    myProcess->StartInfo->Arguments = "plot_spectrum.py " + mode;

    myProcess->StartInfo->UseShellExecute = false;
    myProcess->StartInfo->CreateNoWindow = false;

    try {
        myProcess->Start();
    }
    catch (System::Exception^ ex) {
        MessageBox::Show("Не вдалося запустити Python " + ex->Message,
            "Помилка запуску", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void DirectionOfArrival::MainForm::buttonMUSIC_Click(System::Object^ sender, System::EventArgs^ e) {
    RunDOAAnalysis("MUSIC");
}

System::Void DirectionOfArrival::MainForm::buttonESPRIT_Click(System::Object^ sender, System::EventArgs^ e) {
    RunDOAAnalysis("ESPRIT");
}

System::Void DirectionOfArrival::MainForm::buttonCOMPARE_Click(System::Object^ sender, System::EventArgs^ e) {
    RunDOAAnalysis("COMPARE");
}