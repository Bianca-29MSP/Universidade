/*
* pilha_vetor.c
* Pilha em vetor estatico
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

#define MAXTAM 5

struct pilha
{
  int dados[MAXTAM];
  int top;
};

bool pilhaEstaCheia(Pilha *p)
{
  if (p->top == MAXTAM)
    return true;
  return false;
}

bool pilhaEstaVazia(Pilha *p)
{
  if (p->top == 0)
    return true;
  return false;
}

Pilha *inicializaPilha() /* Inicia toda a pilha com valor -1 [vazia] */
{
  Pilha *aux = (Pilha *)malloc(sizeof(Pilha));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(0);
  }
  for (int i = 0; i < MAXTAM; i++)
  {
    aux->dados[i] = -1;
  }
  aux->top = 0;
  return aux;
}

void empilha(Pilha *p, int dado)
{
  if (pilhaEstaCheia(p))
  {
    printf("Pilha cheia.\n");
    return;
  }
  else
  {
    p->dados[p->top] = dado;
    p->top += 1;
  }
}

int desempilha(Pilha *p)
{
  if (pilhaEstaVazia(p))
  {
    printf("Pilha vazia.\n");
    return -1;
  }
  else
  {
    p->top -= 1;
    return p->dados[p->top];
  }
}

void imprimePilha(Pilha *p)
{
  if (pilhaEstaVazia(p))
  {
    printf("Pilha vazia.\n");
    return;
  }
  else
  {
    for (int i = 0; i < p->top; i++)
    {
      printf("%d ", p->dados[i]);
    }
    printf("\n");
  }
}
