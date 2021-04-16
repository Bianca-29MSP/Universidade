#include <stdlib.h>
#include <stdio.h>
#include "pilha_arvore.h"

typedef struct celula Celula;

struct celula
{
  Arvore arvore;
  Celula *prox;
};

struct pilhaArvore
{
  int tam;
  Celula *top;
};

PilhaArvore *pilhaArvoreInicia()
{
  PilhaArvore *aux = (PilhaArvore *)malloc(sizeof(PilhaArvore));
  if (aux == NULL)
  {
    printf("Ocorreu algo de errado na alocação de memória.\n");
    exit(1);
  }
  aux->top = NULL;
  aux->tam = 0;
  return aux;
}

int pilhaArvoreEhVazia(PilhaArvore *pPilha)
{
  if (pPilha->top == NULL)
    return 1;
  return 0;
}

int pilhaArvorePush(PilhaArvore *pPilha, Arvore arv)
{
  Celula *celula = (Celula *)malloc(sizeof(Celula));
  if (celula == NULL)
  {
    printf("Ocorreu algo de errado na alocação de memória.\n");
    exit(1);
  }
  celula->prox = pPilha->top;
  celula->arvore = arv;
  pPilha->top = celula;
  pPilha->tam += 1;
  return 1;
}

Arvore pilhaArvorePop(PilhaArvore *pPilha)
{
  Celula *cTopo = pPilha->top;
  if (cTopo != NULL)
  {
    Arvore aux = cTopo->arvore;
    pPilha->top = cTopo->prox;
    pPilha->tam -= 1;
    cTopo->prox = NULL;
    free(cTopo);
    cTopo = NULL;
    return aux;
  }
  return NULL;
}

int pilhaArvoreTamanho(PilhaArvore *pPilha)
{
  return pPilha->tam;
}

void pilhaArvoreUnstack(PilhaArvore **pPilha)
{
  Celula *ptr = (*pPilha)->top;
  while (ptr != NULL)
  {
    pilhaArvorePop(*pPilha);
    ptr = NULL;
    ptr = (*pPilha)->top;
  }
  free(ptr);
  free(*pPilha);
  *pPilha = NULL;
  ptr = NULL;
}
