/* gcc -g 62.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define MIN 4642
#define MAX 9999
#define SZ 12
#define LIM 5

int compfn(const void *a, const void *b) 
{
	const long *la = (const long *) a;
	const long *lb = (const long *) b;
	
	return  *la - *lb;
}

void sortandstore (long n, long *p); 
void keyandfind (long n, long key); 

int main() 
{
	long n = MIN;
	long array[MAX - MIN];

	for ( ; n < MAX ; n++) {
		sortandstore((n * n * n), &array[(n - MIN)]);
	//	printf("%lu, %lu: ", array[(n - MIN)], n);
	}

	long end = MAX - MIN;
	
	int i, j;
	long temp;
	//printf("\n");
	//printf("\n");
	//printf("\n");
	for (i = 1 ; i < end ; i++) {
		j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			temp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = temp;
			j--;
		}
	}
		
/*	
	for (i = 0 ; i < end ; i++) {
		printf("%lu, %i: ", array[i], i);
	}
	*/
	
	int limit = 1;
	long key;
	for (i = 1 ; i < end ; i++) {
		if (array[i] == array[i - 1])
			limit++;
		else 
			limit = 1;

		if (limit == LIM) {
			printf("\n %lu %i \n", array[i], i);
			key = array[i];
			break;
		}
	}
	printf("\n %lu %i \n", array[i], i);

	for (n = MIN ; n < MAX ; n++) {
		keyandfind(n, key);
	}

	printf("\n");

	return 0;
}

void sortandstore (long n, long *p) 
{
	long *array = (long *) calloc(SZ, sizeof(long));
	if (array == NULL)
		exit(0);
	int i;

	for (i = 0 ; i < SZ ; i++) {
		*array++ = n % 10;
		n = n / 10;
	}
	array -= SZ;

	qsort(array, SZ, sizeof(long), compfn);
	*p = 0;

	for (i = 0 ; i < SZ ; i++) 
		*p = *p * 10 + *array++;
	

	return;
}

void keyandfind (long n, long key) 
{
	long triple = n * n * n;
	long *array = (long *) calloc(SZ, sizeof(long));
	if (array == NULL)
		exit(0);
	int i;

	for (i = 0 ; i < SZ ; i++) {
		*array++ = triple % 10;
		triple = triple / 10;
	}
	array -= SZ;

	qsort(array, SZ, sizeof(long), compfn);
	long temp = 0;	

	for (i = 0 ; i < SZ ; i++) 
		temp = temp * 10 + *array++;

	if (key == temp) {
		printf(" %lu, ", n);
		for (i = 0 ; i < SZ ; i++)
			printf("%lu", *--array);
	}
	
	return;
}
	



