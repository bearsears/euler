/* gcc -g 44.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
/* max size is 37836.. due to the limits of int */
/* not a fan of my method. too slow. */

int cmfc(const void *a, const void *b)
{
	return (*(int *) a - *(int *) b); 
}

void check(int a, int b, int *p);

int main()
{
	int *penta = (int *) malloc(SIZE * sizeof(int));

	if (penta == NULL) {
		printf("Memory Allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	int *a = penta;
	int i;
	for (i = 1; i <= SIZE; i++) {
		*a = i * (3 * i - 1) / 2;
		//printf("%i:%i, ", i, *a);
		a++;
	}
	printf("\n");

	a = penta;
	int *b = a + 1;
	int *c = b + 1;
	
	while ((c - penta) < SIZE) {
		while ((b - penta) > 1) {
			while((a - penta) > 0) {
				if ((*a + *b) == *c) {
				//	printf("%i+%i=%i and %i-%i=%i\n", *a, *b,\
					*c, *b, *a, (*b - *a));
					check(*a, *b, penta);
				}
				else if ((*a + *b) < *c) 
					break;
				a--;
			}
			b--;
			if (*b < (*c / 2))
				break;
			a = b - 1;
		}
		c++;
		b = c - 1;
		a = c - 2;
	}

	return 0;
}

void check(int a, int b, int *p) 
{
	int diff = b - a;
	int i;

	for (i = 0; i < SIZE; i++) {
		if (diff == *p++) {
			printf("%i+%i=%i and %i-%i=%i", a, b, (a + b), a, b, diff);
			break;
		}
	}

	if (bsearch(&diff, p, SIZE, sizeof(int), cmfc) != NULL) {
		printf("%i+%i=%i and %i-%i=%i", a, b, (a + b), b, a, diff);
	}

	return;
}

