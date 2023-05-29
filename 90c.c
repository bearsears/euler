// Program to print all combination of size r in an array of size n
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void combinationUtil(int arr[], int data[], int start, int end, 
		                     int index, int r, int *p);
 
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r, int *p)
{
	    // A temporary array to store all combination one by one
	    int data[r];
	     
	        // Print all combination using temprary array 'data[]'
	        combinationUtil(arr, data, 0, n-1, 0, r, p);
}
 
/* arr[]  ---> Input Array
      data[] ---> Temporary array to store current combination
         start & end ---> Staring and Ending indexes in arr[]
	    index  ---> Current index in data[]
	       r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end,
		                     int index, int r, int *p)
{
	    // Current combination is ready to be printed, print it
	if (index == r) {
		while(*p != -1)
			    p++;
		for (int j=0; j<r; j++) {
			*p++ = data[j];
		        printf("%d ", data[j]);
		}
		        printf("\n");
		return;
	}
	     
	        // replace index with all possible elements. The condition
	        // "end-i+1 >= r-index" makes sure that including one element
	        // at index will make a combination with remaining elements
	        // at remaining positions
	        for (int i=start; i<=end && end-i+1 >= r-index; i++) {
	      		  data[index] = arr[i];
		          combinationUtil(arr, data, i+1, end, index+1, r, p);
		}
}

int check(int *p, int *q, long *s);

 
// Driver program to test above functions
int main()
{
	int *p = (int *) malloc(sizeof(int) * 1300);
	for(int j = 0; j < 1300; j++)
		*(p + j) = -1;
	    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	        int r = 6;
		    int n = sizeof(arr)/sizeof(arr[0]);
		        printCombination(arr, n, r, p);
/*	
	while(*p != -1)
		printf("%i", *p++);
*/
	int *q = p;
	int *t = p;
	int count = 0;
	long answer[2500];

	long *ap = answer;
	while(*q != -1) {
		t = p;
		while(*t != -1) {
			if(check(q, t, ap) == 1) {
				count++;
				ap++;
			}
			t += 6;
			
		}
		q += 6;
	}

	ap = answer;
	int i, j;
	char *temp;
	for(i = 0; i < count; i++){
		printf("%lu\n", answer[i]);
	}


	for(i = 0; i < count; i++){
		for(j = i + 1; j < count; j++){
			if(answer[i] == answer[j]){
				answer[j] = 0;
			}
		}
	}

	int countx = 0;
	for(i = 0; i < count; i++){
		if(answer[i] != 0)
			countx++;
		printf("\t%lu\n", answer[i]);
	}



	printf("count is %i\n", count);
	printf("countx is %i\n", countx);

	
	return 0;
}

int check(int *p, int *q, long *s) {
	int i, j;
	int temp;
	int found = 0;
	//check 25
	for(i = 0; i < 6; i++){
		if(*(p + i) == 2 || *(p + i) == 5) {
			if(*(p + i) == 2){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 5){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 2){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;
	found = 0;

	//check 81
	for(i = 0; i < 6; i++){
		if(*(p + i) == 1 || *(p + i) == 8) {
			if(*(p + i) == 1){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 8){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 1){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	//check 01
	for(i = 0; i < 6; i++){
		if(*(p + i) == 0 || *(p + i) == 1) {
			if(*(p + i) == 0){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 1){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 0){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	//check 04
	for(i = 0; i < 6; i++){
		if(*(p + i) == 0 || *(p + i) == 4) {
			if(*(p + i) == 0){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 4){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 0){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	//check 09, 06
	for(i = 0; i < 6; i++){
		if(*(p + i) == 0 || *(p + i) == 6 || *(p + i) == 9) {
			if(*(p + i) == 0){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 6 || *(q + j) == 9){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 0){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	//check 19, 16
	for(i = 0; i < 6; i++){
		if(*(p + i) == 1 || *(p + i) == 6 || *(p + i) == 9) {
			if(*(p + i) == 1){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 6 || *(q + j) == 9){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 1){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	//check 39, 36
	for(i = 0; i < 6; i++){
		if(*(p + i) == 3 || *(p + i) == 6 || *(p + i) == 9) {
			if(*(p + i) == 3){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 6 || *(q + j) == 9){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 3){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	//check 49, 46, 64, 94
	for(i = 0; i < 6; i++){
		if(*(p + i) == 4 || *(p + i) == 6 || *(p + i) == 9) {
			if(*(p + i) == 4){
				for(j = 0; j < 6; j++)
					if(*(q + j) == 6 || *(q + j) == 9){
						found = 1;
						break;
					}
			} else {
				for(j = 0; j < 6; j++)
					if(*(q + j) == 4){
						found = 1;
						break;
					}
			}
		}
		if(found == 1)
			break;
	}
	if(found == 0)
		return 0;

	found = 0;
	int small = 0;
	for(i = 0; i < 6; i++) {
		if(*(p + i) > *(q + i)){
			small = 0;
			break;
		} else if(*(p + i) < *(q + i)){
			small = 1;
			break;
		}
	}

	*s = 0;

	if(small == 0){
		for(i = 0; i < 6; i++)
			*s = *s * 10 + (long)*(p + i);
		for(i = 0; i < 6; i++)
			*s = *s * 10 + (long)*(q + i);
	} else if(small == 1){
		for(i = 0; i < 6; i++)
			*s = *s * 10 + (long)*(q + i);
		for(i = 0; i < 6; i++)
			*s = *s * 10 + (long)*(p + i);
	}


	for(i = 0; i < 6; i++)
		printf("%i ", *(p + i));
	printf("--");
	for(i = 0; i < 6; i++)
		printf("%i ", *(q + i));
	printf("\t");
	printf("\t");


	return 1;
}

