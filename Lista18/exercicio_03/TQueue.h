#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define NO_ACTION_REQUIRED -5
#define QUEUE_FULL -6
#define QUEUE_EMPTY -7

struct aluno{
	int matricula;
	char nome[30];
	float n1,n2,n3;
};

typedef struct dqueue DQueue;

DQueue *queue_create(int tamanho);

int queue_free(DQueue *li);

int queue_get(DQueue *li, struct aluno *al);

int queue_push (DQueue *li, struct aluno al);  

int queue_pop (DQueue *li);

int queue_size (DQueue *li);

int queue_full (DQueue *li);

int queue_compact (DQueue *li);