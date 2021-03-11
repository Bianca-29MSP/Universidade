#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "pessoa.h"

struct pessoa
{
  char nome[100];
  int idade;
};

Pessoa *p_cria()
{
  Pessoa *aux = (Pessoa *)malloc(sizeof(Pessoa));
  return aux;
}

void p_setNome(Pessoa *p, char *nome)
{
  strcpy(p->nome, nome);
}

void p_setIdade(Pessoa *p, int idade)
{
  p->idade = idade;
}

int p_getIdade(Pessoa *p)
{
  return p->idade;
}

char *p_getNome(Pessoa *p)
{
  return p->nome;
}

void p_libera(Pessoa **p)
{
  free(*p);
  *p = NULL;
}