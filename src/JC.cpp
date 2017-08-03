#include "MASTER.h"
#include "tools.h"

string JC(string arg, string programCounter, string Registers[],bool flag[]){

	if(flag[0] == true)
		return arg;
	else{
		
		string resultant = "";
		int value16bit[4];
		int returnValue[] = {0,0,0,3};
		int carry = 0;
		hexToDecimal(programCounter,value16bit);	  
		for(int i = 3;i>=0;i--){
					
			int value = value16bit[i] + returnValue[i] + carry;
			carry = value / 16;
			value = value % 16;
			if(value>=0 && value<=9)
				resultant = (char)('0'+value) + resultant;
			else{
				resultant = (char)('A'+(value-10)) + resultant;
			}
		}
		if(validityAddress(resultant))
			return resultant;
		else{
			
			cout<<"Error: "<<arg<<"\nAddress overflow\nThe program will quit\n";
				exit(0);
		}
	}
}
