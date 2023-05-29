#include <stdio.h>
#include <stdlib.h>
/* how i solved it,
   I first generated a low numbers that follows the 50% pattern,
 	I've noticed that by squared current number, divide by old, will give
	a higher new number that was short by 12... so I manipulated that
	pattern. 
 */

int main()
{
	unsigned long temp;
	unsigned long a = 85;
	unsigned long b = 15;

	for(int i = 0; i < 15; i++){
		printf("%lu, \n", a);
		temp = a;
		a = (unsigned long) ((double) a * (double) a / (double) b + 12);
		b = temp;
	}
	
	return 0;
}
