#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

struct pilha
{
  Lista *lista;
  int topo;
};

void Pilha_Inicia(Pilha **pPilha)
{
  *pPilha = (Pilha *)malloc(sizeof(pPilha));
  Lista_Inicia(&(*pPilha)->lista);
  (*pPilha)->topo = 0;
}

int Pilha_EhVazia(Pilha *pPilha)
{
  return Lista_EhVazia(pPilha->lista);
}

void Pilha_Push(Pilha *pPilha, Item x)
{
  Lista_Insere(pPilha->lista, pPilha->topo, x);
  //Lista_Insere(pPilha->lista, pPilha->topo, x);
  //pPilha->topo = Lista_Tamanho(pPilha->lista);
}

int Pilha_Pop(Pilha *pPilha, Item *pX)
{
  int retorno = Lista_Remove(pPilha->lista, pPilha->topo, pX);
  // if (retorno)
  //   pPilha->topo = Lista_Tamanho(pPilha->lista);
  return retorno;
}

int Pilha_Tamanho(Pilha *pPilha)
{
  return Lista_Tamanho(pPilha->lista);
}

void Pilha_imprime(Pilha *pPilha)
{
  Lista_imprime(pPilha->lista);
}

void Pilha_Libera(Pilha **pPilha)
{
  Lista_Libera(&(*pPilha)->lista);
  free(*pPilha);
  *pPilha = NULL;
}