#include "stdafx.h"
#pragma warning(disable:4996)
#include "global.h"

using namespace std;

char *p;  //用于与code[]进行交互，初始化为code

char Token[100];  //存放单词字符串
int token_count = 0; //token计数器
char Ch; //存放当前读入的字符
char IDNAME[100];
char singleCHAR; //用于存放当读到‘c’单个字符的情况
char singleC[5];  //专门用于方便词法分析程序输出的
char stringCHAR[100];   //在本程序中，将单字符和字符串的‘和”也放在了单词中，因为只有这个地方出现了，所以不会对其他语法造成影响//此处更新后未将双引号放入
int num; //存放当前读入的整型数值
string symbol = string("null");
int line_num = 1;               //记录行数用于错误处理
char linebuf[100];              //行缓冲
int line_count = 0;
int endNum = 0;
map<string, int>symcode;
map<string, string>symvalue;

int  code_count = 0;

char code[10000];

int Getchar()
{
	p++;
	Ch = *p;
	if (Ch == '\n') {
		char* n_p = p + 1;
		while ((*n_p != '\n') && (*n_p != '\0'))
			linebuf[line_count++] = *(n_p++);
		linebuf[line_count] = '\0';
		line_count = 0;
	}
	return 0;
}

int clearToken()
{
	for (int i = 0; i <= token_count; i++)
	{
		Token[i] = '\0';
	}
	token_count = 0;
	return 0;
}

int isSpace()
{
	if (Ch == ' ')
		return 1;
	else
		return 0;
}

int isNewline()
{
	if (Ch == '\n')
	{
		line_num++;
		return 1;
	}
	else
		return 0;
}

int isTab()
{
	if (Ch == '\t')
		return 1;
	else
		return 0;
}

int isDigit()
{
	if ((Ch >= '0' && Ch <= '9'))
		return 1;
	else
		return 0;
}

int isLetter()
{
	if ((Ch >= 'A' && Ch <= 'Z') || (Ch >= 'a' && Ch <= 'z') || Ch == '_')
		return 1;
	else
		return 0;
}

int isColon()
{
	if (Ch == ':')
		return 1;
	else
		return 0;
}

int isComma()
{
	if (Ch == ',')
		return 1;
	else
		return 0;
}

int isSemi()
{
	if (Ch == ';')
		return 1;
	else
		return 0;
}

int isEqu()
{
	if (Ch == '=')
		return 1;
	else
		return 0;
}

int isPlus()
{
	if (Ch == '+')
		return 1;
	else
		return 0;
}

int isMinus()
{
	if (Ch == '-')
		return 1;
	else
		return 0;
}

int isDivi()
{
	if (Ch == '/')
		return 1;
	else
		return 0;
}

int isStar()
{
	if (Ch == '*')
		return 1;
	else
		return 0;
}

int isLpar()
{
	if (Ch == '(')         //左括号的ascii码
		return 1;
	else
		return 0;
}

int isRpar()
{
	if (Ch == ')')          //右括号的ascii码
		return 1;
	else
		return 0;
}

int isLbracket()
{
	if (Ch == '[')
		return 1;
	else
		return 0;
}

int isRbracket()
{
	if (Ch == ']')           //右中括号的ascii码
		return 1;
	else
		return 0;
}

int isLbrace()
{
	if (Ch == '{')           //左大括号的ascii码
		return 1;
	else
		return 0;
}

int isRbrace()
{
	if (Ch == '}')            //右大括号的ascii码
		return 1;
	else
		return 0;
}

int isExclam()              //感叹号
{
	if (Ch == '!')
		return 1;
	else
		return 0;
}

int isStringChar()                   //判断是否满足字符串中的条件
{
	if ((Ch >= 32) && (Ch <= 126) && (Ch != 34))
		return 1;
	else
		return 0;
}

int isSQuote()
{
	if (Ch == '\'')
		return 1;
	else
		return 0;
}

int isDQuote()
{
	if (Ch == '\"')
		return 1;
	else
		return 0;
}

int isSmaller()
{
	if (Ch == '<')
		return 1;
	else
		return 0;
}

