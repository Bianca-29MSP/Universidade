#ifndef pilha_h
#define pilha_h

typedef struct pilha Pilha;
typedef int Item;

/* inicia uma pilha */
void Pilha_Inicia(Pilha **);

/* retorna 1 se a pilha for vazia e 0 caso contrario */
int Pilha_EhVazia(Pilha *);

/* insere o elemento x no topo da pilha */
void Pilha_Push(Pilha *, Item);

/* retira o elemento do topo da pilha e o retorna pelo parametro pX
* a função retorna 0 caso não haja nenhum elemento na pilha e 1 caso contrario */
int Pilha_Pop(Pilha *, Item *);

/* retorna o tamanho da pilha */
int Pilha_Tamanho(Pilha *);

/* imprime a pilha */
void Pilha_imprime(Pilha *);

/* libera toda memoria alocada para a pilha*/
void Pilha_Libera(Pilha **);

#endif