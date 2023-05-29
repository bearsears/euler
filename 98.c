#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 1786 // 1786 is the total numbers of words

int cmpfc(const void *a, const void *b){
	return (*(char *) a - *(char *) b);
}

int main()
{
	FILE *fp;
	fp = fopen("98.txt", "r");
	/*
	if(fp == NULL)
		exit(0);
		*/
	char *words[SZ];
	char *sorted[SZ];
	int size[SZ];
	int i;
	int j = 0;
	int k;
	int count;
	long int position = 1;

	while((i = fgetc(fp)) != EOF){
		position++;
		if(i == 44 || i == 34 || i == 10){
			continue;
		}
		count = 1; //starts at one for that \0 at the end
		while(i != 34 && i != EOF){
			count++;
	//		printf("%c", i);
			i = fgetc(fp);
		}
		words[j] = (int *) malloc(sizeof(int) * count);
		sorted[j] = (int *) malloc(sizeof(int) * count);
		size[j] = --count;

	//	printf(", ");
		fseek(fp, position, SEEK_SET);
		i = fgetc(fp);
		k = 0;
		while(i != 44 && i != 34 && i != EOF){
	//		printf("%c", i);
			*(words[j] + k) = i;
			*(sorted[j] + k) = i;
			i = fgetc(fp);
			position++;
			k++;
		}
		*(words[j] + k) = '\0';
		*(sorted[j] + k) = '\0';
	//	printf("\t");
		j++;
	}
	fclose(fp);
	printf("\n");
		
	for(i = 0; i < SZ; i++){
		//printf("%i:%s:%i:%s\t", i, words[i], size[i], sorted[i]);
		qsort(sorted[i], size[i], sizeof(char), cmpfc);
		//printf(" %i:%s\t", i, sorted[i]);
	}
	count = 0;
	
	for(i = 0; i < (SZ - 1); i++){
		if(size[i] != 5)
			continue;
		for(j = i + 1; j < SZ; j++){
			if(strcmp(sorted[i], sorted[j]) == 0){
				count++;
				printf("%i, %s and %i, %s.\n",
						i, words[i], j, words[j]);
			}
		}
	}

	printf("there are %i words greater than 4 letters.\n", count);

	return 0;
}
