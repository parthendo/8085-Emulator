#include"MASTER.h"
string hexAdd16bit (string arg1,string arg2,bool flag[],bool check)
{
	int l1=arg1.length();
	int l2=arg2.length();
	string hex="";
	if(l1==1&&l2==4)
	{
		int value1[4]={0,0,0,0};
		for(int i=0;i<l1;i++)
		{
			if(arg1[i]>='0'&&arg1[i]<='9')
				value1[i]=(int)(arg1[i]-'0');
			else if(arg1[i]>='A'&&arg1[i]<='Z')
				value1[i]=(int)(arg1[i]-'A');
		}
		int i=l1-1;
		value1[l1-1]++;
		while(value1[i]>=16)
		{
			value1[i]=value1[i]%16;
			if(i==0)
			{
				flag[0]=true;
				break;
			}
			else
				value1[--i]++;
		}
		int value=value1[0]*16*16*16+value1[1]*16*16+value1[2]*16+value1[3];
		bitset<16>str(value);
		flag[7]=str[15];
		int parity=str.count();
		if(parity==0)
			flag[6]=true;
		else if(parity%2==0)
			flag[2]=true;
		else if(parity%2==1)
			flag[2]=false;
		for(int i=0;i<l1;i++)
		{
			if(value1[i]>=0&&value1[i]<=9)
				hex+=(char)value1[i];
			else if(value1[i]>=10&&value1[i]<=15)
				hex+=(char)('A'+(value1[i]-10));
		}
	}
	return hex;
}
