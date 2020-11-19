#include "MASTER.h"
#include "tools.h"

void MOV (string argument1,string argument2,string registers[],bool flag[],map<string,string> &memory)
{
	int l1=argument1.length();
	int l2=argument2.length();
	if(l1==1&&l2==1){
        	if(argument1=="M"&&argument2!="M" && validityRegisters(argument2)){
            		string address=registers[5]+registers[6];
            		memory[address]=registers[registerNumber(argument2)];
        	}
        	else if(argument1!="M" && argument2=="M" && validityRegisters(argument1)){
            		string address=registers[5]+registers[6];
            		registers[registerNumber(argument1)]=memory[address];
            	}
        	else if(argument1!="M"&&argument2!="M" && validityRegisters(argument2)&&validityRegisters(argument1)){
               	registers[registerNumber(argument1)]=registers[registerNumber(argument2)];
		}
		else{
			cout<<"Error: "<<"Invalid content\nThe program will quit\n";
			exit(0);
		}
	}
}
