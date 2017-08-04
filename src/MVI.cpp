#include "MASTER.h"
#include "tools.h"

void MVI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory)
{
	int l1=arg1.length();
	int l2=arg2.length();
	if(l1==1&&l2==2)
	{
        if(arg1=="M")
        {
            string address=registers[5]+registers[6];
            if(validityData(arg2))
                memory[address]=arg2;
            else
			{
				cout<<"Error: "<<"Invalid content\nThe program will quit\n";
				exit(0);
			}
        }
		else if(validityRegisters(arg1)&&validityData(arg2)){
			
			/*if(arg1 == "A" && arg2 == "00"){
				
				flags[6] = true;
				flags[2] = true;
			}
			else if(arg1=="A" && arg2!="00")
            {
				string temp = arg2;
				int array[2];
                hexToDecimal(temp,array);
                int value=array[1]*16+array[0];
				//cout<<"just before --> "<<temp<<endl;
                bitset<8> dataInBinary(value);
                //cout<<"here\n";
                int parity = dataInBinary.count();
                //cout<<"i am\n";
                if(parity%2 == 0 && parity!=0)
                   flags[2] = true;
                else
                   flags[2] = false;
            }
			registers[registerNumber(arg1)]=arg2;*/
		}
		else
		{
			cout<<"Error: "<<"Invalid content\nThe program will quit\n";
			exit(0);
		}
	}
	else
	{
		cout<<"Error: "<<"Invalid content\nThe program will quit\n";
		exit(0);
	}
}
