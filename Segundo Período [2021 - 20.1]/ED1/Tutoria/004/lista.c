/*
* Enya Luísa Gomes dos Santos
* 19.2.42.01
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

typedef struct listaNo ListaNo;

struct lista
{
  ListaNo *prim;
};

struct listaNo
{
  Pessoa *info;
  ListaNo *prox;
};

Lista *lst_cria()
{
  Lista *auxL = (Lista *)malloc(sizeof(Lista));
  auxL->prim = NULL;
  return auxL;
}

ListaNo *lstNo_cria(char *nome, int idade)
{
  ListaNo *aux = (ListaNo *)malloc(sizeof(ListaNo));
  aux->prox = NULL;
  aux->info = p_cria();
  p_setNome(aux->info, nome);
  p_setIdade(aux->info, idade);
  return aux;
}

void lst_imprime(Lista *l)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    printf("%s %d\n", p_getNome(lNo->info), p_getIdade(lNo->info));
}

int lst_pertence(Lista *l, char *nome)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    if (!strcmp(nome, p_getNome(lNo->info)))
    {
      printf("%s %d\n", p_getNome(lNo->info), p_getIdade(lNo->info));
      return 1;
    }

  return -1;
}

void lst_insere_ordenado(Lista *l, char *nome, int idade)
{
  ListaNo *ant = NULL;
  ListaNo *prox = l->prim;

  while (prox != NULL && p_getIdade(prox->info) < idade)
  {
    ant = prox;
    prox = prox->prox;
  }

  ListaNo *novoNo = lstNo_cria(nome, idade);

  if (ant == NULL)
  {
    novoNo->prox = l->prim;
    l->prim = novoNo;
  }
  else
  {
    novoNo->prox = ant->prox;
    ant->prox = novoNo;
  }
}

void lst_insere_inicio(Lista *l, char *nome, int idade)
{
  ListaNo *ant = NULL;
  ListaNo *prox = l->prim;

  ListaNo *novoNo = lstNo_cria(nome, idade);

  if (prox == NULL)
  {
    novoNo->prox = l->prim;
    l->prim = novoNo;
  }
  else
  {
    ant = prox;
    novoNo->prox = ant;
    l->prim = novoNo;
  }
}

void lst_insere_fim(Lista *l, char *nome, int idade)
{
  ListaNo *novoNo = lstNo_cria(nome, idade);

  ListaNo *lNo = l->prim;
  if (lNo == NULL)
  {
    novoNo->prox = l->prim;
    l->prim = novoNo;
    return;
  }

  ListaNo *aux = NULL;
  for (lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    aux = lNo;
  aux->prox = novoNo;
}

void lstNo_altera(Lista *l, char *nome, int idade, char *nNome, int nIdade)
{
  for (ListaNo *lNo = l->prim; lNo != NULL; lNo = lNo->prox)
    if (!strcmp(nome, p_getNome(lNo->info)))
    {
      p_setNome(lNo->info, nNome);
      p_setIdade(lNo->info, nIdade);
    }
}

void lst_retira(Lista *l, char *nome, int idade)
{
  ListaNo *ant = NULL;
  ListaNo *prox = l->prim;

  while (prox != NULL && strcmp(nome, p_getNome(prox->info)) && p_getIdade(prox->info) != idade)
  {
    ant = prox;
    prox = prox->prox;
  }

  if (prox != NULL && !strcmp(nome, p_getNome(prox->info)) && p_getIdade(prox->info) == idade)
  {
    if (ant == NULL)
    {
      l->prim = prox->prox;
    }
    else
    {
      ant->prox = prox->prox;
    }
    p_libera(&prox->info);
    free(prox);
  }
}

void lst_liberar(Lista **l)
{
  ListaNo *pNo = (*l)->prim;
  while (pNo != NULL)
  {
    ListaNo *auxNo = pNo->prox;
    p_libera(&pNo->info);
    free(pNo);
    pNo = auxNo;
  }
  free(*l);
  *l = NULL;
}