int isBigger()
{
	if (Ch == '>')
		return 1;
	else
		return 0;
}

int isSingleCh()
{
	if (isPlus() || isMinus() || isStar() || isDivi() || isDigit() || isLetter())
		return 1;
	else
		return 0;
}

int retract()
{
	p--;
	Ch = *p;
	return 0;
}

int catToken()
{
	Token[token_count++] = Ch;
	Token[token_count] = '\0';
	return 0;
}

int transNum()
{
	return atoi(Token);
}

int reserver()
{
	if (strcmp(Token, "const") == 0)
	{
		symbol = "CONSTSY";
		return 1;
	}
	else if (strcmp(Token, "int") == 0)
	{
		symbol = "INTSY";
		return 2;
	}
	else if (strcmp(Token, "char") == 0)
	{
		symbol = "CHARSY";
		return 3;
	}
	else if (strcmp(Token, "void") == 0)
	{
		symbol = "VOIDSY";
		return 4;
	}
	else if (strcmp(Token, "main") == 0)
	{
		symbol = "MAINSY";
		return 5;
	}
	else if (strcmp(Token, "if") == 0)
	{
		symbol = "IFSY";
		return 6;
	}
	else if (strcmp(Token, "do") == 0)
	{
		symbol = "DOSY";
		return 7;
	}
	else if (strcmp(Token, "while") == 0)
	{
		symbol = "WHILESY";
		return 8;
	}
	else if (strcmp(Token, "switch") == 0)
	{
		symbol = "SWITCHSY";
		return 9;
	}
	else if (strcmp(Token, "case") == 0)
	{
		symbol = "CASESY";
		return 10;
	}
	else if (strcmp(Token, "scanf") == 0)
	{
		symbol = "SCANFSY";
		return 11;
	}
	else if (strcmp(Token, "printf") == 0)
	{
		symbol = "PRINTSY";
		return 12;
	}
	else if (strcmp(Token, "return") == 0)
	{
		symbol = "RETURNSY";
		return 13;
	}
	else
		return 0;
}

