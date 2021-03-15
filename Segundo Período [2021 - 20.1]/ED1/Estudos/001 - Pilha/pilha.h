/*
* pilha.h
* Estrutura de dado tipo Pilha
* Referência: https://youtu.be/Y0h8SYtTnmE?list=PLtfCKnLH2KFyH_7mnyEZyW-YgF0Pfqr3d
*/

#ifndef pilha_h
#define pilha_h

typedef struct pilha Pilha;

Pilha *inicializaPilha();

void empilha(Pilha *, int);

int desempilha(Pilha *);

void imprimePilha(Pilha *);

#endif