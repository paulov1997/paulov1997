#include <stdio.h>
#include <stdlib.h>
#include "TCircularList.h"

int main(){
	struct aluno a[5] = {{11,"Paulo",1.0,2.0,3.0},{1,"Victor",5.5,6.6,7.7},{8,"Pedro",9.9,9.5,9.3},{22,"Henrique",7.2,4.5,6.9},{19, "João", 8.8,9.9,10.0}};
	List* li;
	li = list_create();
	int pos;
	int verifica;

	if(li == NULL)
		printf("ERRO. MEMORIA INSUFICIENTE.\n");
	else
		printf("LISTA CRIADA COM SUCESSO.\n");

	//função que valida enquanta ele nao inserir nao achar o nome desejado ele vai executar em loop a função de procurar aluno caso nao ache ele insere um novo alno

	int i = 0;
	
		while(list_find_mat(li,i ,&a[i]) =! 0)
		{	
			list_push_back(li,a[i]);

			i++;


		}

	
	
	

	
    list_free(li);

    return 0;

}