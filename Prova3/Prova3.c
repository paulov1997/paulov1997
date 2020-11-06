//Exercicio 1 

//A

int list_erase_even(List *li){
    if(li == NULL|| li->begin == NULL)
        return -1;
   

    DLNNode *node;
    node = li->begin;
    
  
    
    while( node != NULL){
      if( node -> data % 2 == 0  ){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);

        }
        node = node->next;
       
    }
   
    return 1;
}


//B foi feito desenho em imagem JPG

//C

int list_splice(List *dest, List *source, int pos) {
    if(dest == NULL)
        return -1;

      if(source == NULL)
        return -1;

    if(dest->size < pos|| pos <1 ){
       
        return -1;
    }

    DLNode *node,*node2;
    node = dest->begin;
    
    
    int i = 1;
    while(i<pos && node != NULL){
        node = node->next;
        i++;
    }
    node2  = node->prev;
    node2->next  = source-> begin;
    node = source->end;



    
    return 1;
}


//2


int verifica(char *s){

		Stack pilha*;
		pilha = stack_create();
		for(int i = 0; s[i] != '\0'; i++){
			char *c;
				switch (s[i]){
					case ')':
						if(stack_empty(pilha))
							return 0;
						stack_top(pilha, c);
						if(c != '(')
							return 0;
						stack_pop(pilha);
							break;

						case ']':
						if(stack_empty(pilha))
							return 0;
						stack_top(pilha, c);
						if(c != '[')
							return 0;
						stack_pop(pilha);
						break;

            default: stack_push(pilha, s[i]);
        }
    }   
}

