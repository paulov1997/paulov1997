#include "TStack.h"
#include <stdlib.h>
#include <string.h>

struct stack {
    char c[MAX];
    int size;
};

Stack *stack_create(){
    Stack *st;
    st = malloc (sizeof(struct stack));

    if(st == NULL)
        return 0;

    st->size=0;
    return st;
}

int stack_free(Stack *st){
    if(st == NULL)
        return 0;

    free(st);
    return 1;
}

int stack_push(Stack *st, char c){
    if(st == NULL)
        return 0;

    st->c[st->size] = c;
    st->size++;
    return 1;
}

int stack_pop(Stack *st){
    if(st == NULL || st->size == 0)
        return 0;

    st->size--;
    return 1;
}

int stack_top(Stack *st, char *c){
    if(st == NULL || st->size == 0)
        return 0;
    
    c[0] = st->c[st->size-1];
    return 1;
}

int stack_empty(Stack *st){
    if(st == NULL)
        return 0;

    return (st->size == 0);
}

int stack_size(Stack *st){
    if(st == NULL)
        return 0;

    return st->size;
}