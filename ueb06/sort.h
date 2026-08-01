#ifndef SORT_H
#define SORT_H
#include "datastructure.h"

/*sorts given data with Quicksort-Algorithm. 'datastructure.h' required.*/
void quickSort(sPlayer *array, int amount, int (*cmpfct)(sPlayer *, sPlayer *));

#endif