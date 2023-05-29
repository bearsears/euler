#include <stdio.h>
#include <stdlib.h>
#define SIZE 28123

int amsum(int number);

int main() 
{
	int *nb = (int *) malloc(SIZE * sizeof(int));
	int *abnb = (int *) malloc(SIZE * sizeof(int));
	int i;

	for (i = 1; i <= SIZE; i++) {
		*nb++  = i;
		*abnb++ = i;
	}

	nb -= SIZE;
	abnb -= SIZE;
	int sum ;
	int *temp = nb;

	while ((temp - nb) < SIZE) {
		sum = amsum(*temp);
		if (sum <= *temp) 
			*temp++ = 0;
		else
			temp++;
	}

	for (i = 0; i < SIZE; i++) 
		printf("%i ", *(nb + i)) ;
	printf("\n");

	temp = nb;
	int j = 0;
	int diff = 0;

	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			/*
			diff = *abnb - *temp 
			if (diff == *abnb) {
				temp++;
				continue;
			} else if (diff <= 0)
				break;
			*/
			if (*temp == 0) {
				temp++;
				continue;
			} else if ((*abnb - *temp) <= 0) {
				break;
			} else if (*(nb + (*abnb - *temp) - 1) != 0) {
				*abnb = 0;
				break;
			}
			temp++;
		}
		abnb++;
		temp = nb;
	}

	abnb -= SIZE;

	for (i = 0; i < SIZE; i++) 
		printf("%i ", *(abnb + i)) ;
	printf("\n");

	sum = 0;

	for (i = 0; i < SIZE; i++)
		sum += *(abnb + i);
	printf("\n%i is the sum\n", sum);

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
			if (limit != divisor)
				sum += limit;
		}
		divisor++;
	}

	return sum;
}