void symcodeinit()
{
	symcode.insert(map<string, int>::value_type("CONSTSY", 1));
	symcode.insert(map<string, int>::value_type("INTSY", 2));
	symcode.insert(map<string, int>::value_type("CHARSY", 3));
	symcode.insert(map<string, int>::value_type("VOIDSY", 4));
	symcode.insert(map<string, int>::value_type("MAINSY", 5));
	symcode.insert(map<string, int>::value_type("IFSY", 6));
	symcode.insert(map<string, int>::value_type("DOSY", 7));
	symcode.insert(map<string, int>::value_type("WHILESY", 8));
	symcode.insert(map<string, int>::value_type("SWITCHSY", 9));
	symcode.insert(map<string, int>::value_type("CASESY", 10));
	symcode.insert(map<string, int>::value_type("SCANFSY", 11));
	symcode.insert(map<string, int>::value_type("PRINTSY", 12));
	symcode.insert(map<string, int>::value_type("RETURNSY", 13));
	symcode.insert(map<string, int>::value_type("COLON", 14));
	symcode.insert(map<string, int>::value_type("COMMA", 15));
	symcode.insert(map<string, int>::value_type("SEMI", 16));
	symcode.insert(map<string, int>::value_type("EQUAL", 17));
	symcode.insert(map<string, int>::value_type("PLUS", 18));
	symcode.insert(map<string, int>::value_type("MINUS", 19));
	symcode.insert(map<string, int>::value_type("DIVIDE", 20));
	symcode.insert(map<string, int>::value_type("STAR", 21));
	symcode.insert(map<string, int>::value_type("LPAR", 22));
	symcode.insert(map<string, int>::value_type("RPAR", 23));
	symcode.insert(map<string, int>::value_type("LBRACKET", 24));
	symcode.insert(map<string, int>::value_type("RBRACKET", 25));
	symcode.insert(map<string, int>::value_type("LBRACE", 26));
	symcode.insert(map<string, int>::value_type("RBRACE", 27));
	symcode.insert(map<string, int>::value_type("SQUOTE", 28));
	symcode.insert(map<string, int>::value_type("DQUOTE", 29));
	symcode.insert(map<string, int>::value_type("SMALLER", 30));
	symcode.insert(map<string, int>::value_type("SMALLEREQ", 31));
	symcode.insert(map<string, int>::value_type("BIGGER", 32));
	symcode.insert(map<string, int>::value_type("BIGGEREQ", 33));
	symcode.insert(map<string, int>::value_type("NEQUAL", 34));
	symcode.insert(map<string, int>::value_type("REALEQ", 35));
	symcode.insert(map<string, int>::value_type("NUMSY", 36));
	symcode.insert(map<string, int>::value_type("CHARASCII", 37));
	symcode.insert(map<string, int>::value_type("STRINGSY", 38));
	symcode.insert(map<string, int>::value_type("IDSY", 39));

	symvalue.insert(map<string, string>::value_type("CONSTSY", "const"));
	symvalue.insert(map<string, string>::value_type("INTSY", "int"));
	symvalue.insert(map<string, string>::value_type("CHARSY", "char"));
	symvalue.insert(map<string, string>::value_type("VOIDSY", "void"));
	symvalue.insert(map<string, string>::value_type("MAINSY", "main"));
	symvalue.insert(map<string, string>::value_type("IFSY", "if"));
	symvalue.insert(map<string, string>::value_type("DOSY", "do"));
	symvalue.insert(map<string, string>::value_type("WHILESY", "while"));
	symvalue.insert(map<string, string>::value_type("SWITCHSY", "switch"));
	symvalue.insert(map<string, string>::value_type("CASESY", "case"));
	symvalue.insert(map<string, string>::value_type("SCANFSY", "scanf"));
	symvalue.insert(map<string, string>::value_type("PRINTSY", "printf"));
	symvalue.insert(map<string, string>::value_type("RETURNSY", "return"));
	symvalue.insert(map<string, string>::value_type("COLON", ":"));
	symvalue.insert(map<string, string>::value_type("COMMA", ","));
	symvalue.insert(map<string, string>::value_type("SEMI", ";"));
	symvalue.insert(map<string, string>::value_type("EQUAL", "="));
	symvalue.insert(map<string, string>::value_type("PLUS", "+"));
	symvalue.insert(map<string, string>::value_type("MINUS", "-"));
	symvalue.insert(map<string, string>::value_type("DIVIDE", "/"));
	symvalue.insert(map<string, string>::value_type("STAR", "*"));
	symvalue.insert(map<string, string>::value_type("LPAR", "("));
	symvalue.insert(map<string, string>::value_type("RPAR", ")"));
	symvalue.insert(map<string, string>::value_type("LBRACKET", "["));
	symvalue.insert(map<string, string>::value_type("RBRACKET", "]"));
	symvalue.insert(map<string, string>::value_type("LBRACE", "{"));
	symvalue.insert(map<string, string>::value_type("RBRACE", "}"));
	symvalue.insert(map<string, string>::value_type("SQUOTE", "\'"));
	symvalue.insert(map<string, string>::value_type("DQUOTE", "\""));
	symvalue.insert(map<string, string>::value_type("SMALLER", "<"));
	symvalue.insert(map<string, string>::value_type("SMALLEREQ", "<="));
	symvalue.insert(map<string, string>::value_type("BIGGER", ">"));
	symvalue.insert(map<string, string>::value_type("BIGGEREQ", ">="));
	symvalue.insert(map<string, string>::value_type("NEQUAL", "!="));
	symvalue.insert(map<string, string>::value_type("REALEQ", "=="));

}

