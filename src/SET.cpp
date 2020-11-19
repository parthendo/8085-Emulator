#include "MASTER.h"
#include "tools.h"

void SET(string arg1,string arg2,map<string,string> &memory){
	int l1=arg1.length();
	int l2=arg2.length();
	if(l1==4 && l2==2 && validityAddress(arg1)&&validityData(arg2))
		memory[arg1]=arg2;
	else{
		cout<<"Error: "<<arg1<<" & "<<arg2<<"\nInvalid arguments\nThe program will quit\n";
		exit(0);
	}
}
