#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define WORD 30
#define TXT 1024

char atbashConvertor(char ch);
void abtashWordConvertor(char word[], char atbash[]);
void printAtbash(char word[], char text[]);
int isIn(char ch, char word[], int flags[]);
void resetFlags(int flags[]);
int wordLength(char word[]);
void shortestSequance(char word[], char text[], int flags[]);
void resetTempWord(char word[]);
int gimatriaConvertor(char ch);
void printMinGimatria(char word[], char text[]);



void shortestSequance(char word[], char text[], int flags[])
{
	char tempWord[TXT];
	int wordSize = wordLength(word),currentWordSize=0, flagSize=0,minWordSize=-1,textlength=strlen(text),tempWordIndex=0;
	for (int i = 0; i < textlength; i++)
	{
		char tempCH = text[i];
		if (isIn(tempCH, word, flags) == TRUE)
		{
			currentWordSize++;
			flagSize++;
			int j = 1;
			int isTrue = TRUE;
			while (isTrue==TRUE&&(i+j)<textlength)
			{
				tempCH = text[i + j];
				if (tempCH==' ')
				{
					currentWordSize++;
					j++;
						
				}
				else if (isIn(tempCH, word, flags) == TRUE)
				{
					currentWordSize++;
					j++;
					flagSize++;
				}
				else if (isIn(tempCH, word, flags) == FALSE)
				{
					isTrue = FALSE;
				}

			}
			if (flagSize == wordSize)
			{
				if (currentWordSize < minWordSize || minWordSize == -1)
				{
					minWordSize = currentWordSize;
				}
			}
			flagSize = 0;
			currentWordSize = 0;
			resetFlags(flags);
		}
	}
	for (int i = 0; i < textlength; i++)
	{
		char tempCH = text[i];
		if (isIn(tempCH,word,flags)==TRUE)
		{
			currentWordSize++;
			flagSize++;
			int j = 1;
			int isTrue = TRUE;
			while (isTrue == TRUE && (i + j) < textlength)
			{
				tempCH = text[i + j];
				if (tempCH==' ')
				{
					currentWordSize++;
					tempWord[tempWordIndex] = tempCH;
					tempWordIndex++;
					j++;
				}
				else if (isIn(tempCH,word,flags)==TRUE)
				{
					currentWordSize++;
					flagSize++;
					tempWord[tempWordIndex] = tempCH;
					tempWordIndex++;
					j++;
				}
				else if (isIn(tempCH, word, flags) == FALSE)
				{
					tempWord[tempWordIndex] = '\0';
					isTrue = FALSE;
				}
			}
			if (flagSize == wordSize)
			{
				if (currentWordSize==minWordSize)
				{
					printf("%s ", tempWord);
					printf("~");
				}				
			}
			flagSize = 0;
			currentWordSize = 0;
			resetFlags(flags);
			resetTempWord(tempWord);
		}
		
	}

}

void resetTempWord(char word[])
{
	for (int i = 0; i < strlen(word); i++)
	{
		word[i] = '\0';
	}
}

int wordLength(char word[])
{
	int i = 0;
	while (word[i] != '\0')
	{
		i++;
	}
	return i;
}
void resetFlags(int flags[])
{
	for (int i = 0; i < WORD; i++)
	{
		flags[i] = FALSE;
	}
}

int isIn(char ch, char word[], int flags[])
{
	for (int i = 0; i < WORD; i++)
	{
		if (word[i] == ch)
		{
			if (flags[i] == FALSE)
			{
				flags[i] = TRUE;
				return TRUE;
			}
		}
	}
	return FALSE;
}

