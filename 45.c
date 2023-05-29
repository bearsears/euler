/* gcc -g 45.c -o go */
#include <stdio.h>
#include <stdlib.h>

int main() 
{
	unsigned int ti = 286;
	unsigned int pi = 166;
	unsigned int hi = 144;
	unsigned int t = ti * (ti + 1) / 2;
	unsigned int p = pi * (3 * pi - 1) / 2;
	unsigned int h = hi * (2 * hi - 1);

	while (p != t) {
		while (p < h) {
			pi++;
			p = pi * (3 * pi - 1) / 2;
		}
		while (t < h) {
			ti++;
			t = ti * (ti + 1) / 2;
		}
		//printf("ti %i, pi %i, hi %i, ", ti, pi, hi);
		//printf("t is %i, p is %i, h is %i.\n", t, p, h);
		if (h != p) {
			hi++;
			h = hi * (2 * hi - 1);
		}
	}

	printf("ti %i, pi %i, hi %i, t is %i, p is %i, h is %i.\n", ti,	pi, hi, t, p, h);

	return 0;
}	
