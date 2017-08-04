#include "MASTER.h"
#include <fstream>
#include <set>
#include "tools.h"

class executionPhase
{
	public:
		void executionNormal(string pc,map<string,string>&Memory,vector<string>&sequence,bool flag[],string registers[])
		{
			int size=sequence.size();
			for(int i=0;i<size;i++)
			{
				pc=execution(Memory[sequence[i]],registers,flag,Memory,pc);
			}
		}
		void executionDebugger(string pc,map<string,string>&Memory,vector<string>&sequence,bool flag[],string registers[])
		{
			string option;
			set<int>breakpoints;
			set<int>::iterator it;
			cout<<"Enter Options:-\n";
			while(true)
			{
				cout<<"-> ";
				cin>>option;
				if(option == "help")
				{
					char line;
					ifstream write("help.txt");
					while(write.get(line))
					{
						if(write.eof())
						{
							write.close();
							break;
						}
						cout<<line;
					}
					write.close();
				}
				else if(option == "PC"){
					
					cout<<"Program counter --> "<<pc<<"\n";
				}
				else if(option=="p"||option=="print")
				{
					string valueHolder;
					cin>>valueHolder;
					cin.ignore();
					int l=valueHolder.length();
					if(l==1)
					{
						if(validityRegisters(valueHolder))
							cout<<registers[registerNumber(valueHolder)]<<"\n";
						else
							cout<<"Error: "<<valueHolder<<" You have entered invalid register name\n"<<"Type 'help' for more information\n";
					}
					else if(l==4)
					{
						if(validityAddress(valueHolder))
							cout<<Memory[valueHolder]<<"\n";
						else
							cout<<"Error: "<<valueHolder<<" You have entered invalid address\n"<<"Type 'help' for more information\n";
					}
					else
							cout<<"Error: "<<valueHolder<<"\nType 'help' for more information\n";
				}
				else if(option=="q"||option=="quit")
					break;
				else if(option=="break"||option=="b")
				{
					int lineNumber;
					cin>>lineNumber;
					breakpoints.insert(lineNumber);
				}
				else if(option=="s"||option=="step")
				{
					if(pc!="")
						pc = execution(Memory[pc],registers,flag,Memory,pc);
				}
				else if(option=="r"||option=="run")
				{
					if(pc != ""){
					
						if(breakpoints.empty()){
						
							while(true){
								
								if(Memory[pc] == "HLT"){
									
									pc = "";
									break;
								}
								else
									pc = execution(Memory[pc],registers,flag,Memory,pc);
							}
						}
						else{
						
							it = breakpoints.begin();
							int var = *it;
							while(pc!=sequence[var]){
							
								pc = execution(Memory[pc],registers,flag,Memory,pc);
							}
							breakpoints.erase(it);
						}
					}
					else{
							char choice='\0';
							cout<<"You have reached till the end of execution. Press to continue[Y/n] ";
							cin>>choice;
							if(choice == 'Y' || choice == 'y'){
								continue;
							}
							else if(choice == 'N' || choice == 'n')
							exit(0);
							else
							cout<<"Please input correct option\n";
								continue;
					}
				}
				else
				{
					cout<<"Invalid choice has been entered. Type 'help' for more information about debugger\n";
				}
			}
		}
};
