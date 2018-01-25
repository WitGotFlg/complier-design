#include "global.h"


using namespace std;

ofstream debug_information;

int main()
{
	//cout << "Hello world!" << endl;
	debug_information.open("debug_information.txt");
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
	mips_generate();
	debug_information.close();
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
