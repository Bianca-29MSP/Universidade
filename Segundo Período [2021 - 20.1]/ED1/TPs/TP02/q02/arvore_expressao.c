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
    printf("Erro ao encontrar o operado principal na expressão '%s'.\n", expressao);
    exit(1);
  }
  ArvoreNo *raiz = arvoreCriaNovoNo(expressao[pOperador], pOperador);

  int atual = 0;

  ArvoreNo *noEsq = geraSubarvoreExpressao(expressao, 0, pOperador - 1, &atual);
  raiz = arvoreAdicionaNo(raiz, noEsq);

  ArvoreNo *noDir = geraSubarvoreExpressao(expressao, pOperador + 1, n, &atual);
  raiz = arvoreAdicionaNo(raiz, noDir);

  return raiz;
}

ArvoreNo *geraSubarvoreExpressao(char *exp, int ini, int fim, int *atual)
{
  PilhaArvore *pSubarvores = pilhaArvoreInicia();

  int preferencia = 0;

  for (int i = ini; i <= fim; i++)
  {
    *atual = i; /* caso o fechamento do parênteses esteja na outra extremidade da expressão */
    if (exp[i] == '(')
    {
      ArvoreNo *no = geraSubarvoreExpressao(exp, i + 1, fim, atual);
      pilhaArvorePush(pSubarvores, no);
      i = *atual;
    }
    else if (exp[i] == ')')
    {
      break;
    }
    else if (ehOperador(exp[i]))
    {
      if ((exp[i] == '+' || exp[i] == '-') &&
          pilhaArvoreTamanho(pSubarvores) >= 2 &&
          preferencia == 0)
      {
        ArvoreNo *folha = pilhaArvorePop(pSubarvores);
        ArvoreNo *no = pilhaArvorePop(pSubarvores);
        no = arvoreAdicionaNo(no, folha);
        pilhaArvorePush(pSubarvores, no);

        no = arvoreCriaNovoNo(exp[i], i);
        no = arvoreAdicionaNo(no, pilhaArvorePop(pSubarvores));
        pilhaArvorePush(pSubarvores, no);
      }
      else
      {
        if (preferencia > 0)
          if (pilhaArvoreTamanho(pSubarvores) >= 2)
          {
            ArvoreNo *folha = pilhaArvorePop(pSubarvores);
            ArvoreNo *no = pilhaArvorePop(pSubarvores);
            no = arvoreAdicionaNo(no, folha);
            pilhaArvorePush(pSubarvores, no);
          }

        ArvoreNo *no = arvoreCriaNovoNo(exp[i], i); /*Cria subarvore */
        no = arvoreAdicionaNo(no, pilhaArvorePop(pSubarvores));
        pilhaArvorePush(pSubarvores, no);
      }

      if (exp[i] == '*' || exp[i] == '/')
        preferencia += 1;
    }
    else if (ehOperando(exp[i]))
    {
      ArvoreNo *folha = arvoreCriaNovoNo(exp[i], i);
      if (preferencia == 1)
      {
        ArvoreNo *no = pilhaArvorePop(pSubarvores);
        no = arvoreAdicionaNo(no, folha);
        pilhaArvorePush(pSubarvores, no);
        preferencia -= 1;
      }
      else
        pilhaArvorePush(pSubarvores, folha);
    }
  }

  int i = pilhaArvoreTamanho(pSubarvores);
  while (i >= 2)
  {
    ArvoreNo *folha = pilhaArvorePop(pSubarvores);
    ArvoreNo *no = pilhaArvorePop(pSubarvores);
    no = arvoreAdicionaNo(no, folha);
    pilhaArvorePush(pSubarvores, no);
    i = pilhaArvoreTamanho(pSubarvores);
  }

  ArvoreNo *aux = pilhaArvorePop(pSubarvores);

  pilhaArvoreUnstack(&pSubarvores);

  return aux;
}

/* Função que encontra o primeiro operador, aquele q será a raiz da arvore */
int buscaOperadorPrincipal(char *expressao, int ini, int fim)
{
  int index = -1;
  int temp = -1;

  int parentesesOpen = 0;

  for (int i = fim - 1; i >= ini; i--)
  {
    if (expressao[i] == ')')
    {
      parentesesOpen += 1;
    }
    else if (expressao[i] == '(')
    {
      parentesesOpen -= 1;
    }
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
      index = buscaOperadorPrincipal(expressao, ini + 1, fim - 1); /* caso o a expressão esteja toda dentro de parênteses */
  }

  return index;
}

float calculadoraArvore(ArvoreNo **raiz)
{
  int nNos = arvoreNumeroNos(*raiz);

  Pilha *pilha;
  pilhaInicia(&pilha, nNos);
  arvorePosOrdem(*raiz, pilha);

  float result = -1;

  if (pilhaTamanho(pilha) == 1)
    result = pilhaPop(pilha);

  pilhalibera(&pilha);

  return result;
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
  return (expressao >= '0' && expressao <= '9');
}

int contemEspaco(char *expressao, int n)
{
  for (int i = 0; i < n; i++)
    if (expressao[i] == ' ')
      return 1;

  return 0;
}
