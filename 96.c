#include <stdio.h>
#include <stdlib.h>

/* learning some important lessons here. if you want to pass a array 
   that was created in the function to the main, make it a static int.
   sudoku 49, trial and error, required two keys. first key is in 21st 
   slot, 7.
   direct deduction: count the number horizontally, vertically, and fill 
   in the square with missing number.
   indirect deduction: extend the number shield hz and vt, and fill in
   the missing slot from other squares if there are no options for other
   numbers to exist.
   find the "key": for each slot that has potential candidate of numbers
   there is a key, which will solve the whole sudoku. insert key and use 
   two deductions.
   this method works for 49 out of 50.. 49th sudoku could not be solved 
   this way. this one needed two keys.

  */
void guessandfill(int *p);
int *findnumbers(int *p, int *q);
int crossandsquare(int *p);
int onetonine(int *p);
int checksquare(int *p, int n);
void unminus(int *p);
void printsudoku(int *p);

int main()
{
	FILE *fp;
	fp = fopen("p096_sudoku.txt", "r");

	int *n = (int *) malloc(sizeof(int) * 81);

	//if the character is an alphabet, loop until 
	//newline
	int i;
	int total = 0;
	for(i = 0; i < 50; i++){
		if(fgetc(fp) > 57)
			while(fgetc(fp) != 10);

		int *start = n;
		while(n - start < 81){
			*n = fgetc(fp) - 48;
			if(*n >= 0)
				n++;
		}
		fgetc(fp);
		n -= 81;
	//	printf("sudoku #%i\n", i + 1);	
	//	printsudoku(n);
		while(onetonine(n) == 1);
		while(crossandsquare(n) == 1);
		while(onetonine(n) == 1);
		while(crossandsquare(n) == 1);
		guessandfill(n);
	//	printf("end is \n");
	//	printsudoku(n);
		total += (*n * 100+ *(n + 1) * 10 + *(n + 2));
		
	}
	printf("the total is %i\n", total);
	/*
	int *empty = findnumbers(n, (n + 5));
	int i;
	printf("\nshould work\n");
	if(empty != NULL) {
		for(i = 0; i < 10; i++) {
			printf("%i\t", *empty++);
		}
	}
	*/



	return 0;
}

void guessandfill(int *p)
{
	int *q = p;
	int *temp = (int *) malloc(sizeof(int) * 81);
	while ((q - p) < 81) {
		*temp++ = *q++;
	}
	temp -= 81;
	q = temp;

	int *keys;
	int i, j, count;

	while(q - temp < 81){
		if(*q != 0){
			q++;
			continue;
		}
		keys = findnumbers(temp, q);
		if(keys == NULL){
			q++;
			continue;
		}
		
		for(i = 0; i < 10; i++){
			if(*(keys + i) == 0)
				continue;
			count = 0;
			*q = *(keys + i);
			//printf("Putting %i now\n", *(keys + i));
			while(onetonine(temp) == 1);
			while(crossandsquare(temp) == 1);
			for(j = 0; j < 81; j++){
				if(*(temp + j) == 0)
					break;
				count += *(temp + j);
			}
			
			if(j == 81 && count == 405){
				for(j = 0; j < 81; j++)
					*(p + j) = *(temp + j);
	//			printf("slot %i, key %i\n", (q - temp),
	//					*(keys + i));
				return;
			}
			
			for(j = 0; j < 81; j++)
				*(temp + j) = *(p + j);
		}

		for(j = 0; j < 81; j++)
			*(temp + j) = *(p + j);
		*q++;
	}
	return;
}

