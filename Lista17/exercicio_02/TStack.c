#include "..\lista_encadeada.h"
#include "TStack.h"
#include <stdlib.h>

struct TStack {
    List *data;
};

TStack *stack_create(){
    TStack *st;
    st = malloc (sizeof(TStack));

    if(st != NULL){
        st->data = list_create();
        if(st->data == NULL){
            free(st);
            st = NULL;
        }
    }
    return st;
}

int stack_free(TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_pop_front(st->data);
}

int stack_push (TStack *st, struct aluno al){
    if(st == NULL)
        return INVALID_NULL_POINTER;
    
    return list_push_front (st->data, al);
}

int stack_pop (TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_pop_front (st->data);
}

int stack_top (TStack *st, struct aluno *al){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_front(st->data, al);
}

int stack_empty (TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

}
int stack_size (TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return list_size(st->data);
}