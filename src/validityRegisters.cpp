#include "header/MASTER.h"
bool validityRegisters(string reg)
{
	if(reg=="A"||reg=="B"||reg=="C"||reg=="D"||reg=="E"||reg=="H"||reg=="L")
		return true;
	else
		return false;
}
