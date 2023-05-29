#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define DM 80

int *findlowest(int *n);

int main()
{
	int array[DM][DM];
	int path[DM][DM];
	int i, j, k;
	
	for(i = 0; i < DM; i++) {
		for (j = 0; j < DM; j++) {
			array[i][j] = 0;
			path[i][j]= 0;
		}
	}

	FILE *fp;
	fp = fopen("matrix.txt", "r");
	
	if(fp == NULL){
		printf("Unable to read file.\n");
		exit(0);
	}
	

	int *p = array;
	int *start = path;
	int *strt = array;

	while((k = fgetc(fp)) != EOF) {
		if (k >= 48){
			//printf("%i", k);
			*p = *p * 10 + (k - '0');
		}
		else
			p++;
	}

	path[DM - 1][DM - 1] = array[DM - 1][DM - 1];

	//p = findlowest(path);

	//printf("Let's see %i, %i, %i \n", *p, (p - &path[0][0]) / DM,
	//		(p - &path[0][0]) % DM);
/*
	for(i = 0; i < DM; i++) {
		for(j = 0; j < DM; j++) {
			printf("%i ", array[i][j]);
		}
		printf("\n");
	}
	*/

	while (path[0][0] == 0) {
		
		p = findlowest(start);
		//checks left
		//printf("%i???%i^^^\n", *(p - 1), (p - start - 1));
		if(((p - start) - 1) % DM != (DM - 1) && *(p - 1) == 0) 
			*(p - 1) = *(strt + ((p - start) - 1)) + *p;
		//checks right
		if(((p - start) + 1) % DM != 0 && *(p + 1) == 0)
			*(p + 1) = *(strt + ((p - start) + 1)) + *p;
		//checks up
		if(((p - start) - DM) >= 0 && *(p - DM) == 0)
			*(p - DM) = *(strt + ((p - start) - DM)) + *p;
		//checks down
		if(((p - start) + DM) < (DM * DM) && *(p + DM) == 0)
			*(p + DM) = *(strt + ((p - start) + DM)) + *p;
/*
		for(i = 0; i < DM; i++) {
			for(j = 0; j < DM; j++) {
				printf("%i ", path[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/

	}
	
	printf("%i is the lowest sum, \n", path[0][0]);

	return 0;
}

int *findlowest(int *n) 
{
	int *p = n;
	int max = DM * DM;
	int min = INT_MAX;
	int *minp = n + max - 1;
	int full;
	
	while((p - n) < max) {
		full = 0;
		if(*p == 0) {
			p++;
			continue;
		}
		//printf("where? %i, %i\n", (p - n), *p);
		//checks left boundary
		if(((p - n) - 1) % DM == (DM - 1))
			full++;
		else if (*(p - 1) != 0)
			full++;
		//checks right boundary
		if(((p - n) + 1) % DM == 0) 
			full++;
		else if(*(p + 1) != 0)
			full++;
		//printf("where? %i, %i\n", (p - n), *p);
		//checks up boundary
		if(((p - n) - DM) < 0) 
			full++;
		else if(*(p - DM) != 0)
			full++;
		//checks down
		if(((p - n) + DM) > max) 
			full++;
		else if(*(p + DM) != 0)
			full++;
		//printf("\t%i\n", *p);
		if(full < 4 && *p < min) {
		//	printf("%i is the new min\n", *p);
			min = *p;
			minp = p;
		}

		p++;
	}
	
//	printf("pass? %li, %li\n", (minp - n), *minp);

	return minp;
}

