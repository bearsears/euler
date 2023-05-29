#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//gcc -g 93.c -o go -lm
//How I arrive 1258: I started from 1234 and I incremented by one, 
//1,2,3,5, until no 
//consecutive numbers were created(i would stop at 1,2,3,10, since the 
//consecutive numbers would stop, then I would start at 1,2,4,5, 1,2,4,6, etc.
//I did this manually and entered in euler as soon as it was a new max.
//long and ugly code. I was tired and got lazy.

void heapPermutation(double a[], int size, int n, double *numbers);
void permutation_repetition(int r, int n, int ra[], int na[], int *operators);
void printArr(int a[], int n);
void compute(double a[], int ra[], int *slots);
void bracket(double a[], int ra[], int *slots);
void printResult(double result, int n, double a[], int ra[], int *slots);
double arith(double l, double r, int o);

int main()
{
	int i, j, k;
	// make permutation of numbers where 
	double a[4] = {1, 2, 5, 8};
	int size = sizeof(a) / sizeof(a[0]);
	double *numbers = (double *) calloc(96, sizeof(double));
	heapPermutation(a, size, size, numbers);
	/*
	for(int i = 0; i < 96; i++){
		printf("%.0f ", *(numbers + i));
	}
	*/
	printf("\n");
	// make repetitive permutation of operators;
	// 4 is *, 3 is /, 2 is +, 1 is -
	int ra[3] = {0, 0, 0};
	int na[4] = {1, 2, 3, 4};
	int *operators = (int *) calloc(192, sizeof(int));
	size = sizeof(na) / sizeof(na[0]);
	int *slots = (int *) calloc(10000, sizeof(int));
	permutation_repetition(0, size, ra, na, operators); 
	/*
	for(int i = 0; i < 192; i++){
		printf("%i ", *(operators + i));
	}
	*/
	// put the numbers and arithmatic together.
	for(i = 0; i < 24; i++){
		for(j = 0; j < 4; j++)
			a[j] = *numbers++;
		for(j = 0; j < 64; j++){
			for(k = 0; k < 3; k++)
				ra[k] = *operators++;
			compute(a, ra, slots);
			bracket(a, ra, slots);
		}
		operators -= 192;
		//for(j = 0; j < 100; j++)
		//	*(slots + j) = 0;
		//printf("\n");
	}
	slots++;
	for(i = 1; i < 10000; i++){
		if(*slots == 1)
			printf("%i, ", i);
		else 
			break;
		slots++;
	}
	
	return 0;
}

void heapPermutation(double a[], int size, int n, double *numbers)
{
	double temp;
	if(size == 1){
		while(*numbers++ != 0);
		numbers--;
		for(int i = 0; i < n; i++)
			*numbers++ = a[i];
		//printArr(a, n);
		return;
	}
	for(int i = 0; i < size; i++){
		heapPermutation(a, size - 1, n, numbers);
		//if size is odd, swap first and last element
		if(size % 2 == 1){
			temp = a[0];
			a[0] = a[size - 1];
			a[size - 1] = temp;
		} else {
			temp = a[i];
			a[i] = a[size - 1];
			a[size - 1] = temp;
		}
	}
}

void permutation_repetition(int r, int n, int ra[], int na[], int *operators)
{
	if(r == 3){
		//printArr(ra, r);
		while(*operators++ != 0);
		operators--;
		for(int i = 0; i < r; i++)
			*operators++ = ra[i];
		return;
	}
	for(int i = 0; i < n ; i++){
		ra[r] = na[i];
		permutation_repetition((r + 1), n, ra, na, operators);
	}
}

void compute(double a[], int ra[], int *slots){
	double result;
	//it's always better to go from left to right.
	//going right to left causes double negative.
	// * + + or * * +
	if((ra[0] > 2 && ra[1] <= 2 && ra[2] <= 2) ||
		(ra[0] > 2 && ra[1] > 2 && ra[2] <= 2)){
		result = arith(a[0], a[1], ra[0]);
		result = arith(result, a[2], ra[1]);
		result = arith(result, a[3], ra[2]);
	} else if(ra[0] <= 2 && ra[1] > 2 && ra[2] <= 2){
		// for - / - or + * -
		result = arith(a[1], a[2], ra[1]);
		result = arith(a[0], result, ra[0]);
		result = arith(result, a[3], ra[2]);
	} else if (ra[0] <= 2 && ra[1] > 2 && ra[2] > 2){
		// + * * or - / /
		result = arith(a[1], a[2], ra[1]);
		result = arith(result, a[3], ra[2]);
		result = arith(a[0], result, ra[0]);
	} else if(ra[0] <= 2 && ra[1] <= 2 && ra[2] > 2){
		// for - - *, - + /
		result = arith(a[2], a[3], ra[2]);
		// prevent double negative calculations.
		result = arith(arith(a[0], a[1], ra[0]), result, ra[1]);
	} else if(ra[0] > 2 && ra[1] <= 2 && ra[2] > 2){
		// for * + *, / - /
		result = arith(arith(a[0], a[1], ra[0]),
			arith(a[2], a[3], ra[2]), ra[1]);
	} else {// for * * * or + + +
		// if all the cases fail, go to the first. 

		result = arith(a[0], a[1], ra[0]);
		result = arith(result, a[2], ra[1]);
		result = arith(result, a[3], ra[2]);
	}
	printResult(result, 0, a, ra, slots);
	return;
}

