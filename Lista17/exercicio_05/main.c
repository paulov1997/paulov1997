#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"

#define N 100


// Esta função recebe uma expressão infixa inf
// e devolve a correspondente expressão posfixa.

char *infixaParaPosfixa (char *inf) {
   int n = strlen (inf);
   char *posf; 
   posf = malloc ((n+1) * sizeof (char));
   Stack *st;
   st = stack_create();
   stack_push (st, inf[0]);       // empilha '('

   int j = 0;
   for (int i = 1; inf[i] != '\0'; ++i) {
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

int main(){
    char *inf;
    char *posf;
    int t;

    printf("Digite uma expressão infixa que será convertida em posfixa: \n");
    scanf("%s",inf);

    printf("\n");
    posf = infixaParaPosfixa(inf);
    for (int i = 0; posf[i] != '\0'; ++i) {
        printf("%c", posf[i]);
    }
    return 0;
}