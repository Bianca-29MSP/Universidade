#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilha
{
  Item *itens;
  int max;
  int tam;
};

// Pilha *Pilha_Inicia(int n)
// {
//   Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
//   aux->max = n;
//   aux->tam = 0;
//   aux->itens = (Item *)malloc(n * sizeof(Item));
//   return aux;
// }

void Pilha_Inicia(Pilha **pPilha, int n)
{
  *pPilha = (Pilha *)malloc(sizeof(Pilha));
  (*pPilha)->max = n;
  (*pPilha)->tam = 0;
  (*pPilha)->itens = (Item *)malloc(n * sizeof(Item));
}

int Pilha_EhVazia(Pilha *pPilha)
{
  if (pPilha->tam == 0)
    return 1;
  return 0;
}

int Pilha_Push(Pilha *pPilha, Item x)
{
  if (pPilha->tam < pPilha->max)
  {
    pPilha->itens[pPilha->tam] = x;
    pPilha->tam += 1;
    return 1;
  }
  return 0;
}

Item Pilha_Pop(Pilha *pPilha)
{
  return pPilha->itens[--pPilha->tam];
}

int Pilha_Tamanho(Pilha *pPilha)
{
  return pPilha->tam;
}

void Pilha_Imprime(Pilha *pPilha)
{
  for (int i = 0; i < Pilha_Tamanho(pPilha); i++)
    printf("%d ", pPilha->itens[i]);
  printf("\n");
}

Item Pilha_top(Pilha *pPilha)
{
  return pPilha->itens[pPilha->tam - 1];
}

void Pilha_libera(Pilha **pPilha)
{
  while ((*pPilha)->tam > 0)
    Pilha_Pop(*pPilha);
  free(*pPilha);
  *pPilha = NULL;
}