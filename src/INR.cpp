#include "MASTER.h"
#include "tools.h"

void INR(string arg,string registers[],bool flag[],map<string,string>&memory){

	int length = arg.length();
	if(length == 1){
	
		if(validityRegisters(arg)){
		
			if(arg != "M"){
				
				/*Performs INR on a register*/
				int registerID = registerNumber(arg);
				registers[registerID] = hexAdd(registers[registerID],"01",flag,false); 
			}
			else{
				/*Performs DCR on HL pair*/
				string address = "";
				address = address + registers[5] + registers[6];
				if(validityAddress(address)){
				
					memory[address] = hexAdd(memory[address],"01",flag,false);
				}
				else{
					
					cout<<"Error: "<<arg<<"\nAddress out of bounds\nThe program will quit\n";
					exit(0);
				}
			}
		}
		else{
			
			cout<<"Error: "<<arg<<"\nInvalid register details\nThe program will quit\n";
			exit(0);
			/*Error:Invalid Register*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid argument type\nThe program will quit\n";
		exit(0);
		/*Error: Invalid argument type*/
	}
}
