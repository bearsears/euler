#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpstr(const void *a, const void *b) {
	return strcmp(*(char * const *) a, *(char * const *) b);
}

int main() {
	FILE *fp;
	fp = fopen("p022_names.txt", "r");
	fpos_t pos;
	fgetpos(fp, &pos);
	int i = 0; 
	char c = 0;
	int j = 0;
	int max = 0;

	while ((c = fgetc(fp)) != EOF) {
		if (c == 44){
			i++;
			j -= 2;
			if (max < j) 
				max = j;
			j = 0;
		}
		j++;
	}
	i++; //for the last character
	printf("There are %i names, and the longest name has %i characters.\n", i, max);
	
	char *names[i]; 
	for (j = 0; j <= i; j++) {
		names[i] = (char *) malloc(sizeof(char) * (max + 1));
		if (names[i] = NULL) {
			printf("malloc has failed.\n");
			return EXIT_FAILURE;
		}
	}
	printf("Looks like malloc is a success.\n");

	char *tname; // 2 is added for two "
	fsetpos(fp, &pos);
	j = 0;
	int lh = 0;
	while ((c = fgetc(fp)) != EOF){
		if (c == 34) {
			fgetpos(fp, &pos);
			lh = 0;
			while((c = fgetc(fp)) != 34)  {
	//			printf("%c", c);
				lh++;
			}
	//		printf("%i", lh);
//			lh++;
			fsetpos(fp, &pos);

			tname = malloc(sizeof(char) * lh);
	//		printf("\t");
			while((c = fgetc(fp)) != 34) {
				*tname++ = c;
//				printf("%c", *tname++);
			}
//			*tname++ = '\0';
		tname -= lh;
//		printf("--%s  ", tname);
		names[j] = tname;
		j++;
		}
	}
/*
	for (j = 0; j < i; j++)
		printf("%s%i  ", names[j], strlen(names[j]));

	printf("\n\n\n");
*/	
	qsort(names, i, sizeof(char *), cmpstr);
/*
	for (j = 0; j < i; j++)
		printf("%s%i  ", names[j], strlen(names[j]));
*/

	int k = 0;
	unsigned long res = 0;
	unsigned long result = 0;
	for (j = 0; j < i; j++){
		lh = strlen(names[j]);
		tname = names[j];
		for (k = 0; k < lh; k++)
			res += (*tname++ - '@');
		res *= (j + 1);
			result += res;
		
		res = 0;
	}
	printf("%li, \n", result);

	return 0;
}
