#include <stdio.h>
#include <stdlib.h>

void cardConvert(const char *l, int *n, char *s);

int main()
{
	FILE *fp;
	fp = fopen("p054_poker.txt", "r");
	int c = 1;
	char hand[15];
	int ponen[5];
	char pones[5];
	int ptwon[5];
	char ptwos[5];
	int i;

	while(fgets(hand, 16, fp) != NULL) {
		printf("Hand, %s", hand);
		cardConvert(&hand, &ponen, &pones);
		printf("Player one hands are: ");
		for (i = 0; i < 5; i++) {
			printf("%i ", ponen[i]);
		}
		printf("\n");
		printf("Player suits, ");
		printf("%s ", pones);
		printf("\n");
	}

	return 0;
}
		
void cardConvert(const char *l, int *n, char *s)
{
	int i;
	for (i = 0; i < 5; i++) {
		if (*l == 'A')
			*n = 14;
		else if (*l == 'T')
			*n = 10;
		else if (*l == 'J')
			*n = 11;
		else if (*l == 'Q')
			*n = 12;
		else if (*l == 'K')
			*n = 13;
		else
			*n = *l - '0';
		n++;
		l++;
		*s = *l;
		l += 2; /* beceause it has to move toward suit 
		and space */
	}
}
