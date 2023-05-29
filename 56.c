#include <stdio.h>
#include <stdlib.h>
#define SIZE 201
#define MAX 100

void set(int *a, int b);
int findMax(int *a);

int main()
{
	int numbers[SIZE];
	int a, b, i, j;
	int amax = 0;
	int bmax = 0;
	int nmax = 0;
	int tmax = 0;

	for (a = 1; a < MAX; a++) {
		set(numbers, a);
		for (b = 1; b < MAX; b++) {
			for (i = 1; i < b; i++) {
				for (j = 0; j < SIZE; j++)
					numbers[j] *= a;
				for (j = 0; j < (SIZE - 1); j++) {
					numbers[j + 1] = numbers[j + 1] +
					numbers[j] / 10;
					numbers[j] = numbers[j] % 10;
				}
			}
		/*	
			printf("a:%i, b:%i, ", a, b);
			for (j = 0; j < SIZE; j++) 
				printf("%i", numbers[j]);
			printf("\n");
		*/	
			tmax = findMax(numbers);
			set(numbers, a);
			if (tmax > nmax) {
				nmax = tmax;
				amax = a;
				bmax = b;
			}
		}
	}
	printf("%i is the sum, a is %i, b is %i \n", nmax, a, b);

	return 0;
}

void set(int *a, int b)
{
	int i = 0;
	while (b > 0) {
		i++;
		*a++ = b % 10;
		b /= 10;
	}
	for ( ;  i < SIZE; i++)
		*a++ = 0;
}

int findMax(int *a) 
{
	int sum = 0;
	int i;
	for (i = 0; i < SIZE; i++) { 
		sum = sum + *a;
		//printf("%i is sum, %i is a\t", sum, *a);
		a++;
	}
		
	return sum;
}
