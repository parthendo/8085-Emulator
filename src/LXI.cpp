#include "MASTER.h"
#include "tools.h"
void LXI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory)
{
	int l1=arg1.length();
	int l2=arg2.length();
	if(l1==1&&l2==4)
	{
		if(arg1=="M")
		{
			if(validityAddress(arg2))
			{
				string part1="",part2="";
				for(int i=0;i<2;i++)
				{
					part1+=arg2[i];
					part2+=arg2[i+2];
				}
				registers[5]=part1;
				registers[6]=part2;
			}
			else
			{
				cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid content\nThe program will quit\n";
				exit(0);
			}
		}
		else
		{
			if(validityRegisterPair(arg1)&&validityAddress(arg2))
			{
				string part1="",part2="";
				for(int i=0;i<2;i++)
				{
					part1+=arg2[i];
					part2+=arg2[i+2];
				}
				registers[registerNumber(arg1)]=part1;
				registers[registerNumber(arg1)+1]=part2;
			}
			else
			{
				cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid content\nThe program will quit\n";
				exit(0);
			}
		}
	}
	else
	{
		cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid arguments\nThe program will quit\n";
				exit(0);
		}
}
