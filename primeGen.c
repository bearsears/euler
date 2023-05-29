/* to compile with other programs, do
 * gcc -o other_program_name.c primeGen.c -o go -lm */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "primeGen.h"

/*
int main()
{
	long size; 
	long *pnumbers = primeGen(10000000, &size);
	pnPrint(pnumbers);
	printf("\n%lu is the size\n", size);
	return 0;
}
*/

long *primeGen(long number, long *size)
{
	/* number / log(number - 1) comes from prime number theory, which estimates the size of prime numbers 
	 * under the given number. The formula comes short of the actual, thus multiplying 1.01 is to 
	 * supplement the formula to come slightly higher than the actual
	 */
	float psize = 1.01 * number / (log((float) number) - 1);
	printf("%f\n", psize);
	long *pn = (long *) malloc( ( (long) psize ) * sizeof(long)); /* pn, prime numbers */
	if (pn == NULL) {
		printf("Memory allocation of prime number array has failed.\n");
		exit(0);
	}
	*pn++ = 2; /* initialization */
	*pn-- = 3;
	long i = 5; /* start at 5 */
	*size = 2;
	long *tp;
	long limit;

	for ( ; i < number ; i += 2 )
	{
		limit = ( long ) sqrt(i) ;
		tp = pn;	

		while (*tp <= limit)
			if ((i % *tp++) == 0)
				break;

		/* to skip the number if it is not prime, then continue */
		if ((i % *(tp - 1)) == 0)
			continue;

		*(pn + *size) = i;
		*size = *size + 1;
	}
	return pn;
}

void pnPrint(long *p)
{
	int i = 0;
	while(*p != '\0')
	{
		printf("%lu\t", *p++);
		i++;
	}
	printf("the size is %i\n", i);

	return;
}
