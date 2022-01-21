#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct filaNo FilaNo;

struct fila
{
  FilaNo *prim;
  FilaNo *fim;
};

struct filaNo
{
  int dado;
  FilaNo *prox;
};

Fila *inicializaFila()
{
  Fila *aux = (Fila *)malloc(sizeof(Fila));
  aux->prim = NULL;
  aux->fim = NULL;
  return aux;
}

void enfileira(Fila *f, int dado)
{
  FilaNo *ptr = (FilaNo *)malloc(sizeof(FilaNo));
  if (ptr == NULL)
  {
    printf("Erro na alocação.\n");
    exit(0);
  }

  ptr->prox = NULL;
  ptr->dado = dado;

  if (f->prim == NULL)
    f->prim = ptr;
  else
    f->fim->prox = ptr;

  f->fim = ptr;
}

int desenfileira(Fila *f)
{
  FilaNo *ptr = f->prim;
  int backup;
  if (f->prim == NULL)
  {
    printf("Fila vazia.\n");
    return -1;
  }

  f->prim = ptr->prox;
  backup = ptr->dado;
  ptr->prox = NULL;

  free(ptr);

  if (f->prim == NULL)
    f->fim = NULL;

  return backup;
}

void imprimeFila(Fila *f)
{
  if (f->prim == NULL)
  {
    printf("Fila vazia.\n");
    return;
  }

  FilaNo *ptr = f->prim;
  while (ptr != NULL)
  {
    printf("%d ", ptr->dado);
    ptr = ptr->prox;
  }
  printf("\n");
}

void limpaFila(Fila *f)
{
  FilaNo *ptr = f->prim;

  if (ptr == NULL)
  {
    printf("Fila vazia.\n");
    return;
  }

  while (ptr != NULL)
  {
    desenfileira(f);
    ptr = f->prim;
  }
}

void liberaFila(Fila **f)
{
  limpaFila(*f);
  free(*f);
  *f = NULL;
}