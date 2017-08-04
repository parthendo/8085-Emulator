#include"MASTER.h"
bool validityRegisterPair(string reg)
{
	if(reg=="B"||reg=="D"||reg=="H"||reg=="M")
		return true;
	else 
		return false;
}
