#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char *cn);
int ireverse(int n);
int findProducts(int n);
int main()
{
	int in = 987654;
	int rn = ireverse(in);
	printf("%d\t%d\n", in, rn);
	
	/*
	char cn[6];
	sprintf(cn, "%d", in); // convert int to string 
	puts(cn);
	reverse(cn);
	puts(cn);	
	*/

	int result = 0;
	for( in = 100000 ; in <= 999999 ; in++)
	{
		rn = ireverse(in);
		if( (in - rn) == 0)
		{
			result = findProducts(in);
			if( result > 0)
				printf("%d\t%d\t%d\n", in, result, (in/result));
		}
	}

	return 0;
}

void reverse(char *cn)
{
	int len;
	len = strlen(cn);
	char *bn = (cn + len - 1);
	char temp;

	while(bn > cn)
	{
		temp = *cn;
		*cn++ = *bn;
		*bn-- = temp;
	}
}

int ireverse(int n)
{
	int rn = 0;
	
	while(n > 0)
	{
		rn = 10 * rn + (n % 10);
		n /= 10;
	}

	return rn;
}

int findProducts(int n)
{
	int i, j;
	int r, rm;

	for( i = 999; i >= 100; i--)
	{
		rm = n % i;
		if ( rm == 0)
			return i;
	}

	return -1;
}
		
