#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long n = 2;
	unsigned long t, m;
	int count = 0;

	while(n < 10000000) {
		t = n;
//		printf("%lu, ", n);
		while(t != 1 && t != 89){
	//		printf("%lu, %lu\t", t, n);
			m = 0;
			while(t != 0) {
				m += (t % 10) * (t % 10);
				t /= 10;
			}
	//		printf("%lu, %lu\n", t, m);
			t = m;
		}
		
		if(t == 89)
			count++;
		n++;
	}
	printf("There are %i numbers that end in 89.\n", count);
	return 0;
}
