#include "global.h"

using namespace std;
vector<mipsele> mipssymboltable;
int mipstablelength = 0;

ofstream mipsfile;
map<string, string>REGISTER;

int mipslevel = 0;
int stringcount = 0;
//int register_used = 0;

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

void defineMIPS(string name, string value)      //fp为此时的函数运行起始地址，sw将变量的值保存到fp后addr的地址中
{
	mipsfile << "addi $t0,$zero," << value <<endl;
	string addr = getaddress(name);
	//mipsfile << "addi $t1,$fp,-" << addr << endl;
	mipsfile << "sw $t0,-" << addr << "($fp)" << endl;
}

void returnMIPS()
{
	mipsfile << "addi $sp,$fp,76" << endl;//返回上一层函数的sp值
	mipsfile << "lw $fp,-68($sp)" << endl;//返回上一层函数的fp值
	mipsfile << "lw $ra,-72($sp)" << endl;//将返回后指令的地址重新加载入ra
	mipsfile << "lw $s0,0($sp)" << endl;
	mipsfile << "lw $s1,-4($sp)" << endl;
	mipsfile << "lw $s2,-8($sp)" << endl;
	mipsfile << "lw $s3,-12($sp)" << endl;
	mipsfile << "lw $s4,-16($sp)" << endl;
	mipsfile << "lw $s5,-20($sp)" << endl;
	mipsfile << "lw $s6,-24($sp)" << endl;
	mipsfile << "lw $s7,-28($sp)" << endl;
	//////////////////////////////////////////
	mipsfile << "lw $t4,-32($sp)" << endl;
	mipsfile << "lw $t5,-36($sp)" << endl;
	mipsfile << "lw $t6,-40($sp)" << endl;
	mipsfile << "lw $t7,-44($sp)" << endl;
	mipsfile << "lw $t8,-48($sp)" << endl;
	mipsfile << "lw $t9,-52($sp)" << endl;
	mipsfile << "lw $a1,-56($sp)" << endl;
	mipsfile << "lw $a2,-60($sp)" << endl;
	mipsfile << "lw $a3,-64($sp)" << endl;
	/////////////////////////////////////
	mipsfile << "jr $ra" << endl;
}

void savestackMIPS()
{
	mipsfile << "sw $s0,0($sp)" << endl;
	mipsfile << "sw $s1,-4($sp)" << endl;
	mipsfile << "sw $s2,-8($sp)" << endl;
	mipsfile << "sw $s3,-12($sp)" << endl;
	mipsfile << "sw $s4,-16($sp)" << endl;
	mipsfile << "sw $s5,-20($sp)" << endl;
	mipsfile << "sw $s6,-24($sp)" << endl;
	mipsfile << "sw $s7,-28($sp)" << endl;
	//////////////////////////////////////////
	mipsfile << "sw $t4,-32($sp)" << endl;
	mipsfile << "sw $t5,-36($sp)" << endl;
	mipsfile << "sw $t6,-40($sp)" << endl;
	mipsfile << "sw $t7,-44($sp)" << endl;
	mipsfile << "sw $t8,-48($sp)" << endl;
	mipsfile << "sw $t9,-52($sp)" << endl;
	mipsfile << "sw $a1,-56($sp)" << endl;
	mipsfile << "sw $a2,-60($sp)" << endl;
	mipsfile << "sw $a3,-64($sp)" << endl;
	////////////////////////////////////////////
	mipsfile << "sw $fp,-68($sp)" << endl;
	mipsfile << "sw $fp,-68($sp)" << endl;
	mipsfile << "addi $sp,$sp,-76" << endl;
}

