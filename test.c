#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>

#define LTS 5 /* number of letters */

struct sqn {
	int n;
	int *nsq; /* number squared */
	int *nsqs; /* number squared sorted */
	int match;
	int lgth;
};

void setup(struct sqn *psqn, int nu);

int compfunc(const void * a, const void * b)
{
	return ( *(int *)b - *(int *)a);
}

int main() 
{
	long max = 99999;
	long min = 10000;

	int maxr = (int) sqrt((double) max);
	//int maxr = 10000000;
	int minr = (int) sqrt((double) min);
	//int minr = 3162278;
	printf("maxr %i, minr %i\n", maxr, minr);

	struct sqn *sqnn[maxr - minr + 1];
	int i;
	printf("setting up\n");
	for (i = 0; i <= (maxr - minr); i++) {
		sqnn[i] = (struct sqn *) malloc(sizeof(struct sqn));
		if (sqnn[i] == NULL) {
			printf("memory allocation error.\n");
			exit(0);
		}
		setup(sqnn[i], (minr + i));
	}

	printf("matching up\n");
	int j, k;
	for (i = 0; i <= (maxr - minr); i++) {
		for (j = (maxr - minr); j > i; j--) {
			k = 0;
	//		printf("%i and %i\n", sqnn[i]->n, sqnn[j]->n);

			while (*(sqnn[i]->nsqs + k) == *(sqnn[j]->nsqs + k) && k < sqnn[i]->lgth) {
	//			printf("%i:%i\t ", *(sqnn[i]->nsqs + k), *(sqnn[j]->nsqs + k));
				k++;
			}
	//		printf("%i.%i", k, sqnn[i]->lgth);
	//		printf("\n");
			if (k == sqnn[i]->lgth) 
				sqnn[i]->match = sqnn[j]->n;
		}
	}

	for (i = 0; i < (maxr - minr); i++) {
		if (sqnn[i]->match != 0)
			printf("%i has a match with %i.\n", sqnn[i]->n, sqnn[i]->match);
	}

	//free(sqnn);

	char *letters[300]; 
	for (i = 0; i < 300; i++) {
		letters[i] = (char *) malloc(sizeof(char) * LTS); /*i am looking for five letters */
		if (letters[i] == NULL) {
			printf("memory allocation error.\n");
			exit(0);
		}
	}
	
	printf("long...\n");
/*
	letters[0] = "WHILE";
	for (i = 0; i < 5; i++) {
		printf("%c.", *letters[0]++);
	}
*/

	FILE *fp;
	fp = fopen("98.txt", "r");
	fpos_t position;
	fgetpos(fp, &position);
	int wlgt[2000];
	int *temp = wlgt;
	i = 0;
	j = 0;
	int c;

	while ((c = fgetc(fp)) != EOF) {
		if (c == 44) {
			i -= 2;
			*temp++ = i;
			j++; // j shall be the total numbers
			i = 0; 
		}
		else 
			i++;
	}
	temp = wlgt;
/*
	for (i = 0; i < j; i++) 
		printf("%i,", *temp++);
	
	printf("\n j = %i; i = %i \n", j, i);
*/
	fsetpos(fp, &position);

	char *buf = malloc(sizeof(char) * LTS + 1);
	for (i = 0; i < j; i++) {
		c = fgetc(fp); 
		printf("%c.", c);
		c = fgetc(fp); 
		printf("%c.", c);
		if (*temp == LTS) {
			fgets(buf, LTS, fp);
			printf("%s-", buf);
			letters[i] = buf;
		}
		else {
			fgets(buf, (*temp+1), fp);
			printf("%s+", buf);
		}

		temp++;
		c = fgetc(fp); 
		printf("%c.", c);
	}

	


	                                                                                                                                                            

	return 0;
}

void setup(struct sqn *psqn, int nu)
{
	psqn->n = nu;
	psqn->match = 0;
	long ns = (long) psqn->n * (long) psqn->n;
	//printf("%i\t%i\n", ns, psqn->n); 

	psqn->lgth = 0;
	while (ns != 0) {
		ns /= 10;
		psqn->lgth++;
	}	
	//printf("%i\n", i);

	psqn->nsq = (int *) malloc(sizeof(int) * psqn->lgth);
	psqn->nsqs = (int *) malloc(sizeof(int) * psqn->lgth);
	ns = (long) psqn->n * (long) psqn->n;

	while (ns != 0) {
		*(psqn->nsq) = ns % 10;
		*(psqn->nsqs)++ = *(psqn->nsq)++;
		ns /= 10;
	}
	psqn->nsq -= psqn->lgth;
	psqn->nsqs -= psqn->lgth;

	qsort(psqn->nsqs, psqn->lgth, sizeof(int), compfunc);
	
	int i = 0;

	while (i < psqn->lgth) {
		printf("%i", *(psqn->nsqs + i));
		i++;
	}
	printf("->%i\n", psqn->n);

	
	return;
}
