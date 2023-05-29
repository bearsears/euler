#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"

int main() 
{
	long size;
	long *pnumbers = primeGen(100000000, &size);
	pnPrint(pnumbers);

	return 0;
}
