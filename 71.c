/* gcc -g 71.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	double pole = 3.0 / 7.0;
	double temp, bottom, top;
	int i, ib, j; 
	double closest = 0.0;
	
	int numerator;


	for (i = 1000000; i >= 2; i--) {
		temp = i * pole;
		bottom = floor(temp);
		top = ceil(temp);
		ib = (int) bottom;
		//check if both numbers are even,
		if (ib % 2 == 0 && i % 2 == 0)
			continue;
		for (j = ib; j <= ib; j += 2)
			if (i % j == 0)
				break;
		if (j <= ib)
			continue;

		//printf("%i, %f, %f, %f\n", i, temp, bottom, top);
		temp = bottom / (double) i;
		if (closest < temp && temp < pole) {
			closest = temp;
			numerator = i;
		}

	}
	printf("%i, %f, \n", numerator, closest);

	return 0;
}
