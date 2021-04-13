#include <stdlib.h>
#include <stdio.h>
#include "pilha_arvore.h"

struct pilhaArvore
{
  Arvore *arvores;
  int max;
  int tam;
};

PilhaArvore *pilhaArvoreInicia(int n)
{
  PilhaArvore *aux = (PilhaArvore *)malloc(sizeof(PilhaArvore));
  aux->max = n;
  aux->tam = 0;
  aux->arvores = (Arvore *)malloc(n * sizeof(Arvore));
  return aux;
}

int pilhaArvoreEhVazia(PilhaArvore *pPilha)
{
  if (pPilha->tam == 0)
    return 1;
  return 0;
}

int pilhaArvorePush(PilhaArvore *pPilha, Arvore x)
{
  if (pPilha->tam < pPilha->max)
  {
    pPilha->arvores[pPilha->tam] = x;
    pPilha->tam += 1;
    return 1;
  }
  return 0;
}

Arvore pilhaArvorePop(PilhaArvore *pPilha)
{
  return pPilha->arvores[--pPilha->tam];
}

int pilhaArvoreTamanho(PilhaArvore *pPilha)
{
  return pPilha->tam;
}

Arvore pilhaArvoreTop(PilhaArvore *pPilha)
{
  return pPilha->arvores[pPilha->tam - 1];
}

void pilhaArvoreLibera(PilhaArvore **pPilha)
{
  while ((*pPilha)->tam > 0)
    pilhaArvorePop(*pPilha);
  free((*pPilha)->arvores);
  free(*pPilha);
  *pPilha = NULL;
}