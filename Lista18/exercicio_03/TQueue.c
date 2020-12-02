#include "TQueue.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>


struct dqueue {
    int size_begin;
    int size_current;
    int front;
    int rear;
    int size;
    struct aluno *data;
 };

DQueue *queue_create(int tamanho){

    DQueue *li;
    li = (DQueue *) malloc (sizeof(struct dqueue));

    if(li != NULL){
       li->front = 0;
        li->rear = 0;
        li->size = 0;
        li->size_begin = tamanho;
        li->size_current = tamanho; 
        printf("%d", li->size_current);

        li-> data = malloc (li->size_current * sizeof(struct aluno));
        
         
    }
    return li;
}

int queue_free(DQueue *li){
    if (li == NULL)
        return INVALID_NULL_POINTER;

    free(li);

    return SUCCESS;
}

int queue_get(DQueue *li, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    int i = li->rear - 1;
    if(li->rear == 0 && li->size > 0){
        i = li->size_current -1;
    }

    al[0].matricula = li->data[i].matricula;
	strcpy(al[0].nome,li->data[i].nome);
	al[0].n1 = li->data[i].n1;
	al[0].n2 = li->data[i].n2;
	al[0].n3 = li->data[i].n3;

    return SUCCESS;
}

int queue_push (DQueue *li, struct aluno al){
    if (li == NULL)
        return INVALID_NULL_POINTER;

    if (li->rear == li->front || li->rear != 0){
        int i=li->front+1;
        int j=0;
        struct aluno *aux = malloc (li->size_current * sizeof (struct aluno));

        if (aux == NULL)
            return OUT_OF_MEMORY;
        
        aux[j].matricula = li->data[li->front].matricula;
	    strcpy(aux[j].nome,li->data[li->front].nome);
	    aux[j].n1 = li->data[li->front].n1;
	    aux[j].n2 = li->data[li->front].n2;
	    aux[j].n3 = li->data[li->front].n3;
        
        j++;

        while (i != li->front){

            if(i == li->size_current){
                i = 0;
            }

            aux[j].matricula = li->data[i].matricula;
	        strcpy(aux[j].nome,li->data[i].nome);
	        aux[j].n1 = li->data[i].n1;
	        aux[j].n2 = li->data[i].n2;
	        aux[j].n3 = li->data[i].n3;
            j++;
            i++;
        }

        li->size_current += li->size_begin;
        li = realloc (li->data, li->size_current * sizeof(struct aluno));

        if(li->data == NULL){
            free(aux);
            return OUT_OF_MEMORY;
        }

        for(i = 0; i <= j; i++){
            li->data[i].matricula = aux[i].matricula;
	        strcpy(li->data[i].nome,aux[i].nome);
	        li->data[i].n1 = aux[i].n1 ;
	        li->data[i].n2 = aux[i].n2;
	        li->data[i].n3 = aux[i].n3;
        }

        li->front = 0;
        li->rear = i;
        free(aux);
    }

    li->data[li->rear].matricula = al.matricula;
	strcpy(li->data[li->rear].nome,al.nome);
	li->data[li->rear].n1 = al.n1;
	li->data[li->rear].n2 = al.n2;
	li->data[li->rear].n3 = al.n3;

    if(li->rear + 1  == li->size_current || li->front != 0)
        li->rear = 0;

    li->rear++;
    li->size++;
    return SUCCESS;
}  

int queue_pop (DQueue *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->front + 1 == li->size_current){
        li->front = 0;
        li->size--;
        return SUCCESS;
    }

    li->front++;
    li->size--;
    return SUCCESS;
}

int queue_size (DQueue *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    return li->size;
}

int queue_compact (DQueue *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->size_current - li->size < li->size_begin)
        return NO_ACTION_REQUIRED;

    if(li->front == 0){
        li->size_current = ceil(li->size / li->size_begin) * li->size_begin;
	    li =realloc(li->data, li->size_current * sizeof(struct aluno));

        return SUCCESS;
    }

    int i=li->front+1;
    int j=0;
    struct aluno *aux = malloc (li->size_current * sizeof (struct aluno));

    if (aux == NULL)
        return OUT_OF_MEMORY;
        
    aux[j].matricula = li->data[li->front].matricula;
	strcpy(aux[j].nome,li->data[li->front].nome);
	aux[j].n1 = li->data[li->front].n1;
	aux[j].n2 = li->data[li->front].n2;
	aux[j].n3 = li->data[li->front].n3;
        
    j++;

    while (i != li->front){

        if(i == li->size_current){
            i = 0;
        }

        aux[j].matricula = li->data[i].matricula;
	    strcpy(aux[j].nome,li->data[i].nome);
	    aux[j].n1 = li->data[i].n1;
	    aux[j].n2 = li->data[i].n2;
	    aux[j].n3 = li->data[i].n3;
        j++;
        i++;
    }
    li->size_current = ceil(li->size / li->size_begin) * li->size_begin;
	li = realloc(li->data, li->size_current * sizeof(struct aluno));

    for(i = 0; i <= j; i++){
        li->data[i].matricula = aux[i].matricula;
	    strcpy(li->data[i].nome,aux[i].nome);
	    li->data[i].n1 = aux[i].n1 ;
	    li->data[i].n2 = aux[i].n2;
	    li->data[i].n3 = aux[i].n3;
    }

    li->front = 0;
    li->rear = i;
    free(aux);

    return SUCCESS;
}

int queue_full (DQueue *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    if(li->size == li->size_current)
        return QUEUE_FULL;

    return QUEUE_EMPTY;
}