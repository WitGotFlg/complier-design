#include "stdafx.h"
#include "global.h"

using namespace std;

char* pre1p;
char* pre2p;
char* pre3p;

int flag_for_interger2const;
int level = 0;
bool return_flag = false;
bool return_expression = false;     //为false说明返回值为void（表达式为空）
string return_type = string("VOIDSY");
string operand;
string expression_type = string("INTSY");
string term_type = string("INTSY"); 
string factor_type = string("INTSY");
int label_num = 0;
int error_num = 0;

int tempvarnum = 0;

void nextsym()            //语法分析取单词，3个prep用于标识符，数组，函数区分时必要的预读
{
	pre3p = pre2p;
	pre2p = pre1p;
	pre1p = p;
	getsym();
	Getchar();
}

void recallsym()          //发现是数组或函数时使用，将p回退后再调用相应的子语法分析程序
{
	char* current_p = p;
	p = pre1p;
	Ch = *p;
	pre1p = pre2p;
	pre2p = pre3p;
	char* temp = p;
	while (temp < current_p)
	{
		if (*temp == '\n')
			line_num--;
		temp++;
	}
}

//＜常量定义＞   ::=   int＜标识符＞＝＜整数＞{,＜标识符＞＝＜整数＞}
//                           | char＜标识符＞＝＜字符＞{,＜标识符＞＝＜字符＞}
//＜无符号整数＞  ::= ＜非零数字＞｛＜数字＞｝
//＜整数＞        ::= ［＋｜－］＜无符号整数＞｜０
//＜标识符＞    ::=  ＜字母＞｛＜字母＞｜＜数字＞｝
void next_semi()
{
	while (symbol.compare("SEMI") != 0)
	{
		nextsym();
	}
	nextsym();
}

void next_RBRACE()
{
	while (symbol.compare("RBRACE") != 0)
	{
		nextsym();
	}
	nextsym();
}

void next_LBRACE()
{
	while (symbol.compare("LBRACE") != 0)
	{
		nextsym();
	}
	nextsym();
}

void next_declare_head()
{
	nextsym();
	while ((symbol.compare("INTSY") != 0) && (symbol.compare("CHARSY") != 0) && (symbol.compare("VOIDSY") != 0))
	{
		nextsym();
	}
}

void next_RPAR()
{
	while (symbol.compare("RPAR") != 0)
	{
		nextsym();
	}
}

void next_statement()
{
	while ((symbol.compare("IFSY") != 0) && (symbol.compare("DOSY") != 0) && (symbol.compare("SWITCHSY") != 0) &&
		(symbol.compare("LBRACE") != 0) && (symbol.compare("IDSY") != 0) && (symbol.compare("SCANFSY") != 0) &&
		(symbol.compare("PRINTSY") != 0) && (symbol.compare("SEMI") != 0) && (symbol.compare("RETURNSY") != 0))
	{
		nextsym();
	}
}

int integer()
{
	flag_for_interger2const = 0;
	int NUM = 0;
	int flag = 1;
	if ((symbol.compare("PLUS") == 0) || (symbol.compare("MINUS") == 0))
	{
		if (symbol.compare("MINUS") == 0)
		{
			flag = -1;
		}
		nextsym();
	}
	if (symbol.compare("NUMSY") == 0)
	{
		if (*pre1p != '0' || (p - pre1p)<2)
		{
			NUM = flag*num;
			//cout << "This is integer" << " in line " << line_num << endl;
			nextsym();
		}
		else
		{
			error(9);
			next_semi();
			flag_for_interger2const = 1;
		}
	}
	return NUM;
}

