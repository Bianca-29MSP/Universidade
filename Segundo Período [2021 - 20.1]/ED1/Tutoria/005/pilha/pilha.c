/*
* pilha.c
* Enya L. G. Santos
* 19.2.4201
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct pilhaNo PilhaNo;

struct pilha
{
  PilhaNo *top;
};

struct pilhaNo
{
  int dado;
  PilhaNo *prox;
};

Pilha *pilhaAloca()
{
  Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(0);
  }
  aux->top = NULL;
  return aux;
}

void pilhaPush(Pilha *p, int x)
{ //Função que insere o valor inteiro na pilha
  PilhaNo *ptr = (PilhaNo *)malloc(sizeof(PilhaNo));
  if (ptr == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(0);
  }
  ptr->dado = x;
  ptr->prox = p->top;
  p->top = ptr;
}

void pilhaPop(Pilha *p, int *px)
{ //Retira um nó da pilha e retorna o valor inteiro px
  PilhaNo *ptr = p->top;
  if (ptr == NULL)
  {
    printf("Pilha vazia.\n");
    return;
  }
  p->top = ptr->prox;
  ptr->prox = NULL;
  *px = ptr->dado;
  free(ptr);
}

void pilhaUnstack(Pilha *p)
{ //Desempilha completamente a pilha
  int aux;
  PilhaNo *ptr = p->top;
  while (ptr != NULL)
  {
    pilhaPop(p, &aux);
    ptr = p->top;
    printf("%d ", aux);
  }
  printf("\n");
  free(ptr);
}

void pilhaRead(Pilha *p)
{
  PilhaNo *ptr = p->top;
  if (ptr == NULL)
  {
    printf("Lista vazia.\n");
    return;
  }

  while (ptr != NULL)
  {
    printf("%d ", ptr->dado);
    ptr = ptr->prox;
  }
  printf("\n");
}
