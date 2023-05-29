#include <stdio.h>
#include <stdlib.h>

void allocate(int **p, int size);
void printp(int *p, int size);
void delete(int *num, int *den, int ns, int ds);
int product(int *p, int ps);

int main()
{
	int n, r, nr;
	int c;
	int count = 0;
	int *na, *ra, *nra;

	for (n = 1; n <= 100; n++) {
	//	printp(na, n);
		r = 1;
		while (r < n) {
			allocate(&na, n);
			allocate(&ra, r);
			allocate(&nra, (n - r));
			/*
			printf(" n %i: ", n);
			printp(na, n);
			printf(" r %i: ", r);
			printp(ra, r);
			printf(" (n - r) %i: ", (n - r));
			printp(nra, (n - r));
			printf("\n");
			*/
			delete(na, nra, n, (n - r));
			delete(na, ra, n, r);

			c = product(na, n) / product(ra, r) / product(nra, \
				(n - r));
			/*
			printf(" n %i: ", n);
			printp(na, n);
			printf(" r %i: ", r);
			printp(ra, r);
			printf(" (n - r) %i: ", (n - r));
			printp(nra, (n - r));
			printf("\n");
			printf(" c %i: ", c);
			printf("\n");
			*/
			if (c > 1000000) {
				count += (n - r - r + 1);
				break;
			}
			r++;
		}
		
	}		
	printf("%i is the total.\n", count);

	free(na);
	free(ra);
	free(nra);
	return 0;

}

void allocate(int **p, int size)
{
	*p = (int *) malloc(sizeof(int) * size);
	if (*p == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	int i;
	for (i = 0; i < size; i++) {
		*(*p + i) = (i + 1);
	}
}

void printp(int *p, int size)
{
	int i = 0; 
	while (i < size) {
		printf("%i,", *p++);
		i++;
	}
	//printf("\n");
}	

void delete(int *num, int *den, int ns, int ds) 
{
	int i;
	int j = 0;
	
	for (i = 0; i < ds; i++) {
		for (j = 0; j < ns; j++) {
			if (*(num + j) % *(den + i) == 0) {
				*(num + j) /= *(den + i);
				*(den + i) = 1;
				break;
			}
		}
	}
}

int product(int *p, int ps)
{
	int result = 1;
	int i;
	for (i = 0; i < ps; i++) 
		result *= *p++;

	return result;
}
