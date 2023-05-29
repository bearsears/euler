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
	int *j, *l;
	int size;
	int result = 0;
	
	/* perimeters are even number if all sides are an integer */
	for (i = 10; i <= 150; i += 2) {
		//printf("%i: ", i);
		size = dvs(i, &l);
		j = l;
		result += findLengths(i, j);
	}

	printf("%i is the total.\n", result);

	return 0;
}

int findLengths(int n, int *p) 
{
	int high = n / 4;
	int a, c, b;
	int count = 0;
	int akey = 0;
	int ckey = 0;
	int bkey = 0;
	
	while (*p < high)
		p++;
//	printf("%i, \n", *p);
	
	while (*p > 2) {
		
		a = n / 2 - *p;
		c = n - a - *p;
		
		while (c > a && a != 0) {
			if (((long)c * (long)c) == (((long)a * (long)a) + ((long)*p * (long)*p))) {
				akey = a;
				bkey = *p;
				ckey = c;
				printf("%i: %i, %i, %i \n", n, *p, a, c);
			//	printf("reverse is %i: %i, %i, %i \n", n, (n / *p), (n / a), (n / c));
				count++;
			}
			a++;
			c--;
			
			if (count > 1)
				return 0;
				
		}
		p--;
	}

	p++;
	int key;

	while (*p <= high) {
		key = n / *p;
		//printf("\t %i is the divisor, %i is the key.\n", *p, key);
		while (key < high) {
			a = n / 2 - key;
			c = n - a - key;
			while (c > a && a != 0) {
				if (((long)c * (long)c) == (((long)a * (long)a) + ((long)key * (long)key))) {
					printf("second loop %i: %i, %i, %i \n", n, key, a, c);
					if (akey == 0) {
						akey = a;
						bkey = key;
						ckey = c;
					} else if (akey != a && bkey != key && ckey != c) {
						return 0;
					}
				}
				a++;
				c--;
			}
			key += key;
		}
		p++;
	}
	

	if (count == 1) {
		printf("%i made it,\n", n);
		return 1;
	}
		
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
