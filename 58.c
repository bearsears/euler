#include <stdio.h>
#include <stdlib.h>

int isPrime(int n);

int main()
{
	int br = 5; /* bottom right */
	int brsq = br * br; /* bottom right squared */
	int pn = 5;
	int td = 2 * (br - 1) + 1;
	int i, temp;
		
	while ((pn * 100) / td > 9 ) {
		br += 2;
		brsq = br * br;
		temp = brsq;
		td = 2 * (br - 1) + 1;
		for (i = 0; i < 3; i++) {
			temp = temp - br + 1;
			pn += isPrime(temp);
		}
		//printf("%i, %i / %i\n", br, pn, td);
	}
	printf("%i, %i / %i\n", br, pn, td);

	return 0;
}

int isPrime(int n)
{
	if (n % 2 == 0)
		return 0;

	int limit = n / 2;
	int i = 3;
	
	while (i < limit) {
		if (n % i == 0)
			return 0;
		limit = n / i;
		i += 2;
	}

	return 1;
}
		
