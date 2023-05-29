/* gcc -g 49.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"
/* another interesting 'bug'. try to stay with the type
 * as much as you can, when changing types from long to int, 
 * and try to use the binary search caused increment errors 
 * that were hard to explain, when start was incremented as int, the
 * *start returned zero... after i switched back to long the bugs were gone.
 * I guess I still need a lot of time understanding the science of computer.
 */

int cf(const void *a, const void *b) {
	return (*(long *) a - *(long *) b);
}
int checkPerm(long a, long b);

int main()
{
	long size, size2;
	long *pn =  primeGen(10001, &size);
	//pnPrint(pn);
	//printf("\n%lu is the size\n", size);
	
	long *start = pn;
	while ((start - pn) < size) {
		start++;
		if (*start > 1000) 
			break;
	}		
	size2 = size - (start - pn);

	//printf("%lu is the start, %lu is the size.\n", *start, size2);
	long *second;
	long diff;
	long third;
	long *res;
	
	while (size2 > 2) {
		second = (start + 1);
		while ((second - start) <= size2) {
			if (checkPerm(*second, *start) == 0)
				diff = *second - *start;
			else {
				second++;
				continue;
			}

			third = *second + diff;
			if (third > 10000)
				break;
			else if (checkPerm(*second, third) != 0) {
				second++;
				continue; 
			}

			res = (long *) bsearch(&third, start, size2, sizeof(long), cf);
			if (res != NULL) {
				printf("%lu, ", *start);
				printf("%lu, ", *second);
				printf("%lu\n", *res);
			}
			second++;
		}
		start++;
		size2--;
	}
	
	return 0;
}

int checkPerm(long a, long b) 
{
	int mula = 1; /* multiplication of a */
	int mulb = 1; /* multiplication of b */ 
	int mod;
	int i;

	while (a > 0) {
		mod = a % 10;
		if (mod != 0) 
			mula *= mod;
		a /= 10;
	}
	while (b > 0) {
		mod = b % 10;
		if (mod != 0) 
			mulb *= mod;
		b /= 10;
	}

	return (mula - mulb);
}
