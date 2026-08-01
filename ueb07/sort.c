#include <string.h>
#include "datastructure.h"
#include "search.h"

static int cmpName(sPlayer *p1, sPlayer *p2){
    return strcmp(p1->name, p2->name);
}

void swap(sPlayer *e1, sPlayer *e2){
    sListElement *LE1 = searchP(&playerIndex[calcDivisionrest(e1->name)], e1, cmpName),
                 *LE2 = searchP(&playerIndex[calcDivisionrest(e2->name)], e2, cmpName);
    sPlayer tmp = *e1;

    *e1 = *e2;
    *e2 = tmp;

    LE1->pData = e2;
    LE2->pData = e1;

}

int partition(sPlayer *array, int ui, int oi, int (*cmpfct)(sPlayer *, sPlayer *)){
    sPlayer *cmp = array + ui;
    int i = ui + 1, j = oi;

    while(i<=j){
        while((i<=j) && (cmpfct(array+i, cmp) <= 0))
            i++;
        while((j>=i) && (cmpfct(array+j, cmp) >= 0))
            j--;
        if(i<j){
            swap(array+i, array+j);
            i++;
            j--;
        }
    }
    i--;
    swap(cmp, array+i);
    return i;
}

void qSort(sPlayer *array, int ui, int oi, int (*cmpfct)(sPlayer *, sPlayer *)){
    int idx;
    if(ui >= oi) return;
    else{
        idx = partition(array, ui, oi, cmpfct);
        qSort(array, ui, idx - 1, cmpfct);
        qSort(array, idx + 1, oi, cmpfct);
    }
}

void quickSort(sPlayer *array, int amount, int (*cmpfct)(sPlayer *, sPlayer *)){
    qSort(array, 0, amount-1, cmpfct);
}