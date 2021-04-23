#ifndef lista_h
#define lista_h

typedef struct lista Lista;

Lista *lst_cria();

void lst_imprime(Lista *);

int lst_pertence(Lista *, int);

void lst_insere_ordenado(Lista *, int);

void lst_retira(Lista *, int);

void lst_liberar(Lista **);

#endif