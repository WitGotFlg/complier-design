#include "global.h"

int tablelength = 0;
int procedure_num = 0;
int procedure_end_index[100];


vector<symele> symboltable;

int checkname(string name,int level)
{
	for (int i = tablelength - 1; i >= 0; i--)
	{
		if ((symboltable[i].name.compare(name)==0) && (symboltable[i].level == level))
			return 0;
	}
	return 1;
}

void insertsymboltable(string name, string kind,string type,int value,bool arr,int length,int level,int depth)
{
	if (checkname(name,level))
	{
		symele new_sym;
		new_sym.name = name;
		new_sym.kind = kind;
		new_sym.type = type;
		new_sym.value = value;
		new_sym.arr = arr;
		new_sym.length = length;
		new_sym.depth = depth;
		symboltable.push_back(new_sym);
		tablelength++;
		if (kind.compare("FUNCTION") == 0)
		{
			for (int i = 0; i < length; i++)
			{
				swap(symboltable[tablelength - 1 - i], symboltable[tablelength - 2 - i]);
			}
			if (procedure_num < 100)
				procedure_end_index[procedure_num++] = tablelength - length;
			else
				error(31);
		}
	}
	else
	{
		error(30);
		return;
	}
}

int getsymindex(string name,string kind)
{
	if (kind.compare("FUNCTION") == 0)
	{
		for (int i = tablelength - 1; i >= 0; i--)
		{
			if ((symboltable[i].name.compare(name) == 0) && (symboltable[i].kind.compare("FUNCTION") == 0))
				return i;
		}
	}
	else
	{
		for (int i = tablelength - 1; i >= 0; i--)
		{
			if ((symboltable[i].name.compare(name) == 0) && (symboltable[i].kind.compare("FUNCTION") != 0))
				return i;
		}
	}
	return -1;
}

void deletefunction()
{
	int after_length = procedure_end_index[--procedure_num];
	int stack_depth = 0;
	while (after_length < symboltable.size())
	{
		if (symboltable[after_length].length == 0)
			stack_depth++;
		else
			stack_depth = stack_depth + symboltable[after_length].length;
		symboltable.erase(symboltable.begin() + after_length);
	}
	stack_depth = 4 * stack_depth;
	symboltable[after_length - 1].depth = stack_depth;
	tablelength = after_length;
}


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
		i--;
	}
	addr = addr * 4;   //四字节一个变量
	stringstream temp_s;
	temp_s << addr;
	return temp_s.str();
}
