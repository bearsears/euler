/* I am really happy with how it turned out, despite the fact that I am not
 * comfortable with recursion. 
 * The program turned out to be relatively quick 50ms.
 */
#include <stdlib.h>
#include <stdio.h>
#define SIZE 25

const int primes[SIZE] = {97, 89, 83, 79, 73, 71, 67, 61, 59, 53, 47, 43, 41,
	37, 31, 29, 23, 19, 17, 13, 11, 7, 5, 3, 2};
int result = 0;
void check(int value, int place);

int main()
{
	int i, j;
	for (j = 100; j > 3; j--) {
		i = 0;
		while (primes[i] > j)
			i++;
		//printf("For %i, primes is %i, \t", j, primes[i]);
		for (; i < SIZE; i++) {
			check(j, i);
		}
		if (result < 5000)
			break;
		result = 0;
	}
		printf("%i just breaks through 5000 results.\n", j + 1);

	return 0;
}

void check(int value, int place)
{
	if (place == SIZE)
		return;
	int tvalue = value - primes[place];
	//printf("value is %i, coin is %i, tvalue is %i, place is %i.\n", value,
	//primes[place], tvalue, place);
	if (tvalue == 0) {
		result++;
	//	printf("\tvalue is %i, coin is %i, and tvalue is %i.\n", value,
	//	primes[place], tvalue);
		return;
	}
	else if (tvalue > 1) {
		check(tvalue, place);
		while (place < SIZE) 
			check(tvalue, ++place);
	}
	else if (tvalue < 0 && tvalue == 1) {
		return;
	}
	//printf("\t\t%i is the place.\n", place);

}
