#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *arr, int lines);
void printArrayt(int *arr, int lines);
void checkZero(int *arr, int lines);
int leftSum(int *arr, int lines);
int rightSum(int *arr, int lines);
void leftRv(int *arr, int lines);
void rightRv(int *arr, int lines);

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
	printArrayt(tri, nlines);

	char answer = 'y';
	i = 0;

	while (answer == 'y' || answer == 10)
	{
		i++;
		checkZero(tri, nlines);
		int lsum = leftSum(tri, nlines);
		int rsum = rightSum(tri, nlines);
		printf("\nleft sum %i\t right sum %i\t cycle %i\n", lsum, rsum, i);

		if (lsum > rsum)
			rightRv(tri, nlines);
		else if (lsum < rsum)
			leftRv(tri, nlines);
		else  // wow equal value
			printf("Never thought it could happen but it happened..\n");		
		printArrayt(tri, nlines);
		printf("continue?\n");
		answer = getchar();
	}


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

void checkZero(int *arr, int lines) 
{
	/* this function will check zeros underneath the triangle.
	 * if one below and one below and right are both zeros,
	 * the current element will turn to zero.
	 */

	 int *temp = arr;
	 int size = lines * lines - lines - 1; 
	 /* above is to ensure that pointer will not access memory beyond 
	  * its size
	  */
	 int i;
	 int changed = 0; // if there are changes it will start over to see
	 // if the changes effect more changes.

	 while (changed == 0) {
	 	changed = 1;
		for (i = 0; i < size; i++) {
		 	if (*temp == 0) {
				temp++;
				continue;
			}
			if (*(temp + lines) == 0 && *(temp + lines + 1) == 0) {
				*temp++ = 0;
				changed = 0;
			}
			else 
				temp++;
		}
		
		temp -= size;
		printArrayt(arr, lines);
	}

	return;
}

int leftSum(int *arr, int lines) 
{
	 int *temp = arr;
	 int sum = 0;
	 sum += *temp;
	 int i = 0;
	 int limit = lines - 1;

	 for (i = 0; i < limit; i++) {
		if (*(temp + lines) == 0) {
			temp += (lines + 1);
			sum += *temp;
		}
		else {
			temp += lines;
			sum += *temp;
		}
	}

	return sum;
}

int rightSum(int *arr, int lines)
{
	 int *temp = arr;
	 int sum = 0;
	 sum += *temp;
	 int i = 0;
	 int limit = lines - 1;

	 for (i = 0; i < limit; i++) {
		if (*(temp + lines + 1) == 0) {
			temp += lines;
			sum += *temp;
		}
		else {
			temp += (lines + 1);
			sum += *temp;
		}
	}

	return sum;
}

void leftRv(int *arr, int lines)
{
	int *temp = arr;
	temp += (lines * (lines - 1));
	int i = 0;
	/* start at the last row */

	if (*temp != 0) {
		*temp = 0;
		return;
	}
	else {
		while (*temp == 0) {
			i++;
			temp++;
		}
	}

	int size = lines - 3 - i;
	/* it is three because 1 less for having temp move forward,
	 * and two less because there has to remain two elements
	 * at the end.
	 */
	for (i = 0; i < size; i++) {
		if (*(temp - 1) == 0 && *(temp - lines - 1) > 0) {
			*(temp - lines - 1) = 0;
			return;
		}
		else if (*(temp - 1) == 0 && *(temp - lines - 1) == 0) {
			*temp = 0;
			return;
		}
		temp++;
	}

	return;
}
	
void rightRv(int *arr, int lines)
{
	int *temp = arr;
	temp += lines * lines - 1;
	int i = 0; 
	/* start at the last row, last element */

	if (*temp != 0) {
		*temp = 0;
		return;
	}
	else {
		while (*temp == 0) {
			i++;
			temp--;
		}
	}

	int size = lines - 3 - i;
	
	/* it is three because 1 less for having temp move forward,
	 * and two less because there has to remain two elements
	 * at the end.
	 */
	for (i = size; i > 0; i--) {
		if (*(temp + 1) == 0 && *(temp - lines) > 0) {
			*(temp - lines) = 0;
			return;
		}
		else if (*(temp + 1) == 0 && *(temp - lines) == 0) {
			*temp = 0;
			return;
		}
		temp--;
	}

	return;
}
