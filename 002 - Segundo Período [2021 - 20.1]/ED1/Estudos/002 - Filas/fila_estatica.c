#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAXTAM 5

struct fila
{
  int dados[MAXTAM];
  int fim;
};

Fila *inicializaFila()
{
  Fila *aux = (Fila *)malloc(sizeof(Fila));
  for (int i = 0; i < MAXTAM; i++)
  {
    aux->dados[i] = 0;
  }
  aux->fim = 0;
  return aux;
}

void enfileira(Fila *f, int dado)
{
  if (f->fim == MAXTAM)
  {
    printf("Fila está cheia.\n");
    return;
  }
  f->dados[f->fim] = dado;
  f->fim += 1;
}

void imprimeFila(Fila *f)
{
  if (f->fim == 0)
  {
    printf("Fila está vazia.\n");
    return;
  }
  for (int i = 0; i < f->fim; i++)
  {
    printf("%d ", f->dados[i]);
  }
  printf("\n");
}

int desenfileira(Fila *f)
{
  if (f->fim == 0)
  {
    printf("Fila está vazia.\n");
    return -1;
  }

  int backup = f->dados[0];

  for (int i = 0; i < f->fim; i++)
  {
    f->dados[i] = f->dados[i + 1];
  }

  f->dados[f->fim - 1] = 0;
  f->fim -= 1;

  return backup;
}

void limpaFila(Fila *f)
{
  if (f->fim == 0)
  {
    printf("Fila está vazia.\n");
    return;
  }

  while (f->fim > 0)
  {
    printf("%d ", desenfileira(f));
  }

  printf("\n");
}

void liberaFila(Fila **f)
{
  free(*f);
  *f = NULL;
}