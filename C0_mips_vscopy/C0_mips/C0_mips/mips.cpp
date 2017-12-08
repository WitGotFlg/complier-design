#include "stdafx.h"
#include "global.h"

using namespace std;
vector<mipsele> mipssymboltable;
int mipstablelength = 0;

ofstream mipsfile;
map<string, string>REGISTER;

int mipslevel = 0;

void insertmipssymboltable(string name, string type, string length, int level)
{
	mipsele mipsc;
	mipsc.name = name;
	mipsc.type = type;
	mipsc.length = length;
	stringstream temp_s;
	temp_s << level;
	mipsc.level = temp_s.str();
	mipssymboltable.push_back(mipsc);
	mipstablelength++;
}

void defineGlobalMIPS(string name,string value,string length)
{
	if (length.compare("0") == 0)
	{
		mipsfile << name << ": .word " << value << endl;
	}
	else
	{
		mipsfile << name << ": .word 0:" << length << endl;
	}
}

int getMIPSindex(string name)          //getMIPSlocation
{
	int i = mipstablelength - 1;
	while (i >= 0)
	{
		if (mipssymboltable[i].name.compare(name) == 0)
		{
			break;
		}
		i--;
	}
	return i;
}

string getaddress(string name)      //得到变量在栈中与fp的相对地址
{
	int index = getMIPSindex(name);
	int addr = 0;            //有多少变量
	string temp_level;
	int i = index - 1;
	while (i >= 0)
	{
		temp_level = mipssymboltable[i].level;
		if (temp_level.compare("1") != 0)
			break;
		if (mipssymboltable[i].length.compare("0") == 0)
			addr++;
		else
			addr = addr + atoi(mipssymboltable[i].length.c_str());
	}
	addr = addr * 4;   //四字节一个变量
	stringstream temp_s;
	temp_s << addr;
	return temp_s.str();
}

void defineMIPS(string name, string value)      //fp为此时的函数运行起始地址，sw将变量的值保存到fp后addr的地址中
{
	mipsfile << "addi $t0,$zero," << value;
	string addr = getaddress(name);
	mipsfile << "addi $t1,$fp,-" << addr << endl;
	mipsfile << "sw $t0,0($t1)" << endl;
}


void mips_generate()
{
	
	mipsfile.open("object_code.asm");
	mipsfile << ".data" << endl;
	bool mainflag = false;
	bool txtflag = false;
	int i = 0;
	while (i < midcode_length)
	{
		if (middlecode_list[i].op.compare("CONST") == 0)
		{
			if (REGISTER.find(middlecode_list[i].ob3) != REGISTER.end())//如果发现分配了全局寄存器
			{
				mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << "," << "$zero" << "," << middlecode_list[i].ob2 << endl;
			}
			if (mipslevel == 0)
			{
				insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].ob1, string("0"), mipslevel);
				defineGlobalMIPS(middlecode_list[i].ob3, middlecode_list[i].ob2, string("0"));
			}
			else
			{
				insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].ob1, string("0"), mipslevel);
				defineMIPS(middlecode_list[i].ob3, middlecode_list[i].ob2);
			}
		}
		//////////////////////////////////////////////////////////
		i++;
	}
}