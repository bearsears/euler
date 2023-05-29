#include <stdio.h>
#include <stdlib.h>
#define SZ 330000

void pandigital(int const *p, int size, int order);
int main()
{
	int a[SZ/4], b[SZ/4], c[SZ/4];
	int *pa, *pb, *pc;
	int i, temp, count;
	temp = SZ / 4;
	for(i = 0; i < temp; i++){
		a[i] = -1;
		b[i] = -1;
		c[i] = -1;
	}

	a[0] = 0;
	b[0] = 1;
	c[0] = 1;

	for(i = 3; i < SZ; i++){
		pa = &a[0];
		pb = &b[0];
		pc = &c[0];
		temp = 0;
		while(*pc != -1){
			temp = *pb++ + *pc++ + temp;
			*pa++ = temp % 10;
			temp /= 10;
		}
		while(*pb != -1){
			temp = *pb++ + temp;
			*pa++ = temp % 10;
			temp /= 10;
		} 
		while(temp != 0){
			*pa++ = temp % 10;
			temp /= 10;
		}
		pa = &a[0];
		pb = &b[0];
		pc = &c[0];
		count = 0;
		while(*pa != -1){
			*pc++ = *pb;
			*pb++ = *pa++;
			count++;
		}

		if(count > 30)
			pandigital(&a[0], count, i);
			
		//printf("%ith-> %i\n", i, count);
	}
	
	/*
	pa = &a[0];
	while(*pa != -1)
		printf("%i", *pa++);
	printf("\t%i\n", count);
*/
	return 0; 
}

void pandigital(int const *p, int size, int order)
{
	/*
	if(size != 113)
		return;
		*/
	int digits[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = 0;
	
	for(i = 1; i < 10; i++){
		digits[*p] = 0;
		p++;
	}
	for(i = 1; i < 10; i++){
		if(digits[i] != 0)
			return;
		//printf("%i, ", digits[i]);
	}
	p -= 9;
	p = p + size - 9;

	for(i = 0; i < 10; i++)
		digits[i] = i;
	for(i = 1; i < 10; i++){
		digits[*p] = 0;
		p++;
	}
	for(i = 1; i < 10; i++){
		if(digits[i] != 0)
			return;
		//printf("%i, ", digits[i]);
	}
	   printf("\n");
	//p -= 9;
	p -= size;
	while(*p != -1)
		printf("%i", *p++);
	printf("\t%i, %ith\n", size, order);
}
