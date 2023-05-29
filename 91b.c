#include <stdio.h>
#include <stdlib.h>
#define SZ 200
int pythagoras(int *lsq, int a, int b, int l);
int main() 
{
	struct coord {
		int x;
		int y;
	};
	int grid = (SZ + 1) * (SZ + 1);
	struct coord *c = malloc(sizeof(struct coord) * grid);

	int i = 0;
	for(i = 0; i < grid; i++){
		c->x = i % (SZ + 1);
		c->y = i / (SZ + 1);
		c++;
	}
	c = c - grid;
	int *lsq = (int *) malloc(sizeof(int) * grid);
	for(i = 0; i < grid; i++){
		*lsq = c->x * c->x + c->y * c->y;
		//printf("x: %i, y: %i lsq is %i,\n", c->x, c->y, *lsq);
		c++;
		lsq++;
	}

	c -= (grid - 1);
	lsq -= grid;
	struct coord *start = c - 1;
	struct coord *d = c; //it should never start at (0, 0)
	int area;
	int count = 0;
	int tl;
	while((c - start) < grid){
		d = c + 1;
		while((d - start) < grid){
			if((d - c) == 0){
				d++;
				continue;
			}
			//check if d is in left bottom of the quadrant 
			//or right top of the quadrant
			//relative to c;
			if((d->x < c->x) && (d->y < c->y)){
				d++;
				continue;
			} else if((d->x > c->x) && (d->y > c->y)){
				d++;
				continue;
			}
			area = (double)(c->x * d->y - d->x * c->y);
			if(area < 0)
				area *= -1;
			tl = (c->x - d->x) * (c->x - d->x) + 
				(c->y - d->y) * (c->y - d->y);
			if(pythagoras(lsq, (d - start), (c - start), tl) ==
					0){
				d++;
				continue;
			}
			//divide square * 2 / area, since i am not
			//i am not dividing area by 2
			/* this logic below is wrongs.
			if((area != 0) && (SZ * SZ * 2  % area == 0)){
				printf("x: %i, y: %i,\t", c->x, c->y);
				printf("x: %i, y: %i,\n", d->x, d->y);
				printf("%i\n", area);
				count++;
			}
			*/
			count++;
			d++;
		}
		c++;
	}

	printf("%i is the total \n", count);

	return 0;
}

int pythagoras(int *lsq, int a, int b, int l)
{
	//the lengths are all squared for ease of calculation
	int asq, bsq;
	asq = *(lsq + a);
	bsq = *(lsq + b);

	if(asq > bsq && asq > l)
		if(asq == (bsq + l))
			return 1;

	if(bsq > asq && bsq > l)
		if(bsq == (asq + l))
			return 1;

	if(l > bsq && l > asq)
		if(l == (bsq + asq))
			return 1;

	return 0;
}
