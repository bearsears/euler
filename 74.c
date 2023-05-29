#include <stdio.h>
#include <stdlib.h>

int main()
{

	int factorials[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	int keys[9] = {1, 2, 145, 169, 871, 872, 1454, 45361, 363601};

	int *pf = factorials;

	int n, temp, i, sum, length, found, anchor;
	int total = 0;

	for (n = 3; n < 1000000; n++) {
		temp = n;
	//	printf("%i-->", temp);
		sum = 0;
		length = 0;
		anchor = 0;
		for (i = 0; i < 100; i++) {

			if (anchor == 0) {
				for (found = 0; found < 9; found++) 
					if (keys[found] == temp)
						break;
				if (found < 9)
					anchor = keys[found];
			} else if (anchor == temp) {
				break;
			}

			length++;
			while (temp > 0) {
		//		printf("%i, ", *(pf + temp % 10));
		//		printf("%i\t,", sum);
				sum += *(pf + temp % 10);
				//printf("%i\t,", sum);
				temp /= 10;
			}

	//		printf("%i\t", sum);
			temp = sum;
			sum = 0;
		}
		if (length >= 60 && length <= 70) {
		//	printf("%i's length is %i\n", n, length);
			total++;
		}
		/*
		if (i > 60)
			printf("%i\t", n);
			*/

	//	printf("\n\n");
	}
	printf("%i is the total.\n", total);

	return 0;
}
		
		
