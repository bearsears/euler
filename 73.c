#include <stdio.h>
#include <stdlib.h>

#define SIZE 12000

int main()
{
	int i, j, k, bottom, top;
	int sum = 0;
	
	for (i = 5; i <= SIZE;  i++) {
		if (i % 3 == 0)
			bottom = i / 3;
		else
			bottom = i / 3 + 1;
	
		if (i % 2 == 0)
			top = i / 2;
		else
			top = i / 2 + 1;
	//	printf("%i, %i, %i,\n", i, bottom, top);
		for (j = bottom; j < top; j++) {
			if (j % 2 == 0 && i % 2 == 0)
				continue;
			for (k = 3; k <= j ; k += 2)
				if (i % k == 0 && j % k == 0)
					break;
			if (k <= j)
				continue;
	//		printf("\t %i, %i, \n", j, i);
			sum++;
		}
	}
	printf("%i is the sum.\n", sum);

	return 0;
}
			

