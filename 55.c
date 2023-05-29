#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
/* gcc -g 55.c -o go 
I got lazy here, I've just assumed that 
int main() 
{
	long l, add, temp, rev;
	int i;
	long limit = LONG_MAX / 10;
	printf("\t%lu\n", limit);
	int count = 0;

	for (l = 100; l < 10000; l++) {
		temp = l;
		rev = 0;
		add = l;
		while (temp > 0) {
			rev = rev * 10 + temp % 10;
			temp /= 10;
		}
		add += rev;
		temp = add;
		rev = 0;
		for (i = 1; i < 50; i++) {
			while (temp > 0) {
				rev = rev * 10 + temp % 10;
				temp /= 10;
			}
			/* checks palindrome */
			if ((add - rev) == 0) {
			//	printf("%lu is not a lychrel number, it has "
			//	"taken %i iteration to reach %lu.\n", l, i, add);
				break;
			}
			add += rev;
			temp = add;
			rev = 0;
			if (add > limit) {
			//	printf("Breaking out, due to long limits. "
			//	"%lu is the number, %i iteration, %lu.\n",
			//	l, i, add);
				count++;
				break;
			}
		}
	}
	printf("%i is the count.\n", count);

	return 0;
}

						