void constdefine()
{
	while (symbol.compare("CONSTSY") == 0)
	{
		nextsym();
		string type;
		if (symbol.compare("INTSY") == 0)
		{
			type = string("INTSY");
			nextsym();
			if (symbol.compare("IDSY") == 0)
			{
				string Name = string(IDNAME);
				nextsym();
				if (symbol.compare("EQUAL") == 0)
				{
					nextsym();
					int NUM = integer();
					if (flag_for_interger2const == 1)
					{
						continue;
					}
					insertsymboltable(Name, string("CONST"), type, NUM, false, 0, level, 0);
					ConstMidCode(string("CONST"), type, NUM, Name);
					/*cout << middlecode_list[midcode_length-1].op << " " 
						<< middlecode_list[midcode_length-1].ob1 << " " 
						<< middlecode_list[midcode_length-1].ob2 << " " 
						<< middlecode_list[midcode_length-1].ob3 << endl;*/
				}
				else
				{
					error(10);
					next_semi();
					continue;
				}
			}
			else
			{
				error(8);
				next_semi();
				continue;
			}
			int flag = 0;
			while (symbol.compare("COMMA") == 0)
			{
				nextsym();
				if (symbol.compare("IDSY") == 0)
				{
					string Name = string(IDNAME);
					nextsym();
					if (symbol.compare("EQUAL") == 0)
					{
						nextsym();
						int NUM = integer();
						if (flag_for_interger2const == 1)
						{
							continue;
						}
						insertsymboltable(Name, string("CONST"), type, NUM, false, 0, level, 0);
						ConstMidCode(string("CONST"), type, NUM, Name);
						/*cout << middlecode_list[midcode_length-1].op << " "
							<< middlecode_list[midcode_length-1].ob1 << " "
							<< middlecode_list[midcode_length-1].ob2 << " "
							<< middlecode_list[midcode_length-1].ob3 << endl;*/
					}
					else
					{
						error(10);
						flag = 1;
						break;
					}
				}
				else
				{
					error(8);
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				next_semi();
				continue;
			}
		}
		else if (symbol.compare("CHARSY") == 0)
		{
			type = string("CHARSY");
			nextsym();
			if (symbol.compare("IDSY") == 0)
			{
				string Name = string(IDNAME);
				nextsym();
				int ascii;
				if (symbol.compare("EQUAL") == 0)
				{
					nextsym();

					if (symbol.compare("CHARASCII") == 0)
					{
						ascii = singleCHAR;
						nextsym();
					}
					else
					{
						error(11);
						next_semi();
						continue;
					}
					insertsymboltable(Name, string("CONST"), type, ascii, false, 0, level, 0);
					ConstMidCode(string("CONST"), type, ascii, Name);
					/*cout << middlecode_list[midcode_length-1].op << " "
						<< middlecode_list[midcode_length-1].ob1 << " "
						<< middlecode_list[midcode_length-1].ob2 << " "
						<< middlecode_list[midcode_length-1].ob3 << endl;*/
				}
				else
				{
					error(10);
					next_semi();
					continue;
				}
			}
			else
			{
				error(8);
				next_semi();
				continue;
			}
			int flag = 0;
			while (symbol.compare("COMMA") == 0)
			{
				nextsym();
				if (symbol.compare("IDSY") == 0)
				{
					string Name = string(IDNAME);
					nextsym();
					int ascii;
					if (symbol.compare("EQUAL") == 0)
					{
						nextsym();
						if (symbol.compare("CHARASCII") == 0)
						{
							ascii = singleCHAR;

							nextsym();
						}
						else
						{
							error(11);
							flag = 1;
							break;
						}
						insertsymboltable(Name, string("CONST"), type, ascii, false, 0, level, 0);
						ConstMidCode(string("CONST"), type, ascii, Name);
						/*cout << middlecode_list[midcode_length-1].op << " "
							<< middlecode_list[midcode_length-1].ob1 << " "
							<< middlecode_list[midcode_length-1].ob2 << " "
							<< middlecode_list[midcode_length-1].ob3 << endl;*/
					}
					else
					{
						error(10);
						flag = 1;
						break;
					}
				}
				else
				{
					error(8);
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				next_semi();
				continue;
			}
		}
		else
		{
			error(6);
			next_semi();
			continue;
		}
		if (symbol.compare("SEMI") != 0)
		{
			error(12);
		}
		//cout << "This is const define!" << " in line " << line_num << endl;
		nextsym();
	}
}

void functiondefine()
{
	while ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0) || (symbol.compare("VOIDSY") == 0))
	{
		level++;
		string type = symbol;
		return_type = symbol;
		nextsym();
		if (symbol.compare("MAINSY") == 0)
		{
			recallsym();
			recallsym();
			level--;
			nextsym();
			return;
		}
		if (symbol.compare("IDSY") == 0)
		{
			string Name = string(IDNAME);
			nextsym();
			if (symbol.compare("LPAR") == 0)
			{
				nextsym();
				FstartMidCode();
				/*cout << middlecode_list[midcode_length - 1].op << " "
					<< middlecode_list[midcode_length - 1].ob1 << " "
					<< middlecode_list[midcode_length - 1].ob2 << " "
					<< middlecode_list[midcode_length - 1].ob3 << endl;*/
				LabelMidCode(Name);
				/*cout << middlecode_list[midcode_length - 1].op << " "
					<< middlecode_list[midcode_length - 1].ob1 << " "
					<< middlecode_list[midcode_length - 1].ob2 << " "
					<< middlecode_list[midcode_length - 1].ob3 << endl;*/
				int paranum = paratable();
				if (symbol.compare("RPAR") == 0)
				{
					nextsym();
					insertsymboltable(Name, string("FUNCTION"), type, -1, false, paranum, level - 1, 0);
					if (symbol.compare("LBRACE") != 0)
					{
						error(14);
						next_RBRACE();
						continue;
					}
				}
				else
				{
					error(15);
					next_RBRACE();
					continue;
				}
			}
			else
			{
				error(16);
				next_RBRACE();
				continue;
			}
		}
		else
		{
			error(8);
			next_RBRACE();
			continue;
		}
		next_LBRACE();
		compoundstatement();
		if (symbol.compare("RBRACE") != 0)
		{
			error(17);
			next_declare_head();
			continue;
		}
		deletefunction();
		FendMidCode();
		/*cout << middlecode_list[midcode_length - 1].op << " "
			<< middlecode_list[midcode_length - 1].ob1 << " "
			<< middlecode_list[midcode_length - 1].ob2 << " "
			<< middlecode_list[midcode_length - 1].ob3 << endl;*/
		//cout << "This is function define!" << " in line " << line_num << endl;
		nextsym();      /////////暂时放在上面两个之后
		level--;
		if ((return_flag == false) && (return_type.compare("VOIDSY") != 0))
		{
			error(18);
		}
		return_flag = false;
		return_expression = false;
	}
}

void mainfunction()
{
	level++;
	if (symbol.compare("VOIDSY") == 0)
	{
		return_type = symbol;
		nextsym();
		if (symbol.compare("MAINSY") == 0)
		{
			FstartMidCode();
			LabelMidCode(string("main"));
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			nextsym();
			insertsymboltable(string("main"), string("FUNCTION"), string("VOIDSY"), -1, false, 0, level - 1, 0);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			if (symbol.compare("LPAR") == 0)
			{
				nextsym();
				if (symbol.compare("RPAR") == 0)
				{
					nextsym();
					if (symbol.compare("LBRACE") != 0)
					{
						error(14);
					}
				}
				else
				{
					error(15);
				}
			}
			else
			{
				error(16);
			}
		}
		else
		{
			error(5);
		}
	}
	else
	{
		error(6);
	}
	next_LBRACE();
	compoundstatement();
	if (symbol.compare("RBRACE") != 0)
	{
		error(17);
	}
	deletefunction();
	FendMidCode();
	/*cout << middlecode_list[midcode_length - 1].op << " "
		<< middlecode_list[midcode_length - 1].ob1 << " "
		<< middlecode_list[midcode_length - 1].ob2 << " "
		<< middlecode_list[midcode_length - 1].ob3 << endl;*/
	//cout << "This main function!" << " in line " << line_num << endl;
	if ((return_flag == true) && (return_expression != false))
	{
		error(19);
	}
	return_flag = false;
	return_expression = false;
	level--;
}

