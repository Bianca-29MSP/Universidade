#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pilha.h"
#include "pilha_arvore.h"
#include "arvore.h"

#define MAXTAM 100

void trataString(char *expressao);

ArvoreNo *constroiSubarvore(char *inf, int ini, int fim);

int primeiroOperador(char *expressao, int ini, int fim);

int ehOperador(char c);

int ehOperando(char c);

int calcula(ArvoreNo **raiz);

int main()
{
  char expressao[MAXTAM];

  scanf("\n%100[^\n]s", expressao);

  trataString(expressao);

  int pOperador = primeiroOperador(expressao, 0, strlen(expressao));
  ArvoreNo *raiz = criaNovoNo(expressao[pOperador], pOperador);

  ArvoreNo *noEsq = constroiSubarvore(expressao, 0, pOperador - 1);
  raiz = adiciona(raiz, noEsq);

  ArvoreNo *noDir = constroiSubarvore(expressao, pOperador + 1, strlen(expressao));
  raiz = adiciona(raiz, noDir);

  exibirArvore(raiz);
  printf("\n");

  int resultado = calcula(&raiz);
  printf("%d\n", resultado);

  arv_libera(&raiz);

  return 0;
}

ArvoreNo *constroiSubarvore(char *exp, int ini, int fim)
{
  int n = strlen(exp);
  PilhaArvore *pRaizes = PilhaArvore_Inicia(n);

  int parenteseOpen = 0;
  int preferencia = 0;

  for (int i = ini; i <= fim; i++)
  {
    if (exp[i] == '(')
    {
      parenteseOpen += 1;
      preferencia = 0;
    }
    else if (exp[i] == ')')
    {
      if (preferencia == 0)
      {
        ArvoreNo *folha = PilhaArvore_Pop(pRaizes);
        ArvoreNo *no = PilhaArvore_Pop(pRaizes);
        no = adiciona(no, folha);
        PilhaArvore_Push(pRaizes, no);
      }
      parenteseOpen -= 1;
    }
    else if (ehOperador(exp[i]))
    {
      ArvoreNo *no = criaNovoNo(exp[i], i); /*Cria subarvore */
      if (!PilhaArvore_EhVazia(pRaizes))
      {
        no = adiciona(no, PilhaArvore_Pop(pRaizes));
      }
      PilhaArvore_Push(pRaizes, no);
      preferencia = 0;
      if (exp[i] == '*' || exp[i] == '/')
        preferencia = 1;
    }
    else if (ehOperando(exp[i]))
    {
      ArvoreNo *folha = criaNovoNo(exp[i], i);
      if (preferencia == 1 && parenteseOpen == 0)
      {
        ArvoreNo *no = PilhaArvore_Pop(pRaizes);
        no = adiciona(no, folha);
        PilhaArvore_Push(pRaizes, no);
      }
      else
      {
        PilhaArvore_Push(pRaizes, folha);
        preferencia = 0;
      }
    }
  }

  int i = PilhaArvore_Tamanho(pRaizes);
  while (i > 1)
  {
    ArvoreNo *folha = PilhaArvore_Pop(pRaizes);
    ArvoreNo *no = PilhaArvore_Pop(pRaizes);
    no = adiciona(no, folha);
    PilhaArvore_Push(pRaizes, no);
    i = PilhaArvore_Tamanho(pRaizes);
  }

  ArvoreNo *aux = PilhaArvore_Pop(pRaizes);

  PilhaArvore_Libera(&pRaizes);
  //9 * (6 + 8) - 9 / ( 5 + 4)

  return aux;
}

void trataString(char *expressao)
{
  char *aux = malloc(strlen(expressao) * sizeof(char));
  for (int j = 0, i = 0; i < strlen(expressao); i++)
  {
    if (expressao[i] != ' ')
    {
      aux[j] = expressao[i];
      j++;
    }
  }
  strcpy(expressao, aux);
  free(aux);
}

int ehOperador(char c)
{
  return ((c == '+') || (c == '-') ||
          (c == '*') || (c == '/'));
}

int ehOperando(char expressao)
{
  //return ((int)expressao >= 48 && (int)expressao <= 57);
  return (expressao >= '0' && expressao <= '9');
}

/* Função que encontra o primeiro operador, aquele q será a raiz da arvore */
int primeiroOperador(char *expressao, int ini, int fim)
{
  int index = -1;

  if (ini == fim)
  {
    return -1;
  }

  if (expressao[0] == '(' || expressao[ini] == '(')
  { /* Caso a expressão comece com um parênteses */
    int parenteseOpen = 1;
    for (int i = ini + 1; i < fim; i++)
    {
      if (expressao[i] == '(')
      {
        parenteseOpen += 1;
      }
      else if (expressao[i] == ')')
      {
        parenteseOpen -= 1;
      }
      else if (ehOperador(expressao[i]) && !parenteseOpen)
      {
        index = i;
        break;
      }
    }
  }
  else
  { /* Caso a expressão não comece com um parênteses */
    for (int i = ini; i < fim; i++)
    {
      if (ehOperador(expressao[i]))
      {
        index = i;
        break;
      }
    }
  }
  /* Até aqui, index é o primeiro operador encontrado */
  if ((expressao[index] == '*' || expressao[index] == '/')) /* Respeitando  a precedência dos operadores */
  {
    int aux = primeiroOperador(expressao, index + 1, fim);
    if (aux != -1)
      index = aux;
  }

  return index;
}

int calcula(ArvoreNo **raiz)
{
  int nNos = numeroNos(*raiz);

  Pilha *pilha;
  Pilha_Inicia(&pilha, nNos);
  pos_ordem(*raiz, pilha);

  int result = -1;

  if (Pilha_Tamanho(pilha) == 1)
    result = Pilha_Pop(pilha);

  Pilha_libera(&pilha);

  return result;
}

//9 * (6 + 8) - 9 / ( 5 + 4)
