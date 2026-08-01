#ifndef TOOLS_H
#define TOOLS_H

/*Prints '\n', intended to replace multible \n-calls.*/
void enter(int howMuch);

/*clears input-buffers. Recommended after every scanf-call.*/
void clearBuffer();

/*clears file-input-buffers. Recommended after every fscanf-call.*/
void fclearBuffer(FILE *file);

/*Program expects a enter/'\n'-input before continuing.*/
void waitForEnter();

/*clears the screen using the system-call.*/
void clearScreen();

/*Prints question which returns the yes-or-no-answer binary. y/n and j/n are expected in the inpuit.*/
int askYesOrNo(char *question);

/*prints a line of given character.*/
void printLine(char look, int lenght);

/*Prints a prompt and savely allocates the input-text.*/
int getText(char *prompt, int maxLen, int allowEmpty, char **text);

/*Prints a prompt and expects the input to be a integer to be saved in the last parameter.*/
int getNumber(char *prompt, int smallestNumAllowed, int biggestNumAllowed, int *number);

#endif