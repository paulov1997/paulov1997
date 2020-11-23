#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TQueue.h" //inclui os Protótipos

//Definição do tipo TQueue
 struct TQueue{
 int qtd;
 int tamanho_inicial;
 int tamanho_atual;
 struct aluno *dados;
 };


TQueue* queue_create(int valor){

  TQueue *li;
    li = (TQueue*) malloc( sizeof (struct TQueue));
      if (li != NULL)
        li ->qtd = 0 ;
        li -> tamanho_inicial = valor;
        li -> tamanho_atual = valor;
        li -> dados = malloc(li-> tamanho_inicial * sizeof (struct aluno));
        

        return  li;
}


void queue_free(TQueue *li){
  free(li);

}

int queue_compact (TQueue* li){
	if(li == NULL)
		return -1;

	  li->tamanho_atual = ceil(li->qtd / li->tamanho_inicial)* li->tamanho_inicial;
	    realloc(li->dados, li->tamanho_atual * sizeof(struct aluno));

      return 0;
}


int queue_push(TQueue* li, struct aluno al){
      if(li == NULL)
      return -1 ;

      if(li ->qtd == li->tamanho_atual){
          li->tamanho_atual += li->tamanho_inicial;
             li -> dados =realloc(li->dados, li->tamanho_atual * sizeof(struct aluno));

          return 3;
      }
      

      li -> dados [li -> qtd]= al;
      li ->qtd ++;
      return  0;
}






int queue_pop(TQueue* li){
  if(li == NULL)
    return  -1;
  if(li->qtd == 0)
     return -1; 

    int i;
    for(i =0; i < li -> qtd -1; i++){
      li->dados[i] = li ->dados[i+1];
          }

    li -> qtd --;
    return 0;

}




int queue_size(TQueue* li){
 if(li == NULL)
 return -1;
 else
 return li->qtd;
 }

 

 int queue_empty(TQueue* li){
 if(li == NULL)
 return -1;
 return (li->qtd == 0);
 }
