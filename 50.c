/* gcc -g 50.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"
#define SIZE 1000001

int cf(const void *a, const void *b) {
	return (*(long *) a - *(long *) b);
}

int main()
{
	long size;
	long *pn = primeGen(SIZE, &size);
	//pnPrint(pn);

	long sum;
	long *next;
	long *res;
	int term;
	int mterm;
	long answer;

	while (size > 2){
		sum = *pn + *(pn + 1);
		next = pn + 2;
		term = 2;
		while (sum < SIZE) {
			sum += *next;
			term++;	
			//printf("\t%lu is the last term, %lu is the sum. ", *next, sum);
			//printf("%i total terms.\n", term);
			if (term >= mterm)
				res = (long *) bsearch(&sum, pn, size, sizeof(long), cf);
			else 
				res = NULL;

			if (res != NULL) {
		//		printf("%lu is the last term, %lu is the sum, ", \
		//		*next, *res);
		//		printf("%i total terms.\n", term);
				answer = *res;
				mterm = term;
			}
			next++;
		}
		pn++;
		size--;
	}
	printf("%lu \n", answer);


	return 0;
}

