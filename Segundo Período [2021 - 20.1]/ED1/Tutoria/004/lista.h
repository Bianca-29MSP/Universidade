/*
* Enya Luísa Gomes dos Santos
* 19.2.42.01
*/

#ifndef lista_h
#define lista_h

#include "pessoa.h"

typedef struct lista Lista;

typedef struct pessoa Pessoa;

Lista *lst_cria();

void lst_imprime(Lista *);

int lst_pertence(Lista *, char *);

void lst_insere_ordenado(Lista *, char *, int);

void lst_retira(Lista *, char *, int);

void lst_insere_inicio(Lista *, char *, int);

void lst_insere_fim(Lista *, char *, int);

void lstNo_altera(Lista *, char *, int, char *, int);

void lst_liberar(Lista **);

#endif
