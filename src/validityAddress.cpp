#include "header/MASTER.h"
#include <string>
using namespace std;

bool validityAddress(string data)
{
	bool flag;
	int l=data.length();
	for(int i=0;i<l;i++){
		if(( data[i]>='0' && data[i]<='9')||( data[i]>='A' && data[i]<='F' ))
			flag = true;
		else{		
			flag = false;
			break;
		}
	}
	return flag;
}
