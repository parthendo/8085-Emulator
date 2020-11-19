#include "MASTER.h"
#include "tools.h"

void MVI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory){
	int l1=arg1.length();
	int l2=arg2.length();
	if(l1==1&&l2==2){
        	if(arg1=="M"){
            		string address=registers[5]+registers[6];
            		if(validityData(arg2))
                		memory[address]=arg2;
            		else{
				cout<<"Error: "<<"Invalid content\nThe program will quit\n";
				exit(0);
				}
        	}
		else if(validityRegisters(arg1)&&validityData(arg2)){	
			cout << "Do Nothing\n";
		}
		else{
			cout<<"Error: "<<"Invalid content\nThe program will quit\n";
			exit(0);
		}
	}
	else{
		cout<<"Error: "<<"Invalid content\nThe program will quit\n";
		exit(0);
	}
}
