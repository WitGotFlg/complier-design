#include "global.h"

vector<block> blocklist;
int blocklistlength = 0;

bool islocalvar(string var)
{
	int index = getsymindex(var, string("VAR"));
	if ((index != -1) && (symboltable[index].level == 0))
	{
		return false;
	}
	if (var.length() > 0)
	{
		if (!((var.c_str()[0] >= '0') && (var.c_str()[0] <= '9')))
		{
			if (var.length() > 1)
			{
				if ((var.substr(0, 4).compare("TEMP") == 0) || (var.c_str()[0] == '-'))
				{
					return false;
				}
				if (var.c_str()[0] == '\'')
				{
					return false;
				}
			}
			//cout << "in islocalvar true" << endl;
			return true;
		}
		return false;
	}
}

bool if_exit_vector(string obj, vector<string> &vec, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (vec[i].compare(obj) == 0)
		{
			//cout << "in if_exist_vector true" << endl;
			return true;
		}
	}
	return false;
}

int vectorToSet(vector<string> &vec, int length)    //去除vector中相同的元素，使之变为一个集合
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (vec[i].compare(vec[j]) == 0)
			{
				vec.erase(vec.begin() + j);
				j--;
				length--;
			}
		}
	}
	//vec.shrink_to_fit();               /////////////////////////
	return length;
}

int calculatein(vector<string> &in, int innum, vector<string> &use, int usenum, vector<string> &out, int outnum, vector<string> &def, int defnum)
{
	//in.clear();
	//in.shrink_to_fit();
	int new_innum = 0;
	for (int i = 0; i < outnum; i++)
	{
		int j;
		for (j = 0; j < defnum; j++)
		{
			if (out[i].compare(def[j]) == 0)
			{
				break;
			}
		}
		if (j == defnum)
		{
			in.push_back(out[i]);
			new_innum++;
		}
	}
	for (int i = 0; i < usenum; i++)
	{
		in.push_back(use[i]);
		new_innum++;
	}
	return vectorToSet(in,innum+new_innum);
}

