#include <stdio.h>
#include <stdlib.h>

int qualify(int a[], int size, int max);
int combination(int n, int r);
void permu(int a[], int b[], int c[], int asize, int bsize, int *count);

/* when n is 12 and the subset is 4, it is buggy.
 * I believe it is due to memory, especially when the numbers get large.
 * anyways, the question was hard. Can't believe I solved it.
 */
int main()
{
	int max = 12;
	int ssmax = 4;
	int left[ssmax], i, j, k, count;
	int total = 0;
	
	for(i = 0; i < ssmax; i++){
		left[i] = i;
	}

	int limit = max - ssmax * 2;
	while(left[0] <= limit){
		left[ssmax - 1]++;
		for(i = ssmax - 1; i > 0; i--){
			j = ssmax - i - 1;
			//printf("j is %i\n", j);
			if(left[i] == (max - j)){
				left[i - 1]++;
				for(k = i; k < ssmax; k++){
					left[k] = left[k - 1] + 1;
				}
			}
		}
		if((count = qualify(left, ssmax, max)) > 0){
			/*
			if(count != qualify(left, ssmax,max)){

			for(i = 0; i < ssmax; i++){
				//printf("%i ", left[i]);
				printf("%c ", ('A' + left[i]));
			}
			printf("= %i\n", count);
			}
			*/
			total += count;
		}
	}
	printf("%i is the total.\n", total);

	return 0;
}
	
int qualify(int a[], int size, int max)
{
	//how it is going to work.
	//the left subset and right subsets are counted.
	//when the number of right subset is greater than the left subset
	//it enters a second filter.
	//the second filter counts if how many choices are there, and how
	//many can you pick.
	int i, j;
	int lmax = 1;
	int rmax = 0;
	int count = 0;

	for(i = 1; i < size; i++){
		rmax += a[i] - a[i - 1] - 1;
		if(rmax >= size || rmax > lmax){
			int b[max - size - a[0]];
			int *ap = &a[0];
			int *bp = &b[0];
			for(j = a[0]; j < max; j++){
				if(j != *ap)
					*bp++ = j;
				else 
					ap++;
			}
			int c[size];
			for(j = 0; j < size; j++)
				c[j] = j;
			/*
			for(j = 0; j < size; j++)
				printf("%c ", 'A' + a[j]);
			printf("/ ");
			for(j = 0; j < (max - size - a[0]); j++)
				printf("%c ", 'A' + b[j]);
			printf("\n");
			*/
			
			permu(a, b, c, size, max - size - a[0], &count);
			return count;
			//return 1;
		} 
		lmax++;
	}

	return 0;
}

void permu(int a[], int b[], int c[], int asize, int bsize, int *count)
{
	int i, j;
	while(c[asize - 1] < bsize){
		for(i = 1; i < asize; i++){
			if(b[(c[i])] < a[i]){
				/*
				for(int j = 0; j < asize; j++)
					printf("%c ", 'A' + a[j]);
				printf("and ");
				for(int j = 0; j < asize; j++)
					printf("%c ", 'A' + b[(c[j])]);
				printf("\n");
				*/
				
				*count = *count + 1;
				break;
			}
		}

		i = asize - 1;
		j = 0;	
		while(c[i] == (bsize - 1 - j) && i > 0){
			//printf("\t%i and %i: ", c[i], (bsize - 1 - j));
			i--; 
			j++;
		}
		j = c[i] + 1;
	
		while(i < asize){
			c[i] = j;
			i++;
			j++;
		}
		
		for(i = 0; i < asize; i++){
			printf("%c ", 'A' + b[(c[i])]);
		}
		printf("\n");
		
	
	} 

	return;
}
