#include <stdio.h>
#include <stdlib.h>

int sums(int number, int divisor);

int main() 
{
	int number = 100;
	int sum_count = number - 1;
	int i, j;
	for (i = 2; i < number; i++) {
		for (j = 2; j <= i; j++) {
			sum_count += sums((number -i), j);
			sum_count += (number - i) / j;
		}
	}

	printf("number of sums for %i is %i,\n", number, sum_count);

	return 0;
}

int sums(int number, int divisor) 
{
	int remainder = number - divisor;
	int ndiv, sum = 0;
	while (remainder > 1) {
		for (ndiv = (divisor - 1); ndiv - 1; ndiv--) {
			sum += remainder / ndiv;
			if (ndiv > 2)
				sum += sums(remainder, ndiv);
		}
		remainder -= divisor;
	}
	return sum;
}
	
