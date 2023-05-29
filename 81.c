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

	while((k = fgetc(fp)) != EOF) {
		if (k >= 48){
			//printf("%i", k);
			*p = *p * 10 + (k - '0');
		}
		else
			p++;
	}

	path[DM - 1][DM - 1] = array[DM - 1][DM - 1];
	int it, min;
	for(i = 78; i >= 0; i--) {
		it = i;
		min = INT_MAX;
		for(j = 79; it < DM; j--) {
			//checks right
			if ((j + 1) < DM) 
				min = path[it][j + 1];
			//checks down
			if ((it + 1) < DM) 
				if (min > path[it + 1][j])
					min = path[it + 1][j];
			path[it][j] = array[it][j] + min;
			it++;	
		}
		
	}
/*
	for(i = 0; i < DM; i++) {
		for(j = 0; j < DM; j++) {
			printf("%i ", path[i][j]);
		}
		printf("\n");
	}
*/
	for(j = 78; j >= 0; j--) {
		k = j; // k is temp j
		i = 0;
		while(k >= 0) {
			min = path[i][k + 1];
			if (min > path[i + 1][k])
				min = path[i + 1][k];
		path[i][k] = array[i][k] + min;
		k--;
		i++;
		}
	}
		printf("\n");
		printf("\n");
		printf("\n");
/*
	for(i = 0; i < DM; i++) {
		for(j = 0; j < DM; j++) {
			printf("%i ", path[i][j]);
		}
		printf("\n");
	}

*
	p = findlowest(path);

	printf("Let's see %i, %i, %i \n", *p, (p - &path[0][0]) / DM,
			(p - &path[0][0]) % DM);
	for(i = 0; i < DM; i++) {
		for(j = 0; j < DM; j++) {
			printf("%i ", array[i][j]);
		}
		printf("\n");
	}
	while (path[0][0] == 0) {
		p = findlowest(path);
		i = (p - &path[0][0]) / DM;
		j = (p - &path[0][0]) % DM;
		printf("Let's see %i, %i, %i \n", *p, (p - &path[0][0]) / DM,
				(p - &path[0][0]) % DM);

		//checks left
		if((j - 1) >= 0) {
			//if (path[i][j - 1] == 0) {
				path[i][j - 1] = path[i][j] + array[i][j - 1];
			//}
		}

		//checks up

		if((i - 1) >= 0) {
			//if (path[i - 1][j] == 0) {
				path[i - 1][j] = path[i][j] + array[i - 1][j];
			//}
		}
		
		for(i = 0; i < DM; i++) {
			for(j = 0; j < DM; j++) {
				printf("%i ", path[i][j]);
			}
			printf("\n");
		}
		

	}
	
	*/
	printf("%i is the lowest sum, \n", path[0][0]);

	return 0;
}

int *findlowest(int *n) 
{
	int min = INT_MAX;
	int *mp;
	int i;
	int *p = (n + DM - 1);
//checks vertically
	while((p - n) != 0) {
		for(i = 0; i < DM ; i++) {
			//printf("%i,", *(p + i * DM));
			if (*(p + i * DM) > 0) {
				if (*(p + i * DM) < min) { 
					min = *(p + i * DM);
					mp = (p + i * DM);
				}
				break;
			}
		}
		p--;
	}
//checks horizontally
	while((p - n) < (DM * DM)) {
		for (i = 0; i < DM; i++) {
			if (*(p + i) > 0) {
				if (*(p + i) < min) {
					min = *(p + i);
					mp = (p + i);
				}
				break;
			}
		}
		p += DM;
	}
	
	//printf("%i should be the min.", *mp);

	return mp;
}

