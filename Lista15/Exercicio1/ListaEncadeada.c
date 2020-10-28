#include "ListaEncadeada.h"
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct list_no List_no;

struct list{
 	List_no* head;
};

struct list_no{
 	struct aluno data;
	List_no* next;
};


 List* list_create() {
   List *li;

  li = malloc(sizeof(List));

    if(li != NULL)
		li -> head = NULL;

	return li;
}


 int list_free(List *li){
   if(li == NULL)
        return INVALID_NULL_POINTER;
    List_no *node;
    node = li -> head;
    while(node != NULL){
        li -> head = node -> next;
        free(node);
        node = li -> head;
    }

    return SUCCESS;
 }


 int list_push_front(List *li, struct aluno al){
    if(li == NULL)
		return INVALID_NULL_POINTER;

	List_no* node;
	node = malloc(sizeof(List_no));

	if(node == NULL)
		return INVALID_NULL_POINTER;

	node -> data = al;

	node -> next = li -> head;
	li -> head = node;

	
	return SUCCESS;
}



int list_push_back(List *li, struct aluno al){
  if(li == NULL)
		return INVALID_NULL_POINTER;

	List_no* node;
	node = malloc(sizeof(List_no));

	if(node == NULL)
		return INVALID_NULL_POINTER;

    node -> data = al;
  	node -> next = NULL;

  if(li -> head == NULL){
		li -> head = node;
	
	  }
    else {
        
      List_no* aux = li -> head;
        while(aux -> next != NULL){
			    aux = aux -> next;
		}
		      aux -> next = node;
			
    }
    	return SUCCESS;
}


    int list_insert(List *li, int pos, struct aluno al){
    
     if(li == NULL)
		    return INVALID_NULL_POINTER;
	
    List_no* node;
	    node = malloc(sizeof(List_no));
	      node -> data = al;
	      int i = 1;
	      
        if(li -> head == NULL){
		      node -> next = NULL;
	      	li -> head = node;
	        } else {
		
      List_no* aux;
		    aux = li -> head;
		      while(aux != NULL && i < pos -1){
			      aux = aux -> next;
			      i++;
		  }
		
    if(aux == NULL){
			return ELEM_NOT_FOUND;
		} else {
			node -> next = aux -> next;
			aux -> next = node;
		}
	}
	return SUCCESS;
}


 int list_insert_sorted(List *li, struct aluno al){

    if(li == NULL)
	  	return INVALID_NULL_POINTER;
	
    List_no* node;
	  node = malloc(sizeof(List_no));
	  node -> data = al;
	
      if(li -> head == NULL){
		    node -> next = NULL;
		    li -> head = node;
	    
      } else {
	    	List_no* auxnext;
		      auxnext = li -> head;
		    if(al.matricula < auxnext -> data.matricula){
			      node -> next = auxnext;
			      li -> head = node;
		  } else {
			    while((al.matricula) > (auxnext -> next -> data.matricula)){
				  auxnext = auxnext -> next;
		}
			if(auxnext == NULL)
				return ELEM_NOT_FOUND;
			else {
				node -> next = auxnext -> next;
				auxnext -> next = node;
			}
		}
	}
	return SUCCESS;
}

int list_size(List *li){
  if(li == NULL)
		return INVALID_NULL_POINTER;

    if(li -> head == NULL)
        return INVALID_NULL_POINTER;
	else {
		List_no* node;
		node = li -> head;
		
    int i = 1;
		  while(node -> next != NULL){
			  node = node -> next;
			i++;
		}
	return i;
	}
}



 int list_pop_front(List *li){
  if(li == NULL)
		return INVALID_NULL_POINTER;

    if(li -> head == NULL)
        return INVALID_NULL_POINTER;

	else {
		List_no *node;
		node = li -> head;
		li -> head = node -> next;
	}
	return SUCCESS;
}



int list_pop_back(List *li){
	if(li == NULL || li -> head == NULL)
		return INVALID_NULL_POINTER;
    List_no* node;
    node = li -> head;

	if(node -> next == NULL){
		li -> head = NULL;
		return SUCCESS;
	}

	while(node -> next -> next != NULL)
		node = node -> next;
    node -> next = NULL;
	return SUCCESS;
}
 

int list_erase_data(List *li, int nmat){
  if(li == NULL)
		return INVALID_NULL_POINTER;
	
  List_no* node;
	node = li -> head;
	List_no* aux;
	aux = node -> next;
	
  if(nmat == node -> data.matricula){
		li -> head = node -> next;
	} else {
		while(nmat != node -> next -> data.matricula){
			aux = node -> next -> next -> next;
			node = node -> next;
	}
		node -> next = aux;
	}
	return SUCCESS;
}


int list_erase_pos(List *li, int pos){
  if(li == NULL)
		return INVALID_NULL_POINTER;
	
  List_no* node;
	node = li -> head;
	List_no* aux;
	aux = node -> next;
  int i=1;
  
  if(pos == 1){
		node = li -> head;
	} else {
		while(node != NULL && i < pos){
			aux = node -> next -> next ;
		  i ++;
	}
		node -> next = aux;
	}
	return SUCCESS;

  
}

int list_find_pos(List *li, int pos, struct aluno *al){

    if(li == NULL || li -> head == NULL || pos <= 0)
		return INVALID_NULL_POINTER;
    List_no *node;

	node = li -> head;
	int i = 1;
	while(node != NULL && i < pos){
		node = node -> next;
		i++;
	}

	if(node == NULL)
		return ELEM_NOT_FOUND;
	else {
		*al = node -> data;
		return SUCCESS;
	}
}
  


int list_find_mat(List *li, int nmat, struct aluno *al){

    if(li == NULL || li -> head == NULL)
		return INVALID_NULL_POINTER;

	List_no* node;
	node = li->head;

	while(node != NULL && node -> data.matricula != nmat){
		node = node -> next;
	}
	if (node == NULL){
		return ELEM_NOT_FOUND;
	} else {
		*al = node -> data;
		return SUCCESS;
	}
}

int list_front(List *li, struct aluno *al){
    
    if(li == NULL || li->head == NULL)
        return INVALID_NULL_POINTER;
    
    List_no *node;
    node = li->head;
    *al = node->data;
    return SUCCESS;
}


int list_back(List *li, struct aluno *al){
    if(li == NULL || li->head == NULL)
        return INVALID_NULL_POINTER;

    List_no *node;
    node = li->head;

    while(node -> next != NULL)
        node = node -> next;
    *al = node -> data;
    return SUCCESS;
}


int list_get_pos(List *li, int nmat, int *pos){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_no* node;
    node = li->head;
    int i = 1;

    while(node != NULL && node->data.matricula != nmat){
        node = node -> next;
        i++;
    }
    if (node == NULL)
        return INVALID_NULL_POINTER;
    *pos = i;
    return SUCCESS;
}

int list_print(List *li){
    if(li == NULL)
        return INVALID_NULL_POINTER;
    List_no *node;
    node = li->head;
    while(node != NULL){
        printf("%d, ", node -> data.matricula);
        printf("%s, ", node -> data.nome);
        printf("%f, %f, %f ", node -> data.n1, node -> data.n2, node -> data.n3);
        printf("\n");
        node = node -> next;
    }
  return SUCCESS;
}

