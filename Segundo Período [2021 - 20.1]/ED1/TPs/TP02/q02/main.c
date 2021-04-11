#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pilha.h"
#include "pilha_arvore.h"
#include "arvore.h"
#include "arquivo.h"

//Erro => 5 * (6 - 4 / 2)
//        3*(6+3)-8/(2+2)
//        7 * (2 + 2) / 7

#define MAXTAM 100

ArvoreNo *geraSubarvore(char *inf, int ini, int fim);

void geraArvore(char *expressao);

void trataString(char *expressao, int n);

int contemEspaco(char *expressao, int n);

int operadorPrincipal(char *expressao, int ini, int fim);

int ehOperador(char c);

int ehOperando(char c);

int calculaArvore(ArvoreNo **raiz);

int main()
{
  int op;
  char expressao[MAXTAM];

  printf("1 - Digitar expressao\n2 - Ler expressão(ões) através de um arquivo .txt [expressoes.txt]\n");
  scanf("%d", &op);

  if (op == 1)
  {
    scanf("\n%100[^\n]s", expressao);
    geraArvore(expressao);
  }
  else if (op == 2)
  {
    int nExp;
    char **expressoes = leArquivo(&nExp);

    for (int i = 0; i < nExp; i++)
      geraArvore(expressoes[i]);
  }

  return 0;
}

void geraArvore(char *expressao)
{
  int n = strlen(expressao);

  trataString(expressao, n);

  n = strlen(expressao);

  int pOperador = operadorPrincipal(expressao, 0, n);
  ArvoreNo *raiz = criaNovoNo(expressao[pOperador], pOperador);
  //printf("$ =>%d\n", pOperador);

  ArvoreNo *noEsq = geraSubarvore(expressao, 0, pOperador - 1);
  raiz = adiciona(raiz, noEsq);

  ArvoreNo *noDir = geraSubarvore(expressao, pOperador + 1, n);
  raiz = adiciona(raiz, noDir);

  //exibirArvore(raiz);
  //exibirArvore2(raiz);
  // printf("\n");

  //printf("%s\n", expressao);
  int resultado = calculaArvore(&raiz);
  printf("%d\n", resultado);

  arv_libera(&raiz);
}

ArvoreNo *geraSubarvore(char *exp, int ini, int fim)
{
  PilhaArvore *pRaizes = PilhaArvore_Inicia((fim - ini + 1));

  int parenteseOpen = 0;
  int preferencia = 0;
  int tinhaPreferencia = 0;

  for (int i = ini; i <= fim; i++)
  {
    if (exp[i] == '(')
    {
      parenteseOpen += 1;
      if (preferencia == 1)
        tinhaPreferencia = 1;
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
      if (tinhaPreferencia == 1)
        preferencia = 1;
      parenteseOpen -= 1;
    }
    else if (ehOperador(exp[i]))
    {
      if (preferencia == 1)
      {
        if (PilhaArvore_Tamanho(pRaizes) > 1)
        {
          ArvoreNo *folha = PilhaArvore_Pop(pRaizes);
          ArvoreNo *no = PilhaArvore_Pop(pRaizes);
          no = adiciona(no, folha);
          PilhaArvore_Push(pRaizes, no);
        }
        preferencia = 0;
      }

      ArvoreNo *no = criaNovoNo(exp[i], i); /*Cria subarvore */
      if (!PilhaArvore_EhVazia(pRaizes))
      {
        no = adiciona(no, PilhaArvore_Pop(pRaizes));
      }
      PilhaArvore_Push(pRaizes, no);

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
        //preferencia = 0;
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

  return aux;
}

int contemEspaco(char *expressao, int n)
{
  for (int i = 0; i < n; i++)
    if (expressao[i] == ' ')
      return 1;

  return 0;
}

void trataString(char *expressao, int n)
{
  /* verifica se há espaços */
  if (contemEspaco(expressao, n))
  {
    char *aux = calloc(n, sizeof(char));

    for (int j = 0, i = 0; i < n; i++)
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
int operadorPrincipal(char *expressao, int ini, int fim)
{
  //5 * (6 - 4 / 2)

  int index = -1;

  //printf("$ %d %d\n", ini, fim);

  if (ini == fim)
  {
    return ini;
  }
  else if (ini + 1 == fim)
    return ini - 1;

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
  if ((expressao[index] == '*' || expressao[index] == '/') && (index + 1) != fim) /* Respeitando  a precedência dos operadores */
  {
    int aux = operadorPrincipal(expressao, index + 1, fim);
    if (aux != -1)
      index = aux;
  }

  return index;
}

int calculaArvore(ArvoreNo **raiz)
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
