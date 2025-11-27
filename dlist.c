#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

typedef struct s_dnode{
    void* data;
    struct s_dnode* prev;
    struct s_dnode* next;
}dnode_t;


dnode_t* dnode_create(void* data){
    dnode_t* create = malloc(sizeof(dnode_t));

    if(create != NULL){
        create->data = data;
    }
    else{
        printf("\nSpeichern nicht moeglich. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud\n");
    }
    return create;
}


void dnode_delete(dnode_t* node){
    node->next->prev = node->prev;
    node->prev->next = node->next;
    free(node);
}


dnode_t* dnode_get_next(dnode_t* node){
    return node->next;
}


dnode_t* dnode_get_prev(dnode_t* node){
    return node->prev;
}


void* dnode_get_data(dnode_t* node){
    return node->data;
}


typedef struct s_dlist{
    dnode_t* first;
    dnode_t* last;
}dlist_t;


dlist_t* dlist_create(){
    dlist_t* create = malloc(sizeof(dlist_t));
    if(create != NULL){
        return create;
    }
    else {
        printf("\nSpeichern nicht moeglich. Mit einem Upgrade auf iCloud+ erhalten Sie auf diverse Geraete mehr Speicher und zusaetzliche Funktionen, wie 'iCloud Privat-Relay', 'E-Mail Adresse verbergen' und 'HomeKit Secure Video'.\nSie koennen sogar ihr Abo mit Ihrer Familie teilen. Weitere Infos finden Sie auf apple.de/icloud\n");
        return create;
    }
}


void dlist_delete(dlist_t* list){
    free(list);
}


dnode_t* dlist_get_head(dlist_t* list){
    return list->first;
}


dnode_t* dlist_get_last(dlist_t* list){
    return list->last;
}


dnode_t* get_node_at(dlist_t* list, int index){
    if(list != NULL){
        if(index <= 0) return list->first;
        else{
            dnode_t* tmp = list->first;
            for(int i=0; i<index; i++){
                tmp = tmp->next;
                if(i>index){
                    printf("\nListe ist nicht so lang mach bessere Index.\n");
                    clearBuffer();
                    return NULL;
                }
            }
            return tmp;
        }
    }
    else{
        printf("\nliste gibt nicht. mach mal neue\n");
        clearBuffer();
        return NULL;
    }
}


void* dlist_get_data_at(dlist_t* list, int index){
    if(list != NULL){
        dnode_t* get = get_node_at(list, index);
        return get->data;
    }
    else{
        printf("\nJunge mach richtige Liste.\n");
        return NULL;
    }
}


int dlist_index_of(dlist_t *list, dnode_t *node){
    if((list != NULL) && (node != NULL)){
        int i = 0;
        for(dnode_t* tmp = list->first; tmp != node; tmp = tmp->next){
            i++;
        }
        return i;
    }
    else if(list == NULL){
        printf("\nListe ist kaputt ich brauch andere jetzt du kriegst -69.\n");
        clearBuffer();
        return -69;
    }
    else{
        printf("\nKnoten gibt es nicht ich mach jetzt -69 bei dir.\n");
        clearBuffer();
        return -69;
    }
}


int dlist_length(dlist_t* list){
    if(list != NULL){
        int i = 0;
        for(dnode_t* tmp = list->first; tmp != list->last; tmp = tmp->next){
            i++;
        }
        return i;
    }
    else{
        printf("\nListe geht nicht mach neue du Dummkopf du bist save kein taktisches Kamel.\nIch mach dir -69.\n");
        clearBuffer();
        return -69;
    }
}


void dlist_append(dlist_t* list, void* data){
    if(list != NULL){
        dnode_t* new = dnode_create(data);
        
        if(list->first != NULL){
            new->prev = list->last;
            list->last = list->last->next = new;
        }
        else{
            list->first = new;
            list->last = new;
        }
    }
    else{
        printf("\nJunge bist du behindert? Schreib mal richtige Liste jetzt.\n");
        clearBuffer();
        printf("\nReg mich nicht nochmal so auf.\n");
        clearBuffer();
    }
}


void dlist_prepend(dlist_t* list, void* data){
    if(list != NULL){
        dnode_t* new = dnode_create(data);
        
        if(list->first != NULL){
            new->next = list->first;
            list->first = list->first->prev = new;
        }
        else{
            list->first = new;
            list->last = new;
        }
    }
    else{
        printf("\nJunge bist du behindert? Schreib mal richtige Liste jetzt.\n");
        clearBuffer();
    }
}


void dlist_insert_at(dlist_t* list, int index, void* data){
    if(list != NULL){
        dnode_t* new = dnode_create(data);

        if(list->first != NULL){
            dnode_t* tmp = get_node_at(list, index);
            if(tmp == list->first) list->first = new;

            new->next = tmp;
            new->prev = tmp->prev;
            tmp->prev->next = new;
            tmp->prev = new;
        }
        else{
            list->first = new;
            list->last = new;
        }
    }
    else{
        printf("\nListe ist alle keine da.\n");
        clearBuffer();
    }
}


void dlist_remove_at(dlist_t* list, int index){
    if(index < 0){
        list->first = list->first->next;
        dnode_delete(list->first->prev);
    }
    
    if(list != NULL){
        dnode_t* rm = get_node_at(list, index);
        if(rm != list->last) dnode_delete(rm);
        else{
            list->last = list->last->prev;
            dnode_delete(rm);
        }
    }
    else{
        printf("\nListe ist schon weg entweder du dachtest er ist noch da oder du kannst nicht schreiben lern mal.\n");
    }
}



void dlist_remove_all(dlist_t* list){
    for(dnode_t* rmv = list->first; rmv != list->last->next; rmv = rmv->next){
        dnode_delete(rmv);
    }
}


dlist_t* dlist_copy(dlist_t *list){
    if(list != NULL){
        dlist_t* copy = dlist_create();
        copy->first = dlist_get_head(list);
        copy->last = dlist_get_last(list);
        return copy;
    }
    else{
        printf("\nGibt keine Liste zum Kopieren mach mal kein faxen.\n");
        clearBuffer();
        return NULL;
    }
}


void dlist_reverse(dlist_t* list){
    if(list != NULL){
        dnode_t* tmp = list->first;
        int end = dlist_length(list);
        for(int i=0; i<end; i++){
            tmp->next->prev = tmp->next->next;
            tmp->next->next = tmp;
            tmp = tmp->next;
        }
        list->last = list->first;
        list->first = tmp;
    }
    else{
        printf("\nKeine Liste hier wieso machst du so?\n");
        clearBuffer();
    }
}


void dlist_concat(dlist_t* list1, dlist_t* list2){
    if((list1 != NULL) && (list2 != NULL)){
        list2->first->prev = list1->last;
        list1->last->next = list2->first;

        list1->last = list2->last;
        list2->first = list1->first;

        dlist_remove_all(list2);
    }
    else if(list2 == NULL){
        printf("\nErste Liste gibt es nicht schreib richtig.\n");
        clearBuffer();
    }
    else{
        printf("\nZweite Liste gibt es nicht du Eierkopf\n");
    }
}