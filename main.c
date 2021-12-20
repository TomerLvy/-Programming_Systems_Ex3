#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Strings.h"

#define TRUE 1
#define FALSE 0
#define WORD 30
#define TXT 1024

int main()
{
	int flags[WORD];
	char word[WORD];
	printf("Enter word: ");
	scanf("%[^\t,\n,'']", word);
	char text[TXT];
	printf("enter text: ");
	scanf("%[^~]", text);
	
	printAtbash(word, text);

	printMinGimatria(word, text);

	shortestSequance(word, text, flags);

	return 0;
}