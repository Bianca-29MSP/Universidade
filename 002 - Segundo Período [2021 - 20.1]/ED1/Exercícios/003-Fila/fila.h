#define MAX 500

typedef int Item;

typedef struct fila Fila;

void Fila_Inicia(Fila **);

int Fila_EhVazia(Fila *);

int Fila_Enfileira(Fila *, Item);

int Fila_Desenfileira(Fila *, Item *);

int Fila_Tamanho(Fila *);
