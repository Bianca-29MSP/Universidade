/*
* pilha.c
* Trabalho pratico 2 de EDI (BCC202) - Árvore de expressão   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

typedef struct celula Celula;

struct celula
{
  Item item;
  Celula *prox;
};

struct pilha
{
  Celula *top;
  int tam;
};

Pilha *pilhaInicia()
{
  Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
  if (aux == NULL)
  {
    printf("Ocorreu algo de errado na alocação de memória.\n");
    exit(1);
  }
  aux->top = NULL;
  aux->tam = 0;
  return aux;
}

int pilhaEhVazia(Pilha *pPilha)
{
  if (pPilha->top == NULL)
    return 1;
  return 0;
}

int pilhaPush(Pilha *pPilha, Item x)
{
  Celula *celula = (Celula *)malloc(sizeof(Celula));
  celula->prox = pPilha->top;
  celula->item = x;
  pPilha->top = celula;
  pPilha->tam += 1;
  return 1;
}

Item pilhaPop(Pilha *pPilha)
{
  Celula *cTopo = pPilha->top;
  if (cTopo != NULL)
  {
    Item aux = cTopo->item;
    pPilha->top = cTopo->prox;
    pPilha->tam -= 1;
    free(cTopo);
    cTopo = NULL;
    return aux;
  }
  return -1;
}

int pilhaTamanho(Pilha *pPilha)
{
  return pPilha->tam;
}

void pilhaUnstack(Pilha **pPilha)
{
  Celula *ptr = (*pPilha)->top;
  while (ptr != NULL)
  {
    pilhaPop(*pPilha);
    ptr = NULL;
    ptr = (*pPilha)->top;
  }
  free(ptr);
  free(*pPilha);
  *pPilha = NULL;
  ptr = NULL;
}

float calculadoraPosOrdem(Pilha *pilha, char operador)
{
  float valor1 = pilhaPop(pilha);
  float valor2 = pilhaPop(pilha);

  switch (operador)
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

void constroiPilhaPosFixada(Pilha *pilha, char elemento)
{
  if (elemento == '+' ||
      elemento == '-' ||
      elemento == '*' ||
      elemento == '/')
    pilhaPush(pilha, calculadoraPosOrdem(pilha, elemento));
  else
  {
    pilhaPush(pilha, ((float)elemento - 48));
  }
}