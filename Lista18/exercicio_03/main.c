#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"
#include "../aluno.h"

int main(){
	int valor,i;
	struct aluno a[10] = {{2,"Andre",9.5,7.8,8.5},
						{4,"Ricardo",7.5,8.7,6.8},
						{1,"Bianca",9.7,6.7,8.4},
						{3,"Ana",5.7,6.1,7.4},
            {5,"Paulo",5.7,6.1,7.4},
            {6,"Pedro",5.7,6.1,7.4},
            {7,"Joao",5.7,6.1,7.4}};
						
	printf("\nDigite o tamanho da lista ");
	scanf("%d",&valor);
	

	TQueue* li = queue_create(valor);
	printf("\nLista criada com sucesso, tamanho da lista: %d!",tamanho_lista(li));
	

	


      for(i=5;i<8;i++) {
        	printf("\n\nInserindo dados no fim da lista!");
          queue_push(li,a[i]);

  }
  
	  
	
	printf("\n\nTamanho atual da lista: %d!",queue_size(li));
	
	

	
	printf("\n\nRemovendo dados no inicio da lista!");
	queue_pop(li);

	

	
	printf("\n\nIniciando compactação");

	queue_compact(li);
	printf("\nFim da compactação, tamanho da lista: %d!",tamanho_lista(li));
	
	

	
	printf("\n\nLiberando a lista!");
	queue_free(li);


	system("pause");
	return 0;
}

