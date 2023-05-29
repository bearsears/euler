#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int l, w, row, wtemp;
	int near = 1000000;
	int lnear, wnear;
	int result;

	for(l = 1; l <= 100; l++) {
		row = (l * (l + 1)) / 2;
		for(w = 1; w <= l; w++) {
			wtemp = w;
			while(wtemp > 0) {
				result += (row * wtemp);
				wtemp--;
			}
			if(abs(2000000 - result) < near) {
				printf("length = %i, width = %i, result = %i.\n", 
						l, w, result);
				lnear = l;
				wnear = w;
				near = abs(2000000 - result);
			}
			result = 0;
		}
	}

	return 0;
}
