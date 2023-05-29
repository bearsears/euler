#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main()
{
	int power[1000] = {-1};
	int i, j;

	for (i = 0; i <= 1000; i++)
	{
		power[i] = -1;
		printf("%i", power[i]);
	}

	power[0] = 1;
	for (i = 1 ; i <= 1000 ; i++)
	{
		for (j = 0; power[j] > -1 ; j++)
			power[j] *= 2;

		for (j = 0; power[j] > -1 ; j++)
		{
			if (power[j] >= 10) {
				if (power[j + 1] == -1) {
					power[j + 1] = power[j + 1] + (power[j] / 10) + 1;
					power[j] = power[j] % 10;
				} else { 				
				power[j + 1] = power[j + 1] + (power[j] / 10);
				power[j] = power[j] % 10;
				}
			}
		}
	}

	printf("\n");

	long product = 0;
	for (i = 0; power[i] > -1 ; i++)
	{
		printf("%i ", power[i]);
		product += power[i];
	}
	
	printf("%lu is the sum\n", product);
	printf("\n");
	return 0;
}

