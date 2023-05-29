#include <stdio.h>
#include <stdlib.h>
#define MP 6 /* MP as in multiples */

int md(int n); /* multiple of the digit */
int pd(int n); /* additions of the digit */
int main()
{
	unsigned int n = 1;
	int i;
	int temp;
	int sum;
	int summ; /* sum of the multiple */
	int ad;
	int adm;

	while (1) {
		sum = pd(n);
		ad = md(n);

		for (i = 2; i <= MP; i++) {
			summ = pd (i * n);
			adm = md(i * n);
			if (sum != summ || ad != adm )
				break;
		}
		if (i == (MP + 1)) {
			break;
		}
		n++;
	}
	printf("n is %i, and its sum is %i,\t", n, sum);
	
	return 0;
}

int pd (int n) {
	int sum = 0;
	while (n != 0) {
		sum = sum + (n % 10);
		n /= 10;
	}
	return sum;
}
int md (int n) {
	int mp = 1;
	int rm;
	while (n != 0) {
		rm = n % 10;
		if (rm != 0)
			mp = mp * (n % 10);
		n /= 10;
	}
	return mp;
}


