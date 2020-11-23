#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

typedef struct List_node List_node;

typedef struct List List;

struct List_node{
	struct aluno data;
	List_node *next;
}list_node;

struct List {
	List_node *head;
};

List* list_create(){
	List *li;
	
	li = malloc (sizeof(struct List));
	
	if (li == NULL)
		return -2;
	
	li->head = NULL;
	return li;
}

int free_list(List *li){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL){
		free(li);
		return 0;
	}
	
	List_node *aux = li->head;
	List_node *aux_free;
	
	while (aux != NULL){
		aux_free = aux;
		aux = aux->next;
		free(aux_free);
	}
	return 0;
}

int list_push_front (List *li, struct aluno al){
	if (li == NULL)
		return -1;
		
	List_node* new_node = malloc (sizeof (struct List_node));
	
	if(new_node == NULL)
		return -2;
	
	new_node->data.matricula = al.matricula;
	strcpy(new_node->data.nome,al.nome);
	new_node->data.n1 = al.n1;
	new_node->data.n2 = al.n2;
	new_node->data.n3 = al.n3;

	new_node->next = li->head;
	li->head = new_node;

	return 0;
}

int list_push_back (List *li, struct aluno al){
	if (li == NULL)
		return -1;
		
	List_node *new_node = malloc (sizeof(struct List_node));
	
	if(new_node == NULL)
		return -2;
	
	new_node->data.matricula = al.matricula;
	strcpy(new_node->data.nome,al.nome);
	new_node->data.n1 = al.n1;
	new_node->data.n2 = al.n2;
	new_node->data.n3 = al.n3;
	new_node->next = NULL;
	
	if(li->head == NULL){
		li->head = new_node;
		return 0;
	}
	
	List_node *aux = li->head;

	while (aux->next != NULL){
		aux = aux->next;
	}
	
	aux->next = new_node;
	
	return 0;
}

int list_insert_pos (List *li, int pos, struct aluno al){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL)
		return -3;
		
	if(pos < 1)
		return -3;
	
	List_node* new_node = malloc (sizeof(struct List_node));

	new_node->data.matricula = al.matricula;
	strcpy(new_node->data.nome,al.nome);
	new_node->data.n1 = al.n1;
	new_node->data.n2 = al.n2;
	new_node->data.n3 = al.n3;
	new_node->next = NULL;
	
	if(li->head == NULL && pos == 1){
		li->head = new_node;
		return 0;
	}

	int size = 1;

	List_node *aux_next = li->head;
	List_node *aux_prev;
	
	while (size < pos){
		if(aux_next->next == NULL)
			return -3;
		
		aux_prev = aux_next;
		aux_next = aux_next->next;
		size++;
	}
	
	aux_prev->next = new_node;
	new_node->next = aux_next;
	return 0;	
}

int list_insert_sorted (List *li, struct aluno al){
	if(li == NULL)
		return -1;
		
	List_node *new_node = malloc (sizeof(List_node));
	
	new_node->data.matricula = al.matricula;
	strcpy(new_node->data.nome,al.nome);
	new_node->data.n1 = al.n1;
	new_node->data.n2 = al.n2;
	new_node->data.n3 = al.n3;
	new_node->next = NULL;
	
	if(li->head == NULL){
		li->head = new_node;
		return 0;
	}
	
	List_node* aux_next = li->head;
	List_node* aux_prev;
	
	if((aux_next->next == NULL) && (new_node->data.matricula < aux_next->data.matricula)){
		new_node->next = li->head;
		li->head = new_node;
		return 0;
	}

	while (new_node->data.matricula > aux_next->data.matricula){
		aux_prev = aux_next;
		aux_next = aux_next->next;
	}

	aux_prev->next = new_node;
	new_node->next = aux_next;
	return 0;
}

int list_size (List *li){
	if(li == NULL)
		return -1;
	
	int size = 0;
		
	if(li->head == NULL)
		return size;
	
	List_node *aux = li->head;
	size++;
	
	while (aux->next != NULL)
		size++;
		
	return size;
}

