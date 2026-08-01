#include <stdio.h>
#include "tools.h"

int getMenu(char *title, char *options[], int optionAmount){
    int i;
    int choose = 0;
    
    printf("%s", title);
    printf("\n");
    printLine('-', 50);
    for(i = 0;i<optionAmount;i++){
        printf("\n%i. %s", i+1, options[i]);
    }
    printf("\n\nIhre Wahl: ");
    do{
        scanf("%i", &choose);
        clearBuffer();
    }while((choose < optionAmount) && (choose > optionAmount));

    return choose;
}