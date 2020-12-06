#define MAX 100

typedef struct stackInt StackInt;

StackInt *stackInt_create();
int stackInt_free(StackInt *st);

int stackInt_push(StackInt *st, int *c);
int stackInt_pop(StackInt *st);

int stackInt_top(StackInt *st, int *c);

int stackInt_empty(StackInt *st);
int stackInt_size(StackInt *st);