//this function flips a char based on the atbash algorithm
char atbashConvertor(char ch)
{
	switch (ch)
	{
	case 'A':
		return 'Z';
	case 'a':
		return 'z';
	case 'B':
		return 'Y';
	case 'b':
		return 'y';
	case 'C':
		return 'X';
	case 'c':
		return 'x';
	case 'D':
		return 'W';
	case 'd':
		return 'w';
	case 'E':
		return 'V';
	case 'e':
		return 'v';
	case 'F':
		return 'U';
	case 'f':
		return 'u';
	case 'G':
		return 'T';
	case 'g':
		return 't';
	case 'H':
		return 'S';
	case 'h':
		return 's';
	case 'I':
		return 'R';
	case 'i':
		return 'r';
	case 'J':
		return 'Q';
	case 'j':
		return 'q';
	case 'K':
		return 'P';
	case 'k':
		return 'p';
	case 'L':
		return 'O';
	case 'l':
		return 'o';
	case 'M':
		return 'N';
	case 'm':
		return 'n';
	case 'N':
		return 'M';
	case 'n':
		return 'm';
	case 'O':
		return 'L';
	case 'o':
		return 'l';
	case 'P':
		return 'K';
	case 'p':
		return 'k';
	case 'Q':
		return 'J';
	case 'q':
		return 'j';
	case 'R':
		return 'I';
	case 'r':
		return 'i';
	case 'S':
		return 'H';
	case 's':
		return 'h';
	case 'T':
		return 'G';
	case 't':
		return 'g';
	case 'U':
		return 'F';
	case 'u':
		return 'f';
	case 'V':
		return 'E';
	case 'v':
		return 'e';
	case 'W':
		return 'D';
	case 'w':
		return 'd';
	case 'X':
		return 'C';
	case 'x':
		return 'c';
	case 'Y':
		return 'B';
	case 'y':
		return 'b';
	case 'Z':
		return 'A';
	case 'z':
		return 'a';
	default:
		return ch;
	}
}

//this function takes a word a convert it based on the atbash algorithm
void abtashWordConvertor(char word[],char atbash[])
{
	int length = strlen(word);
	for (int i = 0; i < length; i++)
	{
		atbash[i] = atbashConvertor(word[i]);
	}
}

//this function prints all the strings that are identical to the word in atbash algorithm ignoring white spaces 
void printAtbash(char word[], char text[])
{
//initializing the word in atbash and 1st and last letter of the word
	int wordLength = strlen(word);
	int textLength = strlen(text);
	char newWord[WORD];
	abtashWordConvertor(word, newWord);
	char lastCH = newWord[wordLength - 1];
	char firstCH = newWord[0];
	for (int i = 0; i < textLength; i++)
	{
		char tempCH = text[i];
		int isTrue = FALSE;
		if (tempCH == firstCH)
		{
			char tempPrint[WORD];
			tempPrint[0] = tempCH;
			isTrue = TRUE;
			int j = 1, k = 0; 
			while (isTrue==TRUE)
			{
				if (j>wordLength)
				{
					break;
				}
				else if (i + j + k >= textLength) 
				{
					break;
				}
				char textIndex = text[i + j + k];
				char wordIndex = newWord[j];
				if (textIndex==' ')
				{
					k++; 
					continue;
				}
				else if (textIndex == wordIndex)
				{
					tempPrint[j] = newWord[j];
					j++;
				}
				else
				{
					isTrue = FALSE;
				}

			}
			if (isTrue==TRUE)
			{
				tempPrint[j] = '\0';
				printf("%s ~", tempPrint);
			}
		}
		else if (tempCH == lastCH)
		{
			char tempPrint[WORD];
			tempPrint[0] = tempCH;
			isTrue = TRUE;
			int j = 1, k = 0;
			while (isTrue == TRUE)
			{
				if (wordLength - j - 1 <= 0)
				{
					break;
				}
				else if (i + j + k >= textLength)
				{
					break;
				}
				char textIndex = text[i + j + k];
				char wordIndex = newWord[wordLength-1-j];
				if (textIndex == ' ')
				{
					k++; 
					continue;
				}
				else if (textIndex == wordIndex)
				{
					tempPrint[j] = newWord[wordLength - 1 - j];
					j++;
				}
				else
				{
					isTrue = FALSE;
				}

			}
			if (isTrue==TRUE)
			{
				tempPrint[j] = '\0';
				printf(" %s ~", tempPrint);
			}
		}

	}

}
int gimatriaConvertor(char ch)
{
	switch (ch)
	{
	case 'A':
		return 1;
	case 'a':
		return 1;
	case 'B':
		return 2;
	case 'b':
		return 2;
	case 'C':
		return 3;
	case 'c':
		return 3;
	case 'D':
		return 4;
	case 'd':
		return 4;
	case 'E':
		return 5;
	case 'e':
		return 5;
	case 'F':
		return 6;
	case 'f':
		return 6;
	case 'G':
		return 7;
	case 'g':
		return 7;
	case 'H':
		return 8;
	case 'h':
		return 8;
	case 'I':
		return 9;
	case 'i':
		return 9;
	case 'J':
		return 10;
	case 'j':
		return 10;
	case 'K':
		return 11;
	case 'k':
		return 11;
	case 'L':
		return 12;
	case 'l':
		return 12;
	case 'M':
		return 13;
	case 'm':
		return 13;
	case 'N':
		return 14;
	case 'n':
		return 14;
	case 'O':
		return 15;
	case 'o':
		return 15;
	case 'P':
		return 16;
	case 'p':
		return 16;
	case 'Q':
		return 17;
	case 'q':
		return 17;
	case 'R':
		return 18;
	case 'r':
		return 18;
	case 'S':
		return 19;
	case 's':
		return 19;
	case 'T':
		return 20;
	case 't':
		return 20;
	case 'U':
		return 21;
	case 'u':
		return 21;
	case 'V':
		return 22;
	case 'v':
		return 22;
	case 'W':
		return 23;
	case 'w':
		return 23;
	case 'X':
		return 24;
	case 'x':
		return 24;
	case 'Y':
		return 25;
	case 'y':
		return 25;
	case 'Z':
		return 26;
	case 'z':
		return 26;
	default:
		return 0;
	}
}

