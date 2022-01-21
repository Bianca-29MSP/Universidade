#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashing.h"

int hash(TChave ch, int p)
{
  int h = 0;
  for (int i = 0; i < p; i++)
    h = (31 * h + ch[i]) % M;
  return h;
}

void TDicionario_Inicia(TDicionario dic)
{
  for (int i = 0; i < M; i++)
    memcpy(dic[i].chave, VAZIO, N);
}

int TDicionario_Pesquisa(TDicionario dic, TChave chave, int p)
{
  int i = 0;
  int ini = hash(chave, p);

  while (strcmp(dic[(ini + i) % M].chave, VAZIO) != 0 &&
         strcmp(dic[(ini + i) % M].chave, chave) != 0 && i < M)
    i++;

  if (strcmp(dic[(ini + i) % M].chave, chave) == 0)
    return (ini + i) % M;
  return -1;
}

int TDicionario_Insere(TDicionario dic, TItem x, int p)
{
  if (TDicionario_Pesquisa(dic, x.chave, p) >= 0)
    return 0;

  int i = 0;
  int ini = hash(x.chave, p);
  while (strcmp(dic[(ini + i) % M].chave, VAZIO) != 0 && i < M)
    i++;

  if (i < M)
  {
    dic[(ini + i) % M] = x;
    return 1;
  }

  return 0;
}

int TDicionario_Retira(TDicionario dic, TItem *x, int p)
{
  int i = TDicionario_Pesquisa(dic, x->chave, p);
  if (i == -1)
    return 0; // chave não encontrada
  memcpy(dic[i].chave, VAZIO, N);
  return 1;
}

void TDicionario_Imprimir(TDicionario dic)
{
  for (int i = 0; i < M; i++)
  {
    if (strcmp(dic[i].chave, VAZIO) != 0)
      printf("%d) %s\n", i, dic[i].chave);
    else
      printf("%d) \n", i);
  }
  printf("\n");
}