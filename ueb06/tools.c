#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enter(int howMuch){
    int i;
    for(i=0;i<howMuch;i++) printf("\n");
}

void clearBuffer(){
    char dummy;

    do{
        scanf("%c", &dummy);
    }while(dummy != '\n');
}

void fclearBuffer(FILE *file){
    char Dummy;

    do{
        if(feof(file)) break;
        fscanf(file, "%c", &Dummy);
    }while(Dummy != '\n');
}

void waitForEnter(){
    clearBuffer();
}

void clearScreen(){
    system("clear");
}

int askYesOrNo(char *question){
    char ans;

    printf("\n%s: ", question);
    do{
        scanf("%c", &ans);
        clearBuffer();
    }while((ans != 'y') && (ans != 'Y') && (ans != 'j') && (ans != 'J') && (ans != 'n') && (ans != 'N'));

    if( (ans == 'n') || (ans == 'N')) return 0;
    else return 1;
}

void printLine(char look, int lenght){
    int i;

    for(i=0;i<lenght;i++){
        printf("%c", look);
    }
}

int getText(char *prompt, int maxlen, int allowEmpty, char **text){
    char *Input;
    char Format[20];
    unsigned Len = 0;
    int ok = 0;

    if((text == NULL) || (maxlen == 0)) return 0;
    
    *text = NULL;
    
    Input = malloc(maxlen+1);
    if(Input){
        sprintf(Format, "%%%i[^\n]", maxlen);
        do{
            printf("%s", prompt);
            *Input = '\0';
            scanf(Format, Input);
            clearBuffer();

            Len = strlen(Input);
            if(Len > 0){
                *text = malloc(Len + 1);
                if(*text){
                    strcpy(*text, Input);
                    ok = 1;
                }
            }
            else if(allowEmpty) ok = 1;
        }while(ok != 1);

        free(Input);
        return 1;
    }
    else return 0;
}

int getNumber(char *prompt, int smallestNumAllowed, int biggestNumAllowed, int *number){
    int in;

    if(number == NULL) return 0;
    else{
        int ok = 0;
        *number = 0;
        do{
            printf("%s", prompt);
            scanf("%i", &in);
            clearBuffer();
            if((in >= smallestNumAllowed) && (in <= biggestNumAllowed)){
                *number = in;
                ok = 1;
            }
            else if((smallestNumAllowed == 0) && (biggestNumAllowed == 0)) {
                *number = in;
                ok = 1;
            }
        }while(ok != 1);

        return 1;
    }
}