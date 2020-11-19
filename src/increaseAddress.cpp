#include "header/MASTER.h"

string increaseAddress(string a)
{
	int number[5];
	string nextAddress="";
	int l=a.length();
	for(int i=l-1;i>=0;i--)
	{
		if(a[i]>='A'&&a[i]<='F')
			number[i]=(int)(10+(a[i]-'A'));
		if(a[i]>='0'&&a[i]<='9')
			number[i]=(int)(a[i]-'0');
	}
	number[l-1]++;
	for(int i=l-1;i>=0;i--)
	{
		if(number[i]>=0&&number[i]<=15)
			break;
		if(number[i]>=16)
		{
			number[i]=number[i]%16;
			number[i-1]++;
		}
	}
	for(int i=0;i<l;i++)
	{
		if(number[i]>=0&&number[i]<=9)
			nextAddress+=(char)('0'+(number[i]));
		else if(number[i]>=10 && number[i]<=15)
			nextAddress+=(char)('A'+(number[i]-10));
	}
	return nextAddress;
}
