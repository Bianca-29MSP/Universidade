#define N 500

typedef int Item;

typedef struct pilha Pilha;

void Pilha_Inicia(Pilha *pLista);

int Pilha_EhVazia(Pilha *pLista);

int Pilha_InsereP(Pilha *pLista, int p, Item x);

Item Pilha_RetiraP(Pilha *pLista, int p, Item *pX);

int Pilha_Tamanho(Pilha *pLista);