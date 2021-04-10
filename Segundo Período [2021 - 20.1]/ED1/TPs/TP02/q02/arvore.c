#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

struct arvoreNo
{
  TIPOCHAVE chave;
  int prioridade;
  ArvoreNo *esq, *dir;
};

ArvoreNo *inicializa()
{
  return NULL;
}

ArvoreNo *adiciona(ArvoreNo *raiz, ArvoreNo *no)
{
  if (raiz == NULL)
    return no;
  if (no->prioridade < raiz->prioridade)
    raiz->esq = adiciona(raiz->esq, no);
  else
    raiz->dir = adiciona(raiz->dir, no);
  /* Ignorando chave igual */
  return raiz;
}

ArvoreNo *criaNovoNo(TIPOCHAVE ch, int prioridade)
{
  ArvoreNo *nNo = (ArvoreNo *)malloc(sizeof(ArvoreNo));
  nNo->esq = NULL;
  nNo->dir = NULL;
  nNo->prioridade = prioridade;
  nNo->chave = ch;
  return nNo;
}

void exibirArvore(ArvoreNo *raiz)
{
  if (raiz != NULL)
  {
    printf("%c", raiz->chave);
    printf("(");
    exibirArvore(raiz->esq);
    exibirArvore(raiz->dir);
    printf(")");
  }
}

int numeroNos(ArvoreNo *raiz)
{
  if (raiz == NULL)
    return 0;
  return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

int calculadora(char op, Pilha *pilha)
{
  int valor1 = Pilha_Pop(pilha);
  int valor2 = Pilha_Pop(pilha);

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

void pos_ordem(ArvoreNo *raiz, Pilha *pilha)
{
  if (raiz == NULL)
    return;
  pos_ordem(raiz->dir, pilha);
  pos_ordem(raiz->esq, pilha);

  if (raiz->chave == '+' ||
      raiz->chave == '-' ||
      raiz->chave == '*' ||
      raiz->chave == '/')
    Pilha_Push(pilha, calculadora(raiz->chave, pilha));
  else
  {
    Pilha_Push(pilha, ((int)raiz->chave - 48));
  }
}

TIPOCHAVE exibiRaiz(ArvoreNo *raiz)
{
  if (raiz != NULL)
    return raiz->chave;
  return ' ';
}

void arv_libera(ArvoreNo **a)
{
  if (!arv_vazia(*a))
  {
    arv_libera(&(*a)->esq); /* libera sae */
    arv_libera(&(*a)->dir); /* libera sad */
    free(*a);               /* libera raiz */
    *a = NULL;
  }
}
//NoArv
int arv_vazia(ArvoreNo *a)
{
  return a == NULL;
}