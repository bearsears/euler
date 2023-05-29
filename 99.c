#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE *fp;
	fp = fopen("base_exp.txt", "r");
	if(fp == NULL)
		exit(0);
	double x = 0;
	double y = 0;; // where x ^ y
	double result = 0;
	int i = 1;
	char c = '.';

	while((c = fgetc(fp)) != EOF){
		while(c != ','){
			x = 10 * x + (double) (c - '0');
			c = fgetc(fp);
		}
		c = fgetc(fp);
		while(c != '\n'){
			y = 10 * y + (double)(c - '0');
			c = fgetc(fp);
		}
		result = y * log10(x);
		if(result > 3005315)
			printf("%i: %.1f, %.1f, = %.1f\t\t", i, x, y, result);

		x = 0;
		i++;
		y = 0;
	}
	return 0;
}
		 
		
		
