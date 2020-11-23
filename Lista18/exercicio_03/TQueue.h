#ifndef TQueueh1
#define TQueueh1

#define SUCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2



typedef struct TQueue TQueue;

#include "../aluno.h"

TQueue *queue_create();
int queue_free(TQueue *st);

int queue_push (TQueue *st, struct aluno al);
int queue_pop (TQueue *st);
int queue_compact(TQueue *st);
int queue_empty (TQueue *st);
int queue_size (TQueue *st);

#endif