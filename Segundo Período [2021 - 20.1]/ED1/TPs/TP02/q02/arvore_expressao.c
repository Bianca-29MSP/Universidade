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
    printf("\n");
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
    printf("\n");
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
  ArvoreNo *raiz = arvoreCriaNovoNo(expressao[pOperador], pOperador);

  ArvoreNo *noEsq = geraSubarvoreExpressao(expressao, 0, pOperador - 1);
  raiz = arvoreAdicionaNo(raiz, noEsq);

  ArvoreNo *noDir = geraSubarvoreExpressao(expressao, pOperador + 1, n);
  raiz = arvoreAdicionaNo(raiz, noDir);

  return raiz;
}

ArvoreNo *geraSubarvoreExpressao(char *exp, int ini, int fim)
{
  PilhaArvore *pRaizes = pilhaArvoreInicia((fim - ini + 1));

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
        ArvoreNo *folha = pilhaArvorePop(pRaizes);
        ArvoreNo *no = pilhaArvorePop(pRaizes);
        no = arvoreAdicionaNo(no, folha);
        pilhaArvorePush(pRaizes, no);
      }
      if (tinhaPreferencia == 1)
        preferencia = 1;
      parenteseOpen -= 1;
    }
    else if (ehOperador(exp[i]))
    {
      if (tinhaPreferencia != 1 && preferencia != 1 && pilhaArvoreTamanho(pRaizes) >= 2 && (exp[i] == '+' || exp[i] == '-'))
      {
        ArvoreNo *folha = pilhaArvorePop(pRaizes);
        ArvoreNo *no = pilhaArvorePop(pRaizes);
        no = arvoreAdicionaNo(no, folha);
        pilhaArvorePush(pRaizes, no);

        no = arvoreCriaNovoNo(exp[i], i); /*Cria subarvore */
        if (!pilhaArvoreEhVazia(pRaizes))
        {
          no = arvoreAdicionaNo(no, pilhaArvorePop(pRaizes));
        }
        pilhaArvorePush(pRaizes, no);
      }
      else
      {
        if (preferencia == 1)
        {
          if (pilhaArvoreTamanho(pRaizes) > 1)
          {
            ArvoreNo *folha = pilhaArvorePop(pRaizes);
            ArvoreNo *no = pilhaArvorePop(pRaizes);
            no = arvoreAdicionaNo(no, folha);
            pilhaArvorePush(pRaizes, no);
          }
        }

        ArvoreNo *no = arvoreCriaNovoNo(exp[i], i); /*Cria subarvore */
        if (!pilhaArvoreEhVazia(pRaizes))
        {
          no = arvoreAdicionaNo(no, pilhaArvorePop(pRaizes));
        }
        pilhaArvorePush(pRaizes, no);
      }

      if (exp[i] == '*' || exp[i] == '/')
        preferencia = 1;
    }
    else if (ehOperando(exp[i]))
    {
      ArvoreNo *folha = arvoreCriaNovoNo(exp[i], i);
      if (preferencia == 1 && parenteseOpen == 0)
      {
        ArvoreNo *no = pilhaArvorePop(pRaizes);
        no = arvoreAdicionaNo(no, folha);
        pilhaArvorePush(pRaizes, no);
      }
      else
      {
        pilhaArvorePush(pRaizes, folha);
      }
    }
  }

  int i = pilhaArvoreTamanho(pRaizes);
  while (i > 1)
  {
    ArvoreNo *folha = pilhaArvorePop(pRaizes);
    ArvoreNo *no = pilhaArvorePop(pRaizes);
    no = arvoreAdicionaNo(no, folha);
    pilhaArvorePush(pRaizes, no);
    i = pilhaArvoreTamanho(pRaizes);
  }

  ArvoreNo *aux = pilhaArvorePop(pRaizes);

  pilhaArvoreLibera(&pRaizes);

  return aux;
}

/* Função que encontra o primeiro operador, aquele q será a raiz da arvore */
int buscaOperadorPrincipal(char *expressao, int ini, int fim)
{
  int index = -1;

  if (ini == fim)
  {
    return ini;
  }
  else if ((ini + 1) == fim)
    return ini - 1;

  if (expressao[ini] == '(')
  { /* Caso a expressão comece com um parênteses */
    int parenteseOpen = 1;
    int n = 1;
    while (index == -1 && (ini + n) < fim)
    {
      for (int i = ini + n; i < fim; i++)
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
      n += 1;
      parenteseOpen = 1;
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
    int aux = buscaOperadorPrincipal(expressao, index + 1, fim);
    if (aux != -1)
      index = aux;
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
