#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXR 30
#define MAXC 30
#define NBELLS 50

int main()
{
	int grid[MAXR][MAXC] = { 0 };
	int i, j, row, col, move, bells; 
	long unsigned int empty = 0;
	long unsigned int count = 0;

	/* initialize randomness */
	srand(time(NULL));

	/* print the grid */
	for(i = 0; i < MAXR; i++)
	{
		for(j = 0; j < MAXC; j++)
		{
			printf("%i ", grid[i][j]);
		}
		printf("\n");
	}
		printf("\n");
	
	for(count = 0; count < 10000000; count++)
	{
		printf("%lu\t", count);
		for(i = 0; i < MAXR ; i++)
		{
			for(j = 0; j < MAXC; j++)
			{
				row = i;
				col = j;
				for(bells = 0; bells < NBELLS; bells++)
				{
					move = rand() % 4;
					//printf("%i\t", move);
					if(move == 0) /* move up */
					{
						if(row == 0) /* one the top edge? reverse */
							row++;
						else
							row--;
					}
					else if(move == 1) /* move right */
					{
						if(col == (MAXC - 1)) /* one the right edge? reverse */
							col--;
						else
							col++;
					}
					else if(move == 2) /* move down */
					{
						if(row == (MAXR - 1)) /* one the bottom edge? reverse */
							row--;
						else
							row++;
					}
					else if(move == 3) /* move left */
					{
						if(col == 0) /* one the left edge? reverse */
							col++;
						else
							col--;
					}
				}	
				//printf("Flea is at Row %i, Column %i \n", row, col);
				grid[row][col]++;
			}
		}
		/* print the grid */
		/*
		for(i = 0; i < MAXR; i++)
		{
			for(j = 0; j < MAXC; j++)
			{
				printf("%i ", grid[i][j]);
			}
			printf("\n");
		}
		*/
	
		/* count the zeros in the grid ,
		 * also initialize to zero */
		for(i = 0; i < MAXR; i++)
		{
			for(j = 0; j < MAXC; j++)
			{
				if(grid[i][j] == 0)
					empty++;
				else
					grid[i][j] = 0;
			}
		}
		
		/* initialize the grid */
	}
	
	printf("empty, %lu,", empty);
	
	return 0;
}	
