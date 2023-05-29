#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b) {
	return (*(int *) a - *(int *) b);
}

int dvs(int n, int **p);

int findLengths(int n, int *p);

int main()
{
	int i;
	int *j;
	int *l;
	int size;
	int result = 0;
	
	/* perimeters are even number if all sides are an integer */
	for (i = 10; i <= 150; i += 2) {
//		printf("%i: ", i);
		size = dvs(i, &l);
		j = l;
/*
		while ((j - l) < size) {
			printf("%i, ", *j++);
		}
		printf(" size is %i\n", size);
		if (size == 2)
			continue;
			*/

		result += findLengths(i, j);

	}

	printf("%i is the total.\n", result);

	return 0;
}

int dvs(int n, int **p)
{
	int limit = n;
	int sz = 2;
	int pos = 2;
	int rm;

	*p = malloc(2 * sizeof(int));
	if (p == NULL) {
		printf("Memory allocation failure.\n");
		exit(EXIT_FAILURE);
	}
	**p = 1;
	*(*p + 1) = n;

	while (pos < limit) {
		rm = n % pos;
		if (rm == 0) {
			sz += 2;
			*p = realloc(*p, sz * sizeof(int));
			if (p == NULL) {
				printf("Memory allocation failure.\n");
				exit(EXIT_FAILURE);
			}
			*(*p + (sz - 2)) = pos;
			*(*p + (sz - 1)) = n / pos;
		}
		limit = n / pos;
		pos++;
	}

	qsort(*p, sz, sizeof(int), cmpfunc);

	return sz;
}

int findLengths(int n, int *p) 
{
	int high = n / 4;
	int a, c;
	int count = 0;
	int b;
/*	
	if (n % 4 == 0 && n % 3 == 0 && ((long)n * 5) % 12 == 0) {
		a = n / 4;
		b = n / 3;
		c = (n * 5) % 12;
		if ((((long)c * (long)c) == ((long)a * (long)a) + ((long)b * (long)b)) ) {
			count++;
		}
	}
	*/

	while (*p < high)
		p++;
	//p--;
	b = *p;
//	printf("%i, \n", *p);
	
	while (b > 2) {
	//while (*p > 2) {
		
		/*
		if (*p == *(p - 1)) {
			printf("%i is squared.\t", n);	
			p--;
			continue;
		}
		*/
		
			
	//	a = *p + 1;
	//	c = n - a - *p;
	//	a = n / 2 - *p - 1;
	//	c = n - a - *p;
		a = n / 2 - b;
		c = n - a - b;	
		
		while (c > a && a > b) {
			if ((((long)c * (long)c) == ((long)a * (long)a) + ((long)b * (long)b)) ) {
	//		if ((((long)c * (long)c) == ((long)a * (long)a) + ((long)*p * (long)*p)) ) {
				printf("%i: %i, %i, %i \n", n, b, a, c);
			//	printf("reverse is %i: %i, %i, %i \n", n, (n / *p), (n / a), (n / c));
				count++;
			}
			a++;
			c--;
		/*	
			if (count > 1)
				return 0;
				*/
				
				
		}
		//p--;
		b--;
	}

	if (count == 1)
		return 1;
		

	return 0;
}
