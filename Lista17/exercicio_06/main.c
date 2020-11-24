#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"
#include "TStack_int.h"
#include <ctype.h>

#define N 100


// Esta função recebe uma expressão infixa inf
// e devolve a correspondente expressão posfixa.

char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf; 
   posf = malloc ((n+1) * sizeof (char));
   Stack *st;
   st = stack_create();

   int j = 0;
   for (int i = 0; inf[i] != '\0'; ++i) {
      switch (inf[i]) {
         char *x;
         case '(': stack_push (st, inf[i]);
                   break;
         case ')': stack_top (st, x);
                   while (x[0] != '(') {
                      posf[j++] = x[0];
                      stack_pop (st);
                      stack_top (st, x);
                   }
                   stack_pop (st);
                   break;
         case '+': 
         case '-': stack_top(st, x);
                   while (x[0] != '(') {
                      posf[j++] = x[0];
                      stack_pop(st);
                      stack_top (st, x);
                   }
                   stack_push (st, inf[i]);
                   break;
         case '*':
         case '/': stack_top (st, x);
                   while (x[0] != '(' && x[0] != '+' && x[0] != '-') {
                      posf[j++] = x[0];
                      stack_pop (st);
                      stack_top (st, x);
                   }
                   stack_push (st, inf[i]);
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   posf[j] = '\0';      
   return posf;
}


int soma_funcao (char *posf){
   printf("Forma postfix recebida na função 'soma_funcao': ");
    for (int i = 0; posf[i] != '\0'; ++i) {
        printf("%c", posf[i]);
    }
   printf("\n");
   StackInt *soma;
   soma = stackInt_create();
   
   int a, b, total;
   
   int i;
 
   for (i = 0; posf[i] != '\0'; i++) {
      printf("\nValor a ser trabalhando %c", posf[i]);

      switch (posf[i]) {
         case '+':
            stackInt_top (soma, &a);
            printf("\nRemovendo %d", a);
            stackInt_pop (soma);
            stackInt_top (soma, &b);
            printf("\nRemovendo %d", b);
            stackInt_pop (soma);
            total = b + a;
            printf("\nInserindo resultado da soma de %d com %d, total: %d", b, a, total);
            stackInt_push (soma, &total);
            break;

         case '-':
            stackInt_top (soma, &a);
            printf("\nRemovendo %d", a);
            stackInt_pop (soma);
            stackInt_top (soma, &b);
            printf("\nRemovendo %d", b);
            stackInt_pop (soma);
            total = b - a;
            printf("\nInserindo resultado da subtracao de %d com %d, total: %d", b, a, total);
            stackInt_push (soma, &total);
            break;

         case '*':
            stackInt_top (soma, &a);
            printf("\nRemovendo %d", a);
            stackInt_pop (soma);
            stackInt_top (soma, &b);
            printf("\nRemovendo %d", b);
            stackInt_pop (soma);
            total = b * a;
            printf("\nInserindo resultado da multiplicacao de %d com %d, total: %d", b, a, total);
            stackInt_push (soma, &total);
            break;
         case '/':
            stackInt_top (soma, &a);
            printf("\nRemovendo %d", a);
            stackInt_pop (soma);
            stackInt_top (soma, &b);
            printf("\nRemovendo %d", b);
            stackInt_pop (soma);
            total = b / a;
            printf("\nInserindo resultado da divisao de %d com %d, total: %d", b, a, total);
            stackInt_push (soma, &total);
            break;

         default:
            total = posf[i] - '0';
            printf("\nInserindo %d na pilha", total);
            stackInt_push (soma, &total);
            break;
      }
   }
   stackInt_top (soma, &total);
   printf("\nretornando para main o valor %d da opercao", total);
   return total;
}

int main(){
    char *inf;
    char *posf;
    int soma;
    int t;

    printf("Digite uma expressão infixa que será convertida em posfixa: \n");
    scanf("%s",inf);

    printf("\n");
    posf = infixaParaPosfixa(inf);
    soma = soma_funcao(posf);

    printf("\nForma postfix: ");
    for (int i = 0; posf[i] != '\0'; ++i) {
        printf("%c", posf[i]);
    }

    printf("\nResultado: %d", soma);
    return 0;
}