void vardefine()
{
	while ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0))
	{
		string type = symbol;
		nextsym();
		if (symbol.compare("IDSY") == 0)
		{
			string Name = string(IDNAME);
			nextsym();
			if (symbol.compare("LBRACKET") == 0)
			{
				nextsym();
				if ((symbol.compare("NUMSY") == 0) && ((*pre1p) != '0'))
				{
					int Length = num;
					nextsym();
					if (symbol.compare("RBRACKET") != 0)
					{
						error(13);               //缺少]
						next_semi();
						continue;
					}
					insertsymboltable(Name, string("VAR"), type, 0, true, Length, level, 0);
					VarMidCode(type, Length, Name);
					/*cout << middlecode_list[midcode_length - 1].op << " "
						<< middlecode_list[midcode_length - 1].ob1 << " "
						<< middlecode_list[midcode_length - 1].ob2 << " "
						<< middlecode_list[midcode_length - 1].ob3 << endl;*/
					nextsym();
				}
				else
				{
					error(9);
					next_semi();
					continue;
				}
			}
			else if (symbol.compare("LPAR") == 0)
			{
				recallsym();
				recallsym();
				recallsym();
				nextsym();
				return;
			}
			else
			{
				insertsymboltable(Name, string("VAR"), type, 0, false, 0, level, 0);
				VarMidCode(type, 0, Name);
				/*cout << middlecode_list[midcode_length - 1].op << " "
					<< middlecode_list[midcode_length - 1].ob1 << " "
					<< middlecode_list[midcode_length - 1].ob2 << " "
					<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			}
		}
		else
		{
			error(8);
			nextsym();
			continue;
		}
		int flag = 0;
		while (symbol.compare("COMMA") == 0)
		{
			nextsym();
			if (symbol.compare("IDSY") == 0)
			{
				string Name = string(IDNAME);
				nextsym();
				if (symbol.compare("LBRACKET") == 0)
				{
					nextsym();
					if ((symbol.compare("NUMSY") == 0) && ((*pre1p) != '0'))
					{
						int Length = num;
						nextsym();
						if (symbol.compare("RBRACKET") != 0)
						{
							error(13);               //缺少]
							flag = 1;
							break;
						}
						insertsymboltable(Name, string("VAR"), type, 0, true, Length, level, 0);
						VarMidCode(type, Length, Name);
						/*cout << middlecode_list[midcode_length - 1].op << " "
							<< middlecode_list[midcode_length - 1].ob1 << " "
							<< middlecode_list[midcode_length - 1].ob2 << " "
							<< middlecode_list[midcode_length - 1].ob3 << endl;*/
						nextsym();
					}
					else
					{
						error(9);
						flag = 1;
						break;
					}
				}
				else
				{
					insertsymboltable(Name, string("VAR"), type, 0, false, 0, level, 0);
					VarMidCode(type, 0, Name);
					/*cout << middlecode_list[midcode_length - 1].op << " "
						<< middlecode_list[midcode_length - 1].ob1 << " "
						<< middlecode_list[midcode_length - 1].ob2 << " "
						<< middlecode_list[midcode_length - 1].ob3 << endl;*/
				}
			}
			else
			{
				error(8);
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			next_semi();
			continue;
		}
		if (symbol.compare("SEMI") != 0)
		{
			error(12);
		}
		//cout << "This is var define!" << " in line " << line_num << endl;
		nextsym();
	}
}

int paratable()
{
	int paranumber = 0;
	if ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0))
	{
		string type = symbol;
		nextsym();
		if (symbol.compare("IDSY") == 0)
		{
			string Name = string(IDNAME);
			insertsymboltable(Name, string("PARAMETER"), type, -1, false, 0, level, 0);
			ParaMidCode(type, Name);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			paranumber++;
			nextsym();
		}
		else
		{
			error(8);
		}
	}
	else if (symbol.compare("RPAR") == 0)
	{
		//cout << "This paratable!" << " in line " << line_num << endl;
		return paranumber;
	}
	else
	{
		error(6);
	}
	while (symbol.compare("COMMA") == 0)
	{
		nextsym();
		if ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0))
		{
			string type = symbol;
			nextsym();
			if (symbol.compare("IDSY") == 0)
			{
				string Name = string(IDNAME);
				insertsymboltable(Name, string("PARAMETER"), type, -1, false, 0, level, 0);
				ParaMidCode(type, Name);
				/*cout << middlecode_list[midcode_length - 1].op << " "
					<< middlecode_list[midcode_length - 1].ob1 << " "
					<< middlecode_list[midcode_length - 1].ob2 << " "
					<< middlecode_list[midcode_length - 1].ob3 << endl;*/
				paranumber++;
				nextsym();
			}
			else
			{
				error(8);
				break;
			}
		}
		else
		{
			error(6);
			break;
		}
	}
	next_RPAR();
	//cout << "This paratable!" << " in line " << line_num << endl;
	return paranumber;
}

