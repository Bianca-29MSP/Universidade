#include <stdlib.h>
#include <stdio.h>
#include "pilha_arvore.h"

struct pilhaArvore
{
  Chave *itens;
  int max;
  int tam;
};

PilhaArvore *PilhaArvore_Inicia(int n)
{
  PilhaArvore *aux = (PilhaArvore *)malloc(sizeof(PilhaArvore));
  aux->max = n;
  aux->tam = 0;
  aux->itens = (Chave *)malloc(n * sizeof(Chave));
  return aux;
}

int PilhaArvore_EhVazia(PilhaArvore *pPilha)
{
  if (pPilha->tam == 0)
    return 1;
  return 0;
}

int PilhaArvore_Push(PilhaArvore *pPilha, Chave x)
{
  if (pPilha->tam < pPilha->max)
  {
    pPilha->itens[pPilha->tam] = x;
    pPilha->tam += 1;
    return 1;
  }
  return 0;
}

Chave PilhaArvore_Pop(PilhaArvore *pPilha)
{
  return pPilha->itens[--pPilha->tam];
}

int PilhaArvore_Tamanho(PilhaArvore *pPilha)
{
  return pPilha->tam;
}

Chave PilhaArvore_Top(PilhaArvore *pPilha)
{
  return pPilha->itens[pPilha->tam - 1];
}

void PilhaArvore_Libera(PilhaArvore **pPilha)
{
  while ((*pPilha)->tam > 0)
    PilhaArvore_Pop(*pPilha);
  free((*pPilha)->itens);
  free(*pPilha);
  *pPilha = NULL;
}