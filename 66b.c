/*gcc -g 66.c -o go -lm */
#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() 
{
	long xsq, x, y, ysq, d;
	long maxd = 0;
	long maxysq = 0;
	long limit;

	for(d = 2 ; d <= 1000 ; d++) {
		for (x = 2 ; x < LONG_MAX ; x++) {
			=
			if ((xsq - 1) % d != 0)
				continue;
			else {
				ysq = (xsq - 1) / d;
				if (sqrt(ysq) == floor((sqrt(ysq)))) {
					y = (long) sqrt(ysq);
					if ((y * y) == ysq) {
						printf("%lu, %lu, %lu, y is %lu\n", d, xsq,
						x, y);
						if (ysq >= maxysq) {
							maxysq = ysq;
							maxd = d;
						}
					}
				}
			}
		}