void bracket(double a[], int ra[], int *slots)
{
	double result;
	// (o o) o o
	result = arith(a[0], a[1], ra[0]);
	if(ra[2] > 2){
		result = arith(result, arith(a[2], a[3], ra[2]), ra[1]);
	} else {
		result = arith(arith(result, a[2], ra[1]), a[3], ra[2]);
	}
	printResult(result, 1, a, ra, slots);
	// (o o) (o o)
	result = arith(arith(a[0], a[1], ra[0]), 
			arith(a[2], a[3], ra[2]), ra[1]);
	printResult(result, 2, a, ra, slots);
	// ((o o) o) o
	result = arith(arith(arith(a[0], a[1], ra[0]), a[2], ra[1]), a[3], ra[2]);
	printResult(result, 3, a, ra, slots);
	// o (o o) o
	result = arith(a[1], a[2], ra[1]);
	if(ra[2] > 2){
		result = arith(a[0], arith(result, a[3], ra[2]), ra[0]);
	} else {
		result = arith(arith(a[0], result, ra[0]), a[3], ra[2]);
	}
	printResult(result, 4, a, ra, slots);
	// (o (o o)) o
	result = arith(arith(a[0], arith(a[1], a[2], ra[1]), ra[0]), a[3], ra[2]);
	printResult(result, 5, a, ra, slots);
	// o ((o o) o) this could cause error, due to double negative.
	result = arith(arith(a[1], a[2], ra[1]), a[3], ra[2]);
	result = arith(a[0], result, ra[0]);
	printResult(result, 6, a, ra, slots);
	// o o (o o)
	result = arith(a[2], a[3], ra[2]);
	if(ra[1] > 2){
		result = arith(a[0], arith(a[1], result, ra[1]), ra[0]);
	} else {
		result = arith(arith(a[0], a[1], ra[0]), result, ra[1]);
	}
	printResult(result, 7, a, ra, slots);
	// o (o (o o))
	result = arith(a[1], arith(a[2], a[3], ra[2]), ra[1]);
	result = arith(a[0], result, ra[0]);
	printResult(result, 8, a, ra, slots);
	// (o o o) o
	if(ra[1] > 2){
		result = arith(a[0], arith(a[1], a[2], ra[1]), ra[0]);
	} else {
		result = arith(arith(a[0], a[1], ra[0]), a[2], ra[1]);
	}
	result = arith(result, a[3], ra[2]);
	printResult(result, 9, a, ra, slots);
	//o (o o o)
	if(ra[2] > 2){
		result = arith(a[1], arith(a[2], a[3], ra[2]), ra[1]);
	} else {
		result = arith(arith(a[1], a[2], ra[1]), a[3], ra[2]);
	}
	result = arith(a[0], result, ra[0]);
	printResult(result, 10, a, ra, slots);
}

void printResult(double result, int n, double a[], int ra[], int *slots)
{
	int i;
	char ops[3];
	if (result < 1 || (result != floor(result)) || result == INFINITY)
		return;
	if(*(slots + (int) result) != 0)
		return; // as this number has already been calculated.
	else
		*(slots + (int) result) = 1;

	for(i = 0; i < 3; i++){
		if(ra[i] == 1)
			ops[i] = '-';
		else if(ra[i] == 2)
			ops[i] = '+';
		else if(ra[i] == 3)
			ops[i] = '/';
		else if(ra[i] == 4)
			ops[i] = '*';
	}
	
	if(n == 0){
		for(i = 0; i < 3; i++)
			printf("%.1f %c ", a[i], ops[i]);
		printf("%.1f = %.1f\n", a[3], result);
	} else if(n == 1){ // (o o) o o
		printf("(%.1f %c %.1f) %c %.1f %c %.1f = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 2){// (o o) (o o)
		printf("(%.1f %c %.1f) %c (%.1f %c %.1f) = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 3){// ((o o) o) o
		printf("((%.1f %c %.1f) %c %.1f) %c %.1f = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 4){// o (o o) o
		printf("%.1f %c (%.1f %c %.1f) %c %.1f = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 5){// (o (o o)) o
		printf("(%.1f %c (%.1f %c %.1f)) %c %.1f = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 6){// o ((o o) o)
		printf("%.1f %c ((%.1f %c %.1f) %c %.1f) = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 7){// o o (o o)
		printf("%.1f %c %.1f %c (%.1f %c %.1f) = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 8){// o (o (o o))
		printf("%.1f %c (%.1f %c (%.1f %c %.1f)) = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 9){// (o o o) o
		printf("(%.1f %c %.1f %c %.1f) %c %.1f = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	} else if(n == 10){// o (o o o)
		printf("%.1f %c (%.1f %c %.1f %c %.1f) = %.1f\n",
			a[0], ops[0], a[1], ops[1], a[2], ops[2], a[3], result);
	}
	return;
}
	
double arith(double l, double r, int o){
	double result;
	if(o == 1)
		result = l - r;
	else if(o == 2)
		result = l + r;
	else if(o == 3)
		result = l / r;
	else if(o == 4)
		result = l * r;
	else {
		printf("this is not possible, %i", o);
		exit(1);
	}
	return result;
}

void printArr(int a[], int n)
{
	for(int i = 0; i < n; i++){
		printf("%i", a[i]);
	}
	printf("\n");
	return;
}