void dataflowanalysis(int start)
{
	blocklistlength = 0;
	blocklist.clear();
	//blocklist.shrink_to_fit();
	int jlabelcount = 0;
	for (int i = start; middlecode_list[i].op.compare("FEND") != 0; i++)    //划分block以及计算def和use
	{
		if (middlecode_list[i].op.compare("LABEL") == 0)
		{
			block new_block;
			new_block.prenum = 0;
			new_block.sucnum = 0;
			new_block.defnum = 0;
			new_block.usenum = 0;
			new_block.innum = 0;
			new_block.outnum = 0;
			new_block.inchanged = 0;
			new_block.label = middlecode_list[i].ob3;
			if (blocklistlength > 0) /////////////////////////
			{
				new_block.pre.push_back(blocklist[blocklistlength - 1].label);
				new_block.prenum++;
				blocklist[blocklistlength - 1].suc.push_back(new_block.label);
				blocklist[blocklistlength - 1].sucnum++;
			}
			blocklist.push_back(new_block);
			blocklistlength++;
			continue;
		}
		else if ((middlecode_list[i].op.compare("JBE") == 0) ||
			(middlecode_list[i].op.compare("JB") == 0) ||
			(middlecode_list[i].op.compare("JSE") == 0) ||
			(middlecode_list[i].op.compare("JS") == 0) ||
			(middlecode_list[i].op.compare("JNE") == 0) ||
			(middlecode_list[i].op.compare("JE") == 0) ||
			(middlecode_list[i].op.compare("JUMP") == 0) ||
			(middlecode_list[i].op.compare("JNEI") == 0) ||
			(middlecode_list[i].op.compare("JNEC") == 0))
		{
			if (islocalvar(middlecode_list[i].ob1) &&
				!if_exit_vector(middlecode_list[i].ob1, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob1);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob2) &&
				!if_exit_vector(middlecode_list[i].ob2, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob2);
				blocklist[blocklistlength - 1].usenum++;
			}
			block new_block;
			new_block.prenum = 0;
			new_block.sucnum = 0;
			new_block.defnum = 0;
			new_block.usenum = 0;
			new_block.innum = 0;
			new_block.outnum = 0;
			new_block.inchanged = 0;
			stringstream temp_s;
			temp_s << jlabelcount++;
			new_block.label = "jlabel" + temp_s.str();
			blocklist[blocklistlength - 1].suc.push_back(middlecode_list[i].ob3);
			blocklist[blocklistlength - 1].sucnum++;
			if (blocklistlength > 0 && middlecode_list[i].op.compare("JUMP") != 0)
			{
				new_block.pre.push_back(blocklist[blocklistlength - 1].label);
				new_block.prenum++;
				blocklist[blocklistlength - 1].suc.push_back(new_block.label);
				blocklist[blocklistlength - 1].sucnum++;
			}
			blocklist.push_back(new_block);
			blocklistlength++;
			continue;
		}
		else if ((middlecode_list[i].op.compare("RCALL") == 0) || (middlecode_list[i].op.compare("PARA") == 0))
		{
			blocklist[blocklistlength - 1].def.push_back(middlecode_list[i].ob3);
			blocklist[blocklistlength - 1].defnum++;
		}
		else if ((middlecode_list[i].op.compare("ADD") == 0) ||
			(middlecode_list[i].op.compare("SUB") == 0) ||
			(middlecode_list[i].op.compare("MUL") == 0) ||
			(middlecode_list[i].op.compare("DIV") == 0))
		{
			if (islocalvar(middlecode_list[i].ob1) &&
				!if_exit_vector(middlecode_list[i].ob1, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob1);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob2) &&
				!if_exit_vector(middlecode_list[i].ob2, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob2);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob3) &&
				!if_exit_vector(middlecode_list[i].ob3, blocklist[blocklistlength - 1].use, blocklist[blocklistlength - 1].usenum))
			{
				blocklist[blocklistlength - 1].def.push_back(middlecode_list[i].ob3);
				blocklist[blocklistlength - 1].defnum++;
			}
		}
		else if (middlecode_list[i].op.compare("ASN") == 0)
		{
			if (islocalvar(middlecode_list[i].ob1) &&
				!if_exit_vector(middlecode_list[i].ob1, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob1);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob3) &&
				!if_exit_vector(middlecode_list[i].ob3, blocklist[blocklistlength - 1].use, blocklist[blocklistlength - 1].usenum))
			{
				blocklist[blocklistlength - 1].def.push_back(middlecode_list[i].ob3);
				blocklist[blocklistlength - 1].defnum++;
			}
		}
		else if (middlecode_list[i].op.compare("GETAR") == 0)
		{
			if (islocalvar(middlecode_list[i].ob2) &&
				!if_exit_vector(middlecode_list[i].ob2, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob2);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob3) &&
				!if_exit_vector(middlecode_list[i].ob3, blocklist[blocklistlength - 1].use, blocklist[blocklistlength - 1].usenum))
			{
				blocklist[blocklistlength - 1].def.push_back(middlecode_list[i].ob3);
				blocklist[blocklistlength - 1].defnum++;
			}
		}
		else if (middlecode_list[i].op.compare("ASNAR") == 0)
		{
			if (islocalvar(middlecode_list[i].ob1) &&
				!if_exit_vector(middlecode_list[i].ob1, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob1);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob2) &&
				!if_exit_vector(middlecode_list[i].ob2, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob2);
				blocklist[blocklistlength - 1].usenum++;
			}
		}
		else if ((middlecode_list[i].op.compare("RETURN") == 0) || (middlecode_list[i].op.compare("PUSH") == 0))
		{
			if (islocalvar(middlecode_list[i].ob3) &&
				!if_exit_vector(middlecode_list[i].ob3, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob3);
				blocklist[blocklistlength - 1].usenum++;
			}
		}
		else if (middlecode_list[i].op.compare("SCANF") == 0)
		{
			if (islocalvar(middlecode_list[i].ob3) &&
				!if_exit_vector(middlecode_list[i].ob3, blocklist[blocklistlength - 1].use, blocklist[blocklistlength - 1].usenum))
			{
				blocklist[blocklistlength - 1].def.push_back(middlecode_list[i].ob3);
				blocklist[blocklistlength - 1].defnum++;
			}
		}
		else if (middlecode_list[i].op.compare("PRINTF") == 0)
		{
			if (islocalvar(middlecode_list[i].ob2) &&
				!if_exit_vector(middlecode_list[i].ob2, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob2);
				blocklist[blocklistlength - 1].usenum++;
			}
		}
		else if ((middlecode_list[i].op.compare("INTSY") == 0) ||
			(middlecode_list[i].op.compare("CHARSY") == 0))
		{
			if (islocalvar(middlecode_list[i].ob1) &&
				!if_exit_vector(middlecode_list[i].ob1, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob1);
				blocklist[blocklistlength - 1].usenum++;
			}
			if (islocalvar(middlecode_list[i].ob2) &&
				!if_exit_vector(middlecode_list[i].ob2, blocklist[blocklistlength - 1].def, blocklist[blocklistlength - 1].defnum))
			{
				blocklist[blocklistlength - 1].use.push_back(middlecode_list[i].ob2);
				blocklist[blocklistlength - 1].usenum++;
			}
		}
	}

	while (1)
	{
		for (int i = 0; i < blocklistlength; i++)
		{
			int len = 0;
			for (int j = 0; j < blocklist[i].sucnum; j++)
			{
				for (int q = 0; q < blocklistlength; q++)
				{
					if (blocklist[q].label.compare(blocklist[i].suc[j]) == 0)
					{
						for (int p = 0; p < blocklist[q].innum; p++)
						{
							blocklist[i].out.push_back(blocklist[q].in[p]);
							len++;
						}
					}
				}
			}
			blocklist[i].outnum = vectorToSet(blocklist[i].out, len);
			int newinnum = calculatein(blocklist[i].in, blocklist[i].innum, blocklist[i].use, blocklist[i].usenum, blocklist[i].out, blocklist[i].outnum, blocklist[i].def, blocklist[i].defnum);
			if (blocklist[i].innum != newinnum)
			{
				blocklist[i].inchanged = 1;
				blocklist[i].innum = newinnum;
			}
			else
			{
				blocklist[i].inchanged = 0;
			}
		}
		int ier;
		for (ier = 0; ier < blocklistlength; ier++)
		{
			if (blocklist[ier].inchanged == 1)
				break;
		}
		if (ier == blocklistlength)
			break ;                  //////////////////////
	}
}

