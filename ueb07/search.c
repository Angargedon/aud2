#include <stdio.h>
#include <ctype.h>
#include "datastructure.h"

int calcDivisionrest(char *calcString){
    int Sum = 0;

    while(*calcString != '\0'){
        Sum += toupper(*calcString);
        calcString++;
    }

    return (Sum % MAXINDEX);
}

sListElement *searchP(sHashTableElement *hIdx, sPlayer *player, int (*cmp) (sPlayer *, sPlayer *)){
    sListElement *searchList = hIdx->first;

    while(searchList != NULL){
        if(cmp(searchList->pData, player) == 0)
            break;
        else
            searchList = searchList->next;
    }
    return searchList;
}