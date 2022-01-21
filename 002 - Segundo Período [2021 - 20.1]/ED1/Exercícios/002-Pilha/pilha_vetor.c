#define N 500

#include <stdlib.h>
#include "pilha.h"

struct pilha
{
  Item itens[N];
  int tam;
};

void Pilha_Inicia(Pilha **pPilha)
{
  (*pPilha)->tam = 0;
}

int Pilha_EhVazia(Pilha *pPilha)
{
  if (pPilha->tam == 0)
    return 1;
  return 0;
}

int Pilha_Push(Pilha *pPilha, Item x)
{
  if (pPilha->tam < N)
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