void functioncall(bool return_not)       
{
	int realparanum = 0;
	if (symbol.compare("IDSY") == 0)
	{
		string Name = string(IDNAME);
		nextsym();
		if (symbol.compare("LPAR") == 0)
		{
			nextsym();
			if (symbol.compare("RPAR") == 0)
			{
				nextsym();
				//cout << "This function call!" << " in line " << line_num << endl;
				return;
			}
			expression();
			vector<string> realparalist_type;
			vector<string> realpara;
			realparalist_type.push_back(expression_type);
			realpara.push_back(operand);
			realparanum++;
			while (symbol.compare("COMMA") == 0)
			{
				nextsym();
				expression();
				realparalist_type.push_back(expression_type);
				realpara.push_back(operand);
				realparanum++;
			}
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				next_semi();
				return;
			}
			int func_index = getsymindex(Name, string("FUNCTION"));
			if (func_index == -1)
			{
				error(32);
				func_index = tablelength - 1;
			}
			if (symboltable[func_index].length != realparanum)
			{
				error(33);
			}
			if ((symboltable[func_index].type.compare("VOIDSY") == 0) && (return_not == true))
			{
				error(34);
			}
			for (int i = 0; i < realparanum; i++) /////////////////////////////////////////////////////////////
			{
				SetParaMidCode(realpara[i]);
				/*cout << middlecode_list[midcode_length - 1].op << " "
					<< middlecode_list[midcode_length - 1].ob1 << " "
					<< middlecode_list[midcode_length - 1].ob2 << " "
					<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			}
			nextsym();
			//cout << "This function call!" << " in line " << line_num << endl;
			return;
		}
		else
		{
			error(16);
			next_semi();
		}
	}
	else
	{
		error(5);
		next_semi();
	}
}

int expression()
{
	int result = 0;
	//int flag = 1;
	expression_type = string("INTSY");
	string ob1, ob2, ob3;
	if ((symbol.compare("PLUS") == 0) || (symbol.compare("MINUS") == 0))
	{
		if (symbol.compare("MINUS") == 0)
		{
			//flag = -1;
			nextsym();
			term();
			ob2 = operand;
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), string("INTSY"), 0, false, 0, level, 0);
			ExpressionMidCode(string("SUB"), string("0"), ob2, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
		}
		else
		{
			nextsym();
			term();
			ob3 = operand;
			operand = ob3;
		}
	}
	else
	{
		term();
		ob3 = operand;
		operand = ob3;
	}
	if (term_type.compare("CHARSY") == 0)
	{
		expression_type = string("CHARSY");
	}
	while ((symbol.compare("PLUS") == 0) || (symbol.compare("MINUS") == 0))
	{
		ob1 = ob3;
		expression_type = string("INTSY");
		if (symbol.compare("PLUS") == 0)
		{
			nextsym();
			term();
			ob2 = operand;
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), string("INTSY"), 0, false, 0, level, 0);
			ExpressionMidCode(string("ADD"), ob1, ob2, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
		}
		else
		{
			nextsym();
			term();
			ob2 = operand;
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), string("INTSY"), 0, false, 0, level, 0);
			ExpressionMidCode(string("SUB"), ob1, ob2, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
		}
	}
	//cout << "This expression!" << " in line " << line_num << endl;
	return result;
}

int term()
{
	term_type = string("INTSY");
	factor();
	string ob1, ob2, ob3;
	if (factor_type.compare("CHARSY") == 0)
	{
		term_type = string("CHARSY");
	}
	ob3 = operand;
	while ((symbol.compare("STAR") == 0) || (symbol.compare("DIVIDE") == 0))
	{
		term_type = string("INTSY");
		ob1 = ob3;
		if (symbol.compare("STAR") == 0)
		{
			nextsym();
			factor();
			ob2 = operand;
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), string("INTSY"), 0, false, 0, level, 0);
			ExpressionMidCode(string("MUL"), ob1, ob2, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
		}
		else if (symbol.compare("DIVIDE") == 0)
		{
			nextsym();
			factor();
			ob2 = operand;
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), string("INTSY"), 0, false, 0, level, 0);
			ExpressionMidCode(string("DIV"), ob1, ob2, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
		}
	}
	//cout << "This term!" << " in line " << line_num << endl;
	return 0;
}

int factor()
{
	factor_type = string("INTSY");
	string ob3;
	if (symbol.compare("IDSY") == 0)
	{
		string Name = string(IDNAME);
		nextsym();
		if (symbol.compare("LBRACKET") == 0)
		{
			nextsym();
			expression();
			if (symbol.compare("RBRACKET") != 0)
			{
				error(13);
			}
			int arr_index = getsymindex(Name, "VAR");
			if (arr_index == -1)
			{
				error(32);
				arr_index = tablelength - 1;
			}
			factor_type = symboltable[arr_index].type;
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), factor_type, 0, false, 0, level, 0);
			ExpressionMidCode(string("GETAR"), Name, operand, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
			nextsym();
			//cout << "This is factor" << " in line " << line_num << endl;
			return 1;
		}
		else if (symbol.compare("LPAR") == 0)
		{
			recallsym();
			recallsym();
			nextsym();
			int func_index = getsymindex(Name, string("FUNCTION"));
			if (func_index == -1)
			{
				error(32);
				func_index = tablelength - 1;
			}
			factor_type = symboltable[func_index].type;
			functioncall(true);
			stringstream temp_s;
			temp_s << tempvarnum++;
			ob3 = "TEMP" + temp_s.str();
			insertsymboltable(ob3, string("VAR"), factor_type, 0, false, 0, level, 0);
			CallReturnFunctionMidCode(Name, ob3);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			operand = ob3;
			//cout << "This is factor" << " in line " << line_num << endl;
			return 1;
		}
		else
		{
			int var_index = getsymindex(Name, string("VAR"));
			if (var_index == -1)
			{
				error(32);
				var_index = tablelength - 1;
			}
			operand = Name;
			//cout << "This is factor" << " in line " << line_num << endl;
			return 1;
		}
	}
	else if ((symbol.compare("PLUS") == 0) || (symbol.compare("MINUS") == 0) || (symbol.compare("NUMSY") == 0))
	{
		int NUM;
		NUM = integer();
		stringstream temp_s;
		temp_s << NUM;
		operand = temp_s.str();
		temp_s.str("");            //清空stringstream
		temp_s << tempvarnum++;
		ob3 = "TEMP" + temp_s.str();
		insertsymboltable(ob3, string("VAR"), string("INTSY"), 0, false, 0, level, 0);
		AssignmentMidCode(string("ASN"), operand, string(""), ob3);
		/*cout << middlecode_list[midcode_length - 1].op << " "
			<< middlecode_list[midcode_length - 1].ob1 << " "
			<< middlecode_list[midcode_length - 1].ob2 << " "
			<< middlecode_list[midcode_length - 1].ob3 << endl;*/
		operand = ob3;
		//cout << "This is factor" << " in line " << line_num << endl;
		return 1;
	}
	else if (symbol.compare("CHARASCII") == 0)
	{
		factor_type = string("CHARSY");
		char tempchar = singleCHAR;
		nextsym();
		stringstream temp_s;
		temp_s << (int)tempchar;
		operand = "\'" + temp_s.str() + "\'";
		temp_s.str("");
		temp_s << tempvarnum++;
		ob3 = "TEMP" + temp_s.str();
		insertsymboltable(ob3, string("VAR"), string("CHARSY"), 0, false, 0, level, 0);
		AssignmentMidCode(string("ASN"), operand, string(""), ob3);
		/*cout << middlecode_list[midcode_length - 1].op << " "
			<< middlecode_list[midcode_length - 1].ob1 << " "
			<< middlecode_list[midcode_length - 1].ob2 << " "
			<< middlecode_list[midcode_length - 1].ob3 << endl;*/
		operand = ob3;
		//cout << "This is factor" << " in line " << line_num << endl;
		return tempchar;
	}
	else if (symbol.compare("LPAR") == 0)
	{
		nextsym();
		if (symbol.compare("RPAR") == 0)
		{
			error(20);
			nextsym();
			return 0;
		}
		int e_value;
		e_value = expression();
		if (symbol.compare("RPAR") != 0)
		{
			error(15);
			nextsym();
			return 0;
		}
		factor_type = expression_type;
		nextsym();
		//cout << "This is factor" << " in line " << line_num << endl;
		return e_value;
	}
	else
	{
		error(21);           //////////////////////////////////////////////////////////////////
		nextsym();
		return 0;
	}
}

void compoundstatement()
{
	if (symbol.compare("CONSTSY") == 0)
	{
		constdefine();
	}
	if ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0))
	{
		vardefine();
	}
	statementlist();
}

