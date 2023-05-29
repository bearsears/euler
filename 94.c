#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long perfect_sq(long n);

int main()
{
	unsigned long i;
	unsigned long r, s;
	unsigned long p = 0;
	for(i = 3; i <= 333333334; i++){
		//result = sqrt(3 * i * i - 8 * i + 4);
		//result /= 2;

		r = (3 * i - 2) * (i - 2);
		if((r % 4) == 0) {
			r /= 4;
			//printf("%lu and %lu, %f\n", i, r, sqrt(r));
			r = perfect_sq(r);
			if(r > 0) {
		//		printf("%lu and %lu\n", i, r);
				p += (3 * i - 2);
			}
		}

		r = (3 * i + 2) * (i + 2);
		if((r % 4) == 0) {
			r /= 4;
			//printf("\t%lu and %lu, %f\n", i, r, sqrt(r));
			r = perfect_sq(r);
			if(r > 0){
		//		printf("\t%lu and %lu\n", i, r);
				p += (3 * i + 2);
			}
		}
		

	}
	printf("answer should be %lu.\n", p);

	return 0;
}

long perfect_sq(long n)
{
	long i = (long) sqrt(n) - 1;
	while((i * i) <= n) {
		if((i * i) == n)
			return i;
		i++;
	}

	return 0;
}
