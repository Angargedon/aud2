#include <stdio.h>
#include "datastructure.h"
#include "tools.h"

void insertInDList(sTeam *newTeam, int (*cmp) (sTeam *,sTeam *)){
    sTeam *tmp = first;

    if(newTeam){
        if(first == NULL){
            first = last = newTeam;
        }
        else if(cmp(first, newTeam) >= 0){
            newTeam->next = first;
            first = first->prev = newTeam;
        }
        else if(cmp(last, newTeam) <= 0){
            newTeam->prev = last;
            last = last->next = newTeam;
        }
        else{
            while(tmp->next){
                if(cmp(tmp->next, newTeam) > 0){
                    newTeam->prev = tmp;
                    newTeam->next = tmp->next;
                    tmp->next = tmp->next->prev = newTeam;
                    break;
                }
                tmp = tmp->next;
            }
        }
    }
}

sTeam *removeFromDList(sTeam *rmTeam, int (*cmp) (sTeam *, sTeam *)){
    sTeam *tmp = first,*rm = NULL;

    if(rmTeam){
        if(cmp(first, rmTeam) == 0){
            rm = first;
            first = first->next;
            if(first == NULL)
                last = NULL;
            else
                first->prev = NULL;
        }
        else if(cmp(last, rmTeam) == 0){
            rm = last;
            last = last->prev;
            last->next = NULL;
        }
        else{
            while(tmp->next){
                if(cmp(tmp->next, rmTeam) == 0){
                    rm = tmp->next;
                    tmp->next = rm->next;
                    tmp->next->prev = tmp;
                    break;
                }
                tmp = tmp->next;
            }
        }
        return rm;
    }
    else{
        printf("\naus Liste entfernen: Fehlgeschlagen.");
        waitForEnter();
        return NULL;
    }
}