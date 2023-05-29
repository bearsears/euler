#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* the back bone of this comes from 16.c */

int main()
{
	int fact[1000] = {-1};
	int i, j;

	for (i = 0; i <= 1000; i++)
	{
		fact[i] = -1;
		//printf("%i", fact[i]);
	}

	fact[0] = 1;
	for (i = 1 ; i <= 100 ; i++)
	{
		for (j = 0; fact[j] > -1 ; j++)
			fact[j] *= i;

		for (j = 0; fact[j] > -1 ; j++)
		{
			if (fact[j] >= 10) {
				if (fact[j + 1] == -1) {
					fact[j + 1] = fact[j + 1] + (fact[j] / 10) + 1;
					fact[j] = fact[j] % 10;
				} else { 				
				fact[j + 1] = fact[j + 1] + (fact[j] / 10);
				fact[j] = fact[j] % 10;
				}
			}
		}
	}

	printf("\n");

	long product = 0;
	for (i = 0; fact[i] > -1 ; i++)
	{
		printf("%i ", fact[i]);
		product += fact[i];
	}
	
	printf("%lu is the sum\n", product);
	printf("\n");
	return 0;
}

