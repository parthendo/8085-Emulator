#include "MASTER.h"
#include "tools.h"
void CMA(string registers[],bool flags[])
{
	string complment = complement(registers[0]);
	registers[0] = complment;
	if(registers[0]=="00")
    {
        flags[6] = true;
        flags[2] = true;
    }
    else
    {
        string temp = registers[0];
		int array[2];
		hexToDecimal(temp,array);
		int value=array[1]*16+array[0];
		bitset<8> dataInBinary(value);
		int parity = dataInBinary.count();
		if(parity%2 == 0 && parity!=0)
			flags[2] = true;
		else
			flags[2] = false;
    }
}