void statementlist()
{
	while ((symbol.compare("IFSY") == 0) || (symbol.compare("DOSY") == 0) || (symbol.compare("SWITCHSY") == 0) ||
		(symbol.compare("LBRACE") == 0) || (symbol.compare("IDSY") == 0) || (symbol.compare("SCANFSY") == 0) ||
		(symbol.compare("PRINTSY") == 0) || (symbol.compare("SEMI") == 0) || (symbol.compare("RETURNSY") == 0))
	{
		statement();
		///////////////欠输出
	}
	//cout << "This is statementlist!" << " in line " << line_num << endl;
}

void statement()
{
	if (symbol.compare("IFSY") == 0)
	{
		conditionalstatement();
	}
	else if (symbol.compare("DOSY") == 0)
	{
		loopstatement();
	}
	else if (symbol.compare("SWITCHSY") == 0)
	{
		casestatement();
	}
	else if (symbol.compare("LBRACE") == 0)
	{
		nextsym();
		statementlist();
		if (symbol.compare("RBRACE") != 0)
		{
			error(17);
			recallsym();
		}
		nextsym();
	}
	else if (symbol.compare("IDSY") == 0)
	{
		string Name = string(IDNAME);
		nextsym();
		if (symbol.compare("LBRACKET") == 0)
		{
			recallsym();
			recallsym();
			nextsym();
			assignmentstatement();
			if (symbol.compare("SEMI") != 0)
			{
				error(12);
				recallsym();
			}
			nextsym();
		}
		else if (symbol.compare("LPAR") == 0)
		{
			recallsym();
			recallsym();
			nextsym();
			functioncall(false);
			CallFunctionMidcode(Name);
			/*cout << middlecode_list[midcode_length - 1].op << " "
				<< middlecode_list[midcode_length - 1].ob1 << " "
				<< middlecode_list[midcode_length - 1].ob2 << " "
				<< middlecode_list[midcode_length - 1].ob3 << endl;*/
			if (symbol.compare("SEMI") != 0)
			{
				error(12);
				recallsym();
			}
			nextsym();
		}
		else if (symbol.compare("EQUAL") == 0)
		{
			recallsym();
			recallsym();
			nextsym();
			assignmentstatement();
			if (symbol.compare("SEMI") != 0)
			{
				error(12);
				recallsym();
			}
			nextsym();
		}
		else
		{
			error(22);
			next_semi();
		}
	}
	else if (symbol.compare("SCANFSY") == 0)
	{
		readstatement();
		if (symbol.compare("SEMI") != 0)
		{
			error(12);
			recallsym();
		}
		nextsym();
	}
	else if (symbol.compare("PRINTSY") == 0)
	{
		writestatement();
		if (symbol.compare("SEMI") != 0)
		{
			error(12);
			recallsym();
		}
		nextsym();
	}
	else if (symbol.compare("RETURNSY") == 0)
	{
		returnstatement();
		if (symbol.compare("SEMI") != 0)
		{
			error(12);
			recallsym();
		}
		nextsym();
	}
	else if (symbol.compare("SEMI") == 0)
	{
		nextsym();
	}
	else
	{
		error(23);
		next_semi();
	}
}

/*void condition()
{
	////////////////
	////////////////
	///////////////
	expression();
	////////////
	/////////////
	/////////////
	if (symbol.compare("RPAR") == 0)
	{
		cout << "This is condition" << " in line " << line_num << endl;
		return;
	}
	else if ((symbol.compare("SMALLER") == 0) || (symbol.compare("SMALLEREQ") == 0) || (symbol.compare("BIGGER") == 0) ||
		(symbol.compare("BIGGEREQ") == 0) || (symbol.compare("NEQUAL") == 0) || (symbol.compare("REALEQ") == 0))
	{
		////////////////////
		////////////////////
		nextsym();
		expression();
		cout << "This is condition" << " in line " << line_num << endl;
	}
	else
	{
		error(24);
		next_statement();
	}
}*/

