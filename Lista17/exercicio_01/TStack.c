#include "..\ListaSequencial.h"
#include "TStack.h"
#include <stdlib.h>

struct TStack {
    Lista *data;
};

TStack *stack_create(){
    TStack *st;
    st = malloc (sizeof(TStack));

    if(st != NULL){
        st->data = cria_lista();
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
    
    return libera_lista(st->data);
}

int stack_push (TStack *st, struct aluno al){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return insere_lista_final (st->data, al);
}

int stack_pop (TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return remove_lista_final (st->data);
}

int stack_empty (TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return lista_vazia (st->data);

}

int stack_size (TStack *st){
    if(st == NULL)
        return INVALID_NULL_POINTER;

    return tamanho_lista (st->data);
}