void calculateMIPS(string op,string ob1,string ob2,string ob3)
{
	string cal1, cal2, cal3;
	string ob3_addr;
	int index;
	if (REGISTER.find(ob1) != REGISTER.end())
	{
		cal1 = REGISTER[ob1];
	}
	else
	{
	/*	if (register_used < 8)
		{
			stringstream temp_s;
			temp_s << register_used;
			REGISTER.insert(make_pair(ob1, "$s" + temp_s.str()));
			register_used++;
			cal1 = REGISTER[ob1];
		}*/
		index = getMIPSindex(ob1);
		if (index == -1)
		{
			mipsfile << "addi $t0,$zero," << ob1 << endl;
		}
		else
		{
			if (mipssymboltable[index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << mipssymboltable[index].name << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
			}
			else
			{
				string addr = getaddress(ob1);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
			}
		}
		cal1 = string("$t0");
	}
	if (REGISTER.find(ob2) != REGISTER.end())
	{
		cal2 = REGISTER[ob2];
	}
	else
	{
	/*	if (register_used < 8)
		{
			stringstream temp_s;
			temp_s << register_used;
			REGISTER.insert(make_pair(ob2, "$s" + temp_s.str()));
			register_used++;
			cal2 = REGISTER[ob2];
		}*/
		index = getMIPSindex(ob2);
		if (index == -1)
		{
			mipsfile << "addi $t1,$zero," << ob2 << endl;
		}
		else
		{
			if (mipssymboltable[index].level.compare("0") == 0)
			{
				mipsfile << "la $t1," << mipssymboltable[index].name << endl;
				mipsfile << "lw $t1,0($t1)" << endl;
			}
			else
			{
				string addr = getaddress(ob2);
				//mipsfile << "addi $t1,$fp,-" << addr << endl;
				mipsfile << "lw $t1,-" << addr << "($fp)" << endl;
			}
		}
		cal2 = string("$t1");
	}
	if (REGISTER.find(ob3) != REGISTER.end())
	{
		cal3 = REGISTER[ob3];
	}
	else
	{
		index = getMIPSindex(ob3);
		if (index == -1)
		{
			insertmipssymboltable(ob3, string("INTSY"), string("0"), mipslevel);
			index = getMIPSindex(ob3);
		}
		if (mipssymboltable[index].level.compare("0") == 0)
		{
			mipsfile << "la $t2," << mipssymboltable[index].name << endl;
		}
		else
		{
			ob3_addr = getaddress(ob3);
			//mipsfile << "addi $t2,$fp,-" << addr << endl;              //$t2中保存着ob3的保存地址
		}
		cal3 = string("$t3");                       //t3保存算出来的值
	}
	if (op.compare("ADD") == 0)
	{
		mipsfile << "add " << cal3 << "," << cal1 << "," << cal2 << endl;
	}
	else if (op.compare("SUB") == 0)
	{
		mipsfile << "sub " << cal3 << "," << cal1 << "," << cal2 << endl;
	}
	else if (op.compare("MUL") == 0)
	{
		mipsfile << "mult " << cal1 << "," << cal2 << endl;
		mipsfile << "mflo " << cal3 << endl;
	}
	else
	{
		mipsfile << "div " << cal1 << "," << cal2 << endl;
		mipsfile << "mflo " << cal3 << endl;
	}
	if (REGISTER.find(ob3) == REGISTER.end())
	{
		mipsfile << "sw $t3,-" << ob3_addr << "($fp)" << endl;
	}
}

void assignarrMIPS(string ob1, string ob2, string ob3)
{
	if (REGISTER.find(ob2) != REGISTER.end())
	{
		mipsfile << "addi $t1,$zero,4" << endl;
		mipsfile << "mult " << REGISTER[ob2] << ",$t1" << endl;
		mipsfile << "mflo $t0" << endl;
	}
	else
	{
		int ob2_index = getMIPSindex(ob2);
		if (ob2_index == -1)
		{
			mipsfile << "addi $t1,$zero,4" << endl;
			mipsfile << "addi $t0,$zero," << ob2 << endl;
			mipsfile << "mult $t0,$t1" << endl;
			mipsfile << "mflo $t0" << endl;
		}
		else
		{
			if (mipssymboltable[ob2_index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << ob2 << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
				mipsfile << "addi $t1,$zero,4" << endl;
				mipsfile << "mult $t0,$t1" << endl;
				mipsfile << "mflo $t0" << endl;
			}
			else
			{
				string addr = getaddress(ob2);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				//cout << "~~~~~~~~~~~~~~~" << addr <<"!!!!!!!!!!!!!!!!!!!!!" <<endl;
				mipsfile << "lw $t0,,-" << addr << "($fp)" << endl;
				mipsfile << "addi $t1,$zero,4" << endl;
				mipsfile << "mult $t0,$t1" << endl;
				mipsfile << "mflo $t0" << endl;
			}
		}
	}
	int ob3_index = getMIPSindex(ob3);
	if (mipssymboltable[ob3_index].level.compare("0") == 0)
	{
		mipsfile << "la $t1," << ob3 << endl;
		mipsfile << "add $t0,$t1,$t0" << endl;
	}
	else
	{
		string addr = getaddress(ob3);
		mipsfile << "addi $t1,$fp,-" << addr << endl;
		mipsfile << "sub $t0,$t1,$t0" << endl;
	}
	if (REGISTER.find(ob1) != REGISTER.end())
	{
		mipsfile << "sw " << REGISTER[ob1] << ",0($t0)" << endl;
	}
	else
	{
		int ob1_index = getMIPSindex(ob1);
		if (ob1_index == -1)                  //可能是单个字符或数字
		{
			mipsfile << "addi $t1,$zero," << ob1 << endl;
		}
		else
		{
			if (mipssymboltable[ob1_index].level.compare("0") == 0)
			{
				mipsfile << "la $t1," << ob1 << endl;
				mipsfile << "lw $t1,0($t1)" << endl;
			}
			else
			{
				string addr = getaddress(ob1);
				//mipsfile << "addi $t1,$fp,-" << addr << endl;
				mipsfile << "lw $t1,,-" << addr << "($fp)" << endl;
			}
		}
		mipsfile << "sw $t1,0($t0)" << endl;
	}
}

void getarrMIPS(string ob1, string ob2, string ob3)
{
	if (REGISTER.find(ob2) != REGISTER.end())
	{
		mipsfile << "addi $t1,$zero,4" << endl;
		mipsfile << "mult " << REGISTER[ob2] << ",$t1" << endl;
		mipsfile << "mflo $t0" << endl;
	}
	else
	{
		//cout << "in aetarrMIPS" << endl;
		int ob2_index = getMIPSindex(ob2);
		if (ob2_index == -1)
		{
			mipsfile << "addi $t1,$zero,4" << endl;
			mipsfile << "addi $t0,$zero," << ob2 << endl;
			mipsfile << "mult $t0,$t1" << endl;
			mipsfile << "mflo $t0" << endl;
		}
		else
		{
			if (mipssymboltable[ob2_index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << ob2 << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
				mipsfile << "addi $t1,$zero,4" << endl;
				mipsfile << "mult $t0,$t1" << endl;
				mipsfile << "mflo $t0" << endl;
			}
			else
			{
				string addr = getaddress(ob2);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
				mipsfile << "addi $t1,$zero,4" << endl;
				mipsfile << "mult $t0,$t1" << endl;
				mipsfile << "mflo $t0" << endl;
			}
		}
	}

	int ob1_index = getMIPSindex(ob1);
	if (mipssymboltable[ob1_index].level.compare("0") == 0)
	{
		mipsfile << "la $t1," << ob1 << endl;
		mipsfile << "add $t0,$t1,$t0" << endl;
		mipsfile << "lw $t0,0($t0)" << endl;
	}
	else
	{
		string addr = getaddress(ob1);
		mipsfile << "addi $t1,$fp,-" << addr << endl;
		mipsfile << "sub $t0,$t1,$t0" << endl;
		mipsfile << "lw $t0,0($t0)" << endl;
	}
	if (REGISTER.find(ob3) != REGISTER.end())
	{
		mipsfile << "addi " << REGISTER[ob3] << ",$t0,0" << endl;
	}
	else
	{
		int ob3_index = getMIPSindex(ob3);
		if (ob3_index == -1)                  //可能是单个字符或数字
		{
			insertmipssymboltable(ob3, mipssymboltable[ob1_index].type, string("0"), mipslevel);
			ob3_index = getMIPSindex(ob3);
		}
		if (mipssymboltable[ob3_index].level.compare("0") == 0)
		{
			mipsfile << "la $t1," << ob3 << endl;
			mipsfile << "sw $t0,0($t1)" << endl;
		}
		else
		{
			string addr = getaddress(ob3);
			//mipsfile << "addi $t1,$fp,-" << addr << endl;
			mipsfile << "sw $t0,-" << addr << "($fp)" << endl;
		}
	}
}

void assignMIPS(string ob1, string ob3)
{
	string ob3type = string("INTSY");
	if ((REGISTER.find(ob1) != REGISTER.end()) && (REGISTER.find(ob3) != REGISTER.end()))
	{
		mipsfile << "addi " << REGISTER[ob3] << "," << REGISTER[ob1] << ",0" << endl;
	}
	else if ((REGISTER.find(ob1) == REGISTER.end()) && (REGISTER.find(ob3) != REGISTER.end()))
	{
		int ob1_index = getMIPSindex(ob1);
		if (ob1_index == -1)
		{
			if (ob1.c_str()[0] == '\'')            //可能是单字符
			{
				string temp_s = ob1;
				temp_s.erase(0, 1);
				temp_s.erase(temp_s.length() - 1, 1);
				ob3type = string("CHARSY");
				mipsfile << "addi $t0,$zero," << temp_s << endl;
			}
			else
			{
				mipsfile << "addi $t0,$zero," << ob1 << endl;    //也可能直接是数字
			}
		}
		else
		{
			if (mipssymboltable[ob1_index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << ob1 << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
			}
			else
			{
				string addr = getaddress(ob1);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
			}
			ob3type = mipssymboltable[ob1_index].type;                //要时刻记住类型
		}
		mipsfile << "addi " << REGISTER[ob3] << ",$t0,0" << endl;
	}
	else if ((REGISTER.find(ob1) != REGISTER.end()) && (REGISTER.find(ob3) == REGISTER.end()))
	{
		int ob3_index = getMIPSindex(ob3);
		if (ob3_index == -1)
		{
			insertmipssymboltable(ob3, ob3type, string("0"), mipslevel);
			ob3_index = getMIPSindex(ob3);
		}
		if (mipssymboltable[ob3_index].level.compare("0") == 0)
		{
			mipsfile << "la $t1," << ob3 << endl;
		}
		else
		{
			string addr = getaddress(ob3);
			mipsfile << "addi $t1,$fp,-" << addr << endl;
		}
		mipsfile << "sw " << REGISTER[ob1] << ",0($t1)" << endl;
	}
	else
	{
		int ob1_index = getMIPSindex(ob1);
		if (ob1_index == -1)
		{
			if (ob1.c_str()[0] == '\'')            //可能是单字符
			{
				string temp_s = ob1;
				temp_s.erase(0, 1);
				temp_s.erase(temp_s.length() - 1, 1);
				ob3type = string("CHARSY");
				mipsfile << "addi $t0,$zero," << temp_s << endl;
			}
			else
			{
				mipsfile << "addi $t0,$zero," << ob1 << endl;    //也可能直接是数字
			}
		}
		else
		{
			if (mipssymboltable[ob1_index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << ob1 << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
			}
			else
			{
				string addr = getaddress(ob1);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
			}
			ob3type = mipssymboltable[ob1_index].type;                //要时刻记住类型
		}
		int ob3_index = getMIPSindex(ob3);
		if (ob3_index == -1)
		{
			insertmipssymboltable(ob3, ob3type, string("0"), mipslevel);
			ob3_index = getMIPSindex(ob3);
		}
		if (mipssymboltable[ob3_index].level.compare("0") == 0)
		{
			mipsfile << "la $t1," << ob3 << endl;
		}
		else
		{
			string addr = getaddress(ob3);
			mipsfile << "addi $t1,$fp,-" << addr << endl;
		}
		mipsfile << "sw $t0,0($t1)" << endl;
	}
}

void scanfMIPS(string ob3)
{
	int index = getMIPSindex(ob3);
	debug_information << "~~~~~~~~~~~~~~" << index << endl;
	if (mipssymboltable[index].type.compare("INTSY") == 0)
	{
		mipsfile << "addi $v0,$zero,5" << endl;
	}
	else
	{
		mipsfile << "addi $v0,$zero,12" << endl;
	}
	mipsfile << "syscall" << endl;
	if (REGISTER.find(ob3) != REGISTER.end())
	{
		mipsfile << "addi " << REGISTER[ob3] << ",$v0,0" << endl;
	}
	else
	{
		if (mipssymboltable[index].level.compare("0") == 0)
		{
			mipsfile << "la $t0," << ob3 << endl;
			mipsfile << "sw $v0,0($t0)" << endl;
		}
		else
		{
			string addr = getaddress(ob3);
			//mipsfile << "addi $t0,$fp,-" << addr << endl;
			mipsfile << "sw $v0,-" << addr << "($fp)" << endl;
		}
	}
}

void printfMIPS(string ob1, string ob2)
{
	int strlength = ob1.length();
	//for (int i = 0; i < strlength; i++)
	if (strlength > 0)
	{
	/*	mipsfile << "addi $a0,$zero," << ob1[i] - 'A' + 65 << endl;
		mipsfile << "addi $v0,$zero,11" << endl;
		mipsfile << "syscall" << endl;*/
		///////////////////////////////////
		stringstream temp_s;
		temp_s << stringcount++;
		string stringLabel = "string" + temp_s.str();
		mipsfile << ".data" << endl;
		mipsfile << stringLabel << ": .asciiz \"" << ob1 << "\"" << endl;
		mipsfile << ".text" << endl;
		mipsfile << "la $a0," << stringLabel << endl;
		mipsfile << "addi $v0,$zero,4" << endl;
		mipsfile << "syscall" << endl;
	}
	int ob2_index = getMIPSindex(ob2);
	if (ob2_index != -1)
	{
		if (REGISTER.find(ob2) != REGISTER.end())
		{
			mipsfile << "addi $a0," << REGISTER[ob2] << ",0" << endl;
		}
		else
		{
			if (mipssymboltable[ob2_index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << ob2 << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
			}
			else
			{
				string addr = getaddress(ob2);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
			}
			mipsfile << "addi $a0,$t0,0" << endl;
		}
		if (mipssymboltable[ob2_index].type.compare("INTSY") == 0)
		{
			mipsfile << "addi $v0,$zero,1" << endl;
		}
		else
		{
			mipsfile << "addi $v0,$zero,11" << endl;
		}
		mipsfile << "syscall" << endl;
	}
	mipsfile << "addi $a0,$zero," << '\n' - 'A' + 65 << endl;
	mipsfile << "addi $v0,$zero,11" << endl;
	mipsfile << "syscall" << endl;
}

void jumpMIPS(string op, string ob1, string ob2, string ob3)
{
	string cal1, cal2;
	int index;
	if (REGISTER.find(ob1) != REGISTER.end())
	{
		cal1 = REGISTER[ob1];
	}
	else
	{
		index = getMIPSindex(ob1);
		if (index == -1)
		{
			mipsfile << "addi $t0,$zero," << ob1 << endl;
		}
		else
		{
			if (mipssymboltable[index].level.compare("0") == 0)
			{
				mipsfile << "la $t0," << mipssymboltable[index].name << endl;
				mipsfile << "lw $t0,0($t0)" << endl;
			}
			else
			{
				string addr = getaddress(ob1);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
			}
		}
		cal1 = string("$t0");
	}
	if (REGISTER.find(ob2) != REGISTER.end())
	{
		cal2 = REGISTER[ob2];
	}
	else
	{
		index = getMIPSindex(ob2);
		if (index == -1)
		{
			mipsfile << "addi $t1,$zero," << ob2 << endl;
		}
		else
		{
			if (mipssymboltable[index].level.compare("0") == 0)
			{
				mipsfile << "la $t1," << mipssymboltable[index].name << endl;
				mipsfile << "lw $t1,0($t1)" << endl;
			}
			else
			{
				string addr = getaddress(ob2);
				//mipsfile << "addi $t1,$fp,-" << addr << endl;
				mipsfile << "lw $t1,-" << addr << "($fp)" << endl;
			}
		}
		cal2 = string("$t1");
	}
	if (op.compare("JB") == 0)
	{
		mipsfile << "sub $t2," << cal1 << "," << cal2 << endl;
		mipsfile << "bgtz $t2," << ob3 << endl;
	}
	else if (op.compare("JBE") == 0)
	{
		mipsfile << "sub $t2," << cal1 << "," << cal2 << endl;
		mipsfile << "bgez $t2," << ob3 << endl;
	}
	else if (op.compare("JS") == 0)
	{
		mipsfile << "sub $t2," << cal1 << "," << cal2 << endl;
		mipsfile << "bltz $t2," << ob3 << endl;
	}
	else if (op.compare("JSE") == 0)
	{
		mipsfile << "sub $t2," << cal1 << "," << cal2 << endl;
		mipsfile << "blez $t2," << ob3 << endl;
	}
	else if (op.compare("JE") == 0)
	{
		mipsfile << "beq " << cal1 << "," << cal2 << "," << ob3 << endl;
	}
	else if (op.compare("JNE") == 0)
	{
		mipsfile << "bne " << cal1 << "," << cal2 << "," << ob3 << endl;
	}
}

void jumpswitchMIPS(string op, string ob1, string ob2, string ob3)
{
	string cal1;
	int index;
	if (REGISTER.find(ob1) != REGISTER.end())
	{
		cal1 = REGISTER[ob1];
	}
	else
	{
		index = getMIPSindex(ob1);
		if (mipssymboltable[index].level.compare("0") == 0)
		{
			mipsfile << "la $t0," << mipssymboltable[index].name << endl;
			mipsfile << "lw $t0,0($t0)" << endl;
		}
		else
		{
			string addr = getaddress(ob1);
			//mipsfile << "addi $t0,$fp,-" << addr << endl;
			mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
		}
		cal1 = string("$t0");
	}
	if (op.compare("JNEI") == 0)
	{
		mipsfile << "addi $t1,$zero," << ob2 << endl;
		mipsfile << "bne " << cal1 << ",$t1," << ob3 << endl;
	}
	else if (op.compare("JNEC") == 0)
	{
		mipsfile << "addi $t1,$zero," << ob2[0] - 'A' + 65 << endl;
		mipsfile << "bne " << cal1 << ",$t1," << ob3 << endl;
	}
}

void mips_generate()
{
	mipsfile.open("object_code.asm");
	mipsfile << ".data" << endl;
	bool mainflag = false;
	bool textflag = false;
	int basepoint = 0;
	int i = 0;
	while (i < midcode_length)
	{
		debug_information << i << " " << middlecode_list[i].op << " "
			<< middlecode_list[i].ob1 << " "
			<< middlecode_list[i].ob2 << " "
			<< middlecode_list[i].ob3 << endl;
		if (middlecode_list[i].op.compare("CONST") == 0)
		{
			debug_information << "enter CONST " << endl;
			if (REGISTER.find(middlecode_list[i].ob3) != REGISTER.end())//如果发现分配了全局寄存器
			{
				mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << "," << "$zero" << "," << middlecode_list[i].ob2 << endl;
			}
/*			else      //初步的全局寄存器分配，并未做优化
			{
				if (register_used < 8)
				{
					stringstream temp_s;
					temp_s << register_used;
					REGISTER.insert(make_pair(middlecode_list[i].ob3, "$s" + temp_s.str()));
					register_used++;
					mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << "," << "$zero" << "," << middlecode_list[i].ob2 << endl;
				}
			}*/
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
		else if ((middlecode_list[i].op.compare("INTSY") == 0) || (middlecode_list[i].op.compare("CHARSY") == 0))
		{
			debug_information << "enter INTSY or CHARSY " << endl;
			if (mipslevel == 0)
			{
				if (middlecode_list[i].ob2.compare("") == 0)     //不是数组的情况
				{
					insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].op, string("0"), mipslevel);
					defineGlobalMIPS(middlecode_list[i].ob3, string("0"), string("0"));
				}
				else                                     //是数组的情况
				{
					insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].op, middlecode_list[i].ob2, mipslevel);
					defineGlobalMIPS(middlecode_list[i].ob3, string("0"), middlecode_list[i].ob2);
				}
			}
			else
			{
				if (middlecode_list[i].ob2.compare("") == 0)     //不是数组的情况
				{
					insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].op, string("0"), mipslevel);
				}
				else                                     //是数组的情况
				{
					insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].op, middlecode_list[i].ob2, mipslevel);
				}
			}
		}
		else if (middlecode_list[i].op.compare("FSTART") == 0)
		{
			debug_information << "enter FSTART " << endl;
			mipslevel++;
			basepoint = mipstablelength;
			REGISTER.clear();
			//REGISTER.erase(REGISTER.begin(), REGISTER.end());
			map<string, string>::iterator  it = REGISTER.begin();
			for (; it != REGISTER.end(); ++it)
				debug_information << "key:" << it->first << " "
				<< "value:" << it->second << endl;
			debug_information << "----------------" << endl;
	//		register_used = 0;
			REGISTERallocation(i);
			it = REGISTER.begin();
			for (; it != REGISTER.end(); ++it)
				debug_information << "key:" << it->first << " "
				<< "value:" << it->second << endl;
			debug_information << "----------------" << endl;
		}
		else if (middlecode_list[i].op.compare("FEND") == 0)
		{
			debug_information << "enter FEND " << endl;
			if (mainflag == true)
			{
				mipsfile << "EXIT:" << endl;
				mainflag = false;
			}
			else
			{
				returnMIPS();
				mipslevel--;
				while (basepoint < mipssymboltable.size())                 //删除新层函数
				{
					mipssymboltable.erase(mipssymboltable.begin() + basepoint);
				}
				mipstablelength = basepoint;
			}
		}
		else if (middlecode_list[i].op.compare("LABEL") == 0)
		{
			debug_information << "enter LABEL " << endl;
			if (textflag == false)      //代码段的开始
			{
				mipsfile << ".text" << endl;
				mipsfile << "addi $fp,$sp,0" << endl;
				mipsfile << "j main" << endl;
				textflag = true;
			}
			mipsfile << middlecode_list[i].ob3 << ":" << endl;
			if ((middlecode_list[i].ob3.compare("main") != 0) && (middlecode_list[i - 1].op.compare("FSTART") == 0))    //非main函数的函数标签
			{
				mipsfile << "sw $ra,4($sp)" << endl;
				int index = getsymindex(middlecode_list[i].ob3, string("FUNCTION"));
				int depth = symboltable[index].depth;
				mipsfile << "addi $sp,$sp," << -depth << endl;
			}
			else if ((middlecode_list[i].ob3.compare("main") == 0) && (middlecode_list[i - 1].op.compare("FSTART") == 0))    //main函数标签
			{
				mainflag = true;
				int index = getsymindex(middlecode_list[i].ob3, string("FUNCTION"));
				int depth = symboltable[index].depth;
				mipsfile << "addi $sp,$sp," << -depth << endl;
			}
		}
		else if (middlecode_list[i].op.compare("PUSH") == 0)
		{
			debug_information << "enter PUSH " << endl;
			int word_offset = 0;
			savestackMIPS();
			while (middlecode_list[i].op.compare("PUSH") == 0)
			{
				if (REGISTER.find(middlecode_list[i].ob3) != REGISTER.end())
				{
					mipsfile << "sw " << REGISTER[middlecode_list[i].ob3] << "," << -4 * word_offset << "($sp)" << endl;
				}
				else
				{
					int index = getMIPSindex(middlecode_list[i].ob3);
					if (index == -1)             //可能直接是数字或字符
					{
						mipsfile << "addi $t0,$zero," << middlecode_list[i].ob3 << endl;
					}
					else
					{
						if (mipssymboltable[index].level.compare("0")==0)     //是全局变量
						{
							mipsfile << "la $t0," << mipssymboltable[index].name << endl;
							mipsfile << "lw $t0,0($t0)" << endl;
						}
						else
						{
							string addr = getaddress(mipssymboltable[index].name);
							//mipsfile << "addi $t0,$fp,-" << addr << endl;
							mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
						}
					}
					mipsfile << "sw $t0," << -4 * word_offset << "($sp)" << endl;
				}
				word_offset++;
				i++;
			}
			mipsfile << "addi $fp,$sp,0" << endl;
			i--;                            //使得不会跳读midcode
		}
		else if ((middlecode_list[i].op.compare("CALL") == 0) || (middlecode_list[i].op.compare("RCALL") == 0))
		{
			debug_information << "enter CALL or RCALL " << endl;
			int func_index = getsymindex(middlecode_list[i].ob1, string("FUNCTION"));
			if (symboltable[func_index].length == 0)
			{
				savestackMIPS();
				mipsfile << "addi $fp,$sp,0" << endl;
			}
			mipsfile << "jal " << middlecode_list[i].ob1 << endl;
			if (middlecode_list[i].op.compare("RCALL") == 0)
			{
				if (REGISTER.find(middlecode_list[i].ob3) != REGISTER.end())
				{
					mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << ",$v0,0" << endl;
				}
/*				else if (register_used < 8)
				{
					stringstream temp_s;
					temp_s << register_used;
					REGISTER.insert(make_pair(middlecode_list[i].ob3, "$s" + temp_s.str()));
					register_used++;
					mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << ",$v0,0" << endl;
				}*/
				else
				{
					/*if (register_used < 8)
					{
						stringstream temp_s;
						temp_s << register_used;
						REGISTER.insert(make_pair(middlecode_list[i].ob3, "$s" + temp_s.str()));
						register_used++;
						mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << ",$v0,0" << endl;
					}*/
					int return_index = getMIPSindex(middlecode_list[i].ob3);
					if (return_index == -1)
					{
						int func_index = getsymindex(middlecode_list[i].ob1, string("FUNCTION"));
						insertmipssymboltable(middlecode_list[i].ob3, symboltable[func_index].type, string("0"), mipslevel);
						return_index = getMIPSindex(middlecode_list[i].ob3);
					}           //判断返回值变量是否被插入mips符号表，若没插入则插入
					if (mipssymboltable[return_index].level.compare("0") == 0)
					{
						mipsfile << "la $t0," << mipssymboltable[return_index].name << endl;           ///////////////////////////////////////////
					}
					else
					{
						string addr = getaddress(mipssymboltable[return_index].name);
						mipsfile << "addi $t0,$fp,-" << addr << endl;
					}
					mipsfile << "sw $v0,0($t0)" << endl;
				}
			}
		}
		else if (middlecode_list[i].op.compare("PARA")==0)
		{
			debug_information << "enter PARA " << endl;
			insertmipssymboltable(middlecode_list[i].ob3, middlecode_list[i].ob1, string("0"), mipslevel);
			if (REGISTER.find(middlecode_list[i].ob3) != REGISTER.end())
			{
				string addr = getaddress(middlecode_list[i].ob3);
				//mipsfile << "addi $t0,$fp,-" << addr << endl;
				mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
				mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << ",$t0,0" << endl;
			}
		/*	else
			{
				if (register_used < 8)
				{
					stringstream temp_s;
					temp_s << register_used;
					REGISTER.insert(make_pair(middlecode_list[i].ob3, "$s" + temp_s.str()));
					register_used++;
					string addr = getaddress(middlecode_list[i].ob3);
					//mipsfile << "addi $t0,$fp,-" << addr << endl;
					mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
					mipsfile << "addi " << REGISTER[middlecode_list[i].ob3] << ",$t0,0" << endl;
				}
			}*/
		}
		else if ((middlecode_list[i].op.compare("ADD") == 0) || (middlecode_list[i].op.compare("SUB") == 0) ||
			(middlecode_list[i].op.compare("MUL") == 0) || (middlecode_list[i].op.compare("DIV") == 0))
		{
			debug_information << "enter CALCULATE " << endl;
			calculateMIPS(middlecode_list[i].op, middlecode_list[i].ob1, middlecode_list[i].ob2, middlecode_list[i].ob3);
		}
		else if (middlecode_list[i].op.compare("ASN") == 0)
		{
			debug_information << "enter ASN " << endl;
			assignMIPS(middlecode_list[i].ob1, middlecode_list[i].ob3);
		}
		else if (middlecode_list[i].op.compare("ASNAR") == 0)
		{
			debug_information << "enter ASNAR " << endl;
			assignarrMIPS(middlecode_list[i].ob1, middlecode_list[i].ob2, middlecode_list[i].ob3);
		}
		else if (middlecode_list[i].op.compare("GETAR") == 0)
		{
			debug_information << "enter GETAR " << endl;
			getarrMIPS(middlecode_list[i].ob1, middlecode_list[i].ob2, middlecode_list[i].ob3);
		}
		else if ((middlecode_list[i].op.compare("RETURN") == 0) && mainflag == false)
		{
			debug_information << "enter RETURN " << endl;
			int index = getMIPSindex(middlecode_list[i].ob3);
			if (index != -1)
			{
				if (REGISTER.find(middlecode_list[i].ob3) != REGISTER.end())
				{
					mipsfile << "addi $v0," << REGISTER[middlecode_list[i].ob3] << ",0" << endl;
				}
				else
				{
					if (mipssymboltable[index].level.compare("0") == 0)
					{
						mipsfile << "la $t0," << mipssymboltable[index].name << endl;
						mipsfile << "lw $t0,0($t0)" << endl;
						mipsfile << "addi $v0,$t0,0" << endl;
					}
					else
					{
						string addr = getaddress(middlecode_list[i].ob3);
						//mipsfile << "addi $t0,$fp,-" << addr << endl;
						mipsfile << "lw $t0,-" << addr << "($fp)" << endl;
						mipsfile << "addi $v0,$t0,0" << endl;
					}
				}
			}
			returnMIPS();
		}
		else if ((middlecode_list[i].op.compare("RETURN") == 0) && mainflag == true)
		{
			debug_information << "enter RETURN " << endl;
			mipsfile << "j EXIT" << endl;
		}
		else if (middlecode_list[i].op.compare("SCANF") == 0)
		{
			debug_information << "enter SCANF " << endl;
			scanfMIPS(middlecode_list[i].ob3);
		}
		else if (middlecode_list[i].op.compare("PRINTF") == 0)
		{
			debug_information << "enter PRINTF " << endl;
			printfMIPS(middlecode_list[i].ob1, middlecode_list[i].ob2);
		}
		else if (middlecode_list[i].op.compare("JUMP") == 0)
		{
			debug_information << "enter JUMP " << endl;
			mipsfile << "j " << middlecode_list[i].ob3 << endl;
		}
		else if ((middlecode_list[i].op.compare("JBE") == 0) || (middlecode_list[i].op.compare("JB") == 0) ||
			(middlecode_list[i].op.compare("JSE") == 0) || (middlecode_list[i].op.compare("JS") == 0) ||
			(middlecode_list[i].op.compare("JE") == 0) || (middlecode_list[i].op.compare("JNE") == 0))
		{
			debug_information << "enter jump " << endl;
			jumpMIPS(middlecode_list[i].op, middlecode_list[i].ob1, middlecode_list[i].ob2, middlecode_list[i].ob3);
		}
		else if ((middlecode_list[i].op.compare("JNEI") == 0) || (middlecode_list[i].op.compare("JNEC") == 0))
		{
			debug_information << "enter SWITCHJUMP " << endl;
			jumpswitchMIPS(middlecode_list[i].op, middlecode_list[i].ob1, middlecode_list[i].ob2, middlecode_list[i].ob3);
		}
		//////////////////////////////////////////////////////////
		i++;
	}
}
