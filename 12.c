#include <stdio.h>
#include <stdlib.h>

int total_divs(long tn, int dvs);

int main()
{
	unsigned long tn = 0; /* trianglular number */;
	unsigned long nn = 1;
	int divisors;

	while (divisors <= 1000)
	{
		tn += nn++;
		divisors = 2;
		divisors = total_divs(tn, divisors);
		printf("triangle number:%lu\t", tn);
		printf("natural number:%lu\t", (nn - 1));
		printf("divisors:%i\n", divisors);
	}

	return 0;
}

int total_divs(long tn, int dvs)
{
	unsigned long limit = tn / 2;
	unsigned long div = 2;

	while (div < limit)
	{
		if ((tn % div) == 0)
		{
			dvs += 2;
			limit = tn / div;
		}

		div++;
	}

	return dvs;
}
