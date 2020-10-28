#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaEnca.h"

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct list_no List_no;
struct list{
    List_no *begin;
    List_no *end;
    int size;
};
struct list_no{
    struct aluno data;
    List_no *next;
    List_no *prev;
};

List* list_create(){
    List *li = malloc(sizeof(List));
    if(li == NULL)
        return INVALID_NULL_POINTER;
    li->size = 0;
    li->begin = NULL;
    li->end = NULL;
    return li;
}

int list_free(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    List_no *node;
    node = li->begin;
    while(node != NULL){
        li->begin = node ->next;
        free(node);
        node = li -> begin;
    }

    return  SUCCESS;
}


int list_push_front(List *li, struct aluno al){
    if(li == NULL || li -> begin == NULL)
        return INVALID_NULL_POINTER;
    List_no *node = malloc(sizeof(List_no));
    if(node == NULL)
        return INVALID_NULL_POINTER;
    node->data = al;
    node->prev = NULL;
    node->next = li-> begin;
    if(li->size == 0){
        node->next = NULL;
        li->begin = node;
        li->end = node;
        li->size++;
    }
    else{
        li->begin->prev = node;
        li->begin = node;
        li->size++;
    }
    return SUCCESS;
}

int list_push_back(List *li, struct aluno al){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    List_no *node = malloc(sizeof(List_no));
    if(node == NULL)
        return INVALID_NULL_POINTER;
    node->data = al;
    node->next = NULL;
    node->prev = li->end;
    if(li->size == 0){
        li->begin = node;
        li->end = node;
        li->size++;
    }
    else{
        li->end->next = node;
        li->end = node;
        li->size++;
    }
    return SUCCESS;
}

int list_insert(List *li, int pos, struct aluno al){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    if(pos>li->size || pos<=0)
        return OUT_OF_MEMORY;
    List_no *aux;
    List_no *node = malloc(sizeof(List_no));
    if(node == NULL)
        return INVALID_NULL_POINTER;
    if(pos == 1){
        node->data = al;
        node->prev = NULL;
        node->next = li->begin;
        li->begin->prev = node;
        li->begin = node;
        li->size++;
        return SUCCESS;
    }
    aux = li->begin;
    int i = 1;
    while(i<pos && aux != NULL){
        aux = aux->next;
        i++;
    }
    node->data = al;
    node->prev = aux->prev;
    node->next = aux;
    node->prev->next = node;
    node->next->prev = node;
    li->size++;
    return SUCCESS;
}

int list_size(List *li){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    return li->size;
    }

int list_pop_front(List *li){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0)
        return ELEM_NOT_FOUND;
    if(li->size == 1){
        free(li->begin);
        li->begin = NULL;
        li->end = NULL;
        li->size--;
    }
    List_no *node;
    node = li->begin;
    li->begin->next->prev = NULL;
    li->begin = li->begin->next;
    free(node);
    li->size--;
    return SUCCESS;
}

int list_pop_back(List *li){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0)
        return ELEM_NOT_FOUND;
    if(li->size == 1){
        free(li->begin);
        li->begin = NULL;
        li->end = NULL;
        li->size--;
    }
    List_no *node;
    node = li->end;
    li->end->prev->next = NULL;
    li->end = li->end->prev;
    free(node);
    li->size--;
    return SUCCESS;
}

int list_erase(List *li, int pos){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    if(pos>li->size || pos<=0)
        return OUT_OF_MEMORY;
    if(li->size == 1){
        free(li->begin);
        li->begin = NULL;
        li->end = NULL;
        li->size--;
        return SUCCESS;
    }
    List_no *node, *node2;
    node = li->begin;
    node2 = li->end;
    if(pos == 1){
        li->begin->next->prev = NULL;
        li->begin = li->begin->next;
        free(node);
        li->size--;
        return SUCCESS;
    }
    if(pos == li->size){
        li->end->prev->next = NULL;
        li->end = li->end->prev;
        free(node2);
        li->size--;
        return SUCCESS;
    }
    int i = 1;
    while(i<pos && node != NULL){
        node = node->next;
        i++;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return SUCCESS;
}

int list_find_pos(List *li, int pos, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0 || pos<=0 || pos>li->size)
        return ELEM_NOT_FOUND;
    List_no *node;
    node = li->begin;
    int i = 1;
    while(i<pos && node != NULL){
        node = node->next;
        i++;
    }
    if(node == NULL)
		return INVALID_NULL_POINTER;
    *al = node->data;
    return SUCCESS;
}

int list_find_mat(List *li, int nmat, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0)
        return ELEM_NOT_FOUND;
    List_no *node;
    node = li->begin;
    int i = 1;
    while(nmat != node->data.matricula && node != NULL){
        node = node->next;
        i++;
    }
    if(node == NULL)
		return INVALID_NULL_POINTER;
    *al = node->data;
    return SUCCESS;

}




int list_front(List *li, struct aluno *al){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0)
        return ELEM_NOT_FOUND;
    *al = li->begin->data;
    return SUCCESS;
    }

int list_back(List *li, struct aluno *al){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0)
        return ELEM_NOT_FOUND;
    *al = li->end->data;
    return SUCCESS;
    }


int list_get_pos(List *li, int nmat, int *pos){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    if(li->size == 0)
        return ELEM_NOT_FOUND;
    List_no *node;
    node = li->begin;
    int i = 1;
    while(nmat != node->data.matricula && node != NULL){
        node = node->next;
        i++;
    }
    if(node == NULL)
        return ELEM_NOT_FOUND;
    *pos = i;
    return SUCCESS;
}

int list_print_forward(List *li){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    List_no *node;
    node = li->begin;
    while(node != NULL){
        printf("%d, ", node->data.matricula);
        printf("%s, ", node->data.nome);
        printf(" %f , %f , %f \n", node->data.n1,node->data.n2, node->data.n3);
        node = node->next;
    }
    return SUCCESS;
}
    int list_print_reverse(List *li){
    if(li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;
    List_no *node;
    node = li->end;
    while(node != NULL){
        printf("%d ,", node->data.matricula);
        printf("%s ,", node->data.nome);
        printf(" %f , %f , %f \n", node->data.n1,node->data.n2, node->data.n3);
        node = node->prev;
    }
    return SUCCESS;
}

