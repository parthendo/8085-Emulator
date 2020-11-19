#include "header/MASTER.h"
#include "header/tools.h"
void SHLD (string arg1, string registers[],bool flag[], map<string,string> &memory){
	int l1=arg1.length();
	if(l1 == 4 && validityAddress(arg1) && registers[5]!="" && registers[6]!="" && memory.empty() == false){
		memory[arg1]=registers[6];
		memory[increaseAddress(arg1)]=registers[5];
	}
	else{
		cout<<"Error: "<<arg1<<"\nInvalid content\nThe program will quit\n";
	}
}
