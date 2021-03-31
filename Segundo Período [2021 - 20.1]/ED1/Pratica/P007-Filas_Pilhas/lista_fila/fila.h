#ifndef fila_h
#define fila_h

typedef struct fila Fila;
typedef int Item;

/* inicia uma fila */
void Fila_Inicia(Fila **);

/* retorna 1 se a fila for vazia e 0 caso contrário */
int Fila_EhVazia(Fila *);

/* insere o elemento x na fila */
void Fila_Enfileira(Fila *, Item);

/* retira o elemento da frente da fila e o retorna pelo parâmetro pX
* a função retorna 0 caso não haja elemento na fila e 1 caso contrário */
int Fila_Desenfileira(Fila *, Item *);

/* retorna o tamanho da fila */
int Fila_Tamanho(Fila *);

/* imprime fila */
void Fila_imprime(Fila *);

/* libera toda memoria alocada para a fila */
void Fila_Libera(Fila **);

#endif
