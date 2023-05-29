/*gcc -g 68.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define RING 5

void rotate(int keya[RING], int keyb[RING]);

int main() 
{
	int keya[RING] = {1, 2, 3, 4, 5};
	int keyb[RING] = {6, 7, 8, 9, 10};
	rotate(keya, keyb);
	rotate(keyb, keya);
	int keyc[RING] = {5, 4, 3, 2, 1};
	int keyd[RING] = {10, 9, 8, 7, 6};
	rotate(keyc, keyd);
	rotate(keyd, keyc);
	int keye[RING] = {1, 3, 5, 7, 9};
	int keyf[RING] = {2, 4, 6, 8, 10};
	rotate(keye, keyf);
	rotate(keyf, keye);
	int keyg[RING] = {9, 7, 5, 3, 1};
	int keyh[RING] = {10, 8, 6, 4, 2};
	rotate(keyg, keyh);
	rotate(keyh, keyg);
	int keyi[RING] = {1, 2, 6, 7, 8};
	int keyj[RING] = {3, 4, 5, 9, 10};
	rotate(keyi, keyj);
	rotate(keyj, keyi);
	
	return 0;

}

void rotate(int keya[RING], int keyb[RING]) 
{
	int a[2], b[2], c[2], d[2], e[2];
	int *ap, *bp, *cp, *dp, *ep;
	ap = &b[1];
	bp = &c[1];
	cp = &d[1];
	dp = &e[1];
	ep = &a[1];

	int temp;

	int i, j, k;

	for (i = 0; i < RING; i++) {
		for (j = 0; j < RING; j++) {
		/*	
			printf("%i, %i, %i, %i, %i;\n", keya[0], keya[1],
				keya[2], keya[3], keya[4]);
			printf("%i, %i, %i, %i, %i;\n", keyb[0], keyb[1], 
				keyb[2], keyb[3], keyb[4]);
		*/	
			a[0] = keya[0];
			b[0] = keya[1];
			c[0] = keya[2];
			d[0] = keya[3];
			e[0] = keya[4];
			a[1] = keyb[0];
			b[1] = keyb[1];
			c[1] = keyb[2];
			d[1] = keyb[3];
			e[1] = keyb[4];
		/*	
			printf("%i, %i, %i; ", a[0], a[1], *ap);
			printf("%i, %i, %i; ", b[0], b[1], *bp);
			printf("%i, %i, %i; ", c[0], c[1], *cp);
			printf("%i, %i, %i; ", d[0], d[1], *dp);
			printf("%i, %i, %i; ", e[0], e[1], *cp);
			printf("\n");
		*/
			if ((a[0] + a[1] + *ap) == (b[0] + b[1] + *bp) && 
				(a[0] + a[1] + *ap) == (c[0] + c[1] + *cp) &&
				(a[0] + a[1] + *ap) == (d[0] + d[1] + *dp) &&
				(a[0] + a[1] + *ap) == (e[0] + e[1] + *ep)) {
				printf("%i-->", (a[0] + a[1] + *ap));
				printf("%i, %i, %i; ", a[0], a[1], *ap);
				printf("%i, %i, %i; ", b[0], b[1], *bp);
				printf("%i, %i, %i; ", c[0], c[1], *cp);
				printf("%i, %i, %i; ", d[0], d[1], *dp);
				printf("%i, %i, %i; ", e[0], e[1], *ep);
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