int error(int e)                    ////////////////////////////初步的报错
{
	switch (e)
	{
	case 1: cout << "error: " << " in line:" << line_num << " Missing \' in the singleCHAR" << endl;     break;
	case 2: cout << "error: " << " in line:" << line_num << " Ilegal single char" << endl;       break;
	case 3: cout << "error: " << " in line:" << line_num << " Missing \" in the string" << endl;     break;
	case 4: cout << "error: " << " in line:" << line_num << " Missing \'=\' in NEQUAL" << endl;      break;
	case 5: cout << "error: " << " in line:" << line_num << " Missing function name or \"main\"" << endl;      break;
	case 6: cout << "error: " << " in line:" << line_num << " Missing type identification: int|char|void" << endl;      break;
	case 7: cout << "error: " << " in line:" << line_num << " Missing \',\' or \';\' or [" << endl;      break;
	case 8: cout << "error: " << " in line:" << line_num << " Missing identification" << endl;      break;
	case 9: cout << "error: " << " in line:" << line_num << " Ileagal integer" << endl;      break;
	case 10: cout << "error: " << " in line:" << line_num << " Missing \'=\'" << endl;      break;
	case 11: cout << "error: " << " in line:" << line_num << " Missing single char" << endl;      break;
	case 12: cout << "error: " << " in line:" << line_num << " Missing semi: ;" << endl;      break;
	case 13: cout << "error: " << " in line:" << line_num << " Missing right bracket:]" << endl;      break;
	case 14: cout << "error: " << " in line:" << line_num << " Missing left brace:{" << endl;      break;
	case 15: cout << "error: " << " in line:" << line_num << " Missing right par:)" << endl;      break;
	case 16: cout << "error: " << " in line:" << line_num << " Missing left par:(" << endl;      break;
	case 17: cout << "error: " << " in line:" << line_num << " Missing right brace:}" << endl;      break;
	case 18: cout << "error: " << " in line:" << line_num << " This function has no return!" << endl;      break;
	case 19: cout << "error: " << " in line:" << line_num << " The main function return is not void" << endl;      break;
	case 20: cout << "error: " << " in line:" << line_num << " Missing expression" << endl;      break;
	case 21: cout << "error: " << " in line:" << line_num << " Ileagal factor" << endl;      break;
	case 22: cout << "error: " << " in line:" << line_num << " Ileagal assignment statement" << endl;      break;
	case 23: cout << "error: " << " in line:" << line_num << " Ileagal statement" << endl;      break;
	case 24: cout << "error: " << " in line:" << line_num << " Ileagal comparational symbol" << endl;      break;
	case 25: cout << "error: " << " in line:" << line_num << " Missing while" << endl;      break;
	case 26: cout << "error: " << " in line:" << line_num << " Missing colon \':\'" << endl;      break;
	case 27: cout << "error: " << " in line:" << line_num << " Ileagal const(not integer and not char)" << endl;      break;
	case 28: cout << "error: " << " in line:" << line_num << " Missing \'=\'" << endl;      break;
	case 29: cout << "error: " << " in line:" << line_num << " Ileagal operation" << endl;      break;
	case 30: cout << "error: " << " in line:" << line_num << " Redefine identified symbol!" << endl;      break;
	case 31: cout << "error: " << " in line:" << line_num << " Procedure table overflow!" << endl;      break;
	}
	cout << linebuf << endl;
	return 0;
}

