#include "MASTER.h"
#include "tools.h"

string JMP(string arg, string Registers[],bool flag[]){

	if(validityAddress(arg))
		return arg;
	else{
		
		cout<<"Error encountered in: "<<arg<<"\n";
		cout<<"The program will quit\n";
		exit(0);
	}
}
