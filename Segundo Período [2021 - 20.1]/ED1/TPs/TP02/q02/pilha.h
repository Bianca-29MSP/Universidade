typedef struct pilha Pilha;

typedef float Item;

void pilhaInicia(Pilha **, int);

int pilhaEhVazia(Pilha *);

int pilhaPush(Pilha *, Item);

Item pilhaPop(Pilha *);

int pilhaTamanho(Pilha *);

void pilhaImprime(Pilha *);

Item pilhatop(Pilha *);

void pilhalibera(Pilha **);
