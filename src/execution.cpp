#include "MASTER.h"
#include "tools.h"
#include "arithmetic.h"
#include "load.h"
#include "logical.h"
#include "jump.h"

string nextAddress(string str,int n){

	int array[4];
	string result = "";
	hexToDecimal(str,array);
	int i = 3;
	array[i]+=n;
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
	return result;
}

string execution(string command, string Registers[], bool flag[], map<string,string>&memory,string programCounter){

	vector<string> commandPart;
	//string command = memory[programCounter];
	string inst;
	int commandSize;
	const char *partition = command.c_str();
	char *temporary = (char*)partition;
	const char *delimiter = " ,";
	char *part = strtok(temporary,delimiter);

	while(part!=NULL){

		inst = part;
		commandPart.push_back(inst);
		part = strtok(NULL,delimiter);

	}

	if(commandPart[0] == "MOV"){

			MOV(commandPart[1],commandPart[2],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "MVI"){

			MVI(commandPart[1],commandPart[2],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "LXI"){

			LXI(commandPart[1],commandPart[2],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "LDA"){

			LDA(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "STA"){

			STA(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "LHLD"){

			LHLD(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "SHLD"){

			SHLD(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "STAX"){

			STAX(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "XCHG"){

			XCHG(Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ADD"){

			ADD(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "ADI"){

			ADI(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "SUB"){

			SUB(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "SUI"){

			SUI(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "INR"){

			INR(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "DCR"){

			DCR(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "INX"){

			INX(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "DCX"){

			DCX(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "DAD"){

			DAD(commandPart[1],Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CMA"){

			CMA(Registers,flag);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "CMP"){

			CMP(commandPart[1],Registers,flag,memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	else if(commandPart[0] == "JMP"){

			return JMP(commandPart[1],Registers,flag);
	}
	else if(commandPart[0] == "JC"){

			return JC(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JNC"){

			return JNC(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JZ"){

			return JZ(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "JNZ"){

			return JNZ(commandPart[1],programCounter,Registers,flag);
	}
	else if(commandPart[0] == "SET"){

			SET(commandPart[1],commandPart[2],memory);
			commandSize = operationSize(commandPart[0]);
			return nextAddress(programCounter,commandSize);
	}
	return "";
}
