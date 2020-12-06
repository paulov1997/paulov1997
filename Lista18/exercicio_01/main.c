#include "TQueue.h"


int main (){

     return 0;


    	struct aluno a[5] = {{11,"Paulo",1.0,2.0,3.0},{1,"Victor",5.5,6.6,7.7},{8,"Pedro",9.9,9.5,9.3},{22,"Henrique",7.2,4.5,6.9},{19, "João", 8.8,9.9,10.0}};

	TQueue* st;

	st = queue_create();
  
	int pos;
	int verifica;


	int i = 0;
	for(i=0; i<5; i++){
	 queue_push(st, a[i]);
	}
    return 0;
}

