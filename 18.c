#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *arr, int lines);
void printArrayt(int *arr, int lines);
void downUp(int *arr, int lines);

int main()
{
	FILE *fp;
	fp = fopen("18.txt", "r");
	char *buffer;
	size_t bufsize = 200;
	buffer = (char *) malloc(bufsize * sizeof(char));
	size_t characters;
	int nlines = 0;
	char *numbers;

	while ((characters = getline(&buffer, &bufsize, fp)) != EOF) {
		//printf("%zu, %zu: ", characters, bufsize);
	//	printf("%s", buffer);
		strcat(numbers, buffer);
		nlines++;
	}
	free(buffer);
	fclose(fp);
//	printf("\n%s\n", numbers);

	int *tri = (int *) calloc((nlines * nlines), sizeof(int));
	if (tri == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	char *temp = numbers;
	temp++; // this is to start the temp point to the right position
	int i = 1;

	while (*temp != '\0') {
//		printf("%i ", *temp);
		if (*temp == 32) 
			temp++;
		else if (*temp == 13) {
			temp += 2;
			tri += (nlines - i);
			i++;
		}
		else {
			*tri++ = (*temp - '0') * 10 + (*(temp + 1) - '0');
			temp += 2;
		}
	}

	printf("\n");
	tri -= (nlines * nlines);

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
