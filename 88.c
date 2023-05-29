/* gcc -g 88.c -o go */
#include <stdio.h>
#include <stdlib.h>
#define SZ 24002

/*the key for this code has been to have two arrays, where one is 
 *string of array of divisors, the next accumulator of length of divisors.
 *ie 2, 3, 2, 2, 5, 2, 3.... and 0, 0, 1, 2, 4, 5, 7, etc.
 *then use pointers to an start of each array, and slice and dice the section
 *of array you need, then use recursion to remove redundant cases and focus on the 
 *absolute necessary cases.
 *0.1 sec execution time.
 */

void find_div(int *div, int *s, int n);
void find_innerdiv(int *d, int *s, int a, int b, int prev, int rec, int *kn, int fn);

int main() 
{
	int i;
	int *d = (int *) malloc(sizeof(int) * SZ * 15);
	int size[SZ];
	size[0] = 0;
	size[1] = 0;
	int kn[SZ];
	kn[0] = 0;
	kn[1] = 0;
	for(i = 2; i < SZ; i++) {
		find_div(d, &size[i], i);
		d = d + size[i];
		size[i] = size[i] + size[i - 1];
		kn[i] = SZ;
	}
	d = d - size[i - 1];
	int end = size[i - 1];
	/*
	for(i = 0; i < end; i++)
		printf("%i, ", *d++);
	printf("\n%i\n", end);
	for(i = 0; i < SZ; i++) {
		printf("%i, ", size[i]);
	}
	*/
	int l; //length
	int j;
	int start;
	int k;

	for(i = 4; i < SZ; i++) {
		l = size[i] - size[i - 1];
		if(l == 1)
			continue;
		start = size[i - 1];
		for(j = 0; j < l; j += 2) {
			k = i - *(d + start + j) - *(d + start + j + 1) + 2;
			if(kn[k] > i)
				kn[k] = i;
	//		printf("%i: %i, %i: k is %i\n", i, *(d + start + j),
	//			*(d + start + j + 1), k);
			find_innerdiv(d, &size, *(d + start + j),
					*(d + start + j + 1), i, 0, 
					&kn, i);
		}
	}

	end = SZ / 2;
	//for(i = 0; i < end; i++)
	//	printf("k: %i, n: %i\n", i, kn[i]);
	int answer[SZ];
	for(i = 0; i < SZ; i++)
		answer[i] = 0;
	int index;
	for(i = 0; i < end; i++){
		index = kn[i];
		if(answer[index] == 0)
			answer[index] = kn[i];
	}
	int sum = 0;
	for(i = 0; i < SZ; i++){
	//	printf("%i\n", answer[i]);
		sum += answer[i];
	}
	printf("%i is the sum.\n", sum);

	return 0;
}
	
void find_innerdiv(int *d, int *s, int a, int b, int prev, int rec, int *kn, int fn)
{
	//d is the pointer for all the divisors,
	//s is the pointer for start of the size array,
	//a is the number on the left, b is number on the right.
	//prev is the number that divisors adds up to.
	//rec is the number that keeps track of recursion loops
	//kn is the pointer for the array that holds number for each k,
	//fn is the very first number.
	//we can just expand the terms on the right, as it
	//covers most cases and expanding the left creates
	//just redundant cases.
	int la, lb, sa, sb, i, k;
	la = *(s + a) - *(s + a - 1);
	lb = *(s + b) - *(s + b - 1);
	sa = *(s + a - 1);
	sb = *(s + b - 1);
	rec++;
	/*
	if(la > 1) {
		for(i = 0; i < la; i += 2) {
			printf("\t%i: %i, %i, :%i\n", a, *(d + sa + i),
				*(d + sa + i + 1), (prev - b));
			find_innerdiv(d, s, *(d + sa + i),
					*(d + sa + i + 1), (prev - b));
		}
	}
	*/
	
	if(lb > 1) {
		for(i = 0; i < lb; i += 2) {
			k = prev - a - *(d + sb + i) - *(d + sb + i + 1) + 2 + rec;
			if(*(kn + k) > fn)
				*(kn + k) = fn;
	//		printf("\t\t%i: %i, %i, :%i, k is %i\n", b, *(d + sb + i),
	//			*(d + sb + i + 1), (prev - a), k);
			find_innerdiv(d, s, *(d + sb + i),
					*(d + sb + i + 1), (prev - a), rec,
					kn, fn);
		}
	}
	
	return;
}

void find_div(int *div, int *s, int n)
{
	int limit = n;
	int d = 2;
	int count = 0;
	
	while(limit > d) {
		if(n % d == 0) {
			count += 2;
			*div++ = d;
			*div++ = n / d;
		}
		limit = n / d;
		d++;
	}

	if(count == 0){//meaning it is a prime number
		*div++ = n;
		count++;
	}
	
	*s = count;

	return;
}

		

