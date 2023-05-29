#include <stdio.h>
#include <stdlib.h>

int cpfc(void const *a, void const *b) {
	return(*(int *) a - *(int *) b);
}
int main()
{
	int keys[16][12] = {
		{2, 8, 3, 0, 6, -1, 5, 1, 6, 4, -1, -1},
		{2, 8, 3, 0, 9, -1, 5, 1, 6, 4, -1, -1},
		{2, 8, 6, 0, -1, -1, 5, 1, 3, 4, 6, -1},
		{2, 8, 6, 0, -1, -1, 5, 1, 3, 4, 9, -1},
		{2, 8, 3, 0, 6, -1, 5, 1, 9, 4, -1, -1},
		{2, 8, 3, 0, 9, -1, 5, 1, 6, 4, -1, -1},
		{2, 8, 9, 0, -1, -1, 5, 1, 3, 4, 6, -1},
		{2, 8, 9, 0, -1, -1, 5, 1, 3, 4, 9, -1},
		{2, 1, 3, 4, 6, -1, 5, 8, 6, 0, -1, -1},
		{2, 1, 3, 4, 9, -1, 5, 8, 6, 0, -1, -1},
		{2, 1, 6, 4, -1, -1, 5, 8, 3, 0, 6, -1},
		{2, 1, 6, 4, -1, -1, 5, 8, 3, 0, 9, -1},
		{2, 1, 3, 4, 6, -1, 5, 8, 9, 0, -1, -1},
		{2, 1, 3, 4, 9, -1, 5, 8, 9, 0, -1, -1},
		{2, 1, 9, 4, 6, -1, 5, 8, 3, 0, -1, -1},
		{2, 1, 9, 4, 9, -1, 5, 8, 3, 0, -1, -1}
		};

	long *numbers = (long *) malloc(16000 * sizeof(long));
	
	int temp[12];
	int temp2[12];
	int i, j, k, l, m;
	int slotj, slotk, slotl;

	for(i = 0; i < 16; i++) {
		for(j = 0; j < 12; j++) {
			temp[j] = keys[i][j];
		//	printf("%i", temp[j]);
		}
		//printf("\n");
		if(temp[4] == -1) {
			slotj = 4; 
			slotk = 5;
			slotl = 11;
		} else {
			slotj = 5; 
			slotk = 10;
			slotl = 11;
		}
				
		for(j = 0; j < 10; j++) {
			temp[slotj] = j;
			for(k = 0; k < 10; k++) {
				temp[slotk] = k;
				for(l = 0; l < 10; l++) {
					temp[slotl] = l;
					for(m = 0; m < 12; m++)
						temp2[m] = temp[m];
					qsort(temp2, 6, sizeof(int), cpfc);
					qsort((temp2 + 6), 6, sizeof(int), cpfc);
					*numbers = 0;
					/*
					for(m = 0; m < 12; m++)
						printf("%i", temp[m]);
					printf("\n\t");
					*/
					for(m = 0; m < 12; m++) {
						*numbers = 10 * *numbers + (long) temp2[m];
						//printf("%i", temp2[m]);
					}
					//printf("\n");
					numbers++;
				}
			}
					
		}
	}
	
	numbers = numbers - 16000;
	for(i = 0; i < 16000; i++) {
		printf("%lu \t", *numbers++);}
	numbers = numbers - 16000;
	long temp3;
	long *temp4;
	for(i = 0; i < 16000; i++) {
		temp3 = *numbers;
		temp4 = numbers;
		temp4++;
		int end = 16000 - i;
		for(j = 0; j <= end; j++) {
			if(temp3 == *temp4)
				*temp4 = 0;
			temp4++;
		}
		numbers++;
	}

	numbers = numbers - 16000;
	int count = 0;
	for(i = 0; i < 16000; i++) {
		if(*numbers != 0)
			count++;
		printf("%lu \t", *numbers++);
	}
	printf("%i is the distinct.\n", count);

	return 0;
}
