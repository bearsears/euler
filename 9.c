#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c, result;

	for(a = 1 ; a < (1000 - 2 - a) ; a++)
	{
		for(b = (a + 1) ; b < (1000 - 1 - a) ; b++)
		{
			result = 500000 - 1000*a - 1000*b + a*b;

			if(result == 0)
			{
				c = 1000 - a - b;
				if(a < b < c)
					printf("a = %i, b = %i, c = %i \n", a, b, c);
			}
		}
	}
	
	return 0;
}
