/* to compile this program, 
 * gcc -g 27.c primeGen.c -o go -lm 
 * to compile the program 
 */
#include <stdlib.h>
#include <stdio.h>
#include "primeGen.h"

int cmpfunc(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int main ()
{
	long sz = 0;
	long *size = &sz;
	long *pn = primeGen(1000, size);
	long *b = pn + *size - 1;
	long *a = pn + *size - 2;
	pnPrint(pn);
	printf("\n%lu is the size \n", *size);

	long sz2 = 0;
	long *size2 = &sz2;
	long *pn2 = primeGen(2500000, size2);
	//pnPrint(pn2);
	//printf("\n%lu is the size \n", *size2);
	long *isPrime;

	long n = 0;
	long result;
	long nmax = 0;
	long amax = 0;
	long bmax = 0;

	for ( ; (b - pn) >= 0; b--) {
	/*
		for ( a = (b - 1); (a - pn) >= 0; a--) {
			n = 1;
			result = n * n + *a * n + *b;
			//printf("a %i, b %i\n", *a, *b);
			isPrime = (long *) bsearch(&result, pn2, sz2, sizeof(long), cmpfunc);
			while (isPrime != NULL) {
		//		printf("a %lu, b %lu, n %lu, result %lu\t", *a, *b, n, result);
				n++;
				result = n * n + *a * n + *b;
				isPrime = (long *) bsearch(&result, pn2, sz2, sizeof(long), cmpfunc);
			}
			if (n > nmax) {
				nmax = n;
				bmax = *b;
				amax = *a;
			}
		//	printf("\n-------------------\n");	
		}
		*/

		for ( a = (b - 1); (a - pn) >= 0; a--) {
			n = 1;
			result = n * n + -(*a * n) + *b;
			//printf("a %i, b %i\n", *a, *b);
			isPrime = (long *) bsearch(&result, pn2, sz2, sizeof(long), cmpfunc);
			while (isPrime != NULL) {
		//		printf("a %lu, b %lu, n %lu, result %lu\t", *a, *b, n, result);
				n++;
				result = n * n + -(*a * n)+ *b;
				isPrime = (long *) bsearch(&result, pn2, sz2, sizeof(long), cmpfunc);
			}
			if (n > nmax) {
				nmax = n;
				bmax = *b;
				amax = *a;
			}
		//	printf("\n-------------------\n");	
		}
	}
	printf("b: %lu, a: %lu, n: %lu\n", bmax, amax, nmax);
	return 0;
}