int getvectorINDEX(string obj, vector<string> &vec, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (vec[i].compare(obj) == 0)
		{
			return i;
		}
	}
	return -1;
}

void REGISTERallocation(int start)
{
	vector<string> varlist;
	int varnum = 0;
	vector<string> stack;
	int stackTop = 0;
	vector<string> abandonstack;
	int abandonstackTop = 0;
	int conflict_graph[100][100] = { 0 };
	int conflict_graph_2[100][100] = { 0 };

	dataflowanalysis(start);
	//cout << "end of dataflowanalysis" << endl;
/*	for (int i= 0; i < blocklistlength; i++)
	{
		cout << "~~~~~~~~~~~~~def~~~~~~~~~~~~~~" << endl;
		for (int j = 0; j < blocklist[i].defnum; j++)
		{
			cout << blocklist[i].def[j] << endl;
		}
		cout << "~~~~~~~~~~~~~def~~~~~~~~~~~~~~" << endl;
		cout << "~~~~~~~~~~~~~use~~~~~~~~~~~~~~" << endl;
		for (int j = 0; j < blocklist[i].usenum; j++)
		{
			cout << blocklist[i].use[j] << endl;
		}
		cout << "-------------use--------------" << endl;
	}*/
////////////////////////////////////////////////////////////////////
	for (int i = 0; i < blocklistlength; i++)                //构建冲突图，第二个冲突图保存为副本使用
	{
		for (int j = 0; j < blocklist[i].innum; j++)            //将所有在in中出现的变量不重复的加入varlist
		{
			if (!if_exit_vector(blocklist[i].in[j], varlist, varnum))
			{
				if (blocklist[i].in[j].compare("") != 0)
				{
					varlist.push_back(blocklist[i].in[j]);
					varnum++;
				}
			}
		}
		for (int j = 0; j < blocklist[i].innum; j++)             //将在同一个in集合中的变量间的边设为1
		{
			if (blocklist[i].in[j].compare("") != 0)
			{
				int temp1 = getvectorINDEX(blocklist[i].in[j], varlist, varnum);
				for (int q = j + 1; q < blocklist[i].innum; q++)
				{
					if (blocklist[i].in[q].compare("") != 0)
					{
						int temp2 = getvectorINDEX(blocklist[i].in[q], varlist, varnum);
						if (temp1 == -1 || temp2 == -1)
						{
							cout << "error in REGISTERallocation!!" << endl;
							exit(1);
						}
						//cout << "uuuuuuuuuuuuu "<<temp1<<" uuuuuuuuuu "<<temp2<<" uuuuuuu"<<endl;
						conflict_graph[temp1][temp2] = 1;
						conflict_graph[temp2][temp1] = 1;
						conflict_graph_2[temp1][temp2] = 1;
						conflict_graph_2[temp2][temp1] = 1;
					}
				}
			}
		}
		/////////////////
		for (int j = 0; j < blocklist[i].outnum; j++)            //将所有在out中出现的变量不重复的加入varlist
		{
			if (!if_exit_vector(blocklist[i].out[j], varlist, varnum))
			{
				if (blocklist[i].out[j].compare("") != 0)
				{
					varlist.push_back(blocklist[i].out[j]);
					varnum++;
				}
			}
		}
		for (int j = 0; j < blocklist[i].outnum; j++)             //将在同一个out集合中的变量间的边设为1
		{
			if (blocklist[i].out[j].compare("") != 0)
			{
				int temp1 = getvectorINDEX(blocklist[i].out[j], varlist, varnum);
				for (int q = j + 1; q < blocklist[i].outnum; q++)
				{
					if (blocklist[i].out[q].compare("") != 0)
					{
						int temp2 = getvectorINDEX(blocklist[i].out[q], varlist, varnum);
						if (temp1 == -1 || temp2 == -1)
						{
							cout << "error in REGISTERallocation!!" << endl;
							exit(1);
						}
						//cout << "uuuuuuuuuuuuu " << temp1 << " uuuuuuuuuu " << temp2 << " uuuuuuu" << endl;
						conflict_graph[temp1][temp2] = 1;
						conflict_graph[temp2][temp1] = 1;
						conflict_graph_2[temp1][temp2] = 1;
						conflict_graph_2[temp2][temp1] = 1;
					}
				}
			}
		}
	}

/*	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < varnum; i++)
	{
		cout << varlist[i] << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << conflict_graph_2[4][6] << endl;
	cout << conflict_graph_2[6][4] << endl;
	cout << conflict_graph_2[3][5] << endl;
	cout << conflict_graph_2[5][3] << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;*/
	//////////////////////////对冲突图进行处理，去除一部分冲突较为严重的节点，使得剩下的节点能够最大化地利用寄存器
	int varnum2 = varnum;
	int conflicttime[100] = { 0 };   //保存着每一个变量的冲突数（边数）
	for (int i = 0; i < varnum; i++)          //计算冲突数
	{
		for (int j = 0; j < varnum; j++)
		{
			if (conflict_graph[i][j] == 1)
				conflicttime[i]++;
		}
	}
	for (int i = 0, flag = 0; varnum != 0;)
	{
		if (i == 0)
			flag = 0;
		if (conflicttime[i] < 17 && !if_exit_vector(varlist[i], stack, stackTop))
		{
			flag = 1;
			for (int j = 0; j < varnum; j++)
			{
				conflict_graph[i][j] = 0;
				if (conflict_graph[j][i] == 1)
				{
					conflicttime[j]--;
					conflict_graph[j][i] = 0;
				}
			}
			conflicttime[i] = 0;
			stack.push_back(varlist[i]);
			stackTop++;
			varnum2--;              //冲突图中还剩余的变量数
		}
		i = (i + 1) % varnum;
		if (i == 0 && flag == 0)             //说明已经没有能够入栈的冲突数小于8的变量了
			break;
	}
	while (varnum2 != 0)
	{
		int maxconflict = 0;
		int maxindex = 0;
		for (int i = 0; i < varnum; i++)
		{
			if (conflicttime[i] > maxconflict)
			{
				maxconflict = conflicttime[i];
				maxindex = i;
			}
		}
		abandonstack.push_back(varlist[maxindex]);
		abandonstackTop++;

		for (int j = 0; j < varnum; j++)                  //将最大冲突数的节点去除
		{
			conflict_graph[maxindex][j] = 0;
			if (conflict_graph[j][maxindex] == 1)
			{
				conflicttime[j]--;
				conflict_graph[j][maxindex] = 0;
			}
		}
		conflicttime[maxindex] = 0;
		varnum2--;

		for (int i = 0, flag = 0;;)            //重新加一遍符合条件的节点
		{
			if (i == 0)
				flag = 0;
			if (conflicttime[i] < 17 &&
				!if_exit_vector(varlist[i], stack, stackTop) &&
				!if_exit_vector(varlist[i], abandonstack, abandonstackTop))
			{
				flag = 1;
				for (int j = 0; j < varnum; j++)
				{
					conflict_graph[i][j] = 0;
					if (conflict_graph[j][i] == 1)
					{
						conflicttime[j]--;
						conflict_graph[j][i] = 0;
					}
				}
				conflicttime[i] = 0;
				stack.push_back(varlist[i]);
				stackTop++;
				varnum2--;              //冲突图中还剩余的变量数
			}
			i = (i + 1) % varnum;
			if (i == 0 && flag == 0)             //说明已经没有能够入栈的冲突数小于8的变量了
				break;
		}

	}
//进行冲突图的修改
/////////////////////////////////////着色
	vector<string> alreadyallocated;
	int alreadynum = 0;
	int usedsign[17] = { 0 };
	for (int i = stackTop - 1; i >= 0; i--)
	{

		for (int j = 0; j < alreadynum; j++)
		{
			int temp1 = getvectorINDEX(stack[i], varlist, varnum);
			int temp2 = getvectorINDEX(alreadyallocated[j], varlist, varnum);
			if (temp1 == -1 || temp2 == -1)
			{
				cout << "error in allocating register color" << endl;
				exit(1);
			}
			if (conflict_graph_2[temp1][temp2] == 1)
			{
				string reg = REGISTER[alreadyallocated[j]];
				stringstream temp_s;
				if (reg.substr(0, 2).compare("$s") == 0)
				{
					int temp_num;
					temp_s << reg.erase(0, 2);
					temp_s >> temp_num;
					usedsign[temp_num] = 1;
				}
				else if (reg.substr(0, 2).compare("$t") == 0)
				{
					int temp_num;
					temp_s << reg.erase(0, 2);
					temp_s >> temp_num;
					temp_num = temp_num + 4;
					usedsign[temp_num] = 1;
				}
				else if (reg.substr(0, 2).compare("$a") == 0)
				{

					int temp_num;
					temp_s << reg.erase(0, 2);
					temp_s >> temp_num;
					temp_num = temp_num + 13;
					usedsign[temp_num] = 1;
				}
			/*	temp_s << reg.erase(0,2);
				temp_s >> temp_num;
				usedsign[temp_num] = 1;*/
			}
		}
		int j;
		for (j = 0; j < 17; j++)
		{
			if (usedsign[j] == 0)
			{
				if (j < 8)
				{
					usedsign[j] = 1;
					stringstream temp_s;
					temp_s << j;
					REGISTER.insert(make_pair(stack[i], "$s" + temp_s.str()));
					alreadyallocated.push_back(stack[i]);
					alreadynum++;
					break;
				}
				else if (j >= 8 && j < 14)
				{
					usedsign[j] = 1;
					stringstream temp_s;
					temp_s << j - 4;
					REGISTER.insert(make_pair(stack[i], "$t" + temp_s.str()));
					alreadyallocated.push_back(stack[i]);
					alreadynum++;
					break;
				}
				else if(j >=14 && j < 17)
				{
					usedsign[j] = 1;
					stringstream temp_s;
					temp_s << j - 13;
					REGISTER.insert(make_pair(stack[i], "$a" + temp_s.str()));
					alreadyallocated.push_back(stack[i]);
					alreadynum++;
					break;
				}
/*				stringstream temp_s;
				temp_s << j;
				REGISTER.insert(make_pair(stack[i], "$s" + temp_s.str()));
				alreadyallocated.push_back(stack[i]);
				alreadynum++;
				break;    */
			}
		}
		if (j == 17)
			break;
	}

/*	map<string,string>::iterator  it=REGISTER.begin();
	for(;it!= REGISTER.end();++it)
	cout<<"key:"<<it->first << " "
	<<"value:"<<it->second<<endl;
	cout<<"----------------"<<endl;*/

	return;
}

