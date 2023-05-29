#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void isPrime(long *p, long i, int *psize);
void pnPrint(long *p);
float number = 600851475143;

int main()
{
	long n = 600851475143;
	float number = 600851475143;
	//float number = 13195;
	//float number = 100000000;
	float sqrNumber = sqrt(number);
	//float psize = 1.2 * sqrNumber / log(sqrNumber); 
	float psize = sqrNumber;
	psize = floor(psize);
	unsigned long *pn;
	pn = malloc( ( (int) psize ) * sizeof(long));
	*pn = 3; /* initialization */
	unsigned long i = 5; /* start at 5 */
	int size = 1;
	int *ps = &size;

	for( ; i < sqrNumber ; i += 2 )
	{
		isPrime(pn, i, ps);
		//pnPrint(pn);
		//printf("\n\n");
	}

	pnPrint(pn);
	printf("\n\n");

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
	while(*p != '\0')
	{
		printf("%lu\t", *p++);
		i++;
	}
	printf("%i\n", i);

	return;
}
