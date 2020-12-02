#include "TCircularList.h"
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct list_no List_no;

struct list{
 	List_no* end;
	List_no* next_element;
};

struct list_no{
 	struct aluno data;
	List_no* next;
};


 List* list_create() {
   List *li;

  li = malloc(sizeof(List));

    if(li != NULL)
		li -> end = NULL;
		li->next_element = NULL;

	return li;
}


 int list_free(List *li){
   if(li == NULL)
        return INVALID_NULL_POINTER;
    List_no *node,*aux;
    node = li -> end;
    while(node != node -> next){
        aux = node ;
		node = node ->next;
        free(aux);
        
    }
	free(node);
	free(aux);

    return SUCCESS;
 }


 int list_push_front(List *li, struct aluno al){
    if(li == NULL)
		return INVALID_NULL_POINTER;

	List_no* node,*aux;
	node = malloc(sizeof(List_no));

	if(node == NULL)
		return INVALID_NULL_POINTER;

		node -> data = al;
		if(li->end == NULL)
		{
			li -> end = node ;
			node -> next = node;
		}
			else {
				aux = li ->end ;
				aux -> next = node;
				node -> next = aux -> next ->next;
				
			}

			if(li->next_element == NULL || li ->next_element != li->end ){
        		li->next_element = node;
    }

			
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

	if(li->end == NULL)
		{
			li -> end = node ;
			node -> next = node;
		}
  	

    else {
        
      List_no* aux = li -> end;

			aux -> next =  node;
			node -> next = aux -> next ;
			li -> end = node ;
		      
			
    }

		
			if(li->next_element == NULL || li ->next_element == li-> end ){
        		li->next_element = node;
			}

    	return SUCCESS;

}



 int list_insert_sorted(List *li, struct aluno al){

    if(li == NULL)
	  	return INVALID_NULL_POINTER;
	
    List_no* node;
	  node = malloc(sizeof(List_no));
	  node -> data = al;
	
     if(li->end == NULL)
		{
			li -> end = node ;
			node -> next = node;
		
	    
      } else {
	    	List_no* auxnext;
		      auxnext = li -> end;
		    if(al.matricula < auxnext -> data.matricula){
			      node -> next = auxnext;
			      li -> end = node;
		  } else {
			    while((al.matricula) > (auxnext -> next -> data.matricula)){
				  auxnext = auxnext -> next;
		}
			if(auxnext == NULL)
				return ELEM_NOT_FOUND;
			else {
				node -> next = auxnext -> next;
				auxnext -> next = node;
				return SUCCESS;
			}
		}
	
	}
 }
	

	


int list_size(List *li){
  if(li == NULL)
		return INVALID_NULL_POINTER;

    if(li -> end == NULL)
        return INVALID_NULL_POINTER;
	else {
		List_no* node;
		node = li -> end;
		
    int i = 1;
		  while(node != node ->next){
			  node = node -> next;
			i++;
		}
	return i;
	}
}



 int list_pop_front(List *li){
  if(li == NULL)
		return INVALID_NULL_POINTER;

    if(li -> end == NULL)
        return INVALID_NULL_POINTER;
		 
		List_no* node,*aux;
		node = li -> end;

		if(li ->end == node->next){
			free(li);
			li == NULL;

			return SUCCESS;
		}

	else {
		aux = li -> end -> next ;
		node ->next = node ->next ->next;
		free(aux);
		
	}

	if(li->next_element == aux){
        li->next_element = aux->next;
    }
	return SUCCESS;
}



int list_pop_back(List *li){
	if(li == NULL || li -> end == NULL)
		return INVALID_NULL_POINTER;
   	List_no* node,*aux;
    node = li -> end;

	if(li ->end == node->next){
			free(li);
			li == NULL;

			return SUCCESS;
		}


	while(node -> next =! li ->end){
		aux = node;
		node = node -> next;
		
	}

	aux -> next = node ->next ;
    free(node);

	if(li->next_element == li->end)
        li->next_element = node->next;
	
	return SUCCESS;
}
 

int list_erase_data(List *li, int nmat){
  if(li == NULL)
		return INVALID_NULL_POINTER;
	
  List_no* node;
	node = li -> end;
	List_no* aux;
	aux = node -> next;
	
  if(nmat == node -> data.matricula){
		li -> end = node -> next;
	} else {
		while(nmat != node -> next -> data.matricula){
			aux = node -> next -> next -> next;
			node = node -> next;
	}
		node -> next = aux;
	}

	if(li->next_element == node)
        li->next_element = node -> next;
	return SUCCESS;
}




int list_find_pos(List *li, int pos, struct aluno *al){

    if(li == NULL || li -> end == NULL || pos <= 0)
		return INVALID_NULL_POINTER;
    List_no *node;

	node = li -> end;
	int i = 1;
	while(node != node ->next && i < pos){
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

    if(li == NULL || li -> end == NULL)
		return INVALID_NULL_POINTER;

	List_no* node;
	node = li->end;

	while(node != node ->next && node -> data.matricula != nmat){
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
    
    if(li == NULL || li->end == NULL)
        return INVALID_NULL_POINTER;
    
    List_no *node;
	node = li -> end ->next;
    *al = node->data;
    return SUCCESS;
}


int list_back(List *li, struct aluno *al){
    if(li == NULL || li->end == NULL)
        return INVALID_NULL_POINTER;

    List_no *node;
    node = li->end;

    *al = node -> data;
    return SUCCESS;
}


int list_get_pos(List *li, int nmat, int *pos){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_no* node;
    node = li->end;
    int i = 1;

    while(node != node ->next  && node->data.matricula != nmat){
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
    node = li->end;
    while(node != node ->next){
        printf("%d, ", node -> data.matricula);
        printf("%s, ", node -> data.nome);
        printf("%f, %f, %f ", node -> data.n1, node -> data.n2, node -> data.n3);
        printf("\n");
        node = node -> next;
    }

	 
		
  return SUCCESS;
}

int list_next (List *li, struct aluno *al){
    if(li == NULL)
        return INVALID_NULL_POINTER;

    List_no *aux = li->next_element;

    al->matricula = aux->data.matricula;
	strcpy(al->matricula, aux->data.nome);
	al->n1 = aux->data.n1;
	al->n2 = aux->data.n2;
	al->n3 = aux->data.n3;

    li->next_element = aux->next;
}

