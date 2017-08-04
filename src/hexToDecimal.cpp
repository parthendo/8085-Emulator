#include "MASTER.h"
#include <string>

void hexToDecimal(string pc,int arr[]){
 
	int l = pc.length();
	int p = 0;
	for(int i =0 ;i<l;i++){
	
		if(pc[i]>='0' && pc[i]<='9')
			arr[i] = pc[i] - '0';
		else 
			arr[i] = 10 + (pc[i] - 'A'); 
	}
}
