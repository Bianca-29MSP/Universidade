/*
* pilha_dinamica.c
* Pilha alocada dinamicamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

Pilha *inicializaPilha()
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

void empilha(Pilha *p, int dado)
{
  PilhaNo *ptr = (PilhaNo *)malloc(sizeof(PilhaNo));
  if (ptr == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(0);
  }
  ptr->dado = dado;
  ptr->prox = p->top;
  p->top = ptr;
}

int desempilha(Pilha *p)
{
  int aux;
  PilhaNo *ptr = p->top;
  if (ptr == NULL)
  {
    printf("Pilha vazia.\n");
    return -1;
  }
  p->top = ptr->prox;
  ptr->prox = NULL;
  aux = ptr->dado;
  free(ptr);
  return aux;
}

void imprimePilha(Pilha *p)
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