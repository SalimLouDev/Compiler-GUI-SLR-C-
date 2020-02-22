#pragma once

#include<iostream>
#include<string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <ctype.h>

namespace CompilerGUI {

	enum Tokens
	{
		START_PROGRAM,
		END_PROGRAM,
		COMMENT,
		END_INSTRUCTION,
		RESERVED_WORD,
		STRING,
		INTEGER,
		FLOAT,
		IDENT,
		GIVE,
		AFFECT,
		RESERVED_CHARACHTER,
		IF,
		BIGGER,
		SMALLER,
		EQUAL,
		NOT_EQUAL,
		ELSE,
		START,
		FINISH,
		SHOW_MES,
		SHOW_VAL,
		TO,
		END_FILE,
		LTE,
		GTE,
		ERROR1,
		NUMBER
	};



	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	
	string filePath;
	ifstream f;
	string line;
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
		System::Windows::Forms::RichTextBox^ richTextBox1;
		//Tokens getToken1();
		//void displayTokens1(string fileName);
		//Tokens checkReserved1(string s);

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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	//private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1071, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 64);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(699, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(64, 64);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)));
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(816, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(64, 64);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)));
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(945, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(64, 64);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)));
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(588, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(64, 64);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::White;
			this->richTextBox1->Location = System::Drawing::Point(12, 118);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1123, 550);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"\n";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(520, 65);
			this->label1->TabIndex = 6;
			this->label1->Text = L"COMPILA COMPILER";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(18)));
			this->ClientSize = System::Drawing::Size(1147, 680);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	Application::Exit();

}
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {


}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	openFileDialog1->ShowDialog();
	String^ FilePath = openFileDialog1->FileName;
	richTextBox1->Text = FilePath;
	filePath = marshal_as<string>(FilePath);
	
	line;
	String^ str2;
	f.open(filePath.c_str());
	if (f.is_open())
	{
		while (getline(f, line))
		{
			str2 += gcnew String(line.c_str());
			str2 += L"\n";
		}
		richTextBox1->Text = str2;
		f.close();
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	//richTextBox1->Text = L"helloooo plllsss i want it to woork"; 
	displayTokens1("txt1.compila");
}
Tokens getToken1()
	   {
		   char ch;
		   string s;

		   f.get(ch);

		   while (isspace(ch)) f.get(ch);
		   if (f.eof())        return Tokens::END_FILE;
		   else if (ch == ',') return Tokens::RESERVED_CHARACHTER;
		   else if (ch == ':') return Tokens::RESERVED_CHARACHTER;
		   else if (ch == '<')
		   {
			   f.get(ch);
			   if (ch == '=')      return Tokens::LTE;
			   else if (ch == '>') return Tokens::NOT_EQUAL;
			   else
			   {
				   f.putback(ch);
				   return Tokens::SMALLER;
			   }
		   }
		   else if (ch == '>')
		   {
			   f.get(ch);
			   if (ch == '=')      return Tokens::GTE;
			   else
			   {
				   f.putback(ch);
				   return Tokens::SMALLER;
			   }
		   }
		   else if (ch == ';')
		   {
			   f.get(ch);
			   if (ch == ';') return Tokens::END_INSTRUCTION;
			   else return Tokens::ERROR1;
		   }
		   else if (ch == '-')
		   {
			   f.get(ch);
			   if (ch == '-') return Tokens::RESERVED_CHARACHTER;
			   else return Tokens::ERROR1;
		   }
		   else if (ch == '/')
		   {
			   f.get(ch);
			   if (ch == '/')
			   {
				   f.get(ch);
				   if (ch == '.') return Tokens::COMMENT;
				   else return Tokens::ERROR1;
			   }
			   else return Tokens::ERROR1;
		   }
		   else if (isalpha(ch))
		   {
			   s += ch;
			   f.get(ch);
			   while (isalpha(ch) || ch == '_' || isdigit(ch))
			   {
				   s += ch;
				   f.get(ch);
			   }
			   f.putback(ch);
			   return checkReserved1(s);
		   }
		   else if (isalpha(ch))
		   {
			   s = ch;
			   f.get(ch);
			   while (isalnum(ch))
			   {
				   s += ch;
				   f.get(ch);
			   }
			   f.putback(ch);
			   return checkReserved1(s);
		   }
		   else if (isdigit(ch))
		   {
			   s = ch;
			   f.get(ch);
			   while (isdigit(ch))
			   {
				   s += ch;
				   f.get(ch);
			   }
			   f.putback(ch);
			   return Tokens::NUMBER;
		   }
		   else if (isdigit(ch))
		   {
			   s = ch;
			   f.get(ch);
			   while (isdigit(ch))
			   {
				   s += ch;
				   f.get(ch);
			   }
			   f.putback(ch);
			   return Tokens::NUMBER;
		   }
		   else return Tokens::ERROR1;
	   }
