#pragma once
#include "HelpForm.h"
#include "Maze.h"
#include <fstream>
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream> // delete this later


namespace Program3
{
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
		// This seems to be where all the code starts, so this is imporant
		MainForm(void)
		{
			InitializeComponent();
			maze = nullptr;
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
	
	private: Maze *maze;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openMazeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openMazeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1016, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openMazeToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openMazeToolStripMenuItem
			// 
			this->openMazeToolStripMenuItem->Name = L"openMazeToolStripMenuItem";
			this->openMazeToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->openMazeToolStripMenuItem->Text = L"Open Maze";
			this->openMazeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openMazeToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::helpToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(13, 108);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(858, 891);
			this->panel1->TabIndex = 1;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::panel1_MouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(206, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 26);
			this->label1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 56);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 47);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Show original";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(873, 56);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 47);
			this->button2->TabIndex = 4;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(934, 56);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(56, 47);
			this->button3->TabIndex = 5;
			this->button3->Text = L"-";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1016, 1061);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void helpToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HelpForm^ f = gcnew HelpForm(); // display help form
		f->ShowDialog();
	}

	private: System::Void openMazeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// This is the method that lets a user open a file when they click "Open Maze" in the "file" section of the header.
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog; 
		openFileDialog1->Filter = "DAT files (*.DAT)|*.DAT"; // Prevent the user from selecting foreign file types
		openFileDialog1->InitialDirectory = ".";

		if (openFileDialog1->ShowDialog() == ::DialogResult::OK)
		{
			// create an empty array for the location of the file
			char filename[1024];

			int i;
			for (i = 0; i < openFileDialog1->FileName->Length; i++)
			{
				filename[i] = openFileDialog1->FileName[i];
			}

			// Null terminate the filename
			filename[i] = '\0';

			// Then, make an ifstream with this data so we can make a new maze with this data!
			ifstream ifs;
			ifs.open(filename);
			maze = new Maze(panel1, ifs);
			ifs.close();
		}
		if (maze->IsValid())
		{
			this->label1->Text = L"Maze loaded!";
			maze->ShowOriginal();
		}
		else // If "IsValid()" is false, let the user know that they gave an improper file.
		{
			MessageBox::Show("Not a proper maze file!");
			this->label1->Text = L"Not a proper maze file!";
		}
	}
	
	// This is triggered when the user clicks a box in the maze
	private: System::Void panel1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{	
		// We have this first if statement because we can't let the user try to solve an invalid file.
		if (maze->IsValid())
		{
			// e->X and e->Y track the location of the mouse.
			maze->Solve(e->X, e->Y);
			if (maze->IsFree())
				this->label1->Text = L"Exit found - I'm free!";
			else
				this->label1->Text = L"I could not find an exit path.";
			maze->ShowSolved();
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// Before the system opens the original maze, it checks to ensure that an original maze exists
		if (maze != nullptr)
		{
			if (maze->IsValid())
			{
				this->label1->Text = L"Original maze opened.";
				maze->ShowOriginal();
			}
			else
				this->label1->Text = L"Open a map first.";
		}
		else
			this->label1->Text = L"Open a map first.";
	}

	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		delete maze;
		_CrtDumpMemoryLeaks();
		this->Close();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (maze != nullptr)
		{
			if (maze->IsValid())
			{
				// If the maze is valid and the maze exists, then we increment the size using my getCellSize and setCellSize methods
				maze->setCellSize(maze->getCellSize() + 1);
				this->label1->Text = L"Size increased";
				maze->ShowOriginal();
			}
		}
		else
		{
			this->label1->Text = L"Open a map first.";
		}
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (maze != nullptr)
		{
			if (maze->IsValid())
			{
				// If the maze is valid and the maze exists, then we decrement the size using my getCellSize and setCellSize methods
				maze->setCellSize(maze->getCellSize() - 1);
				this->label1->Text = L"Size decreased";
				maze->ShowOriginal();
			}
		}
		else
		{
			this->label1->Text = L"Open a map first.";
		}
	}
};
}
