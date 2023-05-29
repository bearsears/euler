#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int main() {

	int board[39] = { 0 };
	int chest[2] = {0, 10};
	int chance[6] = {0, 10, 11, 24, 39, 5}; 
	int t = 0;
	int i, dice1, dice2;
	int dbs = 0; //consecutive doubles
	int cc = 0;
	int ch = 0;
	srand(clock());

	for(i = 0; i < INT_MAX; i++) {
		dice1 = rand() % 4 + 1;
		dice2 = rand() % 4 + 1;
		//printf("%i, %i,\t ", dice1, dice2);
		
		if(dice1 == dice2)
			dbs++;
		else
			dbs = 0;
		//checks for 3 consecutive doubles
		if(dbs == 3) {
			t = 10;
			dbs = 0;
		}
		else
			t += (dice1 + dice2);

		if(t > 39) {
			t -= 40;
		}
		// go to jail
		if(t == 30) {
			srand(clock());
			t = 10;
		}
		//comunity chest
		else if(t == 2 || t == 17 || t == 33) {
			if(cc > 15)
				cc -= 16;
			if(cc < 2)
				t = chest[cc];
			cc++;
		}
		//chance cards
		
		else if(t == 7 || t == 22 || t == 36) {
			if(ch > 15)
				ch -= 16;
			if(ch < 6)
				t = chance[ch];
			else if(ch == 6 || ch == 7) {
				if(t == 7)
					t = 15;
				else if(t == 22)
					t = 25;
				else 
					t = 5;
			} else if(ch == 8) {
				if(t == 22)
					t = 28;
				else 
					t = 12;
			} else if(ch == 9)
				t -= 3;
			ch++;
		}
		
		board[t]++;
	}

	for(i = 0; i < 40; i++)
		printf("%i: %i \t", i, board[i]);
	printf("\n");

	return 0;
}
