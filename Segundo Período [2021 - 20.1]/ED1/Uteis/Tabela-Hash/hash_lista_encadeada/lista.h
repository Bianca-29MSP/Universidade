#ifndef lista_h
#define lista_h

typedef struct lista TLista;

TLista *lst_cria();

void lst_imprime(TLista *);

int lst_pertence(TLista *, int);

void lst_insere_ordenado(TLista *, int);

int lst_insere(TLista *, int);

void lst_retira(TLista *, int);

void lst_liberar(TLista **);

#endif