#include"MASTER.h"
string complement(string a)
{
	int l=a.length();
	string complement="";
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			int diff=15-(a[i]-'0');
			if(diff>=0&&diff<=9)
				complement+=('0'+diff);
			else if(diff>=10&&diff<=15)
				complement+=('A'+(diff-10));	
		}
		if(a[i]>='A'&&a[i]<='F')
		{
			int value=a[i]-'A';
			int diff=15-value;
			if(diff>=0&&diff<=9)
				complement+=('0'+diff);
			else if(diff>=10&&diff<=15)
				complement+=('A'+(diff-10));
		}
	}
	return complement;
}
