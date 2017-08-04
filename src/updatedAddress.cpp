#include "MASTER.h"
#include "tools.h"

string updatedAddress(string PC,map<string,string>&Memory){ 
	
	string command = Memory[PC];
	string opcode;
	if(command == "HLT" || command == "XCHG" || command == "CMA"){
		
		opcode = command;
	}
	else{
		
		const char *partition = command.c_str();
		char *temporary = (char*)partition;
		const char *delimiter = " ,";
		char *part = strtok(temporary,delimiter);
		 opcode = part;
	}
	int n = operationSize(opcode);
	string result;
	for(int j=1;j<=n;j++){
	
		int array[4]={-1,-1,-1,-1};
		result = "";
		hexToDecimal(PC,array);
		int i = 3;
		array[i]+=1;
		while(array[i]>=16){
		
			array[i] = array[i]%16;
			array[i-1]++;
			i--;
		}
		for(int i = 0;i<4;i++){
		
			if(array[i]>=0 && array[i]<=9)
				result = result + char('0' + array[i]);
			else
				result = result + char('A' + (array[i] - 10));
		}
		Memory[result] = Memory[PC];
		PC = result;
	}
	return PC;
}
