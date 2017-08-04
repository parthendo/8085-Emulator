#include "MASTER.h"
/* This function takes in a complete command as an input and breaks it in 
	operand and opcode and checks the size of the command */
	
int operationSize(string str){

	string one[] = {"HLT","MOV","STAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP"};
	string two[] = {"MVI","ADI","SUI"};
	string three[] = {"LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ","SET"};
	const char *ch = str.c_str();
	char *var = (char*)ch;
	const char *delimiter = " ,";
	char *pch = strtok (var,delimiter);
	string query = pch;
	
	int length = sizeof(one)/sizeof(one[0]);
	for(int i=0;i<length;i++){
		
		if(one[i] == query)
			return 1;
	}
	length = sizeof(two)/sizeof(two[0]);
	for(int i=0;i<length;i++){
		
		if(two[i] == query)
			return 2;
	}
	length = sizeof(three)/sizeof(three[0]);
	for(int i=0;i<length;i++){
		
		if(three[i] == query)
			return 3;
	}
	return 0;
}
