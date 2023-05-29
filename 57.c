#include <stdio.h>
#include <stdlib.h>
/* the numbers where numerator is longer digit than 
 * denominator occurs every cycle, where 1 cycle contains
 * two such numbers occuring at 8th in the cycle, and the last.
 * occuring at 13th.
 * then the answer comes down to 
 * (1000 / 13) * 13 + (1000 % 13) / 8
 */

int main()
{
	unsigned long num = 1;
	unsigned long den = 2;
	unsigned long temp;
	int i;

	for (i = 2; i < 40; i++) {
		num += 2 * den;
		temp = num;
		num = den;
		den = temp;
		printf("%i, %lu/%lu\n", i, (num + den), den);
	}

	return 0;
}
