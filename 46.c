/* gcc -g 46.c -o go */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/* interesting bug i found, be really careful when you use comparison operator 
 * on unsigned int... i declared unsigned for remain, and it failed 
 * (remain >= 0) in the if statement. by declaring remain as int remain
 * i was able to fix make the if statement work...
 * 
 * never assume that your loops will work the first time, test out a small 
 * sample and print the results!
 */

int isPrime(unsigned int i);
int main()
{
	unsigned int g = 7; /* g for Goldbach number */
	int b = 1; /* b for boolean, 0 for false, 1 for true */
	unsigned int i = 1;
	int remain;

	while (b == 1 && g < 10000) {
		if (isPrime(g) == 1) {
			g += 2;
			i = 1;
			continue;
		}
		//printf("%i, ", g);
		remain = g - 2 * i * i;
		while (remain >= 0) {
		//	printf("remain %i, ", remain);
			if (isPrime(remain) == 1)
				break;
			i++;
			remain = g - 2 * i * i;
		}
		if (remain < 0){
			b = 0;
		}
		//printf("\n");
		g += 2;
		i = 1;
	}

	printf("%i is the smallest odd composite number.\n", (g - 2));
	return 0;
}

int isPrime(unsigned int i) {
	if (i == 2 || i == 3)
		return 1;
	if ((i % 2) == 0 || (i % 3) == 0)
		return 0;
	
	unsigned int d = 5;
	unsigned int limit = i / 3;

	while (limit >= d) {
		if ((i % d) == 0)
			return 0;
		limit = i / d;
		d += 2;
	}

	return 1;
}
