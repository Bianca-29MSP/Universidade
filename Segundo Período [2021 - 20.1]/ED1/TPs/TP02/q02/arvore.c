#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "arvore.h"

/*https://laptrinhx.com/printing-pretty-ascii-trees-259794796/*/
char depth[2056];
int di;

struct arvoreNo
{
  TIPOCHAVE chave;
  int prioridade;
  ArvoreNo *esq, *dir;
};

//arvoreInicializa
ArvoreNo *inicializa()
{
  return NULL;
}

//arvoreAdicionaNo
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

//arvoreCriaNovoNo
ArvoreNo *criaNovoNo(TIPOCHAVE ch, int prioridade)
{
  ArvoreNo *nNo = (ArvoreNo *)malloc(sizeof(ArvoreNo));
  nNo->esq = NULL;
  nNo->dir = NULL;
  nNo->prioridade = prioridade;
  nNo->chave = ch;
  return nNo;
}

//arvorePrintada
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

//arvoreNumeroNos
int numeroNos(ArvoreNo *raiz)
{
  if (raiz == NULL)
    return 0;
  return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

//arvoreCalculaExpressao
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

//arvorePosOrdem
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

//arvoreExibiRair
TIPOCHAVE exibiRaiz(ArvoreNo *raiz)
{
  if (raiz != NULL)
    return raiz->chave;
  return ' ';
}

//arvoreLibera
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
//arvoreEstaVazia
int arv_vazia(ArvoreNo *a)
{
  return a == NULL;
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

//arvorePrintadaGraficamente
void exibirArvore2(ArvoreNo *raiz)
{
  printf("<%c> \n", raiz->chave);

  if (raiz->esq)
  {
    printf("%s `--", depth);
    Push('|');
    exibirArvore2(raiz->esq);
    Pop();

    printf("%s `--", depth);
    Push(' ');
    exibirArvore2(raiz->dir);
    Pop();
  }
}