/////////////////////////////////////
/////////////////////////////////////         dag图消除公共子表达式
bool search_dag(dagtree* tree, string name, dagele** ob)
{
	for (int i = 0; i < tree->element.size(); i++)
	{
		for (int j = 0; j < tree->element[i]->var.size(); j++)
		{
			if ((tree->element[i]->var[j].compare(name) == 0) && !(name[0] >= '0'&&name[0] <= '9'))
			{
				*ob = tree->element[i];
				return true;
			}
		}
	}
	return false;
}

bool search_op_dag(dagtree* tree,string op,string name,dagele* ob1,dagele* ob2,dagnode** ob)
{
	for (int i = 0; i < tree->element.size(); i++)
	{
		if ((tree->element[i]->nodevalue.compare(op) == 0) &&
			(tree->element[i]->leftChild == ob1) &&
			(tree->element[i]->rightChild == ob2))
		{
			dagele* obdagele;
			if (search_dag(tree, name, &obdagele))
			{
				for (int var_index = 0; var_index < obdagele->var.size(); var_index++)
				{
					if (obdagele->var[var_index].compare(name) == 0)
					{
						obdagele->var[var_index] = obdagele->var[var_index] + "$";
						if (obdagele->father.size() == 0)     //说明这一个赋值没有被应用到，可以直接删去
						{
							obdagele->var.erase(obdagele->var.begin() + var_index);
						}
					}
				}
			}
			tree->element[i]->var.push_back(name);
			*ob = tree->element[i];
			return true;
		}
	}
	return false;
}

