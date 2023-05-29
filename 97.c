#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *marin = (int *) malloc(sizeof(int) * 10);
	int *start = marin;
	while(marin - start < 10)
		*marin++ = 0;
	marin = start;

	*marin = 2;

	int i;

	for(i = 1; i < 7830457; i++){
		while(marin - start < 10){
			*marin = *marin * 2;
			marin++;
		}
		marin = start;
		while(marin - start < 9){
			*(marin + 1)= *(marin + 1) + *marin / 10;
			*marin = *marin % 10;
			marin++;
		}
		*marin = *marin % 10;
		marin = start;
	}
	while(marin - start < 10){
		printf("%i", *marin++);
	}
	printf("\n");
	marin = start;
	while(marin - start < 10){
		*marin = *marin * 28433;
		marin++;
	}
	marin = start;
	while(marin - start < 9){
		*(marin + 1) = *(marin + 1) + *marin / 10;
		*marin = *marin % 10;
		marin++;
	}
	*marin = *marin % 10;
	marin = start;
	*marin += 1;
	while(marin - start < 10){
		printf("%i", *marin++);
	}
	printf("\n");

	return 0;
}
