#ifndef TOOLS_H
#define TOOLS_H

void enter(int howMuch);

void clearBuffer();

void fclearBuffer(FILE *file);

void waitForEnter();

void clearScreen();

int askYesOrNo(char *question);

void printLine(char look, int lenght);

int getText(char *prompt, int maxLen, int allowEmpty, char **text);

int getNumber(char *prompt, int smallestNumAllowed, int biggestNumAllowed, int *number);

#endif