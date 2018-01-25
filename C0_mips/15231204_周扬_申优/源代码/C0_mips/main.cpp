#include "global.h"


using namespace std;

ofstream debug_information;
ofstream middle_information;

int main()
{
	//cout << "Hello world!" << endl;
	debug_information.open("debug_information.txt");
	middle_information.open("15231204_周扬_中间代码.txt");
	readCodeFile();
	program();
	if (errornum != 0)
	{
		cout << "Total error num : " << errornum << endl;
		exit(1);
	}
	for (int i = 0; i < midcode_length; i++)
	{
		debug_information << i << " " << middlecode_list[i].op << " "
			<< middlecode_list[i].ob1 << " "
			<< middlecode_list[i].ob2 << " "
			<< middlecode_list[i].ob3 << endl;
	}
	debug_information << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < tablelength; i++)
	{
		debug_information << symboltable[i].name << " "
			<< symboltable[i].kind << " "
			<< symboltable[i].type << " "
			<< symboltable[i].length << endl;
	}
	//cout << "!!!!!!!!!!!!!!! before dag !!!!!!!!!!!! " << endl;
	dag_opt();
	//cout << "!!!!!!!!!!!!!!! after dag !!!!!!!!!!!!!!" << endl;
	debug_information << "___________________________ddddddd_________dddddd______________________________" << endl;
	for (int i = 0; i < midcode_length; i++)
	{
		debug_information << i << " " << middlecode_list[i].op << " "
			<< middlecode_list[i].ob1 << " "
			<< middlecode_list[i].ob2 << " "
			<< middlecode_list[i].ob3 << endl;
	}
/*	for (int i = 0; i < midcode_length; i++)
	{
		if ((middlecode_list[i].op.compare("ADD") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << " = "
				<< middlecode_list[i].ob1 << " + "
				<< middlecode_list[i].ob2 <<  endl;
		}
		else if ((middlecode_list[i].op.compare("SUB") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << " = "
				<< middlecode_list[i].ob1 << " - "
				<< middlecode_list[i].ob2 << endl;
		}
		else if ((middlecode_list[i].op.compare("MUL") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << " = "
				<< middlecode_list[i].ob1 << " * "
				<< middlecode_list[i].ob2 << endl;
		}
		else if ((middlecode_list[i].op.compare("DIV") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << " = "
				<< middlecode_list[i].ob1 << " / "
				<< middlecode_list[i].ob2 << endl;
		}
		else if ((middlecode_list[i].op.compare("ASN") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << " = "
				<< middlecode_list[i].ob1 << endl;
		}
		else if ((middlecode_list[i].op.compare("GETAR") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << " = "
				<< middlecode_list[i].ob1 << "["
				<< middlecode_list[i].ob2 << "]" << endl;
		}
		else if ((middlecode_list[i].op.compare("ASNAR") == 0))
		{
			middle_information << i << " " << middlecode_list[i].ob3 << "["
				<< middlecode_list[i].ob2 << "] = "
				<< middlecode_list[i].ob1 << endl;
		}
		else
		{
			middle_information << i << " " << middlecode_list[i].op << " "
				<< middlecode_list[i].ob1 << " "
				<< middlecode_list[i].ob2 << " "
				<< middlecode_list[i].ob3 << endl;
		}
	}*/
	mips_generate();
	debug_information.close();
	middle_information.close();
/*	insertsymboltable("name1", "var", "int", 12, false, -1, 0, 0);
	cout << symboltable.size() << endl;
	cout << tablelength << endl;
	insertsymboltable("name2", "const", "int", 12, false, -1, 0, 0);
	insertsymboltable("name3", "var", "char", 'a', false, -1, 0, 0);
	insertsymboltable("paraname1", "var", "int", 2, false, -1, 0, 0);
	insertsymboltable("paraname2", "var", "int", 12, false, -1, 0, 0);
	insertsymboltable("function1", "FUNCTION", "int", 12, false, 2, 0, 0);
	for (int i = 0; i < tablelength; i++)
	{
		cout << symboltable[i].name << " kind " << symboltable[i].kind << endl;
	}
	cout << symboltable.size() << endl;
	cout << tablelength << endl;
	deletefunction();
	for (int i = 0; i < tablelength; i++)
	{
		cout << symboltable[i].name << " kind " << symboltable[i].kind << endl;
	}
	cout << symboltable.size() << endl;
	cout << tablelength << endl;*/

}
