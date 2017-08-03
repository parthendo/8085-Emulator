#include "MASTER.h"
#include "tools.h"
void CMP (string arg1,string registers[],bool flag[],map<string,string> &memory)
{
	int l1=arg1.length();
	if(l1==1)
	{
		if(arg1=="M")
		{
		    string address=registers[5]+registers[6];
			if(registers[0]<memory[address])
			{
			    flag[0]=true;
			}
			else if(registers[0]==memory[address])
			{
				flag[6]=true;
				//cout<<"zero set\n";
			}
			else
			{
				//cout<<"both reset\n";
				flag[0]=false;
				flag[6]=false;
			}
		}
		else if(validityRegisters(arg1))
		{
			int index=registerNumber(arg1);
    		if(registers[0]<registers[index])
    		{
				//cout<<"carry set\n";
				flag[0]=true;
			}
			else if(registers[0]==registers[index])
			{
				//cout<<"zero set\n";
				flag[6]=true;
			}
			else
			{
				//cout<<"both reset\n";
			    flag[0]=false;
				flag[6]=false;
			}
		}
		else{
			
			cout<<"Error: "<<arg1<<"\nInvalid registers\nThe program will quit\n";
			exit(0);
		}
	}
	else{
		
		cout<<"Error: "<<arg1<<"\nInvalid argument\nThe program will quit\n";
		exit(0);
	}
}
