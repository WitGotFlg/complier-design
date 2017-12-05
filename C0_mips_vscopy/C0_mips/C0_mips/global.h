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

extern char *p;  //������code[]���н�������ʼ��Ϊcode

extern char Token[100];  //��ŵ����ַ���
extern int token_count; //token������
extern char Ch; //��ŵ�ǰ������ַ�
extern char IDNAME[100];
extern char singleCHAR; //���ڴ�ŵ�������c�������ַ������
extern char singleC[5];  //ר�����ڷ���ʷ��������������
extern char stringCHAR[100];   //�ڱ������У������ַ����ַ����ġ��͡�Ҳ�����˵����У���Ϊֻ������ط������ˣ����Բ���������﷨���Ӱ��
extern int num; //��ŵ�ǰ�����������ֵ
extern string symbol;
extern int line_num;               //��¼�������ڴ�����
extern char linebuf[100];              //�л���
extern int line_count;
extern int endNum;
extern map<string, int>symcode;
extern map<string, string>symvalue;

extern char* pre1p;
extern char* pre2p;
extern char* pre3p;        //������syntax

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
	string kind;           //const��var....
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
