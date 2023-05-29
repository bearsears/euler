/* to compile, gcc -g 29.c -o go -lm */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define GRID 100

void *checkArray(double *arr, int size, double key);

int main() 
{
	int i, j;
	int size = (GRID - 1 ) * (GRID - 1);
	double *powers = (double *) calloc(size, sizeof(double));
	if (powers == NULL) {
		printf("Error in allocating.\n");
		exit(0);
	}
	double result;
	
	for (i = 2; i <= GRID; i++) {
		for (j = 2; j <= GRID; j++) {
			result = pow(i, j);
			checkArray(powers, size, result);
		}
	}

	i = 0;
	while (*powers != 0) {
		*powers++;
		//printf("%f  ", *powers++);
		i++;
	}

	printf("%i is the numbers available\n", i);

	return 0;
}

void *checkArray(double *arr, int size, double key) {
	double *temp = arr;

	while (*temp != 0) {
		if (*temp == key) 
			break;
		temp++;
	}
	
	*temp = key;
}
