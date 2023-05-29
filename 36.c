#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n = 2;
	int d = log(n)/log(2); /* digit of binary required */
	int bit = 0;
	printf("%i,\n", d);
	int i;

	for (i = 0; i <= d; i++) {
		bit = n >> (d - i);
		if (bit == 1)
			n = n ^ (int) pow(2, (d - i));
		printf("%i", bit);
	}
		/*bit = n;
		printf("%i %i\n", bit, n);
		*/
	printf("\n");

	return 0;
	
}
