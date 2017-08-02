#include "MASTER.h"
#include "tools.h"

void SUI(string arg, string registers[],bool flag[]){

	int length = arg.length();
	if(length == 2){
	
		if(validityData(arg)){
			
			/*Performs immediate subtraction and stores in accumulator*/
			registers[0] = hexSub(arg,registers[0],flag,true);
		}
		else{
			
			cout<<"Error: "<<arg<<"\n";
			cout<<"This is an invalid data\n";
			exit(0);
			/*Error message of invalid data content*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\n";
		cout<<"You have tried to enter invalid data\nThe program will quit\n";
		exit(0);
		/*Error message of invalid data size*/
	}
	
}
