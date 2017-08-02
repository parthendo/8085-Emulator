#include "MASTER.h"
#include "tools.h"

void DCR(string arg,string registers[],bool flag[],map<string,string>&memory){

	int length = arg.length();
	if(length == 1){
	
		if(validityRegisters(arg)){
		
			if(arg != "M"){
				
				/*Performs INR on a register*/
				int registerID = registerNumber(arg);
				registers[registerID] = hexSub(registers[registerID],"01",flag,false);
			}
			else{
				/*Performs DCR on HL pair*/
				string address = "";
				address = address + registers[5] + registers[6];
				if(validityAddress(address)){
				
					memory[address] = hexSub(memory[address],"01",flag,false);
				}
				else{
					cout<<"Error: "<<arg<<"\nInvalid register details\nThe program will quit\n";
					exit(0);
					/*Error:Address out of bounds*/
				}
			}
		}
		else{
			cout<<"Error: "<<arg<<"\nInvalid register\nThe program will quit\n";
			exit(0);
			/*Error:Invalid Register*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid argument\nThe program will quit\n";
				exit(0);
		/*Error: Invalid argument type*/
	}
}
