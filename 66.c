/*gcc -g 66.c -o go -lm */
#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() 
{
	long xsq, x, y, d;
	long limit;
	long totalleft = 0;

	for(d = 2 ; d <= 1000 ; d++) {
		limit = (long) sqrt((LONG_MAX - 1) / d);
		if (sqrt(d) == floor((sqrt(d))))
			continue;
		printf("limit is %lu for ", limit);
		for (y = 1 ; y <= limit ; y++) {
			xsq = 1 + d * y * y;
			/* belwo condition is not accurate, it has rounding
			 * errors. However it is fast enough and will filter
			 * smaller numbers */
			if (sqrt(xsq) == floor((sqrt(xsq)))) {
				x = (long) sqrt(xsq);
				if ((x * x) == xsq) {
					printf("%lu, %lu, %lu, y is %lu\n", d, xsq,
					x, y);
				break;
				}
			}
		}
		if (y == limit + 1) {
			totalleft++;
			printf("\t\t\t %lu is not found \n", d);
		}

	}

	printf("limit of long is %lu\n", LONG_MAX);
	printf("You still have %lu left,\n", totalleft);

	return 0;

}
