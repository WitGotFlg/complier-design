#include "global.h"

int midcode_length = 0;
vector<midcode> middlecode_list;

void ConstMidCode(string op, string type, int num, string name)
{
	midcode code;
	code.op = op;
	code.ob1 = type;
	stringstream s_num;
	s_num << num;
	code.ob2 = s_num.str();
	code.ob3 = name;
	middlecode_list.push_back(code);
	midcode_length ++;
}

void VarMidCode(string type, int length, string name)
{
	midcode code;
	code.op = type;
	code.ob1 = "";
	if (length != 0)
	{
		stringstream s_length;
		s_length << length;
		code.ob2 = s_length.str();
	}
	else
	{
		code.ob2 = "";
	}
	code.ob3 = name;
	middlecode_list.push_back(code);
	midcode_length++;
}

void FunctionMidCode(string name)
{
	midcode code;
	code.op = "LABEL";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = name;
	middlecode_list.push_back(code);
	midcode_length++;
}

void ParaMidCode(string type, string name)
{
	midcode code;
	code.op = "PARA";
	code.ob1 = type;
	code.ob2 = "";
	code.ob3 = name;
	middlecode_list.push_back(code);
	midcode_length++;
}

void SetParaMidCode(string t_para)
{
	midcode code;
	code.op = "PUSH";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = t_para;
	middlecode_list.push_back(code);
	midcode_length++;
}

void CallReturnFunctionMidCode(string name, string V)
{
	midcode code;
	code.op = "RCALL";
	code.ob1 = name;
	code.ob2 = "";
	code.ob3 = V;
	middlecode_list.push_back(code);
	midcode_length++;
}

void CallFunctionMidcode(string name)
{
	midcode code;
	code.op = "CALL";
	code.ob1 = name;
	code.ob2 = "";
	code.ob3 = "";
	middlecode_list.push_back(code);
	midcode_length++;
}

void ExpressionMidCode(string op, string ob1, string ob2, string V)
{
	midcode code;
	code.op = op;
	code.ob1 = ob1;
	code.ob2 = ob2;
	code.ob3 = V;
	middlecode_list.push_back(code);
	midcode_length++;
}

void AssignmentMidCode(string op, string ob1, string ob2, string ob3)
{
	midcode code;
	code.op = op;
	code.ob1 = ob1;
	code.ob2 = ob2;
	code.ob3 = ob3;
	middlecode_list.push_back(code);
	midcode_length++;
}

void JumpMidCode(string op,string ob1,string ob2,string label)
{
	midcode code;
	code.op = op;
	code.ob1 = ob1;
	code.ob2 = ob2;
	code.ob3 = label;
	middlecode_list.push_back(code);
	midcode_length++;
}

void LabelMidCode(string label)
{
	midcode code;
	code.op = "LABEL";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = label;
	middlecode_list.push_back(code);
	midcode_length++;
}

void ScanfMidCode(string name)
{
	midcode code;
	code.op = "SCANF";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = name;
	middlecode_list.push_back(code);
	midcode_length++;
}

void PrintfMidCode(string str, string name)
{
	midcode code;
	code.op = "PRINTF";
	code.ob1 = str;
	code.ob2 = name;
	code.ob3 = "";
	middlecode_list.push_back(code);
	midcode_length++;
}

void ReturnMidCode(string name)
{
	midcode code;
	code.op = "RETURN";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = name;
	middlecode_list.push_back(code);
	midcode_length++;
}

void FstartMidCode()
{
	midcode code;
	code.op = "FSTART";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = "";
	middlecode_list.push_back(code);
	midcode_length++;
}

void FendMidCode()
{
	midcode code;
	code.op = "FEND";
	code.ob1 = "";
	code.ob2 = "";
	code.ob3 = "";
	middlecode_list.push_back(code);
	midcode_length++;
}
