#include <stdio.h>
#include <stdlib.h>
/* guess and try, you notice some patterns repeat itself
   suggesting it is a space. 
  */
void keyswitch(int *p);

int main()
{
	FILE *fp;
	fp = fopen("cipher.txt", "r");
	int count = 0;
	int i, j; 
	int n[1201];
	int m[1201];
	for(i = 0; i < 1201; i++)
		n[i] = 0; 

	j = 0;
	while((i = fgetc(fp)) != EOF){
		if(i == 44){
			j++;
			count++;
			continue;
		}
		n[j] = 10 * n[j] + (i - 48);
	}
/*	
	for(i = 0; i < 1201; i++){
		printf("%i:", n[i]);
	}
	printf("There are %i numbers\n", count);
	*/
	int *key = (int *) malloc(sizeof(int) * 3);
	int *start = key;
	*key++ = 103;
	*key++ = 111;
	*key = 100;
	key = start;
	
//	while(*key != 0){
		/*
		if((n[0] ^ *key) <= 46 && (n[0] ^ *key) > 32){
			*key += 1;
			*(key + 1) = 97;
			*(key + 2) = 97;
			continue;
		}
		*/
		printf("\n%c%c%c,\n", *key, *(key + 1), *(key + 2));
		for(i = 0; i < 1201; i++){
			m[i] = n[i] ^ *key++;
			printf("%c", m[i]);
			i++;
			if(i == 1201)
				break;
			m[i] = n[i] ^ *key++;
			printf("%c", m[i]);
			i++;
			if(i == 1201)
				brea;
			m[i] = n[i] ^ *key;
			printf("%c", m[i]);
			key = start;
		}
		int total = 0;
		for(i = 0; i < 1201; i++)
			total += m[i];
		printf("\ntotal is %i,\n", total);
	//	printf("\n%c\n", m[1201]);
		//for(i = 0; i < 1201; i++)
	//		printf("%c", m[i]);

	//	keyswitch(key);
	//	getchar();
//	}
	/*
	while(*key != 0){
		printf("%c%c%c,  ", *key, *(key + 1), *(key + 2));
		keyswitch(key); 
	}
	*/
	
	return 0;
}

void keyswitch(int *p)
{
	//p += 2;
	*p += 1;
	//*p += 1;
/*	
	if(*p > 122){
		*p = 97;
		*(p - 1) += 1;
	}
	p--;
	
	if(*p > 122){
		*p = 97;
		*(p - 1) += 1;

	}
	p--;
	*/
	
	if(*p > 122){
		*p = 0;
		return;
	}
	return;
}
