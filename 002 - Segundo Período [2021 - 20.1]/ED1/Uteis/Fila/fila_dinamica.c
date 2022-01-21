#include <stdlib.h>
#include "fila.h"

typedef struct celula Celula;

struct celula
{
  Item item;
  Celula *prox;
};

struct fila
{
  Celula *prox;
  Celula *fim;
  int tam;
};

void Fila_Inicia(Fila **pFila)
{
  *pFila = (Fila *)malloc(sizeof(Fila));
  (*pFila)->tam = 0;
  (*pFila)->prox = NULL;
  (*pFila)->fim = NULL;
}

int Fila_EhVazia(Fila *pFila)
{
  if (pFila->tam = NULL)
    return 1;
  return 0;
}

int Fila_Enfileira(Fila *pFila, Item x)
{
  Celula *nCelula = (Celula *)malloc(sizeof(Celula));

  nCelula->item = x;
  nCelula->prox = NULL;

  if (pFila->fim == NULL)
  {
    pFila->fim = nCelula;
    pFila->prox = nCelula;
  }
  else
  {
    pFila->fim->prox = nCelula;
    pFila->fim = nCelula;
  }

  pFila->tam += 1;

  return 1;
}

int Fila_Desenfileira(Fila *pFila, Item *pX)
{
  if (pFila->tam > 0)
  {
    Celula *aux = pFila->prox;
    *pX = aux->item;
    pFila->prox = aux->prox;
    free(aux);
    pFila->tam -= 1;

    if (pFila->prox == NULL)
      pFila->fim = NULL;

    return 1;
  }

  return 0;
}

int Fila_Tamanho(Fila *pFila)
{
  return pFila->tam;
}