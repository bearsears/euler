#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

int amsum(int number);
int main() 
{
	int *nb = (int *) malloc(SIZE * sizeof(int));
	int i;

	for (i = 0; i < SIZE; i++) 
		*(nb + i) = (i + 1);

	int sum ;
	int *temp = nb;

	while ((temp - nb) < SIZE) {
		if (*temp == 0) {
			temp++;
			continue;
		}

		sum = amsum(*temp);

		if (sum <= *temp || sum > SIZE) 
			*temp++ = 0;
		else if (*temp == amsum(sum))
			printf("%i and %i\n", sum, *temp++);
		else {
			*(temp + (sum - *temp)) = 0;
			*temp++ = 0;
		}
	}
/*
	for (i = 0; i < SIZE; i++) 
		printf("%i ", *(nb + i)) ;
*/	
	return 0;
}
		


int amsum(int number) 
{
	int limit = number / 2;
	int divisor = 2;
	int sum = 1;

	while (divisor < limit) {
		if (number % divisor == 0) {
			sum += divisor;
			limit = (number / divisor);
			sum += limit;
		}
		divisor++;
	}

	return sum;
}

