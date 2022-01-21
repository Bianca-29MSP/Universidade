/*
* lista.c
* Enya L. G. Santos
* 19.2.4201
*/

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct listaNo ListaNo;

struct lista
{
  ListaNo *prim;
  ListaNo *ultimo;
};

struct listaNo
{
  int info;
  ListaNo *prox;
};

Lista *lstAlloca()
{
  Lista *auxL = (Lista *)malloc(sizeof(Lista));
  auxL->prim = NULL;
  auxL->ultimo = NULL;
  return auxL;
}

void lstImprime(Lista *l)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    printf("%d ", lNo->info);
  printf("\n");
}

void lstPushOrdenado(Lista *l, int v)
{
  ListaNo *ant = NULL;
  ListaNo *prox = l->prim;
  while (prox != NULL && prox->info < v)
  {
    ant = prox;
    prox = prox->prox;
  }

  ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo));
  novo->info = v;

  if (ant == NULL)
  {
    novo->prox = l->prim;
    l->prim = novo;
    if (l->ultimo == NULL)
      l->ultimo = novo;
  }
  else
  {
    novo->prox = ant->prox;
    ant->prox = novo;
    if (l->ultimo == ant)
      l->ultimo = novo;
  }
}

Lista *lstConcatena(Lista *a, Lista *b)
{
  if (b->prim == NULL)
    return a;
  if (a->prim == NULL)
    return b;

  Lista *aux = (Lista *)malloc(sizeof(Lista));
  a->ultimo->prox = b->prim;
  aux->prim = a->prim;
  aux->ultimo = b->ultimo;

  return aux;
}

void lstFree(Lista **l)
{
  ListaNo *pNo = (*l)->prim;
  while (pNo != NULL)
  {
    ListaNo *auxNo = pNo->prox;
    free(pNo);
    pNo = auxNo;
  }
  free(*l);
  *l = NULL;
}