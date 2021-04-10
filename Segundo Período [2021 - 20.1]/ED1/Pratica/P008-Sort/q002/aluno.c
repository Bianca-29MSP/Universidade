#include <stdlib.h>
#include "aluno.h"

struct aluno
{
  int matricula;
  double prova;
  double trabPratico;
  double media;
};

struct alunos
{
  Aluno *alunos;
  int quantdade;
};

Aluno *aluno_Aloca()
{
  Aluno *aux = (Aluno *)malloc(sizeof(Aluno));
  aux->matricula = 0;
  aux->prova = -1;
  aux->trabPratico = -1;
  aux->media = -1;
  return aux;
}

Aluno **aluno_AlocaVetor(int n)
{
  Aluno **aux = (Aluno **)malloc(n * sizeof(Aluno *));
  for (int i = 0; i < n; i++)
  {
    aux[i] = aluno_Aloca();
  }
  return aux;
}

int aluno_getMatricula(Aluno *aluno)
{
  return aluno->matricula;
}

double aluno_getProva(Aluno *aluno)
{
  return aluno->prova;
}

double aluno_getTrabPratico(Aluno *aluno)
{
  return aluno->trabPratico;
}

double aluno_getMedia(Aluno *aluno)
{
  return aluno->media;
}

void aluno_setMatricula(Aluno *aluno, int n)
{
  aluno->matricula = n;
}

void aluno_setProva(Aluno *aluno, double n)
{
  aluno->prova = n;
}

void aluno_setTrabPratico(Aluno *aluno, double n)
{
  aluno->trabPratico = n;
}

void aluno_setMedia(Aluno *aluno, double n)
{
  aluno->media = n;
}

double aluno_CalculaMedia(Aluno *aluno, double pesoProva, double pesoTPratico)
{
  return (((aluno->prova * pesoProva) + (aluno->trabPratico * pesoTPratico)) / (pesoProva + pesoTPratico));
}

void aluno_Libera(Aluno ***aluno, int n)
{
  for (int i = 0; i < n; i++)
  {
    free((*aluno)[i]);
  }
  free(*aluno);
  *aluno = NULL;
}