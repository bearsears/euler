#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

long *decreasing(long a[]);
long condition(long a[]);

long main()
{
	long a[SIZE];
	long i;
	long *p = a;
	long n = 0;
	long result = 0;

	for (i = 0; i < SIZE; i++)
		a[i] = SIZE - i - 1;
	/*
	for (i = 0; i < SIZE; i++) 
		n = n * 10 + a[i];
	printf("%lu\n", n);
	*/
	
	while (p != NULL) {
		p = decreasing(a);
		/**/
		if (condition(a) == 1) {
			for (i = 0; i < SIZE; i++) 
				n = n * 10 + a[i];
//			printf("%lu\n", n);
			result += n;
		}
		/*  
		for (i = 0; i < SIZE; i++) 
			n = n * 10 + a[i];
		printf("%lu\n", n);
		*/
		n = 0;
	}
	printf("Result %lu\n", result);

	return 0;
}
	
long *decreasing(long a[])
{
	long *p = a;
	long *end = p + SIZE - 1;
	long *pivot = end - 1;
	long t;
	long distance;

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

/* put the polongers back to where it was */
	pivot = p + distance;
	end = p + SIZE - 1;

/* i want the number that is on the left of pivot, and switch to the next
 * lowest */
	t = *(pivot - 1) - 1;
	while (t >= 0) {
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
long condition(long a[])
{
	long *p = a;
	long n = *(p + 1)*100 + *(p + 2)*10 + *(p + 3);
	if ((n % 2) != 0)
		return 0;

	n = *(p + 2)*100 + *(p + 3)*10 + *(p + 4);
	if ((n % 3) != 0)
		return 0;

	n = *(p + 3)*100 + *(p + 4)*10 + *(p + 5);
	if ((n % 5) != 0)
		return 0;

	n = *(p + 4)*100 + *(p + 5)*10 + *(p + 6);
	if ((n % 7) != 0)
		return 0;

	n = *(p + 5)*100 + *(p + 6)*10 + *(p + 7);
	if ((n % 11) != 0)
		return 0;

	n = *(p + 6)*100 + *(p + 7)*10 + *(p + 8);
	if ((n % 13) != 0)
		return 0;

	n = *(p + 7)*100 + *(p + 8)*10 + *(p + 9);
	if ((n % 17) != 0)
		return 0;

	return 1;
}
