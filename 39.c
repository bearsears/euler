#include <stdio.h>
#include <stdlib.h>
/* uses pointer to pointer */

int dvs(int n, int **p);

int main()
{
	int i;
	int *j;
	int *l; 
	int size;

	for (i = 1499999; i <= 1500000; i++) {
		printf("%i: ", i);
		size = dvs(i, &l);
		j = l;

		while ((j - l) < size) {
			printf("%i, ", *j++);
		}
		printf("  size %i\n", size);

	}

	return 0;
}

int dvs(int n, int **p)
{
	int limit = n;
	int sz = 2;
	int pos = 2;
	int rm;

	*p = malloc(2 * sizeof(int));
	if (p == NULL) {
		printf("Memory Allocation failure.\n");
		exit(EXIT_FAILURE);
	}
	**p = 1;
	*(*p + 1) = n;
	
	while (pos < limit) {
		rm = n % pos;
		if (rm == 0) {
			sz += 2;
			*p = realloc(*p, sz * sizeof(int));
			if (p == NULL) {
				printf("Memory Allocation failure.\n");
				exit(EXIT_FAILURE);
			}
			*(*p + (sz - 2)) = pos;
			*(*p + (sz - 1)) = n / pos;
		}
		limit = n / pos ;
		pos++;
	}
	return sz;
}
