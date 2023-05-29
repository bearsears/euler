#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long a, b, result;

	for(a = 20; a < 1000000000; a++){
		b = a * 70711 / 100000;
		result = a * (a - 1) / (b * (b - 1));
		while(result < 2){
			b--;
			result = a * (a - 1) / (b * (b - 1));
		}
		if((a * (a - 1) % (b * (b - 1))) == 0){
			printf("%lu / %lu * %lu / %lu \n", b, a, (b - 1),
				(a - 1));
			a = a * 5 + a * 828 / 1000;
		}
	}

	return 0;
}
