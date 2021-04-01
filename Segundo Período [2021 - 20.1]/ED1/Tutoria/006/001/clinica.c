/*
*   clinica.c
*   ENYA L. G. DOS SANTOS
*   19.2.4201
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clinica.h"

typedef struct filaNo FilaNo;

typedef struct cliente Cliente;

struct fila
{
  FilaNo *prim;
  FilaNo *fim;
};

struct cliente
{
  char nome[64];
  char descricao[100];
};

struct filaNo
{
  Cliente *cliente;
  FilaNo *prox;
};

Cliente *Cliente_Inicia(char *nome, char *descricao)
{
  Cliente *aux = (Cliente *)malloc(sizeof(Cliente));
  strcpy(aux->nome, nome);
  strcpy(aux->descricao, descricao);
  return aux;
}

Fila *Fila_Inicia()
{
  Fila *aux = (Fila *)malloc(sizeof(Fila));
  aux->prim = NULL;
  aux->fim = NULL;
  return aux;
}

bool Fila_EhVazia(Fila *pFila)
{
  if (pFila->prim == NULL)
    return true;
  return false;
}

void Fila_Enfileira(Fila *pFila, char *nome, char *descricao)
{
  FilaNo *nNo = (FilaNo *)malloc(sizeof(FilaNo));
  nNo->cliente = Cliente_Inicia(nome, descricao);
  nNo->prox = NULL;

  if (Fila_EhVazia(pFila))
  {
    pFila->prim = nNo;
    pFila->fim = nNo;
  }
  else
  {
    pFila->fim->prox = nNo;
    pFila->fim = nNo;
  }
}

int Fila_Desenfileira(Fila *pFila)
{
  if (!Fila_EhVazia(pFila))
  {
    FilaNo *primNo = pFila->prim;

    pFila->prim = primNo->prox;
    primNo->prox = NULL;

    free(primNo->cliente);
    free(primNo);

    if (pFila->prim == NULL)
      pFila->fim = NULL;

    return 1;
  }
  return 0;
}

void Fila_Primeiro(Fila *pFila, char *nome, char *descricao)
{
  if (!Fila_EhVazia(pFila))
  {
    FilaNo *primNo = pFila->prim;
    strcpy(nome, primNo->cliente->nome);
    strcpy(descricao, primNo->cliente->descricao);
  }
}

void Fila_Imprime(Fila *pFila)
{
  FilaNo *aux = pFila->prim;

  while (aux != NULL)
  {
    printf("Paciente: %s\n", aux->cliente->nome);
    printf("Descricao: %s\n", aux->cliente->descricao);

    aux = aux->prox;
  }
}

void Fila_Libera(Fila **pFila)
{
  while (!Fila_EhVazia(*pFila))
  {
    Fila_Desenfileira(*pFila);
  }
  free(*pFila);
  *pFila = NULL;
}
