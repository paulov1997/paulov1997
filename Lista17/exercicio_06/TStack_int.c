#include "TStack_int.h"
#include <stdlib.h>
#include <string.h>

struct stackInt {
    int c[MAX];
    int size;
};

StackInt *stackInt_create(){
    StackInt *st;
    st = malloc (sizeof(struct stackInt));

    if(st == NULL)
        return 0;

    st->size=0;
    return st;
}

int stackInt_free(StackInt *st){
    if(st == NULL)
        return 0;

    free(st);
    return 1;
}

int stackInt_push(StackInt *st, int *c){
    if(st == NULL)
        return 0;

    st->c[st->size] = *c;
    st->size++;
    return 1;
}

int stackInt_pop(StackInt *st){
    if(st == NULL || st->size == 0)
        return 0;

    st->size--;
    return 1;
}

int stackInt_top(StackInt *st, int *c){
    if(st == NULL || st->size == 0)
        return 0;
    
    *c = st->c[st->size-1];
    return 1;
}

int stackInt_empty(StackInt *st){
    if(st == NULL)
        return 0;

    return (st->size == 0);
}

int stackInt_size(StackInt *st){
    if(st == NULL)
        return 0;

    return st->size;
}