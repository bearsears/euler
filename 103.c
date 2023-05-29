#include <stdio.h>
#include <stdlib.h>
#define SZ 6

int pts(int size, int subsz, int *n);
void reorder(int *p, int size, int subsz);

int main()
{
	int i, j, temp, result;
	int count = 0;
	int n[SZ] = {11, 14, 17, 19, 20, 21};
	int min[SZ] = {11, 14, 17, 19, 20, 21};
	int max[SZ] = {11, 19, 22, 24, 25, 26};
	// to check second condition, if B has
	// more elements than C than S(B) > S(C);
	int halfway, sumleft, sumright;
	int sum = 117;
	int sumtemp;

	while(n[0] < 12) {
		n[SZ - 1]++;
		for(i = 1; i < SZ; i++){
			if(n[i] < min[i])
				n[i] = min[i];
			else if(n[i] > max[i]){
				temp = ++n[i - 1];
				temp++;
				break;
			}
		}
		while(i < SZ){
			n[i] = temp++;
			i++;
		}
		//gonna have to check the condition
		//if B has more element than C than S(B) > S(C)
		halfway = SZ / 2 + SZ % 2;
		sumleft = 0;
		sumright = 0;
		/*
		for(i = 0; i < SZ; i++)
			printf("%i ", n[i]);
		printf("\n");
		*/
		
		while(halfway > 1){
			temp = 0;
		//	printf("\t\t");
			while(temp < halfway){
	//			printf("%i ", n[temp]);
				sumleft += n[temp];
				temp++;
			}	
	//		printf("\n");
			temp = 1;
	//		printf("\t\t\t");
			while(temp < halfway){
	//			printf("%i ", n[SZ - temp]);
				sumright += n[SZ - temp];
				temp++;
			}
	//		printf("\n");
			if(sumleft <= sumright)
				break;
			halfway--;
		}
		if(halfway != 1)
			continue;
		
		/*
		for(i = 0; i < SZ; i++)
			printf("%i ", n[i]);
		printf("\n");
		count++;
		*/
		result = 0;
		
		for(i = 2; i < 4; i++){
			/*
			for(j = 0; j < SZ; j++)
				printf("%i ", n[j]);
			printf("\n");
			*/

			if((result = pts(SZ, i, &n[0])) == 0)
				break;
		}
		
		if(result == 1){
			sumtemp = 0;
			for(i = 0; i < SZ; i++)
				sumtemp += n[i];
			if(sumtemp >= sum)
				continue;
			for(i = 0; i < SZ; i++)
				printf("%i ", n[i]);
			printf("\n\n");
	//		count++;
			break;
		}
	}
	//printf("%i is the total\n", count);
	// 932 was the total for the 6 digits

	return 0;
}

int pts(int size, int subsz, int *n)
{
	//pts means permutations
	//printf("size: %i, subsz: %i, where?\n", size, subsz);
	int a[subsz], b[subsz], i, j, suma, sumb;
	for(i = 0; i < subsz; i++){
		a[i] = i;
		b[i] = i;
	}

	

	int limit = size - subsz - subsz;
	int *pleft, *pn;
	//printf("%i is the limit.\n", limit);
	while(a[0] <= limit){
		//printf("size: %i, subsz: %i, where?\n", size, subsz);
		a[subsz - 1]++;
		reorder(&a[subsz - 1], size, subsz);
		
		printf("\ta[0] ");	
		for(i = 0; i < subsz; i++)
			printf(" %i, ", a[i]);
		printf("\t%i\n", limit);
		
		
		//How to filter the leftover numbers
		if((size - subsz - a[0]) < subsz)
			continue;
		int leftover[size];
		int reduced[size - subsz - a[0]];
		
		for(i = 0; i < size; i++)
			leftover[i] = 0;
		for(i = 0; i < (size - subsz); i++)
			reduced[i] = 0;
		for(i = 0; i < subsz; i++)
			leftover[a[i]] = -1;
		j = 0;
		for(i = a[0]; i < size; i++){
			while(leftover[i] == -1 && i < size)
				i++;
			reduced[j] = *(n + i);
			j++;
		}
		
		for(i = 0; i < size; i++)
			printf("\t%i ", leftover[i]);
		printf("\n");
		
		printf("the reduced are ");
		for(i = 0; i < (size - subsz - a[0]); i++)
			printf("%i ", reduced[i]);
		printf("\n");
		
		pn = n;
		j = 0;
		suma = 0;
		sumb = 0;
		for(i = 0; i < subsz; i++)
			b[i] = i;
		while(b[0] <= (size - subsz - subsz )){
			
			printf("b[0]\t");	
			for(i = 0; i < subsz; i++)
				printf("%i, ", b[i]);
			printf("\n");

			suma = 0;
			sumb = 0;
/*			
			for(i = 0; i < subsz; i++){
				if(*(pn + a[i]) > reduced[b[i]]){
					i = 0;
					break;
				}
			}
			*/
			for(i = 0; i < subsz; i++){
				suma += *(pn + a[i]);
				sumb += reduced[b[i]];
			}
			printf("\t\t\t %i and %i\n", suma, sumb);
			if(suma != 0 && sumb != 0 && suma == sumb){
				for(i = 0; i < subsz; i++)
					printf("%i ", *(pn + a[i]));
				printf("\t");
				for(i = 0; i < subsz; i++)
					printf("%i ", reduced[b[i]]);
				printf("\n");
				return 0;
			}

			b[subsz - 1]++;
			reorder(&b[subsz - 1], size - subsz - a[0], subsz);
		}
	}
	return 1;
}

void reorder(int *p, int size, int subsz)
{
	int i = subsz - 1;
	int *s = p - subsz + 1;
	int *end = p;
	int *start = s;
	while(*p == size){
		//&& *s <= (size - subsz)){
		*p -= 1;
		while(*p ==(*(p - 1) + 1) && i > 1){
			i--;
			p--;
		}
		p--;
		*p = *p + 1;
		int temp = *p++;
		temp++;
		//printf("%i is the i , %i is the diff, %i\n", i, size - subsz, *(p - 1));
		while(i <= subsz){
			*p++ = temp;
			i++;
			temp++;
		}
		//printf("%i is the i , %i is the subsz, %i\n", i, subsz, *p);
			
		p = end;
		/*
		while((p - s) != 0){
			printf("%i, ", *s++);
		}
		printf("%i, ", *s);
		s = start;
		*/
	//	printf("\n");
	}
	return;
}
