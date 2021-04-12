#include <stdlib.h>
#include <stdio.h>
#include "pilha_arvore.h"

struct pilhaArvore
{
  Arvore *arvores;
  int max;
  int tam;
};

PilhaArvore *PilhaArvore_Inicia(int n)
{
  PilhaArvore *aux = (PilhaArvore *)malloc(sizeof(PilhaArvore));
  aux->max = n;
  aux->tam = 0;
  aux->arvores = (Arvore *)malloc(n * sizeof(Arvore));
  return aux;
}

int PilhaArvore_EhVazia(PilhaArvore *pPilha)
{
  if (pPilha->tam == 0)
    return 1;
  return 0;
}

int PilhaArvore_Push(PilhaArvore *pPilha, Arvore x)
{
  if (pPilha->tam < pPilha->max)
  {
    pPilha->arvores[pPilha->tam] = x;
    pPilha->tam += 1;
    return 1;
  }
  return 0;
}

Arvore PilhaArvore_Pop(PilhaArvore *pPilha)
{
  return pPilha->arvores[--pPilha->tam];
}

int PilhaArvore_Tamanho(PilhaArvore *pPilha)
{
  return pPilha->tam;
}

Arvore PilhaArvore_Top(PilhaArvore *pPilha)
{
  return pPilha->arvores[pPilha->tam - 1];
}

void PilhaArvore_Libera(PilhaArvore **pPilha)
{
  while ((*pPilha)->tam > 0)
    PilhaArvore_Pop(*pPilha);
  free((*pPilha)->arvores);
  free(*pPilha);
  *pPilha = NULL;
}