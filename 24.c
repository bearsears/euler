#include <stdio.h>
#include <stdlib.h>
#define SZ 1000001
void heapP(int a[], int size, int n);
void storeA(int a[], int n);
void swap(int *a, int *b);

int cmpf(const void * a, const void * b) {
	return ( *(long *)a - *(long *)b);
}
int main()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof a / sizeof(a[0]);
	static int count = 0;
	FILE *fp;
	fp = fopen("24.txt", "w+");
	fclose(fp);
	heapP(a, n, n);

	return 0;
}

void heapP(int a[], int size, int n)
{
	if (size == 1) {
		storeA(a, n);
		return;
	}
	int i;
	for (i = 0; i < size; i++) {
		heapP(a, size - 1, n);
		if (size % 2 == 1)
			swap(&a[0], &a[size - 1]);
		else
			swap(&a[i], &a[size - 1]);
	}
}

void storeA(int a[], int n)
{
	int i; 
	unsigned static long ct = 0;
	FILE *fp;
	fp = fopen("24.txt", "a");
	for (i = 0; i < n; i++) {
		printf("%i",a[i]);
		fputc((a[i] + '0'), fp);
	}
	printf(":%lu, \t",  ct);
	fputc(10, fp);
	fclose(fp);
	
	/*
	for (i = 0; i < ct; i++) {
		printf("%i, ", b[i]);
	}
	printf(" %i, \n", ct);
	*/
	ct++;
/*	
	if (ct == 100) {
		qsort(b, SZ, sizeof(long), cmpf);
		for (i = 0; i < SZ; i++) {
			printf("%lu, %i\n", b[i], (i + 1));
		}
		//printf("%i is the millionth element.\n", b[SZ - 2]);
		exit(0);
	}
	*/

}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
