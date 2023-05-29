#include <stdio.h>
#include <stdlib.h>
#define SZ 31622 //31622 is the max,

int sqrndigits(int *n);

int cf(const void *a, const void *b){
	return (*(int *) b - *(int *) a);
}

int main()
{
	int sqn[SZ];
	int *darray[SZ];
	int sqnlength[SZ];
	int sqdarray[SZ];
	int i, j, temp, length;
	int *ns;
	
	for(i = 0; i < SZ; i++){
		sqn[i] = (i + 1) * (i + 1);
		temp = sqn[i];
		length = 0;
		while(temp != 0){
			length++;
			temp /= 10;
		}
		sqnlength[i] = length;
		sqdarray[i] = 0;
		darray[i] = (int *) malloc(sizeof(int) * length);
		temp = sqn[i];
		ns = darray[i];
		while(temp != 0){
			//*(darray[i] + j)= temp % 10;
			*ns++ = temp % 10;
			temp /= 10;
		}
	}
	
	for(i = 0; i < SZ; i++){
	//	printf("%i->%i:", sqn[i], sqnlength[i]);
//		qsort(darray[i], sqnlength[i], sizeof(int), cf);
		ns = darray[i];
		if(
		for(j = 0; j < sqnlength[i]; j++){
			sqdarray[i] = sqdarray[i] * 10 + *ns;
	//		printf("%i", *ns++);
			ns++;
		}
	//	printf(" %i", sqdarray[i]);
	//	printf(" %i", sqdarray[i]);
	//	printf("  ");
	}
	*/
	i = 0;
	while(sqnlength[i] < 9)
		i++;
	ns = darray[i];
	while(i < SZ){
		sqrndigits(ns);
		i++;
		ns = darray[i];
	}

	return 0;
}

void sqrndigits(int *n){
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i = 0; 
	while(i < 9){
		if(a[*n] != -1){
			a[*n] = -1;
		} else {
			return;
		}
		i++;
		n++;
	}
	n -= 9;
	i = 0;
	while(i < 9){
		printf("%i", *n++);
		i++;
	}
	printf("\n");

	return;
}


