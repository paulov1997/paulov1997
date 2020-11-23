#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"


struct TStack{
	int qtd;
	int size;
	char *xar;
};

TStack* stack_create(int size){
	TStack *st;	
	st = malloc(sizeof(struct TStack));
	
	if(st == NULL)
		return OUT_OF_MEMORY;

	st->qtd = 0;
	st->size = size;
	st->xar = malloc(sizeof(size));

	return st;
}

int stack_free(TStack* st){
	if(st == NULL)
		return INVALID_NULL_POINTER;

	free(st);
	return SUCESS;
}

int stack_push(TStack* st, char xar){
	if(st == NULL)
		return INVALID_NULL_POINTER;

	st->xar[st->qtd] = xar;
	st->qtd++;
	
	return SUCESS;  
}

int stack_pop(TStack* st){
	if(st == NULL)
		return INVALID_NULL_POINTER;
	
	if(st->qtd == 0)
		return OUT_OF_RANGE;

	st->qtd--;
	free(st->xar[st->qtd]);
	
	return SUCESS;
}

int stack_size(TStack* st){
	if(st == NULL)
		return INVALID_NULL_POINTER;
	
	return st->size;
}

int stack_full(TStack* st){
	if(st == NULL)
		return INVALID_NULL_POINTER;
	
	return (st->qtd == st->size);
}

int stack_empty(TStack* st){
	if(st == NULL)
		return INVALID_NULL_POINTER;
	
	return (st->qtd == 0);
}