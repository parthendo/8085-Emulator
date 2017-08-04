#include "MASTER.h"
#include "tools.h"
using namespace std;

void LDA (string arg1,string registers[],bool flag[],map<string,string> &memory)
{
	int l1=arg1.length();
	if(l1==4)
	{
		if(validityAddress(arg1)){

			/*if(memory[arg1] == "00"){
				
				flag[6] = true;
				flag[2] = true;
			}
			else
			{
				string temp = memory[arg1];
				int array[2];
                hexToDecimal(temp,array);
                int value=array[1]*16+array[0];
                bitset<8> dataInBinary(value);
                int parity = dataInBinary.count();
                if(parity%2 == 0 && parity!=0)
                   flag[2] = true;
                else
                   flag[2] = false;
			}*/
			registers[0] = memory[arg1];
		}
		else
		{
			cout<<"Error: "<<arg1<<"\nInvalid address\nThe program will quit\n";
				exit(0);
		}
	}
	else
	{
		cout<<"Error: "<<arg1<<"\nInvalid arguments\nThe program will quit\n";
				exit(0);
	}
}
