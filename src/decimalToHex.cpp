#include "MASTER.h"

string decimalToHex(int deciml[])
{
	string hex="";
	int size = *(&deciml+1)-deciml;
	//int size=sizeof(deciml)/sizeof(deciml[0]);
	for(int i=0;i<size;i++)
	{
		if(deciml[i]>=0 && deciml[i]<=9)
			hex = hex + char('0' + deciml[i]);
		else if(deciml[i]>=10 && deciml[i]<=15)
			hex+=(char)('A'+(deciml[i]-10));
	}
	return hex;
}
