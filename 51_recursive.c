#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DG 1

void combGen(int n, int limit, int *p);

int main()
{
	int i, j;
	int size = 0;
	int temp;

	/* setting things up for the combination of 0 and 1's */
	for (i = 1; i <= DG; i++) {
		temp = 1;
		for (j = 1; j <= (DG - i); j++)
			temp *= 2;
		size += temp;
	}

	temp = (int) pow(10.0, (double) DG);
	int *c = (int *) malloc(size*sizeof(int));
	if (c == NULL) {
		printf("Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	combGen(1, temp, c);
	int *t = c;
	*(c + size - 1) = 1;
	/**/
	printf("\n");
	while ((t - c) < size) {
		*t *= 10;
		printf("%i, ", *t++);
	}
	/**/

	/* set up prime numbers */
	temp = (int) pow(10.0, (double) (DG + 1));



	return 0;
}

void combGen(int n, int limit, int *p) 
{
	n *= 10;
	if (n < limit) {
		while (*p != 0)
			p++;
		*p++ = n;
		//printf("%i, ", n);
		combGen(n, limit, p);
	}

	n++;
	if (n < limit) {
		while (*p != 0)
			p++;
		*p++ = n;
		//printf("%i, ", n);
		combGen(n, limit, p);
	}
}
