#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("11.txt", "r");
	char numbers[2];
	unsigned int nb[400];
	int i = 0;

	while( fgets(numbers, 3, fp) != NULL )
	{
		nb[i] = (numbers[0] - '0') * 10 + (numbers[1] -'0');
	//	printf("%s:", numbers);
		if(fgets(numbers, 2, fp) == NULL) 
		/* this will read space or \n */
			break;
		i++;
	}

	/* check if the array has been placed properly */
	/*
	for( i = 0 ; i < 400 ; i++ )
	{
		printf("%i:", nb[i]);
	}
	*/

	/* check diagonally, left up, right down */
	unsigned int *pn = &nb;
	pn += 60;
	printf("%i,\n", *pn);
	long product = 0;
	long temp = 0;

	while ( (pn - nb) < 400 )
	{
		pn += 3;
		printf("%i-%i-%i-%i\n",	*pn , *(pn - 21) , *(pn - 42) , *(pn -63));
		for (i = 0 ; i <= 16 ; i++)
		{
			temp = *pn * *(pn - 21) * *(pn - 42) * *(pn -63);
			printf("%i-%i-%i-%i: %lu\n", *pn , *(pn - 21) , *(pn - 42) , *(pn -63), temp);
			if (temp > product)
				product = temp;
			pn++;
		}
	}
	printf("%lu is the left up right down diagonal product.\n", product);	

	/* check diagonally, left down, right up */
	pn = &nb;
	printf("%i,\n", *pn);
	product = 0;
	temp = 0;

	while ( (pn - nb) < 340 )
	{
		pn += 3;
		printf("%i*%i*%i*%i\n",	*pn , *(pn + 19) , *(pn + 38) , *(pn + 57));
		for (i = 0 ; i <= 16 ; i++)
		{
			temp = *pn * *(pn + 19) * *(pn + 38) * *(pn + 57);
			printf("%i*%i*%i*%i: %lu\n", *pn , *(pn + 19) , *(pn + 38) , *(pn + 57), temp);
			if (temp > product)
				product = temp;
			pn++;
		}
	}
	printf("%lu is the left down right up diagonal product.\n", product);	
	fclose(fp);

	return (0);
}
