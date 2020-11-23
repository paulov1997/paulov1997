#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"

int verifica(char *s){
    Stack *st;
    int resultado;
    st = stack_create();
    for(int i = 0; s[i] != '\0'; i++){
        char *c;
        switch (s[i]){
            case ')':
                if(stack_empty(st))
                    return 0;
                stack_top(st, c);
                if(c[0] != '(')
                    return 0;
                stack_pop(st);
                break;

            case ']':
                if(stack_empty(st))
                    return 0;
                stack_top(st, c);
                if(c[0] != '[')
                    return 0;
                stack_pop(st);
                break;

            default: stack_push(st, s[i]);
        }
    }
    return stack_empty(st);
}

int main(){
    char s[100];

    printf("Digite uma expressão para validar se ela é bem formada: ");
    gets(s);
    if (verifica(s))
        printf("\nválida");
    else printf("\ninválida");

    return 0;
}
