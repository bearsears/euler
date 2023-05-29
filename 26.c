#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*
	int pc = 100; //pc for precision
	int num, rem; //the numerator, the remainder;

	for (i = 900; i <= d; i++) {
		num = 10;
		for (j = 0; j < pc; j++) {
			printf("%i", (num / i));
			num = (num % i) * 10;
		}
		printf("  %i\n", i);
	}
	*/
	int d = 1000; // d < 10;
	int i, j;
	int size;
	for (i = 2; i <= d; i++) {
		printf("%i,\n", i);
		size = i - 1;
		int *cycle = (int *) malloc(sizeof(int) * (1 + size));
		/* set up the array */
		for (j = 0; j < size; j++)
			//printf("%i, ", *cycle);
			*cycle++ = 9;
		*cycle = 0;
		cycle -= size;	
	/*	
		for (j = 0; j <= size; j++)
			printf("%i", *cycle++);
		cycle -= size + 1;
		printf("\n");
	*/	
		for (j = 0; j < size; j++) {
			printf("current %i, next %i :::", *cycle, *(cycle + 1));
			*(cycle + 1) = *(cycle + 1) + (*cycle % i) * 10;
			printf("current %i, next %i :::\n", *cycle, *(cycle + 1));			
			cycle++;
		}

		if (*cycle == 0) {
			printf("number is %i, remainder is %i\n", i, *cycle);
		}
		cycle -= size;
		//free(cycle);			
	}
	return 0;
}
			
