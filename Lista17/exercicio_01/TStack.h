#include "..\aluno.h"
#ifndef TStackh
#define TStackh

#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2



typedef struct TStack TStack;


TStack *stack_create();
int stack_free(TStack *st);

int stack_push (TStack *st, struct aluno al);
int stack_pop (TStack *st);

int stack_empty (TStack *st);
int stack_size (TStack *st);

#endif