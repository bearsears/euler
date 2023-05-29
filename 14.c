#include <stdio.h>
#include <stdlib.h>

int main()
{
	long i;
	long ti;
	long answer;
	long chain = 0;
	long tchain;

	for (i = 1 ; i <= 1000000 ; i++)
	{
		ti = i;
		tchain = 0;	
		
		while ( ti != 1)
		{
			if ((ti % 2) == 0)
			{
				ti /= 2;
				tchain++;
			}
			else
			{
				ti = 3 * ti + 1;
				tchain++;
			}
		}

		if (tchain > chain)
		{
			chain = tchain;
			answer = i;
		}
	}
	printf("Answer is %lu, and %lu chains long.\n", answer, chain);

	return 0;
}
