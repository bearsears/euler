#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SZ 50
int main()
{
	double squared = sqrt(524);
	int array[SZ];
	int i;

	for (i = 0; i < SZ ; i++) {
		array[i] = floor(squared);
		squared = 1 / (squared - floor(squared));
	}

	for (i = 0; i < SZ ; i++) {
		printf("%i, ", array[i]);
	}

	long h, k, hp, kp, temp;
	h = array[0];
	hp = 1;
	k = 1;
	kp = 0;
	printf("n: %i, a: %i, h: %lu, k: %lu\n", 0, array[0], h, k);

	for (i = 1 ; i < SZ ; i++) {
		temp = h;
		h = array[i] * h + hp;
		hp = temp;
		temp = k;
		k = array[i] * k + kp;
		kp = temp;
		printf("n: %i, a: %i, h: %lu, k: %lu\n", i, array[i], h, k);
	}
	
	printf("\n");

	return 0;
}
