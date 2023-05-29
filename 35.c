/* gcc -g 35.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "primeGen.h"

int cf(const void *a, const void *b)
{
	return (*(int *) a - *(int *) b);
}
int main() 
{
	int i; 
	int temp;
	int length;
	long size;
	long *pnumbers = primeGen(1000000, &size);
	int *found;
	int pcount; /* prime count */
	int pof; /* to the power of */

	for (i = 1; i < 1000000; i += 2) {
		temp = i;
		length = 0;
		found = bsearch(&temp, pnumbers, size, sizeof(long), cf);
		if (found != NULL) {
			pcount = 1;
			//printf("%i ", i);
			while (temp != 0) {
				length++;
				temp /= 10;
			}
			pof = length - 1; /* 1000 has length of 4, */
			/* so 10 ^ 3 should be 1000, resulting pof = length -1
			 */
		
			temp = (i / 10) + (i % 10 * (int) pow(10, pof));
			found = bsearch(&temp, pnumbers, size, sizeof(long), cf);
			while ((i != temp) && (found != NULL)) {
			//	printf("%i ", temp);
				temp = (temp / 10) + (temp % 10 * (int) pow(10, pof));
				found = bsearch(&temp, pnumbers, size, sizeof(long), cf);
				pcount++;
			}
			//printf("\n");
		}
		if (pcount == length)
			printf("%i\t", i);
	}

	return 0;
}
