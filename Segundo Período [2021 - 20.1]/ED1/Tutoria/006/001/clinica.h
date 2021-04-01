/*
*   clinica.h
*   ENYA L. G. DOS SANTOS
*   19.2.4201
*/

#define true 1;
#define false 0;

typedef int bool;

typedef struct fila Fila;

typedef struct cliente Cliente;

Fila *Fila_Inicia();

bool Fila_EhVazia(Fila *);

void Fila_Enfileira(Fila *, char *, char *);

int Fila_Desenfileira(Fila *);

void Fila_Primeiro(Fila *, char *, char *);

void Fila_Imprime(Fila *);

void Fila_Libera(Fila **);
