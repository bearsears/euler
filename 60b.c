/* gcc -g 60.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"
#include <math.h>
#define SIZE 5


int cmpf(const void *a, const void *b) {
	return (*(long *) a - *(long *) b);
}

int check (long a, long b, long *p, long s);
int pCheck (long n);

int main()
{
	long size;
	long *pnumbers = primeGen(10000000, &size);
	long *temp = pnumbers;
	long *arrP[SIZE];
	arrP[0] = pnumbers;
	temp = pnumbers + 1;
	int i = 1;
	int j;
	int result = 0;
	long sum = 50000;
	long tsum = 50000;
	while (1) {
		while (i < SIZE) {
			//printf("%lu, \t", *temp);
			for (j = 0 ; j < i ; j++) {
				result = check(*arrP[j], *temp, pnumbers, size);
				if (result == 0)
					break;
			}
			if (result == 1) {
				arrP[i] = temp;
				i++;
				tsum -= *temp;
			}
			temp++;
			if (*temp > tsum)
				break;
		}
			
		if (i == SIZE) {
				sum = 0;
				for (i = 0 ; i < SIZE ; i++) { 
					printf("%lu, ", *arrP[i]);
					sum += *arrP[i];
				}
				printf("sum %lu\n\n", sum);
		}
		tsum = sum;
		arrP[0]++;
		temp = arrP[0] + 1;
		i = 1;
		if (*temp > 7000)
			break;
		printf("%lu,", *arrP[0]);
	}

	return 0;
}

int check (long a, long b, long *p, long s) {
	long al = 1;
	long bl = 1;
	long at = a;
	long bt = b;
	while (at > 0) {
		al *= 10;
		at /= 10;
	}
	while (bt > 0) {
		bl *= 10;
		bt /= 10;
	}
	long first = a * bl + b;
	long second = a + b * al;
	long end = *(p + s - 1);
	long fres = 1;
	long sres = 1;
	//printf("%lu, %lu, %lu, %lu\n", first, second, a, b);
	
	if (first > end) {
		fres = pCheck(first);
		if (fres == 0)
			return 0;
	}
	else if (bsearch(&first, p, s, sizeof(long), cmpf) == NULL)
		return 0;	

	if (second > end) {
		sres = pCheck(second);
		if (sres == 0)
			return 0;
	}
	else if (bsearch(&second, p, s, sizeof(long), cmpf) == NULL) 
		return 0;

	return 1;
}

int pCheck (long n) {
	if (n % 3 == 0)
		return 0;
	
	long limit = n / 2;
	long dv = 5;
	while (dv <= limit) {
		if (n % dv == 0)
			return 0;
		limit = n / dv;
		dv += 2;
	}

	return 1;
}


