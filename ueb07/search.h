#ifndef SEARCH_H
#define SEARCH_H
#include "datastructure.h"

int calcDivisionrest(char *calcString);

sListElement *searchP(sHashTableElement *hIdx, sPlayer *player, int (*cmp) (sPlayer *, sPlayer *));

#endif