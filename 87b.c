#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"

int cpfc(const void * a, const void *b) {
	return(*(long*) a - *(long*) b);
}

int main()
{
	long result;
	long size;
	long *pnumbers = primeGen(7071, &size);
	long *a, *b, *c;
	long count;
	long *numbers = (long *) calloc(2000000, sizeof(long));
	*numbers = 28;
	long *start = numbers;

	for(a = pnumbers; (a - pnumbers) < size; a++) {
		for(b = pnumbers; b <= a; b++) {
			for(c = pnumbers; c <= b; c++) {
				result = *a * *a + *b * *b * *b + *c * *c * *c * *c;
				if (result > 50000000)
					break;
	//			printf("%lu^2+%lu^3+%lu^4 = %lu\t", *a, *b, *c, result);
				*start++ = result;
				count++;
			}
		}
	}
//	printf("%lu\n", count);

	for(a = pnumbers; (a - pnumbers) < size; a++) {
		for(b = pnumbers; b <= a; b++) {
			for(c = pnumbers; c <= b; c++) {
				result = *a * *a + *c * *c * *c + *b * *b * *b * *b;
				if (result > 50000000)
					break;
	//			printf("%lu^2+%lu^3+%lu^4 = %lu\t", *a, *c, *b, result);
				*start++ = result;
				count++;
			}
		}
	}
//	printf("%lu\n", count);

	for(a = pnumbers; (a - pnumbers) < size; a++) {
		for(b = pnumbers; b <= a; b++) {
			for(c = pnumbers; c <= b; c++) {
				result = *b * *b + *c * *c * *c + *a * *a * *a * *a;
				if (result > 50000000)
					break;
	//			printf("%lu^2+%lu^3+%lu^4 = %lu\t", *b, *c, *a, result);
				*start++ = result;
				count++;
			}
		}
	}
//	printf("%lu\n", count);

	for(a = pnumbers; (a - pnumbers) < size; a++) {
		for(b = pnumbers; b <= a; b++) {
			for(c = pnumbers; c <= b; c++) {
				result = *b * *b + *a * *a * *a + *c * *c * *c * *c;
				if (result > 50000000)
					break;
	//			printf("%lu^2+%lu^3+%lu^4 = %lu\t", *b, *a, *c, result);
				*start++ = result;
				count++;
			}
		}
	}
//	printf("%lu\n", count);

	for(a = pnumbers; (a - pnumbers) < size; a++) {
		for(b = pnumbers; b <= a; b++) {
			for(c = pnumbers; c <= b; c++) {
				result = *c * *c + *a * *a * *a + *b * *b * *b * *b;
				if (result > 50000000)
					break;
	//			printf("%lu^2+%lu^3+%lu^4 = %lu\t", *c, *a, *b, result);
				*start++ = result;
				count++;
			}
		}
	}
//	printf("%lu\n", count);

	for(a = pnumbers; (a - pnumbers) < size; a++) {
		for(b = pnumbers; b <= a; b++) {
			for(c = pnumbers; c <= b; c++) {
				result = *c * *c + *b * *b * *b + *a * *a * *a * *a;
				if (result > 50000000)
					break;
	//			printf("%lu^2+%lu^3+%lu^4 = %lu\t", *c, *b, *a, result);
				*start++ = result;
				count++;
			}
		}
	}
//	printf("%lu\n", count);
	
	start = numbers;
	qsort(numbers, count, sizeof(long), cpfc);
/*	
	while((start - numbers) < count) {
		
		printf("%lu\t", *start++);
	}
	*/

	int newcount = 1;
	start = numbers + 1;

	while((start - numbers) < count) {
		if(*(start - 1) != *start) {
			newcount++;
		}
		start++;
	}
	
	printf("\n%lu is the count, %i is the newcount\n", 
		count, newcount);
		
	return 0;
}
