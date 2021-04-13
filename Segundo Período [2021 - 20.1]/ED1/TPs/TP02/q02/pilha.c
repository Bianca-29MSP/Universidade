#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha
{
  Item *itens;
  int max;
  int tam;
};

void pilhaInicia(Pilha **pPilha, int n)
{
  *pPilha = (Pilha *)malloc(sizeof(Pilha));
  (*pPilha)->max = n;
  (*pPilha)->tam = 0;
  (*pPilha)->itens = (Item *)malloc(n * sizeof(Item));
}

int pilhaEhVazia(Pilha *pPilha)
{
  if (pPilha->tam == 0)
    return 1;
  return 0;
}

int pilhaPush(Pilha *pPilha, Item x)
{
  if (pPilha->tam < pPilha->max)
  {
    pPilha->itens[pPilha->tam] = x;
    pPilha->tam += 1;
    return 1;
  }
  return 0;
}

Item pilhaPop(Pilha *pPilha)
{
  return pPilha->itens[--pPilha->tam];
}

int pilhaTamanho(Pilha *pPilha)
{
  return pPilha->tam;
}

void pilhaImprime(Pilha *pPilha)
{
  for (int i = 0; i < pilhaTamanho(pPilha); i++)
    printf("%f ", pPilha->itens[i]);
  printf("\n");
}

Item pilhatop(Pilha *pPilha)
{
  return pPilha->itens[pPilha->tam - 1];
}

void pilhalibera(Pilha **pPilha)
{
  while ((*pPilha)->tam > 0)
    pilhaPop(*pPilha);
  free((*pPilha)->itens);
  free(*pPilha);
  *pPilha = NULL;
}