/* gcc -g 65.c -o go -lm*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SZ 100

/*euler's continued fraction continues in a pattern of 2, 1, 2, 1, 1, 4, 1, 
 * 1, 6, 1 and so on.*/

void add(int *n, int *d, int m);
void print(int *p);

int main() 
{
	int n[200]; /* n is numerator */
	int i;
	for (i = 0; i < 200; i++)
		n[i] = -1;
	n[0] = 1;
	int d[200];
	for (i = 0; i < 200; i++)
		d[i] = -1;
	d[0] = 1;
	int *np, *dp, *temp; /* d is denominator */
	np = &n[0];
	dp = &d[0];
	/*
	print(np);
	printf("\n");
	print(dp);
	printf("\n");
	*/
	int end = (SZ - 1) / 3;
	int mid = 2 * end;

	for (i = 0 ; i < end ; i++) {
		add(np, dp, mid);
		temp = dp;
		dp = np;
		np = temp;
		/*
		print(np);
		printf(" / ");
		print(dp);
		printf("\n");
		*/
		add(np, dp, 1);
		temp = dp;
		dp = np;
		np = temp;
		/*
		print(np);
		printf(" / ");
		print(dp);
		printf("\n");
		*/
		if (i == (end - 1))
			break;
		add(np, dp, 1);
		temp = dp;
		dp = np;
		np = temp;
		/*
		print(np);
		printf(" / ");
		print(dp);
		printf("\n");
		*/
		mid -= 2;
	}

	add(np, dp, 2);
	print(np);
	printf(" / ");
	print(dp);
	printf("\n");

	return 0;
}

void add(int *n, int *d, int m) 
{
	int ncarry = 0;
	int dcarry = 0; 
	int i;

	for (i = 0; i < 200; i++) {
		if (*n == -1 && ncarry == 0 &&
			*d == -1) 
			break;
		if (*n == -1)
			*n = 0;
		if (*d == -1)
			*d = 0;
		*n += ncarry;
		ncarry = *n + m * *d;
		*n = ncarry % 10;
		ncarry /= 10;
		n++;
		d++;
	}

	return;
}

void print(int *p) {
	int i;
	p = p + 199;
	for (i = 199; i >= 0; i--) {
		if (*p < 0) {
			p--;
			continue;
		}
		printf("%i", *p);
		p--;
	}
	return;
}
