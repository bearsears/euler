#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp; 
	fp = fopen("98.txt", "r");

	int i = 0; 
	int max = 0;
	int fc = 0;
	int c;

	while ((c = fgetc(fp)) != EOF) {
		if (max < i)
			max = i;
		printf("%c, %i", c, i);
		if (c == 34 || c == 44) {
			if (i == 13)
				fc++;
			i = 0;
		}
		else if (c >= 65 || c <= 90) 
			i++;



	}

	int random = 34;
	printf("\n\t %c \t\n", random);

	printf ("The max number is %i, there are %i five letter words.\n", max, fc);

	fclose(fp);
	return 0;	
}
