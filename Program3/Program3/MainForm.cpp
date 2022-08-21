#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(cli::array<String^>^ args) {
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Program3::MainForm form;
   Application::Run(% form);
}