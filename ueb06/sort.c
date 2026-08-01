#include <stdio.h>
#include "datastructure.h"

void swap(sPlayer *e1, sPlayer *e2){
    sPlayer tmp;

    tmp.name = e1->name;
    tmp.birthday = e1->birthday;
    tmp.playernumber = e1->playernumber;
    tmp.goals = e1->goals;

    e1->name = e2->name;
    e1->birthday = e2->birthday;
    e1->playernumber = e2->playernumber;
    e1->goals = e2->goals;

    e2->name = tmp.name;
    e2->birthday = tmp.birthday;
    e2->playernumber = tmp.playernumber;
    e2->goals = tmp.goals;
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