void conditionalstatement()
{
	if (symbol.compare("IFSY") == 0)
	{
		nextsym();
		string ob1;
		string ob2;
		string label;
		string compare_sym;
		if (symbol.compare("LPAR") == 0)
		{
			nextsym();
			expression();
			ob1 = operand;
			if (symbol.compare("RPAR") == 0)
			{
				stringstream temp_s;
				temp_s << label_num++;
				label = "label" + temp_s.str();
				JumpMidCode(string("JE"), ob1, string("0"), label);
			}
			else if ((symbol.compare("SMALLER") == 0) || (symbol.compare("SMALLEREQ") == 0) || (symbol.compare("BIGGER") == 0) ||
				(symbol.compare("BIGGEREQ") == 0) || (symbol.compare("NEQUAL") == 0) || (symbol.compare("REALEQ") == 0))
			{
				compare_sym = symbol;
				nextsym();
				expression();
				ob2 = operand;
				stringstream temp_s;
				temp_s << label_num++;
				label = "label" + temp_s.str();
				if (compare_sym.compare("SMALLER") == 0)
					JumpMidCode(string("JBE"), ob1, ob2, label);
				else if(compare_sym.compare("SMALLEREQ") == 0)
					JumpMidCode(string("JB"), ob1, ob2, label);
				else if (compare_sym.compare("BIGGER") == 0)
					JumpMidCode(string("JSE"), ob1, ob2, label);
				else if (compare_sym.compare("BIGGEREQ") == 0)
					JumpMidCode(string("JS"), ob1, ob2, label);
				else if (compare_sym.compare("NEQUAL") == 0)
					JumpMidCode(string("JE"), ob1, ob2, label);
				else if (compare_sym.compare("REALEQ") == 0)
					JumpMidCode(string("JNE"), ob1, ob2, label);
				//cout << "This is condition" << " in line " << line_num << endl;
			}
			else
			{
				error(24);
				next_statement();
			}
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				recallsym();
			}
			nextsym();
			statement();
			LabelMidCode(label);
			//cout << "This is conditional statement!" << " in line " << line_num << endl;
		}
		else
		{
			error(16);
			recallsym();
			nextsym();
			expression();
			ob1 = operand;
			if (symbol.compare("RPAR") == 0)
			{
				stringstream temp_s;
				temp_s << label_num++;
				label = "label" + temp_s.str();
				JumpMidCode(string("JE"), ob1, string("0"), label);
			}
			else if ((symbol.compare("SMALLER") == 0) || (symbol.compare("SMALLEREQ") == 0) || (symbol.compare("BIGGER") == 0) ||
				(symbol.compare("BIGGEREQ") == 0) || (symbol.compare("NEQUAL") == 0) || (symbol.compare("REALEQ") == 0))
			{
				compare_sym = symbol;
				nextsym();
				expression();
				ob2 = operand;
				stringstream temp_s;
				temp_s << label_num++;
				label = "label" + temp_s.str();
				if (compare_sym.compare("SMALLER") == 0)
					JumpMidCode(string("JBE"), ob1, ob2, label);
				else if (compare_sym.compare("SMALLEREQ") == 0)
					JumpMidCode(string("JB"), ob1, ob2, label);
				else if (compare_sym.compare("BIGGER") == 0)
					JumpMidCode(string("JSE"), ob1, ob2, label);
				else if (compare_sym.compare("BIGGEREQ") == 0)
					JumpMidCode(string("JS"), ob1, ob2, label);
				else if (compare_sym.compare("NEQUAL") == 0)
					JumpMidCode(string("JE"), ob1, ob2, label);
				else if (compare_sym.compare("REALEQ") == 0)
					JumpMidCode(string("JNE"), ob1, ob2, label);
				//cout << "This is condition" << " in line " << line_num << endl;
			}
			else
			{
				error(24);
				next_statement();
			}
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				recallsym();
			}
			nextsym();
			statement();
			LabelMidCode(label);
		}
	}
}

void loopstatement()
{
	//cout << "This is enter loop statement" << " in line " << line_num << endl;
	if (symbol.compare("DOSY") == 0)
	{
		string ob1;
		string ob2;
		string label_loop;
		//string label_break;
		string compare_sym;
		stringstream temp_s;
		temp_s << label_num++;
		label_loop = "label" + temp_s.str();
		LabelMidCode(label_loop);
		nextsym();
		statement();
		if (symbol.compare("WHILESY") == 0)
		{
			nextsym();
			if (symbol.compare("LPAR") == 0)
			{
				nextsym();
				expression();
				ob1 = operand;
				if (symbol.compare("RPAR") == 0)
				{
					JumpMidCode(string("JNE"), ob1, string("0"), label_loop);
				}
				else if ((symbol.compare("SMALLER") == 0) || (symbol.compare("SMALLEREQ") == 0) || (symbol.compare("BIGGER") == 0) ||
					(symbol.compare("BIGGEREQ") == 0) || (symbol.compare("NEQUAL") == 0) || (symbol.compare("REALEQ") == 0))
				{
					compare_sym = symbol;
					nextsym();
					expression();
					ob2 = operand;
					if (compare_sym.compare("SMALLER") == 0)
						JumpMidCode(string("JBE"), ob1, ob2, label_loop);
					else if (compare_sym.compare("SMALLEREQ") == 0)
						JumpMidCode(string("JB"), ob1, ob2, label_loop);
					else if (compare_sym.compare("BIGGER") == 0)
						JumpMidCode(string("JSE"), ob1, ob2, label_loop);
					else if (compare_sym.compare("BIGGEREQ") == 0)
						JumpMidCode(string("JS"), ob1, ob2, label_loop);
					else if (compare_sym.compare("NEQUAL") == 0)
						JumpMidCode(string("JE"), ob1, ob2, label_loop);
					else if (compare_sym.compare("REALEQ") == 0)
						JumpMidCode(string("JNE"), ob1, ob2, label_loop);
					//cout << "This is condition" << " in line " << line_num << endl;
				}
				else
				{
					error(24);
					next_statement();
				}
				if (symbol.compare("RPAR") != 0)
				{
					error(15);
					recallsym();
				}
				nextsym();
				//cout << "This is loop statement" << " in line " << line_num << endl;
			}
			else
			{
				error(16);
				next_statement();
				return;
			}
		}
		else
		{
			error(25);
			next_statement();
			return;
		}
	}
}

