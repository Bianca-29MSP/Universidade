#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

typedef struct listaNo ListaNo;

struct lista
{
  ListaNo *prim;
  int tamanho;
};

struct listaNo
{
  Item item;
  ListaNo *prox;
};

void Lista_Inicia(Lista **pLista)
{
  *pLista = (Lista *)malloc(sizeof(Lista));
  (*pLista)->prim = NULL;
  (*pLista)->tamanho = 0;
}

int Lista_EhVazia(Lista *pLista)
{
  if (pLista->prim == NULL)
    return 1;
  else
    return 0;
}

void Lista_Insere(Lista *pLista, int p, Item x)
{
  ListaNo *nNo = (ListaNo *)malloc(sizeof(ListaNo));
  nNo->item = x;
  nNo->prox = NULL;

  if (Lista_EhVazia(pLista) && p == 0)
  {
    pLista->prim = nNo;
    pLista->tamanho += 1;
  }
  else
  {
    ListaNo *anterior = pLista->prim;

    for (int i = 1; i < p; i++)
      anterior = anterior->prox;

    nNo->prox = anterior->prox;
    anterior->prox = nNo;
    pLista->tamanho += 1;
  }
}

int Lista_Remove(Lista *pLista, int p, Item *pX)
{
  if (!Lista_EhVazia(pLista))
  {
    ListaNo *anterior = NULL;
    ListaNo *prox = pLista->prim;

    for (int i = 0; i < p - 1; i++)
      if (prox != NULL)
      {
        anterior = prox;
        prox = prox->prox;
      }

    if (prox != NULL)
    {
      if (anterior == NULL)
      {
        pLista->prim = prox->prox;
      }
      else
      {
        anterior->prox = prox->prox;
      }

      *pX = prox->item;
      prox->prox = NULL;
      prox->item = 0;
      free(prox);

      pLista->tamanho -= 1;
    }
    return 1;
  }
  return 0;
}

int Lista_Tamanho(Lista *pLista)
{
  return pLista->tamanho;
}

void Lista_imprime(Lista *pLista)
{
  if (!Lista_EhVazia(pLista))
  {
    for (ListaNo *lNo = pLista->prim; lNo != NULL; lNo = lNo->prox)
      printf("%d ", lNo->item);
    printf("\n");
  }
}

void Lista_Libera(Lista **pLista)
{
  ListaNo *pNo = (*pLista)->prim;

  while (pNo != NULL)
  {
    ListaNo *auxNo = pNo->prox;
    free(pNo);
    pNo = auxNo;
  }

  free(*pLista);
  *pLista = NULL;
}
