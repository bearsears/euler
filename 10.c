#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void isPrime(long *p, long i, int *psize);
void pnPrint(long *p);

int main()
{
	long limit = 2000000;

	unsigned long *pn;
	pn = malloc( limit * sizeof(long));
	*pn = 3; /* initialization */
	unsigned long i = 5; /* start at 5 */
	int size = 1;
	int *ps = &size;

	for( ; i < limit ; i += 2 )
	{
		isPrime(pn, i, ps);
		//pnPrint(pn);
		//printf("\n\n");
	}

	pnPrint(pn);
	printf("\n\n");

	/*
	long divisor;
	unsigned long ipsize = (long) psize;
	printf("ipsize is %lu\n", ipsize);
	for( i = 0 ; i < 10000 ; i++ )
	{
		divisor = n % *pn;	
		//divisor = fmod( (double) number , (double) *pn);	
		if( divisor < 5)
			printf("%lu::%lu\t", divisor, *pn);
		pn++;
	}

	printf("%lu, remainder", (n % 3));
	*/

	return 0;
}

void isPrime(long *p, long i, int *psize)
{
	//int limit = (int) sqrt(i);
	long limit = ( long ) sqrt(i) ;
	//printf("l is %lu, limit is %lu, \n", i, limit);
	long *tp = p;	

	while(*tp <= limit)
	{
	//	printf("%lu mod %lu ** \n", i, *tp);
		if( (i % *tp++) == 0)
		{
	//		printf("returning \n\n");
			return;
		}
	}

	*psize = *psize + 1;
	printf("%i\n\n", *psize);
	//p = realloc(p, *psize);

	int lastaddress = *psize - 1;

	*(p + lastaddress) = i;
	//*(p + *psize) = '\0';

	return;
}

void pnPrint(long *p)
{
	int i = 0;
	long sum = 0;
	while(*p != '\0' && *p < 1999994)
	{
		sum += *p;
		printf("%lu\t", *p++);
		i++;
	}

	printf("\n%i %lu\n", i, sum);

	return;
}