int list_pop_front (List *li){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL)
		return -3;
	
	List_node *aux = li->head;
	List_node *aux_free = li->head;
	aux = aux->next;
	li->head = aux;
	free(aux_free);

	return 0;
}

int list_pop_back (List *li){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL)
		return -3;
		
	List_node *aux = li->head;
	List_node *aux_prev;

	if(aux->next == NULL){
		li->head = NULL;
		free(aux);
		return 0;
	}
	
	while(aux->next != NULL){
		aux_prev = aux;
		aux = aux->next;
	}

	aux_prev->next = NULL;
	free(aux);
			
	return 0;
}

int list_erase (List *li, int pos){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL)
		return -3;
	
	if(pos < 1)
		return -3;
	
	int size = 1;
	List_node *aux_next = li->head;
	List_node *aux_prev;
	
	while(size != pos){
		
		if(aux_next->next == NULL && size < pos)
			return -3;
		
		aux_prev = aux_next;
		aux_next = aux_next->next;
		size++;
	}
	
	if(pos == 1 && size == 1){
		free(aux_next);
		li->head = NULL;
	}
	
	aux_prev->next = aux_next->next;
	free(aux_next);
	return 0;
}

int list_find_pos(List *li, int pos, struct aluno *al){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL)
		return -3;
		
	if(pos < 1)
		return -3;
	
	int cont = 1;
	List_node *aux = li->head;

	while (cont < pos){
		if(aux->next == NULL)
			return -3;

		aux = aux->next;
		cont++;
	}

	al->matricula = aux->data.matricula;
	strcpy(al->matricula, aux->data.nome);
	al->n1 = aux->data.n1;
	al->n2 = aux->data.n2;
	al->n3 = aux->data.n3;

	return 0;
}

int list_find_mat(List *li, int nmat, struct aluno *al){
	if(li == NULL)
		return -1;
	
	if(li->head == NULL)
		return -3;
		
	int cont = 1;
	List_node* aux = li->head;
	
	while (aux != NULL){
		if(aux->data.matricula == nmat)
			return cont;
		
		aux = aux->next;
		cont++;
	}	
	return -4;
}

int list_front(List *li, struct aluno *al){
	if(li == NULL)
		return -1;
	
	if(li->head == NULL)
		return -3;

	List_node* aux = li->head;

	al->matricula = aux->data.matricula;
	strcpy(al->matricula, aux->data.nome);
	al->n1 = aux->data.n1;
	al->n2 = aux->data.n2;
	al->n3 = aux->data.n3;

	return 0;
}

int list_back(List *li, struct aluno *al){
	if(li == NULL)
		return -1;
	
	if(li->head == NULL)
		return -3;

	List_node* aux = li->head;

	while(aux->next != NULL)
		aux = aux->next;
	
	al->matricula = aux->data.matricula;
	strcpy(al->matricula, aux->data.nome);
	al->n1 = aux->data.n1;
	al->n2 = aux->data.n2;
	al->n3 = aux->data.n3;

	return 0;
}

int list_get_pos(List *li, int nmat, int *pos){
	if(li == NULL)
		return -1;
	
	if(li->head == NULL)
		return -3;

	List_node* aux = li->head;
	int cont = 1;

	while(aux != NULL){
		if(aux->data.matricula == nmat){
			pos = cont;
			return 0;
		}
	}
	return -4;
}

int list_print (List *li){
	if(li == NULL)
		return -1;
		
	if(li->head == NULL)
		return -3;
		
	List_node *aux = li->head;
	
	while (aux != NULL){
		printf("\nNome: %s",aux->data.nome);
		printf("\nMatricula: %d",aux->data.matricula);
		printf("\nNota 1: %.1lf",aux->data.n1);
		printf("\nNota 2: %.1lf",aux->data.n2);
		printf("\nNota 3: %.1lf",aux->data.n3);
		
		aux = aux->next;
	}
	return 0;
}