#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arvore.h"

char depth[2056];
int di;

// typedef struct tItem TItem;

typedef struct
{
  TChave chave;
  TElemento elemento;
} TItem;

struct arvoreNo
{
  TItem item;
  ArvoreNo *esq, *dir;
};

ArvoreNo *arvoreInicializa()
{
  return NULL;
}

ArvoreNo *arvoreAdicionaNo(ArvoreNo *raiz, ArvoreNo *no)
{
  if (raiz == NULL)
    return no;
  if (no->item.chave < raiz->item.chave)
    raiz->esq = arvoreAdicionaNo(raiz->esq, no);
  else
    raiz->dir = arvoreAdicionaNo(raiz->dir, no);
  /* Ignorando chave igual */
  return raiz;
}

ArvoreNo *arvoreCriaNovoNo(TElemento el, TChave ch)
{
  ArvoreNo *nNo = (ArvoreNo *)malloc(sizeof(ArvoreNo));
  nNo->esq = NULL;
  nNo->dir = NULL;
  nNo->item.chave = ch;
  nNo->item.elemento = el;
  return nNo;
}

void arvorePrintSimples(ArvoreNo *raiz)
{
  if (raiz != NULL)
  {
    printf("%c", raiz->item.elemento);
    printf("(");
    arvorePrintSimples(raiz->esq);
    arvorePrintSimples(raiz->dir);
    printf(")");
  }
}

float calculadoraPosOrdem(char op, Pilha *pilha)
{
  float valor1 = pilhaPop(pilha);
  float valor2 = pilhaPop(pilha);

  switch (op)
  {
  case '+':
    return valor1 + valor2;
    break;
  case '-':
    return valor1 - valor2;
    break;
  case '*':
    return valor1 * valor2;
    break;
  case '/':
    return valor1 / valor2;
    break;
  }

  return 0;
}

void arvorePosOrdem(ArvoreNo *raiz, Pilha *pilha)
{
  if (raiz == NULL)
    return;
  arvorePosOrdem(raiz->dir, pilha);
  arvorePosOrdem(raiz->esq, pilha);

  if (raiz->item.elemento == '+' ||
      raiz->item.elemento == '-' ||
      raiz->item.elemento == '*' ||
      raiz->item.elemento == '/')
    pilhaPush(pilha, calculadoraPosOrdem(raiz->item.elemento, pilha));
  else
  {
    pilhaPush(pilha, ((float)raiz->item.elemento - 48));
  }
}

void arvoreLibera(ArvoreNo **raiz)
{
  if (!arvoreEhVazia(*raiz))
  {
    arvoreLibera(&(*raiz)->esq); /* libera sae */
    arvoreLibera(&(*raiz)->dir); /* libera sad */
    free(*raiz);                 /* libera raiz */
    *raiz = NULL;
  }
}

int arvoreEhVazia(ArvoreNo *raiz)
{
  return raiz == NULL;
}

int arvoreNumeroNos(ArvoreNo *raiz)
{
  if (raiz == NULL)
    return 0;
  return (arvoreNumeroNos(raiz->esq) + 1 + arvoreNumeroNos(raiz->dir));
}

void Push(char c)
{
  depth[di++] = ' ';
  depth[di++] = c;
  depth[di++] = ' ';
  depth[di++] = ' ';
  depth[di] = 0;
}

void Pop()
{
  depth[di -= 4] = 0;
}

void arvorePrintGrafico(ArvoreNo *raiz)
{
  printf("<%c> \n", raiz->item.elemento);

  if (raiz->esq)
  {
    printf("%s `--", depth);
    Push('|');
    arvorePrintGrafico(raiz->esq);
    Pop();

    printf("%s `--", depth);
    Push(' ');
    arvorePrintGrafico(raiz->dir);
    Pop();
  }
}

void arvorePrintGraficoArquivo(ArvoreNo *raiz, FILE *arq)
{

  fprintf(arq, "<%c> \n", raiz->item.elemento);

  if (raiz->esq)
  {
    fprintf(arq, "%s `--", depth);
    Push('|');
    arvorePrintGraficoArquivo(raiz->esq, arq);
    Pop();

    fprintf(arq, "%s `--", depth);
    Push(' ');
    arvorePrintGraficoArquivo(raiz->dir, arq);
    Pop();
  }
}