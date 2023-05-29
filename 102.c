#include <stdio.h>
#include <stdlib.h>

//not efficient, but it gets the job done.
int origin(double *p, int size);

int main()
{
	FILE *fp;
	fp = fopen("p102_triangles.txt", "r");
	char c;
	double pts[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int neg, i;
	int count = 0;
	int pce = 0;
	while((c = fgetc(fp)) != EOF){
		if(c == '-'){
			neg = -1;
		} else if(c == ','){
			if(neg == -1){
				pts[pce] *= neg;
			}
			neg = 1;
			pce++;
		} else if(c == '\n'){
			if(neg == -1)
				pts[pce] *= neg;
			pts[6] = pts[0];
			pts[7] = pts[1];
			count += origin(&pts[0], (sizeof(pts)/sizeof(pts[0])));
			for(i = 0; i < 6; i++){
				//printf("%f, ", pts[i]);
				pts[i] = 0;
			}
			//printf("\n");
			pce = 0;
			neg = 1;
		} else {
			pts[pce] = pts[pce] * 10 + (c - '0');
		}
	}
	printf("%i is the count,\n", count);

	return 0;
}

int origin(double *p, int size)
{
	// the idea is that, the lines that connect the points
	// will eventually occupy all the quadrants, 
	// otherwis it would not contain the origin
	double slp, itc, left, right, inc, y;
	int qud[4] = {0, 0, 0, 0};
	// ++, +-, -+, --
	int i;
	for(i = 0; i < 3; i++){
		// y = slp * x + itc
		slp = (*(p + 3) - *(p + 1)) / (*(p + 2) - *p);
		itc = *(p + 1) - slp * *p;
		if(*p < *(p + 2)){
			left = *p;
			right = *(p + 2);
		} else {
			left = *(p + 2);
			right = *p;
		}
		for(inc = left; inc < right; inc += 0.1){
			y = slp * inc + itc;
			if(inc > 0 && y > 0)
				qud[0] = 1;
			else if(inc > 0 && y < 0)
				qud[1] = 1;
			else if(inc < 0 && y > 0)
				qud[2] = 1;
			else 
				qud[3] = 1;
		}
		p += 2;
	}
	for(i = 0; i < 4; i++)
		if(qud[i] == 0)
			return 0;

	return 1;
}

