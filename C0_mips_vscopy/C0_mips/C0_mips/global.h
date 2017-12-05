#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
void readCodeFile();

extern char *p;  //用于与code[]进行交互，初始化为code

extern char Token[100];  //存放单词字符串
extern int token_count; //token计数器
extern char Ch; //存放当前读入的字符
extern char IDNAME[100];
extern char singleCHAR; //用于存放当读到‘c’单个字符的情况
extern char singleC[5];  //专门用于方便词法分析程序输出的
extern char stringCHAR[100];   //在本程序中，将单字符和字符串的‘和”也放在了单词中，因为只有这个地方出现了，所以不会对其他语法造成影响
extern int num; //存放当前读入的整型数值
extern string symbol;
extern int line_num;               //记录行数用于错误处理
extern char linebuf[100];              //行缓冲
extern int line_count;
extern int endNum;
extern map<string, int>symcode;
extern map<string, string>symvalue;

extern char* pre1p;
extern char* pre2p;
extern char* pre3p;        //定义于syntax

int Getchar();
int getsym();
int error(int e);
void recallsym();
void nextsym();
int clearToken();

extern int flag_for_interger2const;
extern int level;
extern bool return_flag;
extern bool return_expression;
extern string return_type;

int integer();
void constdefine();
void functiondefine();
void mainfunction();
void vardefine();
int paratable();
void functioncall();
int expression();
int term();
int factor();
void compoundstatement();
void statementlist();
void statement();
void condition();
void conditionalstatement();
void loopstatement();
void casestatement();
void casetable();
void assignmentstatement();
void readstatement();
void writestatement();
void returnstatement();
void program();

typedef struct symnode
{
	string name;
	string kind;           //const，var....
	string type;           //int char string...
	int value;
	bool arr;
	int length;
	int level;
	int depth;
}symele;
extern vector<symele> symboltable;

extern int tablelength;
extern int procedure_num;
extern int procedure_end_index[100];

int checkname(string name, int level);
void insertsymboltable(string name, string kind, string type, int value, bool arr, int length, int level, int depth);
int getsymindex(string name,string kind);
void deletefunction();

extern string operand;
extern string expression_type;
extern string term_type;
extern string factor_type;
extern int label_num;
extern int error_num;

typedef struct middle
{
	string op;
	string ob1;
	string ob2;
	string ob3;
}midcode;

extern int midcode_length;
extern vector<midcode> middlecode_list;

void ConstMidCode(string op, string type, int num, string name);
void VarMidCode(string type, int length, string name);
void FunctionMidCode(string name);
void ParaMidCode(string type, string name);
void SetParaMidCode(string t_para);
void CallReturnFunctionMidCode(string name, string V);
void CallFunctionMidcode(string name);
void ExpressionMidCode(string op, string ob1, string ob2, string V);
void AssignmentMidCode(string op, string ob1, string ob2, string ob3);
void JumpMidCode(string op, string ob1, string ob2, string label);
void LabelMidCode(string label);
void ScanfMidCode(string name);
void PrintfMidCode(string str, string name);
void ReturnMidCode(string name);
void FstartMidCode();
void FendMidCode();

#endif // GLOBAL_H_INCLUDED
