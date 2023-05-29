#include <stdio.h>
#include <stdlib.h>

int cmpf(const void *a, const void *b){
	return (*(int *) a - *(int *)b);
}
/*The answer is Board, Broad with 17689 and 18769
  despised the question, had to compare manually. 
  manually filter out number patters created by the 
  letters, and compare the number to letters.*/
int main()
{
	int i, j, k, n[5], sq, nn[66], snn[66];
	int count = 0;
	int p = 0;
	for(i = 100; i < 317; i++){
		sq = i * i;
		
		for(j = 0; j < 5; j++){
			n[j] = sq % 10;
			sq /= 10;
		}
		sq = i * i;	
		
		for(j = 0; j < 4; j++)
			for(k = j + 1; k < 5; k++)
				if(n[j] == n[k])
					sq = 0;
					
		if(sq != 0){
		//if((sq/100000 == (sq/100)%10)){
				//|| (sq/10000)%10 == (sq/100)%10){
			count++;
		//	printf("%i has no duplicate numbers.\n", (i * i));
			
			snn[p] = sq;
			nn[p] = 0;
			qsort(n, 5, sizeof(int), cmpf);
			for(j = 0; j < 5; j++){
				nn[p] = nn[p] * 10 + n[j];
			}
			p++;
			
			
			
		}	
		
	}
	/*
	for(i = 0; i < 66; i++){
		printf("%i\n", nn[i]);
	}
	printf("\n");
	for(i = 0; i < 66; i++){
		printf("%i\n", snn[i]);
	}
	*/
	
	for(i = 0; i < 66; i++){
		for(j = (i + 1); j < 66; j++){
			if(nn[i] == nn[j] && ((snn[j]/1000) == snn[i]%100)){
				//|| ((nn[i]/10000)%100 == (nn[j]/10)%100))){

			//	printf("%i, %i\n", snn[i], snn[j]);
				
				printf("%i, %i \t %i, %i\n", nn[i], nn[j],
						snn[i], snn[j]);
						
			}
		}
	}
	
	printf("%i is the total.\n", count);

	return 0;
}