int getsym()
{
	clearToken();

	while (isSpace() || isNewline() || isTab())
	{
		symbol = string("null");
		Getchar();
	}
	if (isLetter())
	{
		while (isLetter() || isDigit())
		{
			catToken();
			Getchar();
		}
		retract();
		int i = 0;
		while (i <= token_count)                    ///////////不考虑大小写
		{
			if (Token[i] <= 'Z' && Token[i] >= 'A')
			{
				Token[i] = Token[i] - 'A' + 'a';
			}
			i++;
		}
		if (reserver() == 0)
		{
			symbol = "IDSY";
			strcpy(IDNAME, Token);
		}
	}
	else if (isDigit())
	{
		while (isDigit())
		{
			catToken();
			Getchar();
		}
		retract();
		num = transNum();
		symbol = "NUMSY";
	}
	else if (isColon())
		symbol = "COLON";
	else if (isComma())
		symbol = "COMMA";
	else if (isSemi())
		symbol = "SEMI";
	else if (isPlus())
		symbol = "PLUS";
	else if (isMinus())
		symbol = "MINUS";
	else if (isDivi())
		symbol = "DIVIDE";
	else if (isStar())
		symbol = "STAR";
	else if (isLpar())
		symbol = "LPAR";
	else if (isRpar())
		symbol = "RPAR";
	else if (isLbracket())
		symbol = "LBRACKET";
	else if (isRbracket())
		symbol = "RBRACKET";
	else if (isLbrace())
		symbol = "LBRACE";
	else if (isRbrace())
		symbol = "RBRACE";
	else if (isEqu())
	{
		Getchar();
		if (isEqu())
			symbol = "REALEQ";
		else
		{
			retract();
			symbol = "EQUAL";
		}
	}
	else if (isExclam())
	{
		Getchar();
		if (isEqu())
			symbol = "NEQUAL";
		else
		{
			retract();
			error(4);
		}
	}
	else if (isSmaller())
	{
		Getchar();
		if (isEqu())
			symbol = "SMALLEREQ";
		else
		{
			retract();
			symbol = "SMALLER";
		}
	}
	else if (isBigger())
	{
		Getchar();
		if (isEqu())
			symbol = "BIGGEREQ";
		else
		{
			retract();
			symbol = "BIGGEREQ";
		}
	}
	else if (isSQuote())                 /////////////////////////
	{
		Getchar();
		singleCHAR = Ch;
		singleC[0] = '\'';
		if (isSingleCh())
		{
			singleC[1] = singleCHAR;
			Getchar();
			if (isSQuote())
			{
				symbol = "CHARASCII";
				singleC[2] = '\'';
				singleC[3] = '\0';
			}
			else
			{
				symbol = "CHARASCII";
				singleC[2] = '\0';
				error(1);            //////////////////////////////////
			}
		}
		else
		{
			symbol = "CHARASCII";
			singleC[1] = '\0';
			error(2);                 //////////////////////////////////////
		}
	}
	else if (isDQuote())
	{
		Getchar();
		int stringcount = 0;
		//stringCHAR[stringcount++] = '\"';
		while (isStringChar() && stringcount < 98)
		{
			stringCHAR[stringcount++] = Ch;
			Getchar();
		}
		if (stringcount >= 98)
			cout << "too long string!" << endl;
		else
		{
			if (isDQuote())
			{
				//stringCHAR[stringcount++] = '\"';
				stringCHAR[stringcount] = '\0';
				symbol = "STRINGSY";
			}
			else
			{
				error(3);                       //////////////////////////////
				symbol = "STRINGSY";
			}
		}
	}
	return 0;
}

int Lexical_output()
{
	ofstream outfile("15231204_lexical_result.txt");
	int lexnum = 0;
	Ch = *p;
	while (Ch != '\0')
	{
		getsym();
		if (symbol != string("null"))
		{
			lexnum++;
			//cout << lexnum << " " << symbol << endl;
			if (symbol == string("NUMSY"))
				cout << lexnum << " " << symbol << " " << num << " in line: " << line_num << endl;
			else if (symbol == string("CHARASCII"))
				cout << lexnum << " " << symbol << " " << singleC << " in line: " << line_num << endl;
			else if (symbol == string("STRINGSY"))
				cout << lexnum << " " << symbol << " " << stringCHAR << " in line: " << line_num << endl;
			else if (symbol == string("IDSY"))
				cout << lexnum << " " << symbol << " " << IDNAME << " in line: " << line_num << endl;
			else
				cout << lexnum << " " << symbol << " " << symvalue.find(symbol)->second << " in line: " << line_num << endl;

		}
		Getchar();
	}
	outfile.close();
	return 0;
}

void readCodeFile()
{
	ifstream infile;

	string infileName;

	cout << "Please input the original code file: " << endl;
	getline(cin, infileName);

	infile.open(infileName.c_str());           //infileName.c_str()
	assert(infile.is_open());

	char c;
	infile >> noskipws;

	p = code;
	pre1p = code;
	pre2p = code;
	pre3p = code;

	while (infile.get(c))
	{
		code[code_count++] = c;
	}
	code[code_count] = '\0';
	infile.close();

	symcodeinit();
	//Lexical_output();
}

