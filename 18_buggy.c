#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	FILE *temp;
	char *buffer;
	size_t bufsize = 1;
	size_t characters;

        int **c = malloc( 15 * sizeof(int *));
	int i;
        for (i = 0; i < 15; i++)
        {
                c[i] = malloc((i + 1) * sizeof(int));
        }


	fp = fopen("18.txt", "r");
	temp = fp;

	int nlines = 0;
	while ((characters = getline(&buffer, &bufsize, temp)) != EOF) {
		printf("%zu, %zu: ", characters, bufsize);
		printf("%s", buffer);
		nlines++;
	}

	fclose(fp);
	free(buffer);
	printf("\nThere are %i lines.\n", nlines);
	
	int nelem = 0;
	for (i = nlines; i > 0; i--)
		nelem += i;
	printf("Number of elements are %i\n", nelem);
	
	free(c);
	return 0;
}
