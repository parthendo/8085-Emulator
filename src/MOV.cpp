#include "MASTER.h"
#include "tools.h"

void MOV (string argument1,string argument2,string registers[],bool flag[],map<string,string> &memory)
{
	int l1=argument1.length();
	int l2=argument2.length();
	if(l1==1&&l2==1)
	{
        if(argument1=="M"&&argument2!="M")
        {
            if(validityRegisters(argument2))
            {
                string address=registers[5]+registers[6];
                memory[address]=registers[registerNumber(argument2)];
            }
            else
			{
				cout<<"Error: "<<argument1<<" & "<<argument2<<"\nInvalid registers\nThe program will quit\n";
				exit(0);
			}
        }
        else if(argument1!="M" && argument2=="M")
        {
            if(validityRegisters(argument1))
            {
                string address=registers[5]+registers[6];
                /*if(argument1 == "A" && memory[address] == "00")				{

                    flag[6] = true;
                    flag[2] = true;
                    }
                else if(argument1=="A" && memory[address]!="00")
                {
					string temp = memory[address];
					int array[2];
                    hexToDecimal(temp,array);
                    int value=array[1]*16+array[0];
					//cout<<"just before --> "<<temp<<endl;
                    bitset<8> dataInBinary(value);
                    //cout<<"here\n";
                    int parity = dataInBinary.count();
                    //cout<<"i am\n";
                    if(parity%2 == 0 && parity!=0)
                        flag[2] = true;
                    else
                        flag[2] = false;
                }*/
                //cout<<"bryan\n";
                registers[registerNumber(argument1)]=memory[address];
            }
            else
			{
				cout<<"Error: "<<argument1<<" & "<<argument2<<"\nInvalid registers\nThe program will quit\n";
				exit(0);
			}
        }
        else if(argument1!="M"&&argument2!="M")
        {
            if(validityRegisters(argument2)&&validityRegisters(argument1)){
				/*if(argument1 == "A" && registers[registerNumber(argument2)] == "00"){

					flag[6] = true;
					flag[2] = true;
				}
				else if(argument1=="A" && registers[registerNumber(argument2)]!="00")
                {
					string temp=registers[registerNumber(argument2)];
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
               registers[registerNumber(argument1)]=registers[registerNumber(argument2)];
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
	else
	{
		cout<<"Error: "<<"Invalid content\nThe program will quit\n";
		exit(0);
	}
}