int *findnumbers(int *p, int *q)
{
	int distance, cut, i;
	static int n[10];
	int grid = 0;
	int found = 0;
	int count = 0;
	int topleft[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
	int insq[9] = {0, 1, 2, 9, 10, 11, 18, 19, 20};

	grid = 0;
	count = 0;
	for(i = 0; i < 10; i++)
		n[i] = i;
	if(*q == 0){
		//printf("where stuck\n");
		distance = q - p - 9;
		//going up
		while(distance >= 0){
			n[*(p + distance)] = 0;
			distance -= 9;
		}

		distance = q - p + 9;
		//going down
		while(distance < 81){
			n[*(p + distance)] = 0;
			distance += 9;
		}

		distance = q - p;
		cut = distance / 9;
		distance--;
		//going left
		while(distance / 9 == cut && distance >= 0){
			n[*(p + distance)] = 0;
			distance--; 
		}

		distance = q - p;
		cut = distance / 9;
		distance++;
		//going right
		while(distance / 9 == cut && distance < 81){
			n[*(p + distance)] = 0;
			distance++; 
		}

		//find which grid it is
		grid = (q - p) / 27 * 3;
		grid = grid + ((q - p) % 9) / 3;
		//printf("slot %li-> grid %i :: ", (q - p), grid);
		for(i = 0; i < 9; i++){
			n[*(p + topleft[grid] + insq[i])] = 0;
		}
	
		//is there just one number left?
		//then fill up that slot with a number;
		for(i = 0; i < 10; i++){
			if(n[i] != 0)
				count++;
		}
		if(count > 1){
			/*
			printf("slot %li has ", (q - p));
			for(i = 0; i < 10; i++){
				if(n[i] != 0)
					printf("%i, ", n[i]);
			}
			printf("left\t");
			*/
			return n;
		}
	}
	return NULL;
}

int crossandsquare(int *p)
{
	int *q = p;
	int distance, cut, n[10], i;
	int grid = 0;
	int found = 0;
	int count = 0;
	int topleft[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
	int insq[9] = {0, 1, 2, 9, 10, 11, 18, 19, 20};


	while(q - p < 81){
		grid = 0;
		count = 0;
		for(i = 0; i < 10; i++)
			n[i] = i;
		if(*q == 0){
			//printf("where stuck\n");
			distance = q - p - 9;
			//going up
			while(distance >= 0){
				n[*(p + distance)] = 0;
				distance -= 9;
			}

			distance = q - p + 9;
			//going down
			while(distance < 81){
				n[*(p + distance)] = 0;
				distance += 9;
			}

			distance = q - p;
			cut = distance / 9;
			distance--;
			//going left
			while(distance / 9 == cut && distance >= 0){
				n[*(p + distance)] = 0;
				distance--; 
			}

			distance = q - p;
			cut = distance / 9;
			distance++;
			//going right
			while(distance / 9 == cut && distance < 81){
				n[*(p + distance)] = 0;
				distance++; 
			}

			//find which grid it is
			grid = (q - p) / 27 * 3;
			grid = grid + ((q - p) % 9) / 3;
			//printf("slot %li-> grid %i :: ", (q - p), grid);
			for(i = 0; i < 9; i++){
				n[*(p + topleft[grid] + insq[i])] = 0;
			}
		
			//is there just one number left?
			//then fill up that slot with a number;
			for(i = 0; i < 10; i++){
				if(n[i] != 0)
					count++;
			}
			if(count == 1){
				for(i = 0; i < 10; i++){
					if(n[i] != 0){
						*q = n[i];
						found = 1;
						break;
					}
				}
			} else {
		//		printf("slot %li has ", (q - p));
		//		for(i = 0; i < 10; i++){
		//			if(n[i] != 0)
		//				printf("%i, ", n[i]);
		//		}
		//		printf("left\t");
		//		keyandfill(p, &n, (q - p));
			}
		}
		q++;
	}
//	printf("crossandsquare\n");
//	printsudoku(p);
	return found;
}

int onetonine(int *p)
{
	int *q = p;
	int i;
	int distance, cut;
	int found = 0;
	for(i = 1; i < 10; i++){
		q = p;
		while(q - p < 81){
			if(*q == i){
				distance = q - p - 9;
				//going up
				while(distance >= 0){
					if(*(p + distance) == 0)
						*(p + distance) = -1 * i;
					distance -= 9;
				}

				distance = q - p + 9;
				//going down
				while(distance < 81){
					if(*(p + distance) == 0)
						*(p + distance) = -1 * i;
					distance += 9;
				}

				distance = q - p;
				cut = distance / 9;
				distance--;
				//going left
				while(distance / 9 == cut && distance >= 0){
					if(*(p + distance) == 0)
						*(p + distance) = -1 * i;
					distance--; 
				}

				distance = q - p;
				cut = distance / 9;
				distance++;
				//going right
				while(distance / 9 == cut && distance < 81){
					if(*(p + distance) == 0)
						*(p + distance) = -1 * i;
					distance++; 
				}
				
			}
			q++;
		}
		//printsudoku(p);
		if(checksquare(p, i) == 1){
			found = 1;
			i--; 
		}else{
			unminus(p);
			//printsudoku(p);
		}
		//do not put more codes below here due to 
		//i--!
	}
	
	unminus(p);
//	printf("onetonine\n");
//	printsudoku(p);
	return found;
}

int checksquare(int *p, int n)
{
	int found = 0;
	int topleft[9] = {0, 3, 6, 27, 30, 33, 54, 57, 60};
	int insq[9] = {0, 1, 2, 9, 10, 11, 18, 19, 20};
	int *q;
	int filled;

	int i, j;
	for(i = 0; i < 9; i++){
		q = p + topleft[i];
		filled = 9;
		for(j = 0; j < 9; j++){
			if(*(q + insq[j]) == n){
				break;
			}
			else if(*(q + insq[j]) != 0)
				filled--;
			
		}
		//printf("%i\n", filled);
		//printf("\t%li\n", (q - p));

		if(filled == 1){
			for(j = 0; j < 9; j++){
				if(*(q + insq[j]) == 0){
					*(q + insq[j]) = n;
					found = 1;
				}
				/*
				if(((q + insq[j]) - p) == 55){
					printf("%i\n", filled);
					printf("%i\n", *(q + insq[j]));
				}
				*/
					
			}
		}
	}

	return found;
}

void printsudoku(int *p)
{
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			printf("%i  ", *p++); 
		printf("\n"); 
	}
	printf("\n");
	return;
}


void unminus(int *p)
{
	for(int i = 0; i < 81; i++){
		if(*p < 0)
			*p = 0;
		p++;
	}

	return;
}
