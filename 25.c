#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#define SIZE 1001

/* the back bone of this comes from 16.c, and 20.c */
/* if time I do want to do a pointer version of this... the array one was
 * buggy
 */

int main()
{
	int main[SIZE];
	int oneback[SIZE];
	int twoback[SIZE];
	int i, j;

	for (i = 0; i < SIZE; i++)
	{
		main[i] = -1;
		oneback[i] = -1;
		twoback[i] = -1;
		//printf("%i", main[i]);
	}

	oneback[0] = 1;
	twoback[0] = 1;
	i = 2;
	
	printf("\nentering\n");
	while ( main[SIZE - 2] == -1 )
	{
		for (j = 0; oneback[j] > -1 ; j++) {
			if (twoback[j] == -1)
				main[j] = oneback[j];
			else
				main[j] = oneback[j] + twoback[j];
		}

		for (j = 0; main[j] > -1 ; j++)
		{
			if (main[j] >= 10) {
				if (main[j + 1] == -1) {
					main[j + 1] = main[j + 1] + (main[j] / 10) + 1;
					main[j] = main[j] % 10;
				} else { 				
				main[j + 1] = main[j + 1] + (main[j] / 10);
				main[j] = main[j] % 10;
				}
			}
		}
		for (j = 0; oneback[j] > -1; j++)
			twoback[j] = oneback[j];

		for (j = 0; main[j] > -1; j++)
			oneback[j] = main[j];
		i++;
		printf("%i: ", i);
		for (j = 0; main[j] > -1; j++)
			printf("%i ", main[j]);
		printf("\n");
	}

	
	printf("\n%i is the index\n", i);

	long product = 0;
	for (i = 0; main[i] > -1 ; i++)
	{ 
		printf("%i ", main[i]);
		product += main[i];
	}

	printf("\n%i is the number of digits \n", i);

	printf("%lu is the sum\n", product);
	printf("\n");
	return 0;
}

