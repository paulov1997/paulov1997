struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct list List;

List* list_create();
int list_free(List *li);
int list_push_front(List *li, struct aluno al);
int list_push_back(List *li, struct aluno al);
int list_insert(List *li, int pos, struct aluno al);
int list_size(List *li);
int list_pop_front(List *li);
int list_pop_back(List *li);
int list_erase(List *li, int pos);
int list_find_pos(List *li, int pos, struct aluno *al);
int list_find_mat(List *li, int nmat, struct aluno *al);
int list_front(List *li, struct aluno *al);
int list_back(List *li, struct aluno *al);
int list_get_pos(List *li, int nmat, int *pos);
int list_print_forward(List *li);
int list_print_reverse(List *li);
