#include "header/MASTER.h"

bool isHexadecimal(char a){

	if((a>='0' && a<='9') || (a>='A' && a<='F'))
		return true;
	else
		return false;
}

bool validityData(string a){

	int l=a.length();
	if(l==2 && isHexadecimal(a[0]) && isHexadecimal(a[1]))
		return true;
	else 
		return false;
}