void displayTokens1(string fileName)
	   {
	String^ str2;
	f.open(fileName.c_str());
	if (f.is_open())
	{
		while (getline(f, line))
		{
			str2 += gcnew String(line.c_str());
			str2 += L"\n";
		}
		richTextBox1->Text = str2;
		f.close();
	}
			/*f.open(fileName.c_str());
		   Tokens a;
		   string l = " ";
		   if (f.eof()) l+= "END OF FILE \n";
		   while (!f.eof())
		   {
			   a = getToken1();
			   switch (a)
			   {
			   case START_PROGRAM:        l += "Start_Program -----> START OF THE PROGRAM\n";//cout << "Start_Program -----> START OF THE PROGRAM\n";
				   break;
			   case END_PROGRAM:          l += "End_Program -----> END OF PROGRAM\n";
				   break;
			   case COMMENT:              l += "//. -----> COMMENT STARTER\n";
				   break;
			   case END_INSTRUCTION:      l += ";; -----> END OF INSTRUCRUCTION \n";
				   break;
			   case RESERVED_WORD:        l += "RESERVED WORD\n";
				   break;
			   case STRING:               l += "STRING WORD\n";
				   break;
			   case INTEGER:              l += "Int_Number -----> word reserved charachter\n";
				   break;
			   case FLOAT:                l += "Real_Number -----> word reserved charachter\n";
				   break;
			   case IDENT:                l += "IDENTIFIRE\n";
				   break;
			   case GIVE:                 l += "Give ----> Reserved Give Word \n";
				   break;
			   case AFFECT:               l += "Affect ----> Reserved word for affectation\n";
				   break;
			   case RESERVED_CHARACHTER:  l += "RESERVED CHARACHTER\n";
				   break;
			   case IF:                   l += "IF -----> CONDITION\n";
				   break;
			   case BIGGER:               l += "> -----> BIGGER\n";
				   break;
			   case SMALLER:              l += "< -----> SMALLER\n";
				   break;
			   case EQUAL:                l += "== -----> EQUAL\n";
				   break;
			   case NOT_EQUAL:            l += "<> -----> NOT EQUAL\n";
				   break;
			   case ELSE:                 l += "Else -----> ELSE CONDITION\n";
				   break;
			   case START:                l += "Start -----> START OF THE BLOCK\n";
				   break;
			   case FINISH:               l += "Finish -----> END OF THE BLOCK\n";
				   break;
			   case SHOW_MES:             l += "ShowMes -----> RESERVED TO SHOW MESSAGES\n";
				   break;
			   case SHOW_VAL:             l += "ShowVal -----> RESERVED TO SHOW VARIABLES VALUES\n";
				   break;
			   case TO:                   l += "to -----> TO reserved charachter\n";
				   break;
			   case LTE:                  l += "<= -----> LESS THEN OR EQUAL reserved charachter\n";
				   break;
			   case GTE:                  l += ">= -----> GREATER THAN OR EQUAL reserved charachter\n";
				   break;
			   case NUMBER:               l += "NUMBER\n";
				   break;
			   case END_FILE:             l += "\n ============== THE END OF THE FILE ======================\n";
				   break;
			   case ERROR1:                l += "ERROR\n";
				   break;
			   }
		   }
		   String^ str2;
		   str2 = gcnew String(l.c_str());
		   richTextBox1->Text = str2;
		   //f.close();*/
	   }
Tokens checkReserved1(string s)
{
	if (s == "Start_Program")    return Tokens::START_PROGRAM;
	else if (s == "Int_Number")  return Tokens::INTEGER;
	else if (s == "Give")        return Tokens::GIVE;
	else if (s == "Real_Number") return Tokens::FLOAT;
	else if (s == "If")          return Tokens::IF;
	else if (s == "Affect")      return Tokens::AFFECT;
	else if (s == "to")          return Tokens::TO;
	else if (s == "ShowMes")     return Tokens::SHOW_MES;
	else if (s == "ShowVal")     return Tokens::SHOW_VAL;
	else if (s == "Start")       return Tokens::START;
	else if (s == "Finish")      return Tokens::FINISH;
	else if (s == "Else")        return Tokens::ELSE;
	else if (s == "String")      return Tokens::STRING;
	else if (s == "End_Program") return Tokens::END_PROGRAM;
	else                         return Tokens::IDENT;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	displayTokens1("txt2.compila");
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	displayTokens1("txt3.compila");
}
};
}
