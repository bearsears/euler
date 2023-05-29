#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define DM 80

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

	for (i = 0; i < DM; i++)
		path[i][DM - 1] = array[i][DM - 1];
	
	int min, it, jt;
	for (j = (DM - 2); j > 0 ; j--) {
		k = 80; //let k designate spaces left
		while(k > 0) {
			//find minimum
			min = INT_MAX;
			for(i = 0; i < DM; i++) {
				if(path[i][j] != 0 && min > path[i][j]) {
					if (i == 0 && path[i + 1][j] == 0) {
						min = path[i][j];
						it = i;
						jt = j;
					} else if(i == (DM - 1) && path[i - 1][j] == 0) {
						min = path[i][j];
						it = i;
						jt = j;
					} else if(i > 0 && i < (DM - 1) && (path[i + 1][j] == 0 || path[i - 1][j] == 0)) {
						min = path[i][j];
						it = i;
						jt = j;
					}
				}else if(path[i][j] == 0 && min > path[i][j + 1]) {
					min = path[i][j + 1];
					it = i;
					jt = j + 1;
				}
			}
		
		//	printf("%i, %i, %i, %i,\n", min, it, jt, path[it - 1][jt]);
			if((jt - j) == 1) {
				path[it][j] = array[it][j] + path[it][jt];
				k--;
				continue;
			} 
			if(it > 0) {
				if(path[it - 1][j] == 0) {
					path[it - 1][j] = array[it - 1][j] +
						path[it][j];
					k--;
				}
			} 
			if(it < (DM - 1)) {
				if(path[it + 1][j] == 0) {
					path[it + 1][j] = array[it + 1][j] +
						path[it][j];
					k--;
				}
			}
			
		}
	}

	for(i = 0; i < DM; i++) {
		path[i][0] = path[i][1] + array[i][0];
	}
/*
	for(i = 0; i < DM; i++) {
		for(j = 0; j < DM; j++) {
			printf("%i ", path[i][j]);
		}
		printf("\n\n");
	}
	*/
	min = INT_MAX;	

	for(i = 0; i < DM; i++) 
		if(min > path[i][0])
			min = path[i][0];
	printf("%i is the minimum\n", min);

	return 0;
}

