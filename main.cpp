#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(cli::array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    DirectionOfArrival::MainForm form;
    Application::Run(% form);

    return 0;
}