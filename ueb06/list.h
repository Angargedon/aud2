#ifndef LIST_H
#define LIST_H
#include "datastructure.h"

void insertInDList(sTeam *newTeam, int (*cmp) (sTeam *, sTeam *));

sTeam *removeFromDList(sTeam *rmTeam, int (*cmp) (sTeam *, sTeam *));

#endif