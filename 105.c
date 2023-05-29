#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stoi(int *p, char *cp);
int cmpfunc(const void *a, const void *b){
	return ( *(int *) a - *(int *) b);
}
int condition2(int size, int *p);
int pts(int size, int subsz, int *n);
void reorder(int *p, int size, int subsz);

int main()
{
	FILE *fp = fopen("p105_sets.txt", "r");
	size_t length = 60; // each line had about 60 characters
	char *buffer = (char *) malloc(length * sizeof(char)); 
	size_t characters;
	const char s[2] = ",";
	char *token;
	int size, i, sum, a[12], halfway, result;
	char *pa;

	while(feof(fp) == 0){
		characters = getline(&buffer, &length, fp);
		//printf("%zu characters.\t", characters);
		//printf("%s", buffer);
		token = strtok(buffer, s);
		size = 0;
		while(token != NULL){
			stoi(&a[size], token);
		//	printf(" %s", token);
			token = strtok(NULL, s);
			size++;
		}
	/*	
		printf("size is %i\n", size);
		for(i = 0; i < size; i++){
			printf("%i-", a[i]);
		}
		printf("\n");
		*/
		for(i = size; i < 12; i++)
			a[i] = 0;
		qsort(&a[0], size, sizeof(int), cmpfunc);
		/*
		for(i = 0; i < size; i++){
			printf("%i-", a[i]);
		}
		printf("\n\n");
		*/

		result = 0;
	        halfway = size / 2 + 1;
		printf("sum is %i, halfway is %i, size is %i", sum, halfway, size);
		
		for(i = 2; i < halfway; i++){
			if((result = pts(size, i, &a[0])) == 0)
				break;
		}

		if(result == 1){
		/*
			sumtemp = 0;
			for(i = 0; i < SZ; i++)
				sumtemp += n[i];
			if(sumtemp >= sum)
				continue;
				*/
			sum += condition2(size, &a[0]);
			for(i = 0; i < size; i++)
				printf("%i ", a[i]);
			printf("\n\n");
	//		count++;
		}

	}
	printf("sum is %i, halfway is %i, size is %i", sum, halfway, size);
	return 0;
}

void stoi(int *p, char *cp)
{
	*p = 0;
	while(*cp != '\0' && *cp != '\n'){
		*p = *p * 10 + (*cp++ - '0');
		
	}
	return;
}
	
int condition2(int size, int *p)
{
	//left subset will have more than one than the right subset.
	//so left subset sum should be larger but it may not.
	//it will return sum, or zero
	int halfway = size / 2 + size % 2;
	int sumleft = 0;
	int sumright = 0;
	int temp;
	
	while(halfway > 1){
		temp = 0;
	//	printf("\t\t");
		while(temp < halfway){
	//	printf("%i ", *(p + temp));
			sumleft += *(p + temp);
			temp++;
		}	
	//	printf("\n");
		temp = 1;
	//	printf("\t\t\t");
		while(temp < halfway){
	//		printf("%i ", *(p + (size - temp)));
			sumright += *(p + (size - temp));
			temp++;
		}
	//	printf("\n");
		if(sumleft <= sumright)
			break;
		halfway--;
	}
	
	if(halfway > 1)
		return 0;
		
	int i;
	temp = 0;
	for(i = 0; i < size; i++)
		temp += *p++;

	return temp;
	
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
		while(b[0] <= (size - subsz - a[0] - subsz)){

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
		printf("\n");
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

