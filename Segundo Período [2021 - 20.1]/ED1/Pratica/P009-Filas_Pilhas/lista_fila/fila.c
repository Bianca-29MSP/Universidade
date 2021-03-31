#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "lista.h"

struct fila
{
  Lista *lista;
  int inicio;
  int fim;
};

void Fila_Inicia(Fila **pFila)
{
  *pFila = (Fila *)malloc(sizeof(pFila));
  Lista_Inicia(&(*pFila)->lista);
  (*pFila)->inicio = 0;
  (*pFila)->fim = 0;
}

int Fila_EhVazia(Fila *pFila)
{
  return Lista_EhVazia(pFila->lista);
}

void Fila_Enfileira(Fila *pFila, Item x)
{
  Lista_Insere(pFila->lista, pFila->fim, x);
  pFila->fim = Lista_Tamanho(pFila->lista);
}

int Fila_Desenfileira(Fila *pFila, Item *pX)
{
  int retorno = Lista_Remove(pFila->lista, pFila->inicio, pX);
  if (retorno)
    pFila->fim = Lista_Tamanho(pFila->lista);
  return retorno;
}

int Fila_Tamanho(Fila *pFila)
{
  return Lista_Tamanho(pFila->lista);
}

void Fila_imprime(Fila *pFila)
{
  Lista_imprime(pFila->lista);
}

void Fila_Libera(Fila **pFila)
{
  Lista_Libera(&(*pFila)->lista);
  free(*pFila);
  *pFila = NULL;
}
