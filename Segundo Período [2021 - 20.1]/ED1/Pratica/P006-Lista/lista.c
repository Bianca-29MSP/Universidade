#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct listaNo ListaNo;

struct lista
{
  ListaNo *prim;
};

struct listaNo
{
  int info;
  ListaNo *prox;
};

Lista *lst_cria()
{
  Lista *auxL = (Lista *)malloc(sizeof(Lista));
  auxL->prim = NULL;
  return auxL;
}

void lst_imprime(Lista *l)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    printf("%d ", lNo->info);
  printf("\n");
}

int lst_pertence(Lista *l, int valor)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
  {
    if (lNo->info == valor)
      return 1;
  }
  return 0;
}

void lst_insere_ordenado(Lista *l, int valor)
{
  ListaNo *ant = NULL;
  ListaNo *prox = l->prim;
  while (prox != NULL && prox->info < valor)
  {
    ant = prox;
    prox = prox->prox;
  }

  ListaNo *novo = (ListaNo *)malloc(sizeof(ListaNo));
  novo->info = valor;

  if (ant == NULL)
  {
    novo->prox = l->prim;
    l->prim = novo;
  }
  else
  {
    novo->prox = ant->prox;
    ant->prox = novo;
  }
}

void lst_retira(Lista *l, int valor)
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

void lst_liberar(Lista *l)
{
  ListaNo *pNo = l->prim;
  while (pNo != NULL)
  {
    ListaNo *auxNo = pNo->prox;
    free(pNo);
    pNo = auxNo;
  }
  free(l);
}