void casestatement()
{
	if (symbol.compare("SWITCHSY") == 0)
	{
		stringstream temp_s;
		temp_s << label_num++;
		string label_break;
		label_break = "label" + temp_s.str();
		temp_s.str("");
		string ob1;
		nextsym();
		if (symbol.compare("LPAR") == 0)
		{
			nextsym();
			expression();
			ob1 = operand;
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				next_LBRACE();
			}
			nextsym();
			if (symbol.compare("LBRACE") == 0)
			{
				nextsym();
				string label_case;
				if (symbol.compare("CASESY") == 0)
				{
					nextsym();
					string type;
					int case_value;
					temp_s.str("");
					temp_s << label_num++;
					label_case = "label" + temp_s.str();
					if ((symbol.compare("NUMSY") == 0) || (symbol.compare("PLUS") == 0) || (symbol.compare("MINUS") == 0))
					{
						type = string("INTSY");
						case_value = integer();
						temp_s.str("");
						temp_s << case_value;
						JumpMidCode(string("JNEI"), ob1, temp_s.str(), label_case);
						if (symbol.compare("COLON") == 0)
						{
							nextsym();
							statement();
							JumpMidCode(string("JUMP"), string(""), string(""), label_break);
							//cout << "This is one of case table" << " in line " << line_num << endl;
						}
						else
						{
							error(26);
							next_statement();
						}
					}
					else if (symbol.compare("CHARASCII") == 0)
					{
						char tempchar = singleCHAR;
						type = string("CHARSY");
						temp_s.str("");
						temp_s << tempchar;
						JumpMidCode(string("JNEC"), ob1, temp_s.str(), label_case);
						nextsym();
						if (symbol.compare("COLON") == 0)
						{
							nextsym();
							statement();
							JumpMidCode(string("JUMP"), string(""), string(""), label_break);
							//cout << "This is one of case table" << " in line " << line_num << endl;
						}
						else
						{
							error(26);
							next_statement();
						}
					}
					else
					{
						error(27);
					}
				}
				while (symbol.compare("CASESY") == 0)
				{
					LabelMidCode(label_case);
					string type;
					int case_value;
					temp_s.str("");
					temp_s << label_num++;
					label_case = "label" + temp_s.str();
					nextsym();
					if ((symbol.compare("NUMSY") == 0) || (symbol.compare("PLUS") == 0) || (symbol.compare("MINUS") == 0))
					{
						type = string("INTSY");
						case_value = integer();
						temp_s.str("");
						temp_s << case_value;
						JumpMidCode(string("JNEI"), ob1, temp_s.str(), label_case);
						if (symbol.compare("COLON") == 0)
						{
							nextsym();
							statement();
							JumpMidCode(string("JUMP"), string(""), string(""), label_break);
							//cout << "This is one of case table" << " in line " << line_num << endl;
						}
						else
						{
							error(26);
							next_statement();
						}
					}
					else if (symbol.compare("CHARASCII") == 0)
					{
						char tempchar = singleCHAR;
						type = string("CHARSY");
						temp_s.str("");
						temp_s << tempchar;
						JumpMidCode(string("JNEC"), ob1, temp_s.str(), label_case);
						nextsym();
						if (symbol.compare("COLON") == 0)
						{
							nextsym();
							statement();
							JumpMidCode(string("JUMP"), string(""), string(""), label_break);
							//cout << "This is one of case table" << " in line " << line_num << endl;
						}
						else
						{
							error(26);
							next_statement();
						}
					}
					else
					{
						error(27);
					}
				}
				if (symbol.compare("RBRACE") != 0)
				{
					error(17);
					next_statement();
				}
				LabelMidCode(label_break);
				nextsym();
				//cout << "This is case statement" << " in line " << line_num << endl;
			}
			else
			{
				error(14);
			}
		}
		else
		{
			error(16);
		}
	}
}

/*void casetable()
{
	if (symbol.compare("CASESY") == 0)
	{
		nextsym();
		if (symbol.compare("NUMSY") == 0)
		{
			/////////
			//////////
			if ((*pre1p == '0') && (p - pre1p>1))
			{
				error(9);
			}
			int NUM = num;
			//////////////////
			///////////////////
			nextsym();
			if (symbol.compare("COLON") == 0)
			{
				nextsym();
				statement();
				cout << "This is one of case table" << " in line " << line_num << endl;
			}
			else
			{
				error(26);
				next_statement();
			}
		}
		else if (symbol.compare("CHARASCII") == 0)
		{
			/////////
			//////////
			char tempchar = singleCHAR;
			//////////////////
			///////////////////
			nextsym();
			if (symbol.compare("COLON") == 0)
			{
				nextsym();
				statement();
				cout << "This is one of case table" << " in line " << line_num << endl;
			}
			else
			{
				error(26);
				next_statement();
			}
		}
		else
		{
			error(27);
		}
	}
	while (symbol.compare("CASESY") == 0)
	{
		nextsym();
		if (symbol.compare("NUMSY") == 0)
		{
			/////////
			//////////
			if ((*pre1p == '0') && (p - pre1p>1))
			{
				error(9);
			}
			int NUM = num;
			//////////////////
			///////////////////
			nextsym();
			if (symbol.compare("COLON") == 0)
			{
				nextsym();
				statement();
				cout << "This is one of case table" << " in line " << line_num << endl;
			}
			else
			{
				error(26);
				next_statement();
			}
		}
		else if (symbol.compare("CHARASCII") == 0)
		{
			/////////
			//////////
			char tempchar = singleCHAR;
			//////////////////
			///////////////////
			nextsym();
			if (symbol.compare("COLON") == 0)
			{
				nextsym();
				statement();
				cout << "This is one of case table" << " in line " << line_num << endl;
			}
			else
			{
				error(26);
				next_statement();
			}
		}
		else
		{
			error(27);
		}
	}
}*/

void assignmentstatement()
{
	if (symbol.compare("IDSY") == 0)
	{
		string Name = string(IDNAME);
		nextsym();
		if (symbol.compare("LBRACKET") == 0)
		{
			int arr_index = getsymindex(Name, string("VAR"));
			if (arr_index == -1)
			{
				error(32);
				arr_index = tablelength - 1;
			}
			nextsym();
			expression();
			string index = operand;
			if (symbol.compare("RBRACKET") != 0)
			{
				error(13);
				recallsym();
			}
			nextsym();
			if (symbol.compare("EQUAL") != 0)
			{
				error(28);
				recallsym();
			}
			nextsym();
			expression();
			AssignmentMidCode(string("ASNAR"), operand, index, Name);
			//cout << "This is array assign statement" << " in line " << line_num << endl;
		}
		else if (symbol.compare("EQUAL") == 0)
		{
			int var_index = getsymindex(Name, string("VAR"));
			if (var_index == -1)
			{
				error(32);
				var_index = tablelength - 1;
			}
			if (symboltable[var_index].kind.compare("CONST") == 0)
			{
				error(35);
			}
			nextsym();
			expression();
			AssignmentMidCode(string("ASN"), operand, string(""), Name);
			//cout << "This is assign satement" << " in line " << line_num << endl;
		}
		else
		{
			error(29);
		}
	}
}

