/* to compile, gcc -g 28.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 500

int main() 
{
	long res = 0;
	int grid, turn;
	int cur = 1; /* cur for current */
	int inc = 2; /* inc for increment */


	for (grid = 0; grid < SIZE; grid++) {
		for (turn = 0; turn < 4; turn++) {
			res += (long) cur;
			printf("%i ", cur);
			cur += inc;

		}
		printf("\n");
		inc += 2;
	}

	res += (long) cur;

	printf("%lu is the sum of the diagonals.\n", res);
	return 0;
}

