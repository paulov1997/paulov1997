#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplaEnca.h"

int main(){
	struct aluno a[5] = {{11,"Paulo",1.0,2.0,3.0},{1,"Victor",5.5,6.6,7.7},{8,"Pedro",9.9,9,5.9},{22,"Henrique",7.2,4.5,6.9},{19, "João", 8.8,9.9,10.0}};
	List* li;
	li = list_create();
	int pos;
	int verifica;

	if(li == NULL)
		printf("ERRO. MEMORIA INSUFICIENTE.\n");
	else
		printf("LISTA CRIADA COM SUCESSO.\n");

	int i = 0;
	for(i=0; i<5; i++){
		list_push_back(li, a[i]);
	}
	printf("\n\nTESTE DAS FUNCOES LIST PRINT E LIST PUSH BACK: \n");
    list_print_forward(li);

    struct aluno b = {29,"Julio",7.0,7.7,8.2};
    printf("\n\nTESTE DA FUNCAO LIST PUSH FRONT: \n");
	verifica = list_push_front(li, b);
	if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -2)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        list_print_forward(li);

	struct aluno c = {10,"Edna",9.9,10.0,9.8};
	printf("\n\nTESTE DA FUNCAO LIST INSERT: \n");
	verifica = list_insert(li, 2, c);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -2)
        printf("POSICAO INEXISTE.\n");
    if(verifica == 0)
        list_print_forward(li);

	printf("\n\nTESTE DA FUNCAO LIST SIZE: \n");
	printf("TAMANHO DA LISTA: %d\n", list_size(li));

	printf("\n\nTESTE DA FUNCAO LIST FIND POS: \n");
	verifica = list_find_pos(li, 2, &c);
	if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -4)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        printf("POSICAO OCUPADA. \n");


    printf("\n\nTESTE DA FUNCAO LIST POP FRONT: \n");
    verifica = list_pop_front(li);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -4)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        list_print_forward(li);

    printf("\n\nTESTE DA FUNCAO LIST POP BACK: \n");
    verifica = list_pop_back(li);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -4)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        list_print_forward(li);
    printf("\nTAMANHO DA LISTA: %d", list_size(li));

    printf("\n\nTESTE DA FUNCAO GET POS: ");
    verifica = list_get_pos(li, 1, &pos);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -4)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        printf("%d", pos);

    struct aluno x, y;
    printf("\n\nTESTE DA FUNCAO LIST FRONT: \n");
    verifica = list_front(li, &x);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -4)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        printf("%d, ", x.matricula);
        printf("%s, ", x.nome);
        printf("%f, %f, %f ", x.n1, x.n2, x.n3);

    printf("\n\nTESTE DA FUNCAO LIST BACK: \n");
    verifica = list_back(li, &y);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -4)
        printf("ELEMENTO NAO ENCONTRADO.\n");
    if(verifica == 0)
        printf("%d, ", y.matricula);
        printf("%s, ", y.nome);
        printf("%f, %f, %f ", y.n1, y.n2, y.n3);

    printf("\n\nTESTE DA FUNCAO LIST ERASE: \n");
    verifica = list_erase(li, 1);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");
    if(verifica == -2)
        printf("FORA DA MEMORIA.\n");
    if(verifica == 0)
        list_print_reverse(li);

    printf("\nTAMANHO DA LISTA: %d\n", list_size(li));

    verifica = list_free(li);
    if(verifica == -1)
        printf("PONTEIRO INVALIDO.\n");

    return 0;
}