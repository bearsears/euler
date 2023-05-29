/* gcc -g 61.c -o go */
#include <stdlib.h>
#include <stdio.h>
#define ROW 6
#define COL 4

struct NTH {
	/* row 0 triangle, 1 square, 2 pentagonal, 3 hexagonal, 
	 * 4 hepatgonal, 5 octagonal.
	 * column 0 head, 1 tail, 2 head switch, 3 tail switch.
	 */
	int cyc[ROW][COL];
};
int generate(int n, int order);
void cswitch(int c, int toh, int number, struct NTH *cn);
void cclear(struct NTH *cn);
int check(int n, int or, int row, struct NTH *cn);

int main() 
{
	struct NTH cn[141];
	int i, j, k, l;
	int number;
	int head, tail; 
	int *cyclic = (int *) calloc(ROW, sizeof(int));

	if (cyclic == NULL) {
		printf("memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	/* generate the cyclic numbers */
	for (i = 0 ; i < 141 ; i++) {
		//printf("%i ", i);
		for (j = 0 ; j < ROW ; j++) {
			for (k = 0 ; k < COL ; k++) 
				cn[i].cyc[j][k] = 0;
			number = generate(i, j);
			head = number / 100;
			tail = number % 100;
			if (head >= 10 && head < 100 && tail >= 10 &&
				tail < 100) {
				cn[i].cyc[j][0] = head;
				cn[i].cyc[j][1] = tail;
			} else {
				cn[i].cyc[j][0] = 0;
				cn[i].cyc[j][1] = 0;
			}
			printf("%i%i ", cn[i].cyc[j][0], cn[i].cyc[j][1]);
		}
		printf("\n");
	}
		printf("\n");

	/* this is to delete any numbers that will not match anywhere in the 
	 * numbers 
	*/ 
	for (i = 0; i < 141; i++) {
		for (j = 0 ; j < ROW ; j++) {
			//if (cn[i].cyc[j][0] == 0 || cn[i].cyc[j][1] == 0)
			//	continue;
			if (check(cn[i].cyc[j][0], 1, j, &cn) == 0) {
				cn[i].cyc[j][0] = 0;
				cn[i].cyc[j][1] = 0;
			}
			if (check(cn[i].cyc[j][1], 0, j, &cn) == 0) {
				cn[i].cyc[j][0] = 0;
				cn[i].cyc[j][1] = 0;
			}
			printf("%i%i ", cn[i].cyc[j][0], cn[i].cyc[j][1]);
		}
		printf("\n");
	}

/*
	int result; 
	for (i = 0 ; i < 141 ; i++) {
		for (j = 0 ; j < ROW ; j++) {
			result = check2(cn[i].cyc[j][0], 1, j, j, &cn);
			if (result >= 0)
				result = check2(cn[i].cyc[j][1], 0, j, result, 
				&cn);
				*/


	for (l = 1; l < 141 ; l++) {
		if (cn[l].cyc[0][0] == 0 || cn[l].cyc[0][1] == 0) {
			cclear(&cn);
			continue;
		}

		for (i = 0 ; i < ROW ; i++) {
			*(cyclic + i) = 0;
		//	printf("%i,", *(cyclic + i));
		}
		
		cn[l].cyc[0][2] = 1;
		cn[l].cyc[0][3] = 1;
		printf("%i %i \t", cn[l].cyc[0][0], cn[l].cyc[0][1]);
		printf("%i %i \t", cn[l].cyc[0][2], cn[l].cyc[0][3]);

		for (k = 0 ; k < 2 ; k++) {
			for (i = 0 ; i < 141; i++) {
				for (j = 0 ; j < ROW ; j++) {
					if (cn[i].cyc[j][2] == 1) {
						cswitch(j, 1, cn[i].cyc[j][0], &cn);
			//			cswitch(j, 0, cn[i].cyc[j][1], &cn);
				//		printf("%i%i ", cn[i].cyc[j][0],
				//		cn[i].cyc[j][1]);
				//		printf("%i%i \n", cn[i].cyc[j][2],
				//		cn[i].cyc[j][3]);
					}
					if (cn[i].cyc[j][3] == 1) {
						cswitch(j, 0, cn[i].cyc[j][1], &cn);
				//		cswitch(j, 1, cn[i].cyc[j][0], &cn);
					//		printf("%i%i ", cn[i].cyc[j][0],
				//		cn[i].cyc[j][1]);
				//		printf("%i%i \n", cn[i].cyc[j][2],
				//		cn[i].cyc[j][3]);
					}
				}
			}
		}

		for (k = 0 ; k < 2 ; k++) {
		for (i = 0 ; i < 141; i++) {
			for (j = 0 ; j < ROW ; j++) {
				if (cn[i].cyc[j][2] == 1) {
			//		cswitch(j, 1, cn[i].cyc[j][0], &cn);
					cswitch(j, 0, cn[i].cyc[j][1], &cn);
			//		printf("%i%i ", cn[i].cyc[j][0],
			//		cn[i].cyc[j][1]);
			//		printf("%i%i \n", cn[i].cyc[j][2],
			//		cn[i].cyc[j][3]);
				}
				if (cn[i].cyc[j][3] == 1) {
			//		cswitch(j, 0, cn[i].cyc[j][1], &cn);
					cswitch(j, 1, cn[i].cyc[j][0], &cn);
				//	printf("%i%i ", cn[i].cyc[j][0],
				//	cn[i].cyc[j][1]);
				//	printf("%i%i \n", cn[i].cyc[j][2],
				//	cn[i].cyc[j][3]);
				}
			}
		}
		}

		number = 0;
		for (i = 0 ; i < 141; i++) {
			for (j = 0 ; j < ROW ; j++) {
				if (cn[i].cyc[j][2] == 1 && cn[i].cyc[j][3] == 1) {
					*(cyclic + j) = 1;
				}
			}
		}

		for (j = 0 ; j < ROW ; j++) {
			//printf("%i,", *(cyclic + j));
			number += *(cyclic + j);
		}
		
		printf("%i\t", number);
		
	//	if (number == ROW) {
			for (i = 0 ; i < 141 ; i++) {
				for (j = 0 ; j < ROW ; j++) {
					if (cn[i].cyc[j][2] == 1 && cn[i].cyc[j][3] == 1) {
						printf("%i:%i%i \t", j, cn[i].cyc[j][0],
						cn[i].cyc[j][1]);
					}
				}
			}
	//	}

		printf("\n");
		cclear(&cn);
	}

	return 0;
}

int check(int n, int or, int row, struct NTH *cn) 
{
	int i, j;
	for (i = 0 ; i < 141 ; i++) {
		for (j = 0 ; j < ROW ; j++) {
			if (j == row)
				continue;
			if (cn->cyc[j][or] == n)
				return 1;
		}
		cn++;
	}
	/* if it got to here, there were no match */
	return 0;
}

void cswitch(int c, int toh, int number, struct NTH *cn) 
{
	int i, j;
	for (i = 0 ; i < 141; i++) {
		for (j = 1 ; j < ROW ; j++) {
			if (c == j)
				continue;
			if (cn->cyc[j][toh] == number) {
				cn->cyc[j][(toh + 2)] = 1;
				/*
				printf("%i is toh ", toh);
				printf("n: %i ", i);
				printf("Cyclic: %i ", (j + 3));
				printf("%i ", number);
				printf("%i", cn->cyc[j][0]);
				printf("%i", cn->cyc[j][1]);
				printf("%i", cn->cyc[j][2]);
				printf("%i\n", cn->cyc[j][3]);
				*/
			}
		}
		cn++;
	}
}

int generate(int n, int order) 
{
	switch(order) {
		case 0 : /* triangular */
			return ((n * (n + 1)) / 2);
		case 1 : /* square */
			return (n * n);
		case 2 : /* pentagonal */
			return ((n * (3 * n - 1)) / 2);
		case 3 : /* hexagonal */
			return (n * (2 * n - 1));
		case 4 : /* heptagonal */
			return ((n * (5 * n - 3)) / 2);
		case 5 : /* octagonal */
			return (n * (3 * n - 2));
		default :
			printf("Invalid number.\n");
			return 0;
	}

	return 0;
}

void cclear(struct NTH *cn) 
{
	int i, j;
	for (i = 0 ; i < 141; i++) {
		for (j = 0 ; j < ROW ; j++) {
				cn->cyc[j][2] = 0;
				cn->cyc[j][3] = 0;
		}
		cn++;
	}
}

