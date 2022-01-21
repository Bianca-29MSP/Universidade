#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

struct arquivo
{
  char nome[50];
  char extensao[5];
  float tamanho;
};

Arquivo *file_set_values(char *nome, char *extensao, float tamanho)
{
  Arquivo *aux = (Arquivo *)malloc(sizeof(Arquivo));
  strcpy(aux->nome, nome);
  strcpy(aux->extensao, extensao);
  aux->tamanho = tamanho;
  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  return aux;
}

Arquivo **file_create_array(int n)
{
  Arquivo **aux = (Arquivo **)calloc(n, sizeof(Arquivo *));
  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  return aux;
}

void file_free(Arquivo **arqv)
{
  free(*arqv);
  *arqv = NULL;
}

char *file_get_name(Arquivo *arqv)
{
  return arqv->nome;
}

float file_get_size(Arquivo *arqv)
{
  return arqv->tamanho;
}

int file_set_name(Arquivo *arqv, char *nome)
{
  strcpy(arqv->nome, nome);
  return 1;
}

void file_relloc(Arquivo *arqv1, Arquivo *arqv2)
{
  arqv1 = arqv2;
  arqv2 = NULL;
}