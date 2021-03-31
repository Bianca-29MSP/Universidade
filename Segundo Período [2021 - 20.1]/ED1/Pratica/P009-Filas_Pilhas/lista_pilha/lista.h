#ifndef lista_h
#define lista_h

typedef struct lista Lista;
typedef int Item;

/* inicia uma lista */
void Lista_Inicia(Lista **);

/* retorna 1 se a lista for vazia e 0 caso contrario */
int Lista_EhVazia(Lista *);

/* insere o elemento x na posição p da lista */
void Lista_Insere(Lista *, int, Item);

/* retira o elemento da posição p da lista e o retorna pelo parâmetro pX
* a função retorna 0 caso não haja elemento na posição p da lista e 1 caso contrario */
int Lista_Remove(Lista *, int, Item *);

/* retorna o tamanho da lista */
int Lista_Tamanho(Lista *);

/* imprime a lista */
void Lista_imprime(Lista *);

/* libera toda memoria alocada para a lista */
void Lista_Libera(Lista **pLista);

#endif
