#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *buffer;
	size_t bufsize = 1;
	FILE *fileopen;
	size_t characters;
	long array[20][50] = {};
	long *parray = &array;
	fileopen = fopen("8.txt", "r");
	if (fileopen == NULL)
		exit(EXIT_FAILURE);
	
	int i, j;

	while ((characters = getline(&buffer, &bufsize, fileopen)) != EOF) {
		printf("%zu, %zu: ", characters, bufsize);
		printf("%s", buffer);
		for(i = 0; i < (characters - 1) ; i++)
		{
			*parray++ = *(buffer + i) - '0';
		}
	}

	/*
	for( j = 0 ; j < 20; j++ ) 
	{
		for ( i = 0; i < 50; i++)
		{
			printf("%i ", array[j][i]);
		}
		printf("\n");
	}
	*/
	
	parray = &array;
	parray += 12;
	printf("\n%lu\n", *parray);
	long product = 0;
	long temp;

	
	/* check left to right */
	for( i = 0; i <= 987; i++)
	{
		temp = *parray * *(parray - 1) * *(parray - 2) * *(parray - 3)  * *(parray - 4) * *(parray - 5) * *(parray - 6) * *(parray - 7) * *(parray - 8) * *(parray - 9) * *(parray - 10) * *(parray - 11) * *(parray - 12) ;
		printf("%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu%lu:%lu\n", *parray , *(parray - 1) , *(parray - 2) , *(parray - 3)  , *(parray - 4) , *(parray - 5) , *(parray - 6) , *(parray - 7) , *(parray - 8) , *(parray - 9) , *(parray - 10) , *(parray - 11) , *(parray - 12), temp) ;
		parray++;
		if( temp > product)
			product = temp;
	}
	printf("\nleft to right:%lu\n", product);

	parray = &array;
	parray += 600;
	printf("\n%lu\n", *parray);
	product = 0;

	/* check vertically */
	while( *parray >= 0 )
	{
		temp = *parray * *(parray - 50) * *(parray - 100) * *(parray - 150) * *(parray - 200) * *(parray - 250) * *(parray - 300) * *(parray - 350) * *(parray - 400) * *(parray - 450) * *(parray - 500) * *(parray - 550) * *(parray - 600);
		parray++;
		if( temp > product)
			product = temp;
	}
	printf("\ndown and up :%lu\n", product);

	free(buffer);
	fclose(fileopen);

	return 0;
}

