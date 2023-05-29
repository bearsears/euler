 /* gcc -g 48.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define LIM 1000

int *last_ten(int n);
int main() 
{
	int n;
	int *lt;
	int i;
	int *sum = (int *) calloc(10, sizeof(int));
	if (sum == NULL) {
		printf("Memory allocation failed for sum.\n");
		exit(EXIT_FAILURE);
	}
	int carry;

	for (n = 1; n <= LIM; n++) {
		lt = last_ten(n);
	/*	
		for (i = 9; i >= 0; i--) {
			printf("%i", *(lt + i));
		}
		printf("\n");
	*/
		carry = 0;
		for (i = 0; i < 10; i++) {
			*(sum + i) = *(sum + i) + carry + *(lt + i);
			carry = *(sum + i) / 10;
			*(sum + i) %= 10;
		}
		/*
		printf("\t");
		for (i = 9; i >= 0; i--) {
			printf("%i", *(sum + i));
		}
		printf("\n");
		*/
	}
	for (i = 9; i >= 0; i--) {
		printf("%i", *(sum + i));
	}
	printf("\n");

	return 0;
}

int *last_ten(int n)
{
	int *lt = (int *) calloc(10, sizeof(int));
	if (lt == NULL) {
		printf("Memory allocation failed for lt.\n");
		exit(EXIT_FAILURE);
	}

	*lt = 1;
	int carry;

	int i, j;

	for (j = 0; j < n; j++) {
		//printf("%i --> ", n);
		for (i = 0; i < 10; i++) {
			*(lt + i) = *(lt + i) * n;
		//	printf("%i::", *(lt + i));
		}
		//printf("\n");
		carry = 0;
		for (i = 0; i < 10; i++) {
			*(lt + i) = *(lt + i) + carry;
			carry = *(lt + i) / 10;
			*(lt + i) %= 10;
	//		printf("%i::", *(lt + i));
		}
		//printf("\n");
		/*
		for (i = 9; i >= 0; i--) {
			printf("%i", *(lt + i));
		}
		printf("\n");
		*/
	}
	return lt;
}
