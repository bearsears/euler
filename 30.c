#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5

int numb(int *arr, int power);
void increment(int *arr);

int main()
{
	int *ar = (int *) calloc(SIZE, sizeof(int));
	if (ar == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	//*(ar + SIZE - 1) = 1;

	int i;
	
/*	
	for (i = 0; i < SIZE; i++) {
		printf("%i ", *ar++);
	}
	ar -= SIZE;
	printf("\n");
*/	
	int number;
	int result;

	while (number != 99999) {
		number = numb(ar, 0);
		result = numb(ar, 1);
		if (number == result)
			printf("number %i, :: result %i\n", number, result);
		increment(ar);
	}
		
	return 0;
}

int numb(int *arr, int power) 
{
	int pw;
	if (power == 1)	
		pw = SIZE;
	else if(power == 0) 
		pw = 1;
	else {
		printf("This should not happen.\n");
		exit(1);
	}

	int ret = 0;
	int i = 0;
	for (i = 0; i < SIZE; i++) {
		if (pw == 1)
			ret = ret + pow(*(arr + i), pw) * pow(10, i);
		else
			ret += pow(*(arr + i), pw);
	}

	return ret;
}

void increment(int *arr) 
{
	*arr += 1;
	int carry = 0;
	int i;
	for (i = 0; i < SIZE; i++) {
		*(arr + i) += carry;
		carry = *(arr + i) / 10;
		*(arr + i) %= 10;
	//	printf("%i", *(arr + i));
	}
	//printf("\n");
}


	