void readstatement()
{
	if (symbol.compare("SCANFSY") == 0)
	{
		nextsym();
		if (symbol.compare("LPAR") == 0)
		{
			nextsym();
			string Name;
			if (symbol.compare("IDSY") == 0)
			{
				Name = string(IDNAME);
				int index = getsymindex(Name, string("VAR"));
				if (index == -1)
				{
					error(32);
					index = tablelength - 1;
				}
				ScanfMidCode(Name);
				nextsym();
			}
			else
			{
				error(8);
				next_semi();
				return;
			}
			while (symbol.compare("COMMA") == 0)
			{
				nextsym();
				if (symbol.compare("IDSY") == 0)
				{
					Name = string(IDNAME);
					int index = getsymindex(Name, string("VAR"));
					if (index == -1)
					{
						error(32);
						index = tablelength - 1;
					}
					ScanfMidCode(Name);
					nextsym();

				}
				else
				{
					error(8);
					next_semi();
					return;
				}
			}
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				next_semi();
				return;
			}
			nextsym();
			//cout << "This is read statement" << " in line " << line_num << endl;
		}
		else
		{
			error(16);
			next_semi();
			return;
		}
	}
}

void writestatement()
{
	if (symbol.compare("PRINTSY") == 0)
	{
		nextsym();
		if (symbol.compare("LPAR") == 0)
		{
			nextsym();
			if (symbol.compare("STRINGSY") == 0)
			{
				nextsym();
				if (symbol.compare("COMMA") == 0)
				{
					nextsym();
					expression();
					PrintfMidCode(string(stringCHAR), operand);
				}
				else
				{
					PrintfMidCode(string(stringCHAR), string(""));
				}
			}
			else
			{
				expression();
				PrintfMidCode(string(""), operand);
			}
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				recallsym();
			}
			nextsym();
			//cout << "This is write statement！" << " in line " << line_num << endl;
		}
		else
		{
			error(16);
			next_semi();
			return;
		}
	}
}

void returnstatement()
{
	if (symbol.compare("RETURNSY") == 0)
	{
		nextsym();
		return_flag = true;
		if (symbol.compare("LPAR") == 0)
		{
			if (return_type.compare("VOIDSY") == 0)
			{
				error(34);
			}
			nextsym();
			expression();
			ReturnMidCode(operand);
			return_expression = true;
			if (symbol.compare("RPAR") != 0)
			{
				error(15);
				recallsym();
			}
			nextsym();
			//cout << "This is return statement" << " in line " << line_num << endl;
		}
		/*else if (symbol.compare("SEMI") == 0)
		{

			//cout << "This is return statement" << " in line " << line_num << endl;
			return;
		}*/
		else
		{
			ReturnMidCode(string(""));
			if (return_type.compare("VOIDSY") != 0)
				error(18);
			return;
		}
	}
}
//＜程序＞    ::= ［＜常量说明＞］［＜变量说明＞］{＜有返回值函数定义＞|＜无返回值函数定义＞}＜主函数＞
//＜常量说明＞ ::=  const＜常量定义＞;{ const＜常量定义＞;}
//＜常量定义＞   ::=   int＜标识符＞＝＜整数＞{,＜标识符＞＝＜整数＞}
//                       | char＜标识符＞＝＜字符＞{,＜标识符＞＝＜字符＞}
//＜有返回值函数定义＞  ::=  ＜声明头部＞‘(’＜参数表＞‘)’ ‘{’＜复合语句＞‘}’
//＜无返回值函数定义＞  ::= void＜标识符＞‘(’＜参数表＞‘)’‘{’＜复合语句＞‘}’

//＜主函数＞    ::= void main‘(’‘)’ ‘{’＜复合语句＞‘}’

void program()         //程序的语法如上
{
	Ch = *p;
	nextsym();
	while (1)
	{
		if (symbol.compare("CONSTSY") == 0)
		{
			constdefine();
		}
		if ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0))
		{
			nextsym();
			if (symbol.compare("IDSY") == 0)
			{
				nextsym();
				if (symbol.compare("LPAR") == 0)
				{
					recallsym();
					recallsym();
					recallsym();
					nextsym();
					functiondefine();
					mainfunction();
					return;
				}
				else if ((symbol.compare("COMMA") == 0) || (symbol.compare("SEMI") == 0) || (symbol.compare("LBRACKET") == 0))
				{
					recallsym();
					recallsym();
					recallsym();
					nextsym();
					vardefine();
					if ((symbol.compare("INTSY") == 0) || (symbol.compare("CHARSY") == 0))
					{
						functiondefine();
						mainfunction();
						return;
					}
					else if (symbol.compare("VOIDSY") == 0)
					{
						nextsym();
						if (symbol.compare("MAINSY") == 0)
						{
							recallsym();
							recallsym();
							nextsym();
							mainfunction();
							return;
						}
						else if (symbol.compare("IDSY") == 0)
						{
							recallsym();
							recallsym();
							nextsym();
							functiondefine();
							mainfunction();
							return;
						}
						else
						{
							error(5);
							next_declare_head();
							continue;
						}
					}
					else
					{
						error(6);
						next_declare_head();
						continue;
					}
				}
				else
				{
					error(7);
					next_declare_head();
					continue;
				}

			}
			else
			{
				error(8);
				next_declare_head();
				continue;
			}
		}
		else if (symbol.compare("VOIDSY") == 0) /////////////////////
		{
			nextsym();
			if (symbol.compare("MAINSY") == 0)
			{
				recallsym();
				recallsym();
				nextsym();
				mainfunction();
				return;
			}
			else if (symbol.compare("IDSY") == 0)
			{
				recallsym();
				recallsym();
				nextsym();
				functiondefine();
				mainfunction();
				return;
			}
			else
			{
				error(5);
				next_declare_head();
				continue;
			}
		}
		else         //////////////////
		{
			error(6);
			next_declare_head();
			continue;
		}
	}
}

