#ifndef ListaEncadeada
#define ListaEncadeada


#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#include "aluno.h"

typedef struct List List;


List* list_create();
int free_list(List *li);

int list_push_front (List *li, struct aluno al);
int list_push_back (List *li, struct aluno al);
int list_insert(List *li, int pos, struct aluno al);
int list_insert_sorted (List *li, struct aluno al);
int list_size (List *li);


int list_pop_front (List *li);
int list_pop_back (List *li);

int list_erase_data(List *li, int mat);
int list_erase_pos(List *li, int pos);

int list_find_pos(List *li, int pos, struct aluno *al);
int list_find_mat(List *li, int nmat, struct aluno *al);

int list_front(List *li, struct aluno *al);
int list_back(List *li, struct aluno *al);

int list_get_pos(List *li, int nmat, int *pos);

int list_print (List *li);

#endif