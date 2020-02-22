#pragma once
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>
#include <ctype.h>
#include <string>
#include "MyForm.h"



using namespace System::Windows::Forms;
using namespace System;
using namespace std;

namespace H {
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

	string filePath;
	string line;

	class Scanner
	{
	public:
		Scanner(string fileName);
		~Scanner();
		Tokens getToken1();
		string displayTokens1(RichTextBox^ r);
	private:
		ifstream f;
		Tokens checkReserved1(string s);
	};

	Scanner::Scanner(string fileName)
	{
		f.open(fileName.c_str());
	}

	Scanner::~Scanner()
	{
		f.close();
	}

	Tokens Scanner::getToken1()
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

	string Scanner::displayTokens1( RichTextBox^ r)
	{
		Tokens a;
		string l=" ";
		if (f.eof()) cout << "END OF FILE \n";
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
		//String^ str2;
		//str2 = gcnew String(l.c_str());
		//r->Text = str2;
		return l;
	}

	inline Tokens Scanner::checkReserved1(string s)
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
}
/*int main()
{
	string name;
	cout << "Enter the file name : ";
	cin >> name;
	Scanner s(name);
	s.displayTokens1();
	s.~Scanner();
}*/