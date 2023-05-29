#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 1818

/* how I solved this problem 
 * used geometry and calculus (first derivative, make it equal to zero),
 * and found an equation for a, b, c.
 * subbed a into the general length equation, and kept reducing it,
 * and found that sqrt(ml^2 + (mw + mh)^2) is an integer.
 */

int main()
{
	int ml, mw, mh;
	double dla, dlb, dlc;
	double a, b, c;
	int count = 0;
	int l;


	for(ml = 1; ml <= M; ml++) {
		for(mw = 1; mw <= ml; mw++) {
			for(mh = 1; mh <= mw; mh++) {
				dla = sqrt((ml * ml) + (mw + mh) * (mw + mh));
				l = (int) dla;
				if((l * l) == ((ml * ml) + (mw + mh) * (mw + mh))) {
					count++;
	//				printf("%i * %i * %i, %i, %f.\n", ml, mw, mh, l, dla);
				}

				/*
				a = (double) (mh * ml) / (double) (mh + mw);
				dla = sqrt(pow(((double) ml - a), 2) + (double) (mw * mw)) + 
					sqrt((a * a) + (double) (mh * mh));

				b = (double) (mw * ml) / (double) (mh + ml);
				dlb = sqrt(pow(((double) mw - b), 2) + (double) (mh * mh)) + 
					sqrt((b * b) + (double) (ml * ml));

				c = (double) (mw * mh) / (double) (ml + mw);
				dlc = sqrt(pow(((double) mh - c), 2) + (double) (ml * ml)) + 
					sqrt((c * c) + (double) (mw * mw));

				if (floor(dla) == dla) {
					count++;
					if(floor(dlb) == dlb && dlb == dla) 
						count++;
					if(floor(dlc) == dlc && dlc == dla) 
						count++;
					
				}
				printf("%i * %i * %i, %f, %f, %f.\n", ml, mw, mh,
					dla, dlb, dlc);
				*/
			}
		}
	}
	printf("%i, M is %i \n", count, M);

	return 0;
}
