#include "../ListaEncadeada.h"
#include "TQueue.h"
#include <stdlib.h>

struct TQueue {
    List *data;
};

TQueue *queue_create(){
    TQueue *st;
    st = malloc (sizeof(TQueue));

    if(st != NULL){
        st->data = list_create();
        if(st->data == NULL){
            free(st);
            st = NULL;
        }
    }
    return st;
}

int queue_free(TQueue *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return free_list(st->data);
}

int queue_push (TQueue *st, struct aluno al){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_push_back (st->data, al);
}

int queue_pop (TQueue *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_pop_front (st->data);
}




int queue_size (TQueue *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_size (st->data);
}