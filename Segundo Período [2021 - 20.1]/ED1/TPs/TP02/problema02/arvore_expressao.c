/*
* arvore_expressao.c
* Trabalho pratico 2 de EDI (BCC202) - Árvore de expressão   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arvore_expressao.h"

float calculaArvExpressao(char *expressao, int op)
{
  ArvoreNo *raiz = geraArvoreExpressao(expressao);

  float resultado = calculadoraArvore(&raiz);

  if (op == 1)
  {
    printf("%s = %.2f\n", expressao, resultado);
    arvorePrintGrafico(raiz);
    printf("---------------------------------------\n");
  }
  else if (op == 2)
  {
    FILE *arq = fopen("./arquivos/resultados.txt", "a");
    if (arq == NULL)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(1);
    }
    fprintf(arq, "%s = %.2f\n", expressao, resultado);
    arvorePrintGraficoArquivo(raiz, arq);
    fclose(arq);
  }
  else if (op == 3)
  {
    printf("%s = %.2f\n", expressao, resultado);
    arvorePrintGrafico(raiz);
    printf("---------------------------------------\n");

    FILE *arq = fopen("./arquivos/resultados.txt", "a");
    if (arq == NULL)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(1);
    }
    fprintf(arq, "%s = %.2f\n", expressao, resultado);
    arvorePrintGraficoArquivo(raiz, arq);
    fprintf(arq, "%s", "\n");
    fclose(arq);
  }

  arvoreLibera(&raiz);

  return resultado;
}

ArvoreNo *geraArvoreExpressao(char *expressao)
{
  int n = strlen(expressao);

  trataString(expressao, n);

  n = strlen(expressao);

  int pOperador = buscaOperadorPrincipal(expressao, 0, n);
  if (pOperador == -1)
  {
    printf("Erro ao encontrar o operador principal na expressão '%s'.\n", expressao);
    exit(1);
  }
  ArvoreNo *raiz = arvoreCriaNovoNo(expressao[pOperador], pOperador);

  int atual = 0;

  ArvoreNo *subarvoreEsq = geraSubarvoreExpressao(expressao, 0, pOperador - 1, &atual);
  raiz = arvoreAdicionaNo(raiz, subarvoreEsq);

  ArvoreNo *subarvoreDir = geraSubarvoreExpressao(expressao, pOperador + 1, n, &atual);
  raiz = arvoreAdicionaNo(raiz, subarvoreDir);

  return raiz;
}

ArvoreNo *geraSubarvoreExpressao(char *exp, int ini, int fim, int *atual)
{
  PilhaArvore *pSubarvores = pilhaArvoreInicia();
  int preferenciaOperador = 0;

  for (int i = ini; i <= fim; i++)
  {
    *atual = i; /* caso o fechamento do parênteses esteja na outra extremidade da expressão */
    if (exp[i] == '(')
    {
      ArvoreNo *noPai = geraSubarvoreExpressao(exp, i + 1, fim, atual);
      pilhaArvorePush(pSubarvores, noPai);
      i = *atual;
    }
    else if (exp[i] == ')')
    {
      break;
    }
    else if (ehOperador(exp[i]))
    {
      if (pilhaArvoreTamanho(pSubarvores) >= 2 && (exp[i] == '+' || exp[i] == '-'))
      {
        ArvoreNo *noFilho = pilhaArvorePop(pSubarvores);
        ArvoreNo *noPai = pilhaArvorePop(pSubarvores);
        noPai = arvoreAdicionaNo(noPai, noFilho);
        pilhaArvorePush(pSubarvores, noPai);
      }
      else if (exp[i] == '*' || exp[i] == '/')
        preferenciaOperador += 1;

      ArvoreNo *noPai = arvoreCriaNovoNo(exp[i], i);
      ArvoreNo *noFilho = pilhaArvorePop(pSubarvores);
      noPai = arvoreAdicionaNo(noPai, noFilho);
      pilhaArvorePush(pSubarvores, noPai);
    }
    else if (ehOperando(exp[i]))
    {
      ArvoreNo *noFilho = arvoreCriaNovoNo(exp[i], i);
      if (preferenciaOperador >= 1)
      {
        ArvoreNo *noPai = pilhaArvorePop(pSubarvores);
        noPai = arvoreAdicionaNo(noPai, noFilho);
        pilhaArvorePush(pSubarvores, noPai);
        preferenciaOperador -= 1;
      }
      else
        pilhaArvorePush(pSubarvores, noFilho);
    }
  }

  int i = pilhaArvoreTamanho(pSubarvores);
  while (i >= 2)
  {
    ArvoreNo *noFilho = pilhaArvorePop(pSubarvores);
    ArvoreNo *noPai = pilhaArvorePop(pSubarvores);
    noPai = arvoreAdicionaNo(noPai, noFilho);
    pilhaArvorePush(pSubarvores, noPai);
    i = pilhaArvoreTamanho(pSubarvores);
  }

  ArvoreNo *aux = pilhaArvorePop(pSubarvores);

  pilhaArvoreUnstack(&pSubarvores);

  return aux;
}

/* Função que encontra o operador da ultima operação, aquele q será a raiz da arvore */
int buscaOperadorPrincipal(char *expressao, int ini, int fim)
{
  int index = -1;
  int temp = -1;

  int parentesesOpen = 0;

  for (int i = fim - 1; i >= ini; i--)
  {
    if (expressao[i] == ')')
      parentesesOpen += 1;
    else if (expressao[i] == '(')
      parentesesOpen -= 1;
    else if (ehOperador(expressao[i]) && !parentesesOpen)
    {
      if ((expressao[i] == '*' || expressao[i] == '/'))
      {
        if (temp == -1)
          temp = i;
      }
      else
      {
        index = i;
        break;
      }
    }
  }

  if (index == -1)
  {
    if (temp != -1)
      index = temp;
    else
      index = buscaOperadorPrincipal(expressao, ini + 1, fim - 1); /* caso a expressão esteja toda dentro de parênteses */
  }

  return index;
}

float calculadoraArvore(ArvoreNo **raiz)
{
  int nNos = arvoreNumeroNos(*raiz);

  Pilha *pilha = pilhaInicia(nNos);
  arvorePosOrdem(*raiz, pilha);

  float result = -1;

  if (pilhaTamanho(pilha) == 1)
    result = pilhaPop(pilha);

  pilhaUnstack(&pilha);

  return result;
}

void trataString(char *expressao, int n)
{
  if (contemEspaco(expressao, n))
  { /* verifica se há espaços */
    char *aux = calloc(n, sizeof(char));

    for (int j = 0, i = 0; i < n; i++)
    { /* remove os espaços */
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

int contemEspaco(char *expressao, int n)
{
  for (int i = 0; i < n; i++)
    if (expressao[i] == ' ')
      return 1;

  return 0;
}

int ehOperador(char c)
{
  return ((c == '+') || (c == '-') ||
          (c == '*') || (c == '/'));
}

int ehOperando(char expressao)
{
  return (expressao >= '0' && expressao <= '9');
}
