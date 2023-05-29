#include <stdio.h>
#include <stdlib.h>
#define SZ 1000001
int main()
{
	int *p = (int *) calloc(SZ, sizeof(int));
	*p++ = 0;
	*p++ = 1;
	int i;
	int limit, j, div;
	
	for(i = 2; i < SZ; i++){
		limit = i;
		for(j = 2; j < limit; j++){
			if(i % j == 0){
				*p += j;
				div = i / j;
				if(div != j)
					*p += div;
			}
			limit = i / j;
		}
		*p++ += 1;
	}
	p -= SZ;
	
	/*
	for(i = 0; i < SZ; i++){
		printf("%i, %i\t", i, *p++);
	}
	p -= SZ;
	*/
	
	int *q, *r;
	q = p;
	q++;
	int count = 0;
	int maxanswer, maxcount = 0;
	while(q - p < 332641){
		r = q;
		printf("%i::", (q - p));
		if(*r > SZ){
			q++;
			continue;
		}

		do{
			printf("%i,%i->", (q - p), *r);
			r = p + *r;
			count++;
			//making sure the number is not a prime,
			//making sure the sum of divisors is not 
			//over one million,
			//and stops when the sum of divisors is 
			//amicable
		}while(*r != 1 && *r < (SZ - 1) && 
				*r != (q - p) && *r != (r - p) &&
				(r - p) != *(p + *r) && 
				count < 1000);
		
		printf("%i\n", *r);
		if(*r == (q - p) && count > maxcount){
			maxanswer = q - p;
			maxcount = count;
		}
		q++;
		count = 0;
		
	}
/*
	for(i = 0; i < 101; i++){
		printf("%i, %i\t", i, *p++);
	}
	*/
	printf("\n%i, %i\n", maxanswer, maxcount);

	return 0;
}


