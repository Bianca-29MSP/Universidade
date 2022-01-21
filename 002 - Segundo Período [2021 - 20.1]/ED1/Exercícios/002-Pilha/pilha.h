
typedef int Item;

typedef struct pilha Pilha;

void Pilha_Inicia(Pilha **pPilha);

int Pilha_EhVazia(Pilha *pPilha);

int Pilha_Push(Pilha *pPilha, Item x);

Item Pilha_Pop(Pilha *pPilha);

int Pilha_Tamanho(Pilha *pPilha);