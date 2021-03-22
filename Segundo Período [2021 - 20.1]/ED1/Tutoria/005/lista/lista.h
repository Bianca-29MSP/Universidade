/*
* lista.h
* Enya L. G. Santos
* 19.2.4201
*/

#ifndef lista_h
#define lista_h

typedef struct lista Lista;

Lista *lstAlloca();

void lstImprime(Lista *);

void lstPushOrdenado(Lista *, int);

Lista *lstConcatena(Lista *, Lista *);

void lstFree(Lista **);

#endif