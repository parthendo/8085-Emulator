#include "MASTER.h"
#include <fstream>
#include "executionPhase.cpp"
#include "tools.h"

class simulator8085
{
private:
     map<string,string> Memory;
     vector<string>sequence;
     string start;
     string pc;
     bool flag[8];
     string registers[7];
public :
	simulator8085(){
		
		for(int i = 0;i<7;i++)
			registers[i] = "NULL";
		
		for(int i=0;i<8;i++)
			flag[i] = false;
		
		start = "";
		pc = "";
	}
    void input()
    {
        cout<<"\nEnter the starting address:\n";
        cin>>start;
        pc = start;
        if(!validityAddress(start)){
			
			cout<<"The memory you entered either does not exist or is reserved by the system\nPlease re-enter the program from a new memory location\nThe program will quit\n";
			exit(1);
		}
        sequence.push_back(start);
    }
    void programFileWithDebugger(char* filename)
    {
        ifstream input;
        executionPhase obj;
		input.open(filename);
		if(input.fail() == true){
			
			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
			exit(0);
		}
		string line;
		while(1)
		{
		    getline(input,line);
			if(validityFile(line))
			{
                Memory[pc]=line;
				pc=updatedAddress(pc,Memory);
				if(line=="HLT")
					break; 
				sequence.push_back(pc);
			}
			else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
		}
		obj.executionDebugger(start,Memory,sequence,flag,registers);
    }
    void onlyProgramFile(char* filename)
    {
        ifstream input;
        executionPhase obj;
        input.open(filename);
        if(input.fail() == true){
			
			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
			exit(0);
		}
        string line;
        while(1)
        {
            getline(input,line);
            if(validityFile(line))
            {
                Memory[pc]=line;
                pc=updatedAddress(pc,Memory);
                if(line=="HLT")
					break;
                sequence.push_back(pc);
			}else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
        }
        obj.executionNormal(start,Memory,sequence,flag,registers);
    }
    void onlyDebugger()
    {
		cin.ignore();
        executionPhase obj;
        cout<<"\nStart typing your code from here:\n";
		while(1)
		{
			cout<<">> "<<pc<<" ";
			string line;
			getline(cin,line);
			if(validityFile(line))
			{
			   	Memory[pc]=line;
				pc=updatedAddress(pc,Memory);
				if(line == "HLT"){
					break;
				sequence.push_back(pc);
				}
			}
			else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
		}
		obj.executionDebugger(start,Memory,sequence,flag,registers);
    }
    void noInput()
    {
		cin.ignore();
        string line;
        executionPhase obj;
        cout<<"\nStart typing your code from here:\n";
		while(1)
		{
			cout<<">> "<<pc<<" ";
			getline(cin,line);
			if(validityFile(line))
			{
			 	Memory[pc]=line;
				pc=updatedAddress(pc,Memory);
				if(line=="HLT")
					break;
				sequence.push_back(pc);
			}else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
		}
		obj.executionNormal(start,Memory,sequence,flag,registers);
    }
};

int main(int argc,char* argv[])
{
    simulator8085 instance;
    instance.input();
    if(argc==2)
    {
	if(strcmp(argv[1],"--debugger")==0)
        {
            instance.onlyDebugger();
        }
        else
        {
            instance.onlyProgramFile(argv[1]);
        }
    }
    else if(argc==1)
    {
        instance.noInput();
    }
    else if(argc==3)
    {
	instance.programFileWithDebugger(argv[1]);
    }
}
