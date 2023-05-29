#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

int length_of_digits(long number);

int main()
{
	long i = 10;
	int length;
	int temp;
	int j, k;
	while (i < LONG_MAX) {
		length = length_of_digits(i);
		for (j = 2 ; j < 20 ; j++) {
			temp = j;
			//printf("%i, %i^%i\n", i, number, length);
			for (k = 1 ; k < length ; k++) {
				temp = temp * j;
				if (temp > i || temp > (LONG_MAX / j))
					break;
			}
			if (temp == i)
				printf("%lu, %i^%i\n", i, j, length);
			
		}
		i++;
	}

	return 0;
}

int length_of_digits(long number) 
{
	int length = 0;

	while (number > 0) {
		number /= 10;
		length++;
	}

	return length;
}

