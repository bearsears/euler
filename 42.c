#include <stdio.h>
#include <stdlib.h>

int cpfc(const void *a, const void *b) {
	return (*(int *) a - *(int *) b);
}

int main() 
{
	int t[35];
	int i;

	for (i = 1; i <= 35; i++) 
		t[i - 1] = i * (i + 1) / 2;

	FILE *fp;
	fp = fopen("p042_words.txt", "r");
	if (fp == NULL) {
		printf("File open failed.\n");
		exit(EXIT_FAILURE);
	}

	char c = fgetc(fp); 
	int result = 0;
	int tw = 0; /* triangle words */

	while (c != EOF) {
		while (c != '"' && c != ',') {
			result += c - '@';
			c = fgetc(fp);
		}
		if (result > 0) {
			if (bsearch(&result, t, 35, sizeof(int), cpfc) != NULL) {
				tw++;
			}
		}
		result = 0;
		c = fgetc(fp);
	}

	printf("%i in total, \n", tw);

	fclose(fp);

	return 0;
}
