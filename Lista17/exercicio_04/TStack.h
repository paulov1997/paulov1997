#define MAX 100

typedef struct stack Stack;

Stack *stack_create();
int stack_free(Stack *st);

int stack_push(Stack *st, char c);
int stack_pop(Stack *st);

int stack_top(Stack *st, char *c);

int stack_empty(Stack *st);
int stack_size(Stack *st);