#include <stdio.h>
#include <stdlib.h>
#define RT 20
#define DN 20

void find_paths(int right, int down, long *ppaths);

int main()
{
	int right = 0;
	int down = 0;
	long paths = 0;
	long *ppaths = &paths;

	find_paths(++right, down, ppaths);

	printf("The number of paths are %lu\n", paths);

	return 0;
}

void find_paths(int right, int down, long *ppaths)
{
	if (right == RT) {
		*ppaths = *ppaths + 1;
		printf("Right %i, Down %i, path # %lu\n", right, down, *ppaths);
		return;
	}
	else if (down == DN) {
		*ppaths = *ppaths + 1;
		printf("Right %i, Down %i, path # %lu\n", right, down, *ppaths);
		return;
	}
	
	find_paths( ++right, down, ppaths);
	find_paths( --right, ++down, ppaths);
	
	return;
}
