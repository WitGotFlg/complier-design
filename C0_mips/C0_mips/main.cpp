#include "global.h"


using namespace std;

int main()
{
	//cout << "Hello world!" << endl;
	readCodeFile();
	program();
	mips_generate();
	for (int i = 0; i < midcode_length; i++)
	{
		cout << middlecode_list[i].op << " "
			<< middlecode_list[i].ob1 << " "
			<< middlecode_list[i].ob2 << " "
			<< middlecode_list[i].ob3 << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < tablelength; i++)
	{
		cout << symboltable[i].name << " "
			<< symboltable[i].kind << " "
			<< symboltable[i].type << " "
			<< symboltable[i].length << endl;
	}
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
