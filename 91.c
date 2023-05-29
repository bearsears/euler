#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sides[51];
	sides[0] = 0;
	int i;
	for(i = 1; i < 51; i++) {
		sides[i] = 3 + (i - 1) * 2 * 3;
		if(i % 2 == 0)
			sides[i] += 2;
	}

	int answer = 0;
	for(i = 0; i < 51; i++) {
		printf("%ix%i, %i\n", i, i, sides[i]);
		answer += sides[i];
	}

	printf("%i is the answer.\n", answer);

	return 0;
}
