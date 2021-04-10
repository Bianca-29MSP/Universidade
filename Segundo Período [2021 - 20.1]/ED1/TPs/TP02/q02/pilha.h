typedef struct pilha Pilha;

typedef int Item;

// Pilha *Pilha_Inicia(int);

void Pilha_Inicia(Pilha **pPilha, int n);

int Pilha_EhVazia(Pilha *);

int Pilha_Push(Pilha *, Item);

Item Pilha_Pop(Pilha *);

int Pilha_Tamanho(Pilha *);

void Pilha_Imprime(Pilha *);

Item Pilha_top(Pilha *);

void Pilha_libera(Pilha **);