int wordGimatriaSum(char word[])
{
	int sum = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		sum = sum + gimatriaConvertor(word[i]);
	}
	return sum;
}

void printMinGimatria(char word[], char text[])
{
	char tempWord[TXT];
	int currentWordLength = 0, textLength = strlen(text), wordSum = wordGimatriaSum(word), minLength = -1, tempWordIndex = 0;
	for (int i = 0; i < textLength; i++)
	{
		currentWordLength = 0;
		int tempSum = gimatriaConvertor(text[i]);
		if (tempSum == wordSum)
		{
			minLength = 1;
		}
		else if (tempSum < wordSum)
		{
			currentWordLength++;
			int j = 1;
			int isTrue = TRUE;
			while (isTrue == TRUE && (i + j) < textLength)
			{
				tempSum = tempSum + gimatriaConvertor(text[i + j]);
				currentWordLength++;
				j++;
				if (tempSum >= wordSum)
				{
					break;
				}

			}
			if ((currentWordLength < minLength || minLength == -1)&&tempSum==wordSum)
			{
				minLength = currentWordLength;
			}
		}

	}
	for (int i = 0; i < textLength; i++)
	{
		resetTempWord(tempWord);
		currentWordLength = 0;
		tempWordIndex = 0;
		int tempSum = gimatriaConvertor(text[i]);
		if (tempSum==wordSum)
		{
			printf("%c ", text[i]);
			printf("~");
		}
		else if (tempSum < wordSum)
		{
			int j = 1;
			tempWord[tempWordIndex] = text[i];
			tempWordIndex++;
			while ((i+j)<textLength)
			{
				tempSum = tempSum + gimatriaConvertor(text[i + j]);
				currentWordLength++;
				tempWord[tempWordIndex] = text[i+j];
				tempWordIndex++;
				j++;
				if (tempSum==wordSum)
				{
					if (currentWordLength==minLength)
					{
						tempWord[tempWordIndex] = '\0';
						printf("%s ", tempWord);
						printf("~");
						break;
					}
				}
				else if (tempSum > wordSum)
				{
					break;
				}
			}
		}
	}
}



