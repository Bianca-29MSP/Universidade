typedef struct pilha Pilha;

typedef float Item;

// void pilhaInicia(Pilha **, int);

Pilha *pilhaInicia();

int pilhaEhVazia(Pilha *);

int pilhaPush(Pilha *, Item);

Item pilhaPop(Pilha *);

int pilhaTamanho(Pilha *);

void pilhaImprime(Pilha *);

Item pilhatop(Pilha *);

void pilhaUnstack(Pilha **);

float calculadoraPosOrdem(Pilha *, char);

void constroiPilhaPosFixada(Pilha *, char);
