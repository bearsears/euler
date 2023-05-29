/*gcc -g 68.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define RING 3

void rotate(int keya[RING], int keyb[RING]);

int main() 
{
	int keya[RING] = {1, 2, 3};
	int keyb[RING] = {4, 5, 6};
	rotate(keya, keyb);
	rotate(keyb, keya);
	int keyc[RING] = {3, 2, 1};
	int keyd[RING] = {6, 5, 4};
	rotate(keyc, keyd);
	rotate(keyd, keyc);
	int keye[RING] = {1, 3, 5};
	int keyf[RING] = {2, 4, 6};
	rotate(keye, keyf);
	rotate(keyf, keye);
	int keyg[RING] = {5, 3, 1};
	int keyh[RING] = {6, 4, 2};
	rotate(keyg, keyh);
	rotate(keyh, keyg);

	return 0;
}

void rotate(int keya[RING], int keyb[RING]) 
{
	int a[2], b[2], c[2];
	int *ap, *bp, *cp;
	ap = &b[1];
	bp = &c[1];
	cp = &a[1];
	int temp;

	int i, j, k;

	for (i = 0; i < RING; i++) {
		for (j = 0; j < RING; j++) {
			//printf("%i, %i, %i;\n", keya[0], keya[1], keya[2]);
		//	printf("%i, %i, %i;\n", keyb[0], keyb[1], keyb[2]);
			
			a[0] = keya[0];
			b[0] = keya[1];
			c[0] = keya[2];
			a[1] = keyb[0];
			b[1] = keyb[1];
			c[1] = keyb[2];
		//	printf("%i, %i, %i; ", a[0], a[1], *ap);
		//	printf("%i, %i, %i; ", b[0], b[1], *bp);
		//	printf("%i, %i, %i; ", c[0], c[1], *cp);
		//	printf("\n");
			if ((a[0] + a[1] + *ap) == (b[0] + b[1] + *bp) && 
				(a[0] + a[1] + *ap) == (c[0] + c[1] + *cp)) {
				printf("%i-->", (a[0] + a[1] + *ap));
				printf("%i, %i, %i; ", a[0], a[1], *ap);
				printf("%i, %i, %i; ", b[0], b[1], *bp);
				printf("%i, %i, %i; ", c[0], c[1], *cp);
				printf("  ");
			}
			temp = keyb[0];
			for (k = 1; k < RING; k++) {
				keyb[k - 1] = keyb[k];
			}
			keyb[RING - 1] = temp;
		}
		//printf("\n");

		temp = keya[0];
		for (k = 1; k < RING; k++) {
			keya[k - 1] = keya[k];
		}
		keya[RING - 1] = temp;
	}

	printf("\n");
	return ;
}
