#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha
{
  Item itens[N];
  int tam;
};

void Pilha_Inicia(Pilha *pLista);

int Pilha_EhVazia(Pilha *pLista);

int Pilha_InsereP(Pilha *pLista, int p, Item x);

Item Pilha_RetiraP(Pilha *pLista, int p, Item *pX);

int Pilha_Tamanho(Pilha *pLista);