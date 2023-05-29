#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define SIZE 9

int dlength(int n);
void ninsert(int n, int *p); /* number insert */
void pprint(int *p, int sz); /* pointer print */
int cfunct(const void *a, const void *b); /* compare function */
int pconvert(int *p, int sz); /* pointer convert to number */

int main()
{
	/* Initialization */
	int mc, mp, pr; /* mc for multiplicand, mp for multiplier, pr for
	product*/
	int mcl, mpl, prl, tl; /* l for length. tl is total length */
	int exact = 0;
	int i;
	for (i = 1; i <=SIZE; i++) {
		exact = 10 * exact + i;
	}
	int limit = (int) pow(10, (SIZE / 2));
	printf("exact %i, limit %i,\n", exact, limit);
	int *store = (int *) malloc(sizeof(int) * SIZE);
	if (store == NULL) {
		printf("Memory allocation failure.\n");
		exit(EXIT_FAILURE);
	}

	for (mc = 1; mc < limit; mc++) {
		mcl = dlength(mc);
		tl = 0;
			for (mp = 1; tl <= SIZE; mp++) {
				mpl = dlength(mp);
				pr = mc * mp;
				prl = dlength(pr);
				tl = mcl + mpl + prl;
				if (tl == SIZE) {
				/*	
					printf("mc %i, mp %i, pr %i, ", mc, mp, pr);
					printf("mcl %i, mpl %i, ", mcl, mpl);
					printf("prl %i, tl %i\n", prl, tl);      
				*/
					ninsert(mc, store);
					ninsert(mp, (store + mcl));
					ninsert(pr, (store + mcl + mpl));
				//	pprint(store, SIZE);
					qsort(store, SIZE, sizeof(int), cfunct);
				//	pprint(store, SIZE);
			
					if (exact == pconvert(store, SIZE)) {
				/**/	
						printf("mc %i, mp %i, pr %i, ", mc, mp, pr);
						printf("mcl %i, mpl %i, ", mcl, mpl);
						printf("prl %i, tl %i\n", prl, tl);      
				/**/
						pprint(store, SIZE);
					}
				}

			}
	}
	
	return 0;
}

int dlength(int n)
{
	int length = 0;
	do {
		n = n / 10;
		length++;
	} while (n > 0);

	return length;
}

void ninsert(int n, int *p) {
	do {
		*p++ = n % 10;
		n /= 10;
	} while (n > 0);
}

void pprint(int *p, int sz) /* pointer print */
{
	int i;
	for (i = 0; i < sz; i++) 
		printf("%i", *p++);
	printf("\n");
}

int cfunct(const void *a, const void *b) /* compare function */
{
	return (*(int *) a - *(int *) b);
}

int pconvert(int *p, int sz) /* pointer convert to number */
{
	int n = 0;
	int i; 

	for (i = 0; i < sz; i++) {
		n = 10 * n + *p++;
		//printf("%i-", n);
	}
	//printf("%i\n ", n);
	
	return n;
}
