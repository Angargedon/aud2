#include <stdio.h>

void clearBuffer(){
    char dummy;

    do{
        scanf("%c", &dummy);
    }while(dummy != '\n');
}