#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int *decreasing(int *p);
int prime(int n);

int main()
{
	int a[SIZE];
	int i;
	int *p = a;
	int n = 0;
	int result = 0;

	for (i = 0; i < SIZE; i++)
		a[i] = SIZE - i;
	
	while (p != NULL) {
		p = decreasing(&a);
		for (i = 0; i < SIZE; i++) 
			n = n * 10 + a[i];
		//printf("%i\n", n);
		result = prime(n);	
		if (result == 1) {
			printf("Prime is %i\n", n);
			return 0;
		}

		
		/*
		if (p != NULL && *(p + SIZE - 1) % 2 != 0) {
			for (i = 0; i < SIZE; i++) 
				n = n * 10 + a[i];
			printf("%i\n", n);
			result = prime(n);	
			if (result == 1) {
				printf("Prime is %i\n", n);
				printf("Result is %i\n", prime(2143));
				return 0;
			}
		*/
			
		//printf("%i\n", n);
		n = 0;
	}

	return 0;
}
	
int *decreasing(int *p)
{
	int *end = p + SIZE - 1;
	int *pivot = end - 1;
	int t;
	int distance;

	if (*end < *(end - 1)) {
		t = *end;
		*end = *(end - 1);
		*(end - 1) = t;
		return p;
	}

/* find the pivot, and from the pivot to the end the numbers will flip */ 
	while ((pivot - p) > 0 && *pivot > *(pivot - 1)) 
		pivot--;

/* record the distance between pivot and the start */
	distance = pivot - p;

/* If the pivot is all sorted, that means the number is now the lowest. The
 * distance should be zero
 */
	if (distance == 0) {
		printf("Lowest number!\n");
		return NULL;
	}

/* from pivot to the end, reverse the numbers */
	while ((end - pivot) > 0) {
		t = *end;
		*end-- = *pivot;
		*pivot++ = t;
	}

/* put the pointers back to where it was */
	pivot = p + distance;
	end = p + SIZE - 1;

/* i want the number that is on the left of pivot, and switch to the next
 * lowest */
	t = *(pivot - 1) - 1;
	while (t > 0) {
		while ((end - pivot) >= 0) {
			if (t == *pivot) {
				*pivot = *(p + distance - 1);
				*(p + distance - 1) = t;
				return p;
			}
			pivot++;
		}
		pivot = p + distance;
		t--;
	}

/* it should never get this far, but if it does, return NULL */
	printf("It should not get this far!\n");
	return NULL;
}

int prime(int n) 
{
	int i;
	int d = 3;
	int limit = n / 2;

	while (d <= limit) {
		if (n % d == 0)
			return 0;
		//limit /= d;
		d++;
	}

	return 1;
}
