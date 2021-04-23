#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#define N 16

typedef struct listaNo ListaNo;

typedef char TChave[N];

typedef struct
{
  TChave chave;
} TItem;

struct lista
{
  ListaNo *prim;
  ListaNo *ult;
};

struct listaNo
{
  TItem item;
  ListaNo *prox;
};

TLista *lst_cria()
{
  TLista *auxL = (TLista *)malloc(sizeof(TLista));
  auxL->prim = NULL;
  return auxL;
}

void lst_imprime(TLista *l)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    printf("%d ", lNo->info);
  printf("\n");
}

int lst_pertence(TLista *l, int valor)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
  {
    if (lNo->info == valor)
      return 1;
  }
  return 0;
}

void lst_retira(TLista *l, int valor)
{
  ListaNo *ant = NULL;
  ListaNo *prox = l->prim;
  while (prox != NULL && prox->info != valor)
  {
    ant = prox;
    prox = prox->prox;
  }

  if (prox != NULL)
  {
    if (ant == NULL)
    {
      l->prim = prox->prox;
    }
    else
    {
      ant->prox = prox->prox;
    }
  }

  free(prox);
}

int lst_insere(TLista *l, int valor)
{
  ListaNo *prim = l->prim;
  if (prim == NULL)
  {
    ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo));
    novo->info = valor;
    novo->prox = NULL;
    l->prim = novo;
    l->ult = novo;
  }
  else
  {
    ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo));
    novo->info = valor;
    novo->prox = NULL;
    ListaNo *ult = l->ult;
    ult->prox = novo;
    l->ult = novo;
  }
}

void lst_liberar(TLista **l)
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