void dag_opt()
{
	//int blockcount = -1;
	for (int i = 0; i < midcode_length; i++)
	{
/*		if (middlecode_list[i].op.compare("FSTART") == 0)
		{
			blockcount = -1;
		}
		if (middlecode_list[i].op.compare("LABEL") == 0)
		{
			blockcount++;
		}
		*/
		vector<dagtree*> dagtreelist;
		int codecount = 0;
		for (; (middlecode_list[i].op.compare("ADD") == 0) ||
			(middlecode_list[i].op.compare("SUB") == 0) ||
			(middlecode_list[i].op.compare("MUL") == 0) ||
			(middlecode_list[i].op.compare("DIV") == 0) ||
			(middlecode_list[i].op.compare("ASN") == 0) ||
			(middlecode_list[i].op.compare("GETAR") == 0); i++)
		{
			codecount++;
			if ((middlecode_list[i].op.compare("ADD") == 0) ||
				(middlecode_list[i].op.compare("SUB") == 0) ||
				(middlecode_list[i].op.compare("MUL") == 0) ||
				(middlecode_list[i].op.compare("DIV") == 0) ||
				(middlecode_list[i].op.compare("GETAR") == 0))
			{
				bool flag = false;
				dagele* ob1 = NULL;
				for (int j = 0; j < dagtreelist.size(); j++)
				{
					flag = search_dag(dagtreelist[j], middlecode_list[i].ob1, &ob1);
					if (flag)
						break;
				}
				if (!flag)
				{
					ob1 = new dagele;
					ob1->nodevalue = middlecode_list[i].ob1;
					ob1->var.push_back(middlecode_list[i].ob1);
					dagtree* new_dagTREE = new dagtree;
					new_dagTREE->element.push_back(ob1);
					dagtreelist.push_back(new_dagTREE);
				}
				///////////////
				flag = false;
				dagele* ob2 = NULL;
				for (int j = 0; j < dagtreelist.size(); j++)
				{
					flag = search_dag(dagtreelist[j], middlecode_list[i].ob2, &ob2);
					if (flag)
						break;
				}
				if (!flag)
				{
					ob2 = new dagele;
					ob2->nodevalue = middlecode_list[i].ob2;
					ob2->var.push_back(middlecode_list[i].ob2);
					dagtree* new_dagTREE = new dagtree;
					new_dagTREE->element.push_back(ob2);
					dagtreelist.push_back(new_dagTREE);
				}
				///////////////
				flag = false;
				dagele* ob3;
				for (int j = 0; j < dagtreelist.size(); j++)
				{
					flag = search_op_dag(dagtreelist[j], middlecode_list[i].op, middlecode_list[i].ob3, ob1, ob2, &ob3);
					if (flag)
						break;
				}
				if (!flag)     //没有找到符合条件的，即左右子孩子都符合条件且op也符合条件
				{
					dagele* obdagele;
					for (int tree_index = 0; tree_index < dagtreelist.size(); tree_index++)
					{
						if (search_dag(dagtreelist[tree_index], middlecode_list[i].ob3, &obdagele))
						{
							for (int var_index = 0; var_index < obdagele->var.size(); var_index++)
							{
								if (obdagele->var[var_index].compare(middlecode_list[i].ob3) == 0)
								{
									obdagele->var[var_index] = obdagele->var[var_index] + "$";
									if (obdagele->father.size() == 0)
									{
										obdagele->var.erase(obdagele->var.begin() + var_index);
									}
								}
							}
						}
					}
					ob3 = new dagele;
					ob3->nodevalue = middlecode_list[i].op;
					ob3->var.push_back(middlecode_list[i].ob3);
					ob3->leftChild = ob1;
					ob3->rightChild = ob2;
					ob1->father.push_back(ob3);
					ob2->father.push_back(ob3);
					int j;
					for (j = 0; j < dagtreelist.size(); j++)
					{
						bool breakflag = false;
						for (int p = 0; p < dagtreelist[j]->element.size(); p++)
						{
							if (dagtreelist[j]->element[p] == ob1)
							{
								breakflag = true;
								break;
							}
						}
						if (breakflag)
							break;
					}
					int k;
					for (k = 0; k < dagtreelist.size(); k++)
					{
						bool breakflag = false;
						for (int p = 0; p < dagtreelist[k]->element.size(); p++)
						{
							if (dagtreelist[k]->element[p] == ob2)
							{
								breakflag = true;
								break;
							}
						}
						if (breakflag)
							break;
					}

					dagtreelist[j]->element.push_back(ob3);
					if (j != k&&j < dagtreelist.size() && k < dagtreelist.size())   //将两棵树合并
					{
						for (int move = 0; move < dagtreelist[k]->element.size(); move++)
						{
							dagtreelist[j]->element.push_back(dagtreelist[k]->element[move]);
						}
						dagtreelist.erase(dagtreelist.begin() + k);
					}

				}

			}
			else
			{
				bool flag = false;
				dagele* ob1 = NULL;
				for (int j = 0; j < dagtreelist.size(); j++)
				{
					flag = search_dag(dagtreelist[j], middlecode_list[i].ob1, &ob1);
					if (flag)
						break;
				}
				if (!flag)
				{
					ob1 = new dagele;
					ob1->nodevalue = middlecode_list[i].ob1;
					ob1->var.push_back(middlecode_list[i].ob1);
					dagtree* new_dagTREE = new dagtree;
					new_dagTREE->element.push_back(ob1);
					dagtreelist.push_back(new_dagTREE);
				}
				///////////////
				dagele* obdagele;
				for (int tree_index = 0; tree_index < dagtreelist.size(); tree_index++)
				{
					if (search_dag(dagtreelist[tree_index], middlecode_list[i].ob3, &obdagele))
					{
						for (int var_index = 0; var_index < obdagele->var.size(); var_index++)
						{
							if (obdagele->var[var_index].compare(middlecode_list[i].ob3) == 0)
							{
								obdagele->var[var_index] = obdagele->var[var_index] + "$";
								if (obdagele->father.size() == 0)
								{
									obdagele->var.erase(obdagele->var.begin() + var_index);
								}
							}
						}
					}
				}
				ob1->var.push_back(middlecode_list[i].ob3);
			}
		}

		//cout << "在生成dag图的for成功跳出" << endl;
		///////////////////dag节点入栈
		///////////////////
		vector<dagele*> elestack;
		for (int j = 0; j < dagtreelist.size(); j++)
		{
			int k = dagtreelist[j]->element.size() - 1;
			while (1)
			{
				if (dagtreelist[j]->element.size() == 0)
					break;
				if (dagtreelist[j]->element[k]->father.size() == 0)
				{
					dagele* ele;
					ele = dagtreelist[j]->element[k];
					elestack.push_back(ele);
					dagtreelist[j]->element.erase(dagtreelist[j]->element.begin() + k);
					if (dagtreelist[j]->element.size() == 0)
						break;
					if (ele->leftChild != NULL)
					{
						//vector<dagele*>::iterator iter = ele->leftChild->father.begin();
						for (int iter = 0; iter < ele->leftChild->father.size();)
						{
							if (ele->leftChild->father[iter] == ele)
							{
								ele->leftChild->father.erase(ele->leftChild->father.begin() + iter);
							}
							else
								iter++;
						}
					}
					if (ele->rightChild != NULL)
					{
						//vector<dagele*>::iterator iter = ele->rightChild->father.begin();
						for (int iter = 0; iter < ele->rightChild->father.size();)
						{
							if (ele->rightChild->father[iter] == ele)
							{
								ele->rightChild->father.erase(ele->rightChild->father.begin() + iter);
							}
							else
								iter++;
						}
					}
					while ((ele->leftChild != NULL) && (ele->leftChild->father.size() == 0))
					{
						ele = ele->leftChild;
						for (int iter = 0; iter < dagtreelist[j]->element.size(); iter++)
						{
							if (dagtreelist[j]->element[iter] == ele)
							{
								elestack.push_back(ele);
								dagtreelist[j]->element.erase(dagtreelist[j]->element.begin() + iter);
								break;
							}
						}
						if (dagtreelist[j]->element.size() == 0)
							break;
						if (ele->leftChild != NULL)
						{
							//vector<dagele*>::iterator iter = ele->leftChild->father.begin();
							for (int iter = 0; iter < ele->leftChild->father.size();)
							{
								if (ele->leftChild->father[iter] == ele)
								{
									ele->leftChild->father.erase(ele->leftChild->father.begin() + iter);
								}
								else
									iter++;
							}
						}
						if (ele->rightChild != NULL)
						{
							//vector<dagele*>::iterator iter = ele->rightChild->father.begin();
							for (int iter = 0; iter < ele->rightChild->father.size();)
							{
								if (ele->rightChild->father[iter] == ele)
								{
									ele->rightChild->father.erase(ele->rightChild->father.begin() + iter);
								}
								else
									iter++;
							}
						}

					}
					k = dagtreelist[j]->element.size();
				}
				//cout << dagtreelist[j]->element.size() << endl;
				//cout << k << endl;
				///////////////////////
				k = (k == 0) ? dagtreelist[j]->element.size() - 1 : k - 1;
			//	cout << k << endl;
			}
		//	cout << "在生成dag图的for中的while成功跳出" << endl;
		}
		//cout << "在dag图的入栈for成功跳出" << endl;
/////////////////////////////////////////////////用得到的stack重新生成中间代码
		int countfinecode = 0;
		for (int k = elestack.size() - 1; k >= 0; k--)
		{
			if ((elestack[k]->nodevalue.compare("ADD") == 0) ||
				(elestack[k]->nodevalue.compare("SUB") == 0) ||
				(elestack[k]->nodevalue.compare("MUL") == 0) ||
				(elestack[k]->nodevalue.compare("DIV") == 0) ||
				(elestack[k]->nodevalue.compare("GETAR") == 0))
			{
				for (int var_count = 0; var_count < elestack[k]->var.size(); var_count++)
				{
					if (var_count == 0)
					{
						midcode code;
						code.op = elestack[k]->nodevalue;
						code.ob1 = elestack[k]->leftChild->var[0];
						code.ob2 = elestack[k]->rightChild->var[0];
						code.ob3 = elestack[k]->var[var_count];
						////////////////
						if (code.ob1.c_str()[strlen(code.ob1.c_str()) - 1] == '$')
						{
							code.ob1.erase(strlen(code.ob1.c_str()) - 1, 1);
						}
						if (code.ob2.c_str()[strlen(code.ob2.c_str()) - 1] == '$')
						{
							code.ob2.erase(strlen(code.ob2.c_str()) - 1, 1);
						}
						if (code.ob3.c_str()[strlen(code.ob3.c_str()) - 1] == '$')
						{
							code.ob3.erase(strlen(code.ob3.c_str()) - 1, 1);
						}

						if (code.ob1[0] == '\'')
						{
							code.ob1.erase(0, 1);
							code.ob1.erase(strlen(code.ob1.c_str()) - 1, 1);
						}
						if (code.ob2[0] == '\'')
						{
							code.ob2.erase(0, 1);
							code.ob2.erase(strlen(code.ob2.c_str()) - 1, 1);
						}
						middlecode_list[i - codecount + countfinecode] = code;
						countfinecode++;
					}
					else if (elestack[k]->var[var_count].substr(0, 4).compare("TEMP") != 0)
					{
						midcode code;
						code.op = string("ASN");
						code.ob1 = elestack[k]->var[0];
						code.ob2 = string("");
						code.ob3 = elestack[k]->var[var_count];
						////////////////
						if (code.ob1.c_str()[strlen(code.ob1.c_str()) - 1] == '$')
						{
							code.ob1.erase(strlen(code.ob1.c_str()) - 1, 1);
						}
						if (code.ob3.c_str()[strlen(code.ob3.c_str()) - 1] == '$')
						{
							code.ob3.erase(strlen(code.ob3.c_str()) - 1, 1);
						}

						if (code.ob1[0] == '\'')
						{
							code.ob1.erase(0, 1);
							code.ob1.erase(strlen(code.ob1.c_str()) - 1, 1);
						}
						middlecode_list[i - codecount + countfinecode] = code;
						countfinecode++;
					}
				}
			}
			else
			{
				for (int var_count = 1; var_count < elestack[k]->var.size(); var_count++)
				{
					midcode code;
					code.op = string("ASN");
					code.ob1 = elestack[k]->var[0];
					code.ob2 = string("");
					code.ob3 = elestack[k]->var[var_count];
					////////////////
					if (code.ob1.c_str()[strlen(code.ob1.c_str()) - 1] == '$')
					{
						code.ob1.erase(strlen(code.ob1.c_str()) - 1, 1);
					}
					if (code.ob3.c_str()[strlen(code.ob3.c_str()) - 1] == '$')
					{
						code.ob3.erase(strlen(code.ob3.c_str()) - 1, 1);
					}
		/*			if (code.ob1[0] == '\'')
					{
						code.ob1.erase(0, 1);
						code.ob1.erase(code.ob1.length - 1, 1);
					} */
					middlecode_list[i - codecount + countfinecode] = code;
					countfinecode++;
				}
			}
		}

		for (int k = i; k < midcode_length; k++)
		{
			middlecode_list[k - codecount + countfinecode] = middlecode_list[k];
		}
		midcode_length = midcode_length - codecount + countfinecode;

	}
	//cout << "out 最外面的for" << endl;
}
