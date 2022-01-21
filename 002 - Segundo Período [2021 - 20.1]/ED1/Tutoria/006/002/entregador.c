/*
*   entregador.c
*   ENYA L. G. DOS SANTOS
*   19.2.4201
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "entregador.h"

typedef struct pilhaNo PilhaNo;

struct pilha
{
  PilhaNo *topo;
};

struct pilhaNo
{
  Pizza pizza;
  PilhaNo *ant;
};

Pilha *Pilha_Inicia()
{
  Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
  aux->topo = NULL;
  return aux;
}

bool Pilha_EhVazia(Pilha *pPilha)
{
  if (pPilha->topo == NULL)
    return true;
  return false;
}

void Pilha_Push(Pilha *pPilha, Pizza pizza)
{
  PilhaNo *nPilha = (PilhaNo *)malloc(sizeof(PilhaNo));
  strcpy(nPilha->pizza, pizza);
  nPilha->ant = NULL;

  if (!Pilha_EhVazia(pPilha))
    nPilha->ant = pPilha->topo;

  pPilha->topo = nPilha;
}

int Pilha_Pop(Pilha *pPilha)
{
  if (!Pilha_EhVazia(pPilha))
  {
    PilhaNo *pTopo = pPilha->topo;

    pPilha->topo = pTopo->ant;
    pTopo->ant = NULL;
    free(pTopo);

    return 1;
  }
  return 0;
}

void Pilha_Imprime(Pilha *pPilha)
{
  if (!Pilha_EhVazia(pPilha))
  {
    PilhaNo *aux = pPilha->topo;
    while (aux != NULL)
    {
      printf("%s\n", aux->pizza);
      aux = aux->ant;
    }
  }
  else
    printf("Não há pizzas\n");
}

void Pilha_Libera(Pilha **pPilha)
{
  while (!Pilha_EhVazia(*pPilha))
  {
    Pilha_Pop(*pPilha);
  }
  free(*pPilha);
  *pPilha = NULL;
}