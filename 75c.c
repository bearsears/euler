#include <stdio.h>
#include <stdlib.h>
#define PM 1500000

/*gcc -g 75c.c -o go */
/* primitive pythagorean triplets */

void primitive(int a, int b, int c, int *p);
void fill(int a, int b, int c, int *p);

int main() 
{
	int *p = (int *) calloc((1 + PM), sizeof(int));

	primitive(3, 4, 5, p);

	int i;
	int count = 0;
	for (i = 0; i <= PM; i++) {
		if (*p++ == 1)
			count++;
	//	printf("%i: %i\t",i, *p++);
	}

	printf("\nThe total count is %i\n", count);

	return 0;
}

void primitive(int a, int b, int c, int *p)
{
	if ((a + b + c) >= PM)
		return;
	fill(a, b, c, p);

	//printf("(%i,%i,%i):::", a, b, c);


	int aa, bb, cc;

	aa = 1 * a - 2 * b + 2 * c;
	bb = 2 * a - 1 * b + 2 * c;
	cc = 2 * a - 2 * b + 3 * c;
	primitive(aa, bb, cc, p);

	aa = 1 * a + 2 * b + 2 * c;
	bb = 2 * a + 1 * b + 2 * c;
	cc = 2 * a + 2 * b + 3 * c;
	primitive(aa, bb, cc, p);

	aa = (-1) * a + 2 * b + 2 * c;
	bb = (-2) * a + 1 * b + 2 * c;
	cc = (-2) * a + 2 * b + 3 * c;
	primitive(aa, bb, cc, p);

	/* safeguard */

	return;
}

void fill(int a, int b, int c, int *p)
{
	int perimeter = a + b + c;
	int aa = a;
	int bb = b;
	int cc = c;
	while (perimeter <= PM) {
		//printf("%i, %i, %i, %i\t", aa, bb, cc, perimeter);
		*(p + perimeter) += 1;
		aa += a;
		bb += b;
		cc += c;
		perimeter = aa + bb + cc;
	}

	return;
}

