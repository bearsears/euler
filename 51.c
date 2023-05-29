/* gcc -o 51.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "primeGen.h"
#define DG 1 /* DG for digits */
#define SK 2 /*SK for strike */

int zeros(long n);
int ones(long n);
int zeroCheck(long *p, int inc);
int oneCheck(long *p, int inc);

int main()
{
	long size;
	long *pn = primeGen(1000000, &size);
	//pnPrint(pn);

	int ztoi;
	int i;	
	int otoi; /* one to integer */

	for (i = 0; i < size; i++) {
	//	printf("%lu,  ", *pn);
//		ztoi = zeros(*pn);
//		if (ztoi != 0) {
			//printf("%lu::%i\t", *pn, ztoi);
//			if (zeroCheck(pn, ztoi) == 1)
//				printf("%lu::%i\n", *pn, ztoi);
//		}
	/* finding zero didn't work, so i am finding one. */
		if (*pn % 10 == 3) {
			otoi = ones(*pn);
			if (otoi > 100) 
				if (oneCheck(pn, otoi) == 1)
					printf("%lu::%i\n", *pn, otoi);
		}

		pn++;
	}

	return 0;
}

int zeros(long n)
{
	//printf("%lu.\n", n);
	int count = 0;
	int sum = 0;
	int rem;
	while (n > 0) {
		rem = n % 10;
		if (rem == 0) 
			sum = sum + (int) pow(10, count);
		n /= 10;
		count++;
	}

	return sum;
}

int ones(long n)
{
	//printf("%lu.\n", n);
	int count = 0;
	int sum = 0;
	int rem;
	while (n > 0) {
		rem = n % 10;
		if (rem == 1) 
			sum = sum + (int) pow(10, count);
		n /= 10;
		count++;
	}

	return sum;
}

int zeroCheck(long *p, int inc)
{
	long *t = p;
	long next = *p + inc;
	long end = *p + inc * 10;
	int strike = 0;

	if (end > 10000000)
		return 0;

	while (next < end) {
		if (*t < next)
			t++;
		else if (*t > next) {
			next += inc;
			strike++;
		}
		else {
			t++;
			next += inc;
		}
		
		if (strike == SK)
			return 0;
	}

	return 1;
}

int oneCheck(long *p, int inc)
{
	long *t = p;
	long next = *p + inc;
	long end = *p + inc * 9;
	int strike = 0;

	if (end > 10000000)
		return 0;

	while (next < end) {
		if (*t < next)
			t++;
		else if (*t > next) {
			next += inc;
			strike++;
		}
		else {
			t++;
			next += inc;
		}
		
		if (strike == SK)
			return 0;
	}

	return 1;
}
