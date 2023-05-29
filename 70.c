/* gcc -g 70.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"
#define end 10150000

int permutationCheck(long m, long n);

int main() 
{
	long size;
	long *pnumbers = primeGen(end, &size);
	//pnPrint(pnumbers);
	printf("\n%lu is the size\n", size);
	
	pnumbers += 4; /* should get me to 11; */
	long limit = end / *pnumbers;
	long *pnn = pnumbers + 1;
	printf("%lu, %lu, %lu\n", *pnumbers, *pnn, limit);
	long n, to, nmax;
	int result = 0;
	double ndivto = 2;
	double temp;


	while (*pnumbers < limit) {
		while (*pnn <= limit) {
			n = *pnumbers * *pnn;	
			to = (*pnumbers - 1) * (*pnn - 1);
			result = permutationCheck(n, to);
			/*
			if (*pnumbers == 11) {
				printf("%lu, %lu, %lu", *pnumbers, *pnn, limit);
				printf(", %lu, %lu,\n", n, to);
			}
			*/
			if (result == 1) {
				temp = (double) n / (double) to;
				if (ndivto > temp) {
					printf("%lu = %lu * %lu, \t %lu \n",
						n, *pnumbers, *pnn, to);
					printf("%f \n", temp);
					ndivto = temp;
					nmax = n;
				}
			}
			
			pnn++;
		}
		pnumbers++;
		pnn = pnumbers + 1;
		limit = end / *pnumbers + 1;
	}

	printf("%lu \n", nmax);

	
	//permutationCheck(87109, 79180);	

	return 0;
}

int permutationCheck(long m, long n)
{
	long mr, nr;
	long madd = 0;
	long nadd = 0;
	long mmul = 1;
	long nmul = 1;
	long mlen = 0;
	long nlen = 0;

	while (m > 0) {
		mr = m % 10;
		m /= 10;
		madd += mr;
		if (mr != 0) {
			mlen++;
			mmul *= mr;
		}
	}

	while (n > 0) {
		nr = n % 10;
		n /= 10;
		nadd += nr;
		if (nr != 0) {
			nlen++;
			nmul *= nr;
		}
	}

	//printf("%lu, %lu, %lu, %lu\n", nadd, madd, nmul, mmul);

	if (nadd == madd && nmul == mmul && mlen == nlen)
		return 1;

	return 0;
}


/*
//	for (n = 2; n <= end; n++) {
		n = 100;
		limit = n;
		totient = n;
		for (i = 2; i < limit; i++) {
			limit = n / i;
			if (n % i == 0) {
				printf("%i, %i, ", i, limit);
				totient -= i;
				totient -= limit;
			}
		}
		totient++;
		printf("\nTotient for %i is %i\t", n, totient);
//	}

*/
