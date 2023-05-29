/* gcc -g 69.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 87109

/* the number came from 2*3*5*7*11*13*17,
 * good lucky educated guess */

int main() 
{
	int *rp = (int *) malloc(sizeof(int) * SIZE);

	if (rp == NULL) {
		exit(1);
	}

	int *temp;
	int n = 2;
	int i, j;
	int count = 0;
	

	for (i = 0; i < SIZE; i++) 
		*rp++ = -1;
	rp -= i;

	for (n = 87109; n <= SIZE; n++) {
		for (i = 1; i < n; i++)
			*rp++ = i;
		rp -= (n - 1);
/*
		printf("%i-->", n);
		for(i = 1; i < n; i++)
			printf("%i,", *rp++);
		printf("\n");
		rp -= (i - 1);

		rp++;
		*/
		rp++;

		for (i = 2; i < n; i++) {
			if (*rp == 0) {
				rp++;
				continue;
			}
			if (n % *rp == 0) {
				temp = rp;
				temp += *rp;
				while ((temp - rp) <= (n - *rp)) {
					*temp = 0;
					temp += *rp;
				}
				*rp = 0;
			}
			if (*rp > (n / 2))
				break;
			rp++;
		}
		rp -= (i - 1);

		printf("%i-->", n);
		for(i = 1; i < n; i++) {
			if (*rp != 0)
				count++;
			printf("%i,", *rp++);
		}
		
		printf("-->%f", ((double) n / (double) count));
		printf("\n");
		printf("\n");
		rp -= (i - 1);
		count = 0;
	}

	return 0;
}
