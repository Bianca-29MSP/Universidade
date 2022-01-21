/*
*   entregador.h
*   ENYA L. G. DOS SANTOS
*   19.2.4201
*/

#define true 1;
#define false 0;

typedef int bool;

typedef struct pilha Pilha;

typedef char Pizza[100];

Pilha *Pilha_Inicia();

void Pilha_Push(Pilha *, Pizza);

int Pilha_Pop(Pilha *);

void Pilha_Imprime(Pilha *);

void Pilha_Libera(Pilha **);