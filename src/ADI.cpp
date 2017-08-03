#include "MASTER.h"
#include "tools.h"

void ADI(string arg, string registers[],bool flag[]){

	int length = arg.length();
	if(length == 2){
	
		if(validityData(arg)){
			
			/*Performs immediate addition and stores in accumulator*/
			registers[0] = hexAdd(arg,registers[0],flag,true);
		}
		else{
			
			cout<<"Error: "<<arg<<"\nInvalid data content\nThe program will quit\n";
			exit(0);
			/*Error message of invalid data content*/
		}
	}
	else{
		
		cout<<"Error: "<<arg<<"\nInvalid data size\nThe program will quit\n";
		exit(0);
		/*Error message of invalid data size*/
	}
	
}
