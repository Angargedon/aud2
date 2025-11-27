#include <stdio.h>
#include "dlist.h"

//
// Dies ist eine Demo-Datei mit einigen Testfällen für Ihren Datentypen.
// Diese Datei wird bei der Ausführung der automatischen Tests ersetzt.
// Sie können die Datei bearbeiten um weitere Testfälle zu prüfen.
//
int main(int argc, char** argv)
{
    dlist_t* list = dlist_create();
    int a = 100, b = 200, c = 300, d = 0xFF;
    dlist_append(list, &a);
    dlist_append(list, &b);
    dlist_append(list, &c);

    printf("Length is %d\n", dlist_length(list));
    printf("First is %d\n", *(int*)dlist_get_data_at(list, 0));
    printf("Second is %d\n", *(int*)dlist_get_data_at(list, 1));
    printf("Third is %d\n", *(int*)dlist_get_data_at(list, 2));

    // Liste kopieren
    dlist_t* second = dlist_copy(list);
    printf("Length is %d\n", dlist_length(second));
    printf("First is %d\n", *(int*)dlist_get_data_at(second, 0));
    printf("Second is %d\n", *(int*)dlist_get_data_at(second, 1));
    printf("Third is %d\n", *(int*)dlist_get_data_at(second, 2));

    // Listen verketten
    dlist_concat(list, second);
    printf("Length of list = %d, length of second = %d\n", dlist_length(list), dlist_length(second));
    for (int index = 0; index < dlist_length(list); index++) {
        printf("data of node %d in list = %d\n", index, *(int *)dlist_get_data_at(list, index));
    }

    // Werte im Abstand von 2 immer wieder einfügen mit prepend und insert
    dlist_prepend(list, &d);
    for (int index = 2; index <= 12; index += 2) {
        dlist_insert_at(list, index, &d);
    }

    // Ausgabe muss nun Muster 255, 100, 255, 200, 255, 300, 255, (...) sein
    for (int index = 0; index < dlist_length(list); index++) {
        printf("data of node %d in list = %d\n", index, *(int*)dlist_get_data_at(list, index));
    }

    // Liste erneut kopieren und Reihenfolge umkehren
    dlist_t *third = dlist_copy(list);
    dlist_reverse(third);

    // Ausgabe von list (von vorne nach hinten) und third (von hinten nach vorne)
    for (int index = 0; index < dlist_length(list); index++) {
        printf("data of node %d in list %d == %d in third at position %d\n", index, *(int*)dlist_get_data_at(list, index),
            *(int*)dlist_get_data_at(third, dlist_length(list) - 1 - index), dlist_length(list) - 1 - index
        );
    }

    dlist_delete(list);
    dlist_delete(second);
    dlist_delete(third);
    return 0;
}
