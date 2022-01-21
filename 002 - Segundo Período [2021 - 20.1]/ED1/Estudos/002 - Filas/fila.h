#ifndef fila_h
#define fila_h
/*
*  FIFO - First in, first out.
*  LILO - Last in, last out.
*/

typedef struct fila Fila;

Fila *inicializaFila();

void enfileira(Fila *, int);

void imprimeFila(Fila *);

int desenfileira(Fila *);

void limpaFila(Fila *);

void liberaFila(Fila **);

#endif