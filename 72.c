#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000000

int main()
{
	int a[SIZE];

	int i;
	for (i = 1; i <= SIZE; i++) {
		a[i - 1] = i;
	}

	unsigned long sum_totient = 1; /* count when n = 2 */

	int n, j, limit, div, end;

	for (n = 3; n <= SIZE; n++) {
		//limit = n;
		printf("%i\t", n);
		for (i = 1; i < n; i++) {
			if (a[i] == 0)
				continue;
			div = a[i];
		//	printf("\t%i,", div);

			if (n % div == 0) {
				end = (n - 1);
				for (j = i; j < end; j += div)
					a[j] = 0;
			}

			//limit = n / i + 1;
		}
		/*
		printf("\n");
		for (i = 0; i < n; i++)
			printf("%i, ", a[i]);
		printf("\n");
		*/

		end = (n - 1);

		for (i = 0; i < end; i++)
			if (a[i] != 0)
				sum_totient++;

		for (i = 1; i < n; i++) {
			a[i - 1] = i;
		}
		
		/*
		for (i = 0; i < n; i++)
			printf("%i, ", a[i]);
		printf("\n");
		*/
	}

	printf("%lu is the elements.\n", sum_totient);

/*
	for (i = 0; i < SIZE; i++) {
		printf("%i, ", a[i]);
	}
	*/

	return 0;
}
	
