/*
* pilha.h
* Enya L. G. Santos
* 19.2.4201
*/

#ifndef pilha_h
#define pilha_h

typedef struct pilha Pilha;

Pilha *pilhaAloca();

void pilhaPush(Pilha *, int);

void pilhaPop(Pilha *, int *);

void pilhaUnstack(Pilha *);

void pilhaRead(Pilha *);

#endif