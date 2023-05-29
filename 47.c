/* gcc -o 47.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"
#define END 1000000
#define CN 4
/* another thing i learned today. NEVER pass a pointer without allocating 
 * how much memory it will have. */

int main() 
{
	long size;
	long *p = primeGen((END / 2), &size);
	//pnPrint(p);

	long n = 100;
	long limit;
	long *d = p;
	long i = 0;
	long lt = n; /* last term */ 
	long inrow = 1; /* numbers in row */

	while (n < END) {
		limit = n / *d;
		
		while ((i < CN) && (limit >= *d)) {
			//printf("help.\n");
			if ((n % *d) == 0) {
				i++;
				limit = n / *d;
			}
			d++;
		}
		if ((i == CN) && (n - lt) == 1) {
			//printf("%lu\t", n);
			inrow++;
			lt = n;
		}
		else if (i == CN) {	
			//printf("\n%lu\t", n);
			inrow = 1; /* reset */
			lt = n;
		}

		if (inrow == CN) {
			printf("\n%lu\t", n);
			break;
		}
			
		d = p;
		i = 0;
		n++;
	}

	free(p);

	return 0;
}
