#ifndef HEADER
#define HEADER
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
#endif // !HEADER

