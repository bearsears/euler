#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	FILE *fp;
	fp = fopen("13.txt", "r");

	unsigned long sum = 0;
	unsigned long number[5000];
	unsigned long *pn = &number;
	unsigned long temp;

	while ((temp = fgetc(fp)) != EOF)
	{
		if (temp > 10)
		{
			temp = temp - '0';
			*pn++ = temp;
			printf("%lu", temp);
		}
		else 
			printf("\n");
	}

	pn = &number;
	pn += 49;
	printf("\n%lu\n", *pn);
	int i, j;
	sum = 0;

	for (i = 49 ; i > 10 ; i--)
	{
		for (j = 0 ; j < 100 ; j++)
		{
			printf("%lu ", *pn);
			sum += *pn;
			pn += 50;
		}

		printf("%lu is the sum.", sum);
		sum /= 10;	
		printf(" %lu is the sum.\n", sum);
		pn = &number;
		pn += (i - 1);
	}

	printf("\n Second loop \n");
	long tens = 1;

	for (i  ; i >= 0 ; i--)
	{
		for (j = 0 ; j < 100 ; j++)
		{
			printf("%lu ", (*pn * tens));
			sum += (*pn * tens);
			pn += 50;
		}

		printf(" %lu is the sum.\n", sum);
		tens *= 10;
		pn = &number;
		pn += (i - 1);
	}

	printf("%i is i, %i is j\n", i , j);


		
	return 0;
}
