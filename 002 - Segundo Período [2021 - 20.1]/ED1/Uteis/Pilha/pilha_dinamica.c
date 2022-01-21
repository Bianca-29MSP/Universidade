#include <stdlib.h>
#include "pilha.h"

typedef struct celula Celula;

struct celula
{
  Item item;
  Celula *prox;
};

struct pilha
{
  int tam;
  Celula *top;
};

void Pilha_Inicia(Pilha **pPilha)
{
  (*pPilha)->top = NULL;
  (*pPilha)->tam = 0;
}

int Pilha_EhVazia(Pilha *pPilha)
{
  if (pPilha->top == NULL)
    return 1;
  return 0;
}

int Pilha_Push(Pilha *pPilha, Item x)
{
  Celula *celula = (Celula *)malloc(sizeof(Celula));
  celula->prox = pPilha->top;
  celula->item = x;
  pPilha->top = celula;
  pPilha->tam += 1;
  return 1;
}

Item Pilha_Pop(Pilha *pPilha)
{
  Celula *cTopo = pPilha->top;
  if (cTopo != NULL)
  {
    Item aux = cTopo->item;
    pPilha->top = cTopo->prox;
    pPilha->tam -= 1;
    free(cTopo);
    cTopo = NULL;
    return aux;
  }
  return -1;
}

int Pilha_Tamanho(Pilha *pPilha)
{
  return pPilha->tam;
}