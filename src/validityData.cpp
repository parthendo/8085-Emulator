#include "MASTER.h"
bool validityData(string a)
{
	int l=a.length();
	if(l==2)
	{
		if((a[0]>='0'&&a[0]<='9')||(a[0]>='A'&&a[0]<='F'))
		{
			if((a[1]>='0'&&a[1]<='9')||(a[1]>='A'&&a[1]<='F'))
				return true;
			else 
				return false;
		}
		else
			return false;
	}
	else 
		return false;
}
