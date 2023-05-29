#include <stdlib.h>
#include <stdio.h>
#define SIZE 20
int main() {
	int n = 5;
	int p = n;
	int limit;
	int divisor;
	int temp; 
	//while ((p % 1000000) != 0) {
	while (n < SIZE) {
		p = n;
		divisor = 2;
		limit = n / 2;
		while (divisor <= limit) {
			temp = n;
			while (temp > divisor) {
				//printf("\n\t%i is temp, %i is divisor", temp, divisor);
				temp -= divisor;
				p++ ;
			}
			divisor++;
		}
		printf("\n%i has %i partitions.\n", n, p);
		n++;
	}
	
	printf("\n%i is the number\n", (n - 1));

	return 0;
}
