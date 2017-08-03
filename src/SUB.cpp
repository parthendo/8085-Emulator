#include "MASTER.h"
#include "tools.h"

void SUB(string arg1,string registers[],bool flag[],map<string,string>&memory){
	
	int length=arg1.length();
	if(length == 1){
		
		if(validityRegisters(arg1)){
			
			if(arg1 != "M"){
			
				/*Fetches index of register to access array string registers[]*/
				int registerID = registerNumber(arg1);              
				/*Converting decimal value to string format and storing in accumulator*/
				registers[0] = hexSub(registers[registerID],registers[0],flag,true);
				
			}
			else{                         
		
				/*Fetches data of HL pair*/
				string address = "";
				address = address + registers[5] + registers[6];
				if(address >= "0000" && address <= "FFFF"){
				
					/*Converting decimal value to string format and storing in accumulator*/
					registers[0] = hexSub(memory[address],registers[0],flag,true);				
					
				}
				else{
					cout<<"Error: "<<arg1<<"\nAddress out of bounds\nThe program will quit\n";
					exit(0);
					/*error message of address out of bounds*/
				}						
			}
		}
		else{
			cout<<"Error: "<<arg1<<"\nInvalid register details\nThe program will quit\n";
			exit(0);
			/*error of invalid register details*/
		}
	}
	else{
		cout<<"Error: "<<arg1<<"\nInvalid arguments\nThe program will quit\n";
		exit(0);
		/*Error message of invalid arguments*/
	}
}
