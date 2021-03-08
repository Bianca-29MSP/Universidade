#include "aluno.h"

struct aluno
{
  int matricula;
  char nome[50];
  float notas[3];
  int faltas;
  char conceito;
};

Aluno **aluno_create_array(int n)
{
  Aluno **aux = (Aluno **)malloc(sizeof(Aluno) * n);

  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  return aux;
}

Aluno *aluno_create(int matricula, char *nome, float *notas, int falta)
{
  Aluno *aux = (Aluno *)malloc(sizeof(Aluno));

  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  aux->matricula = matricula;
  strcpy(aux->nome, nome);
  aux->faltas = falta;

  for (int i = 0; i < 3; i++)
    aux->notas[i] = notas[i];

  return aux;
}

void aluno_destroy(Aluno **aluno)
{
  free(aluno);
}

void aluno_set_conceito(Aluno *aluno)
{
  float media = 0;
  int faltas = aluno->faltas;

  for (int i = 0; i < 3; i++)
    media += aluno->notas[i];

  media /= 3;

  if (faltas > 18)
    aluno->conceito = 'F';
  else
  {
    if (media < 6)
      aluno->conceito = 'R';
    else if (media < 7.5)
      aluno->conceito = 'C';
    else if (media < 9)
      aluno->conceito = 'B';
    else if (media <= 10)
      aluno->conceito = 'A';
  }
}

void aluno_get(Aluno *aluno)
{
  printf("Nome: %s, Conceito: %c\n", aluno->nome, aluno->conceito);
}

void aluno_get_all(Aluno **aluno, int n)
{
  for (int i = 0; i < n; i++)
  {
    aluno_get(aluno[i]);
  }
}