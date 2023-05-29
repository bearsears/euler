/* I am really happy with how it turned out, despite the fact that I am not
 * comfortable with recursion. 
 * The program turned out to be relatively quick 50ms.
 */
#include <stdlib.h>
#include <stdio.h>
#define SIZE 8

const int coins[SIZE] = {200, 100, 50, 20, 10, 5, 2, 1};
int result = 0;
void check(int value, int place);

int main()
{
	int i;
	for (i = 0; i < SIZE; i++) {
		check(coins[0], i);
		printf("Found %i results.\n", result);
	}

	return 0;
}

void check(int value, int place)
{
	if (place == SIZE)
		return;
	int tvalue = value - coins[place];
	//printf("value is %i, coin is %i, tvalue is %i, place is %i.\n", value,
	//coins[place], tvalue, place);
	if (tvalue == 0) {
		result++;
	//	printf("\tvalue is %i, coin is %i, and tvalue is %i.\n", value,
	//	coins[place], tvalue);
		return;
	}
	else if (tvalue > 0) {
		check(tvalue, place);
		while (place < SIZE) 
			check(tvalue, ++place);
	}
	else if (tvalue < 0) {
		return;
	}
	//printf("\t\t%i is the place.\n", place);

}
