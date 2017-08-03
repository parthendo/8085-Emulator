#include "MASTER.h"
#include "tools.h"
void STA (string arg1,string registers[],bool flag[],map<string,string> &memory)
{
	int l1=arg1.length();
	if(l1==4)
	{
		if(validityAddress(arg1))
			memory[arg1]=registers[0];
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
