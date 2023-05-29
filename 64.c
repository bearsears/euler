#include <stdio.h>
#include <stdlib.h>
#define SZ 500

int main() 
{
	int *aarray = (int *) malloc(sizeof(int) * SZ);
	if (aarray == NULL) {
		printf("Memory not allocated.\n");
		exit(1);
	}

	int N;
	int sqrN = 1;
	int i, j, remainder, denominator;
	int *temp;
	int length;
	int *start;
	int answer = 0;

	for (N = 2 ; N <= 10000 ; N++) {
		sqrN = 1;
		while ((sqrN * sqrN) < N) 
			sqrN++;
		if ((sqrN * sqrN) == N)
			continue;
		sqrN--;
		*aarray++ = sqrN;
		remainder = sqrN;
		denominator = N - remainder * remainder;	

		for (i = 1 ; i < SZ ; i++) {
			*aarray = (sqrN + remainder) / denominator;
			remainder = -1 * (remainder - *aarray * denominator);
			denominator = (N - remainder * remainder) / denominator;
			aarray++;
		}
	
		aarray -= SZ;
		
		printf("%i -->", N);
		for (i = 0 ; i < SZ ; i++)
			printf("%i,", *aarray++);
		printf("\n");
		aarray -= SZ;
		aarray++;

		length = 1;
		start = aarray;

		for (i = 1 ; i < SZ ; i++) {
			aarray = (start + i - 1);
			temp = aarray++;
			if (*temp != 0) {
				printf("%i\t", *temp);
				length = (aarray - start);
			}
			for (j = i ; j < SZ ; j++) {
			//	printf("%i/%i/", *temp, *aarray);
				if (*temp == *aarray)
					*aarray = 0;
			//	printf("%i ", *aarray);
				aarray++;
			}

		}

		aarray = start;
		aarray--;
		
		printf("%i -->", N);
		for (i = 0 ; i < SZ ; i++)
			printf("%i,", *aarray++);
		printf("\n");
		aarray -= SZ;

		printf("\t length is %i \n", length);
		if ((length % 2) != 0) 
			answer++;
	}

	printf("Answer is %i\n", answer);
	return 0;
}
