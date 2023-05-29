/* gcc -g 60.c primeGen.c -o go -lm */
#include <stdio.h>
#include <stdlib.h>
#include "primeGen.h"
#include <math.h>
#define SIZE 5


int cmpf(const void *a, const void *b) {
	return (*(long *) a - *(long *) b);
}

void setFind(long number, long *p);
int check (long a, long b);
int pCheck (long n);
long size;
long *pnumbers;

int main()
{
	pnumbers = primeGen(10000000, &size);
	long number = 30000;
	printf("Finished.\n");
	printf("%lu,  ", number);
	setFind(number, (pnumbers + 1));
	
	return 0;
}

void setFind(long number, long *p) 
{
	int i;
	long *arr[SIZE];
	arr[0] = p;
	long *end = p;
	while (*end < number)
		end++;
	long sum = 0 ;

	while (*arr[0] < number) {
		printf("%lu  ", *arr[0]);
		sum += *arr[0];
		if (sum > number) {
			sum -= *arr[0];
			break;
		}
		arr[1] = arr[0] + 1;
		while (*arr[1] < (number - *arr[0])) {
			sum += *arr[1];
			
			if (sum > number) {
				sum -= *arr[1];
				break;
			}
			
			if (check(*arr[0], *arr[1]) == 0) {
				sum -= *arr[1];
				arr[1]++;
				continue;
			}

			arr[2] = arr[1] + 1;
			
			while (*arr[2] < (number - *arr[0] - *arr[1])) {
				sum += *arr[2];

				if (sum > number) {
					sum -= *arr[2];
					break;
				}
				
				if (check(*arr[0], *arr[2]) == 0 ||
					check(*arr[1], *arr[2]) == 0) {
					sum -= *arr[2];
					arr[2]++;
					continue;
				}
				
				arr[3] = arr[2] + 1;
				while (*arr[3] < (number - *arr[0] - *arr[1] - *arr[2])) {
					sum += *arr[3];
					
					if (sum > number) {
						sum -= *arr[3];
						break;
					}
					
					if (check(*arr[0], *arr[3]) == 0 ||
						check(*arr[1], *arr[3]) == 0  ||
						check(*arr[2], *arr[3]) == 0) {
						sum -= *arr[3];
						arr[3]++;
						continue;
					}
					
					arr[4] = arr[3] + 1;
					while (*arr[4] < (number - *arr[0] - *arr[1] - *arr[2] - *arr[3])) {
						sum += *arr[4];
						
						if (sum > number) {
							sum -= *arr[4];
							break;
						}
						
						if (check(*arr[0], *arr[4]) == 0 ||
							check(*arr[1], *arr[4]) == 0 ||
							check(*arr[2], *arr[4]) == 0 ||
							check(*arr[3], *arr[4]) == 0 ) {
							sum -= *arr[4];
							arr[4]++;
							continue;
						}
						printf("%lu = ", number);
						for (i = 0 ; i < SIZE ; i++)
							printf("%lu + ", *arr[i]);
						printf("\n");
						
						
						sum -= *arr[4];
						arr[4]++;
					}
					
					sum -= *arr[3];
					arr[3]++;
				}
				sum -= *arr[2];
				arr[2]++;
			}
			sum -= *arr[1];
			arr[1]++;
		}
		sum = 0;
		arr[0]++;
	}
}

/* the recursion version, while i was surprised that it ever worked,
 * goes to many levels that it over flows (seg fault)
 *
void setFind(long number, long sets[SIZE], int i, long *p, long *start)
{
	if (i < SIZE) 
		sets[i] = *p;
	if (*p > number)
		return;
	long sum = 0;
	int j;
	for (j = 0; j <= i; j++) {
		sum += sets[j];
	//	printf("%i, %lu, ", j, sets[j]);
	}
	//printf("%lu,   ", sum);

	if (sum < number && i < (SIZE - 1)) {
		p++;
		i++;
		setFind(number, sets, i, p, start); 
	} else if (sum < number && i == (SIZE - 1)) {
		p++;
		setFind(number, sets, i, p, start);
	} else if (sum >= number && i > 0 && i < (SIZE - 1)) {
		i--;
		p = start;
		while (*p++ < sets[i]);
		setFind(number, sets, i, p, start);
	} else if (sum > number && i == (SIZE - 1)) {
		i--;
		p = start;
		while (*p++ < sets[i]);
		setFind(number, sets, i, p, start);
	} else if (sum == number, i == (SIZE - 1)) {
		//
		for (j = 0 ; j < i ; j++) {
			result = check(sets[j], sets[j + 1]);
			if (result == 0)
				break;
		}
		//
	//	if (result == 1) {
		printf("%lu = ", number);
		for (j = 0; j <= i; j++)
			printf("%lu + ", sets[j]);
		printf("\n");
		//}
		i--;
		p = start;
		while (*p++ < sets[i]);
		setFind(number, sets, i, p, start);
	}
	if (sets[0] > number)
		return;

	return;
}
*/
int check (long a, long b) {
	long al = 1;
	long bl = 1;
	long at = a;
	long bt = b;
	while (at > 0) {
		al *= 10;
		at /= 10;
	}
	while (bt > 0) {
		bl *= 10;
		bt /= 10;
	}
	long first = a * bl + b;
	long second = a + b * al;
	long end = *(pnumbers + size - 1);
	long fres = 1;
	long sres = 1;
	//printf("%lu, %lu, %lu, %lu\n", first, second, a, b);
	
	if (first > end) {
		fres = pCheck(first);
		if (fres == 0)
			return 0;
	}
	else if (bsearch(&first, pnumbers, size, sizeof(long), cmpf) == NULL)
		return 0;	

	if (second > end) {
		sres = pCheck(second);
		if (sres == 0)
			return 0;
	}
	else if (bsearch(&second, pnumbers, size, sizeof(long), cmpf) == NULL) 
		return 0;

	return 1;
}


int pCheck (long n) {
	if (n % 3 == 0)
		return 0;
	
	long limit = n / 2;
	long dv = 5;
	while (dv <= limit) {
		if (n % dv == 0)
			return 0;
		limit = n / dv;
		dv += 2;
	}
	return 1;
}
