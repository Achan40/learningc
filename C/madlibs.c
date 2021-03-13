#include <stdio.h>
#include <stdlib.h>

int main()
{
	char color[20];
	char plural[20];
	char word1[20];
	char word2[20];

	printf("Enter a color: ");
	scanf("%s", color);
	printf("Enter a plural noun: ");
	scanf("%s", plural);
	printf("Enter a word: ");
	scanf("%s%s", word1, word2);

	printf("Roses are %s\n", color);
	printf("%s are blue\n", plural);
	printf("I love %s %s\n", word1, word2);
}