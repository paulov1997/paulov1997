#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3

typedef struct TStack TStack;
TStack* stack_create(int size);
int stack_free(TStack* st);


int stack_push(TStack* st, char xar);
int stack_pop(TStack* st);

int stack_size(TStack* st);
int stack_full(TStack* st);
int stack_empty(TStack* st);


