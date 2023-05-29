#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *arr, int lines);
void printArrayt(int *arr, int lines);
void downUp(int *arr, int lines);

int main()
{
	FILE *fp;
	fp = fopen("67.txt", "r");
	char numbers[2];
	int *nb = (int *) malloc(10000 * sizeof(int));
	int *temp = nb;	

	while (fgets(numbers, 3, fp) != NULL) {
		*temp++ = (numbers[0] - '0') * 10 + (numbers[1] - '0');
	//	printf("%s: ", numbers);
		if (fgets(numbers, 2, fp) == NULL) 
			break;
	}

	int counter = 0;
	counter = temp - nb;
	int i = 1;
	int nlines = 0;

	while (counter > 0) {
		counter -= i;
		i++;
		nlines++;
	}
	printf("there should be %i lines\n", nlines);

	int *tri = (int *) calloc((nlines * nlines), sizeof(int));
	if (tri == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	temp = nb;
	int *ttemp = tri;
	int limit = 1;

	while ((ttemp - tri) < (nlines * nlines)) {
		for (i = 0; i < limit; i++) {
			*ttemp++ = *temp++;
		}
		ttemp += (nlines - (i % nlines));
		limit++;
	}

	printf("\n");

	printArray(tri, nlines);
	printArrayt(tri, nlines);
	downUp(tri, nlines);

	return 0;
}

void printArray(int *arr, int lines) 
{
	int *temp = arr;
	int i;
	int size = lines * lines;

	for (i = 0; i < size; i++) {
		printf("%i ", *temp++);
		if (i % lines == (lines - 1))
			printf("\n");
	}

	return;
}

void printArrayt(int *arr, int lines) 
{
	int *temp = arr;
	int i, j, k;
	int limit = 1;
	int center = lines ;

	for (i = 0; i < lines; i++) {
		for (j = 0; j < center; j++) 
			printf("  ");
		for (j = 0; j < limit; j++) {
			if ((*temp / 10) == 0) {
				printf("0%i  ", *temp);
				temp++;
			}
			else {
				printf("%i  ", *temp);
				temp++;
			}
		}
		temp += (lines - limit);
		limit++;
		center--;
		printf("\n");
	}

	return;
}

void downUp(int *arr, int lines) 
{
	int *temp;
	int i, j;
	int size = lines - 2;

	for (i = 1; i <= size; i++) {
		temp = arr;
		temp += (lines * (lines - i - 1));
		for (j = 1; j <= (lines - i); j++) {
			if (*(temp + lines) > *(temp + lines + 1)) {
				*temp += *(temp + lines);
				temp++;
			}
			else {
				*temp += *(temp + lines + 1);
				temp++;
			}
		}
		printArrayt(arr, lines);
	}

	return;
}
