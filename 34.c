#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() 
{ 
	int factorial[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	unsigned int i; 
	unsigned int temp;
	unsigned int j;

	for (i = 1; i < UINT_MAX; i++) {
		temp = i;
		j = 0;
		while (temp > 0) {
			j += *(factorial + (temp % 10));
			temp /= 10;
		}
		if (i == j)
			printf("%i is a digit factorial.\n", i);
		//else
		//	printf("%i  ", i);
	}

	return 0;
}
