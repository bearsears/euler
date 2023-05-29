#include <stdio.h>
#include <stdlib.h>
/* i despised solving this problem. 
pain in the ass */
void cardConvert(const char *l, int *n, char *s);
enum handOrder {high = 0, onePair = 1, twoPair = 2, 
	threeKind = 3, straight = 4, flush = 5,
	fullHouse = 6, fourKind = 7, straightFlush = 8,
	royalFlush = 9,
};
int cmpfnc(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}
int cardOrder(const int n[5], int suit);
int determineWinner(const int a[5], const int b[5], const char as[5], 
const char bs[5], const int hand);
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
	int poness, ptwoss; /* same suit */
	int poneh, ptwoh;
	int i;
	int ponew = 0;

	while(fgets(hand, 16, fp) != NULL) {
		//printf("Hand, %s\n", hand);
		cardConvert(hand, ponen, pones);
		if (pones[0] == pones[1] == pones[2] == pones[3] == pones[4]) 
			poness = 1;
		else
			poness = 0;
		qsort(ponen, 5, sizeof(int), cmpfnc);
		poneh = cardOrder(ponen, poness);
		//printf(" %i \n", poneh);

		/* player two */
		fgets(hand, 16, fp);
		//printf("Hand, %s", hand);
		cardConvert(hand, ptwon, ptwos);
		if (ptwos[0] == ptwos[1] == ptwos[2] == ptwos[3] == ptwos[4]) 
			ptwoss = 1;
		else
			ptwoss = 0;
		qsort(ptwon, 5, sizeof(int), cmpfnc);
		ptwoh = cardOrder(ptwon, ptwoss);
		//printf(" %i \n", ptwoh);
		/*
		if(ptwoss == 5 || poness == 5)
			break;
			*/
		if (poneh > ptwoh)
			ponew++;
		else if (poneh == ptwoh)
			ponew = ponew + determineWinner(ponen, ptwon, pones,
			ptwos, poneh);
		//printf("\n");
	}
	printf("Player one wins are %i.\n", ponew);
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
		*s++ = *l;
		l += 2; /* beceause it has to move toward suit 
		and space */
	}
}

int cardOrder(const int n[5], int suit)
{
	if (n[0] == 10 && n[1] == 11 && n[2] == 12 && n[3] == 13 && n[4] == 14
		&& suit == 1)
		return royalFlush;
	else if (n[0] == n[1] - 1 && n[1] == n[2] - 1 && n[2] == n[3] - 1 &&
		n[3] == n[4] - 1 && suit == 1)
		return straightFlush;
	else if (n[0] == n[1] - 1 && n[1] == n[2] - 1 && n[2] == n[3] - 1 &&
		n[4] == 14 && suit == 1)
		return straightFlush;
	else if (n[0] == n[1] && n[1] == n[2] && n[2] == n[3])
		return fourKind;
	else if (n[1] == n[2] && n[2] == n[3] && n[3] == n[4])
		return fourKind;
	else if (n[0] == n[1] && n[2] == n[3] == n[4])
		return fullHouse;
	else if (n[4] == n[3] && n[0] == n[1] == n[2])
		return fullHouse;
	else if (suit == 1)
		return flush;
	else if (n[0] == n[1] - 1 && n[1] == n[2] - 1 &&
		n[2] == n[3] - 1 && n[3] == n[4] - 1)
		return straight;
	else if (n[0] == n[1] - 1 && n[1] == n[2] - 1 &&
		n[2] == n[3] - 1 && n[4] == 14)
		return straight;
	else if (n[0] == n[1] && n[1] == n[2])
		return threeKind;
	else if (n[1] == n[2] && n[2] == n[3])
		return threeKind;
	else if (n[2] == n[3] && n[3] == n[4])
		return threeKind;
	else if (n[0] == n[1] && n[2] == n[3])
		return twoPair;
	else if (n[0] == n[1] && n[3] == n[4])
		return twoPair;
	else if (n[1] == n[2] && n[3] == n[4])
		return twoPair;
	else if (n[0] == n[1] || n[1] == n[2] || 
		n[2] == n[3] || n[3] == n[4])
		return onePair;
	
	return high; 
}

int determineWinner(const int a[5], const int b[5], const char as[5], 
	const char bs[5], const int hand)
{
	int i, j;
	/* for high and straight */
	if (hand == 0 || hand == 4) {
		if (a[4] > b[4])
			return 1;
		else if (a[4] == b[4])
			if (as[4] > bs[4])
				return 1;
	}
	/* for pair */
	if (hand == 1) {
		for (i = 4; i > 1; i--)
			if (a[i] == a[i - 1])
				break;
		for (j = 4; j > 1; j--)
			if (b[j] == b[j - 1])
				break;
		if (a[i] > b[j])
			return 1;
		else if (a[i] == b[j]) {
			if (i == 4)
				i = 2;
			else
				i = 4;
			if (j == 4)
				j = 2;
			else
				j = 4;
			if (a[i] > b[j])
				return 1;
		}
	}
	/* for double pair */
	if (hand == 2) {
		if (a[4] == a[3])
			i = 4;
		else i = 3;
		if (b[4] == b[3])
			j = 4;
		else j = 3;
		if (a[i] > b[j])
			return 1;
		else if (a[i] == b[j]) {
			i -= 2;
			j -= 2;
		}
		if (a[i] > b[j])
			return 1;
		else if (a[i] == b[j]) {
			if (i == 2)
				i == 0;
			else i == 4;
			if (j == 2)
				j == 0;
			else j == 4;
		}
		if (a[i] > b[j])
			return 1;
	}
	/* three of kind */
	if (hand == 3) {
		if (a[4] == a[2])
			i = 4;
		else i = 2;
		if (b[4] == b[2])
			j = 4;
		else j = 2;
		if (a[i] > b[j])
			return 1;
		else if (a[i] == b[j]) {
			if (i == 4)
				i = 1;
			else i = 4;
			if (j == 4)
				j = 1;
			else j = 4;
		}
		if (a[i] > b[j])
			return 1;
	}

	return 0;
}
