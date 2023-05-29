#include <stdio.h>
#include <stdlib.h>
#define DW 21
#define RT 21

int main()
{
	unsigned long grid [DW][RT] ;
	int i, j;

	for (i = 0; i < DW ; i++)
	{
		for (j = 0; j < RT; j++)
			grid[i][j] = 1;
	}

	for (i = 1; i < DW ; i++)
	{
		for (j = 1; j < RT; j++)
			grid[i][j] = grid[i - 1][j] + grid [i][j - 1];
	}

	for (i = 0; i < DW ; i++)
	{
		for (j = 0; j < RT; j++)
			printf("%lu\t", grid[i][j]);
		printf("\n");
	}

	printf("\nThe answer should be %lu\n", grid[DW-1][RT-1]);

	return 0;
}


