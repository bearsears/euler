#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	struct tm start = {.tm_year = 1} ; /* 1901 - 1900 */
	mktime(&start);
	int counter = 0;

	while (start.tm_year <= 100) { /* 2001 - 1901 */
		if ( start.tm_mday == 1 && start.tm_wday == 0) 
			counter++;
			printf("%s\n", asctime(&start));
		}
		start.tm_mday += 1;
		mktime(&start);
	}
	
	printf("\n%i\n", counter);
	
	return 0;
}
