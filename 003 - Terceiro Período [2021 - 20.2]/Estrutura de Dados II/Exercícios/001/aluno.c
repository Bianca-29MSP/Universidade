/*

* matrícula (posições 1 a 4 do arquivo);
* nome (posições 6 a 35 do arquivo);
* nota 1 (posições 37 a 40 do arquivo);
* nota 2 (posições 42 a 45 do arquivo);
* nota 3 (posições 47 a 50 do arquivo);
* faltas (posições 52 e 53 do arquivo).

*/
#include "aluno.h"

struct aluno
{
  int matricula;
  char nome[30];
  float notas[3];
  int faltas;
};

Aluno *aluno_cria()
{
  Aluno *aux = (Aluno *)malloc(sizeof(Aluno));

  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  return aux;
}

Aluno **aluno_cria_array(int n)
{
  Aluno **aux = (Aluno **)malloc(sizeof(Aluno *) * n);

  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  for (int i = 0; i < n; i++)
    aux[i] = aluno_cria();

  return aux;
}

void aluno_set_matricula(Aluno *aluno, int mat)
{
  aluno->matricula = mat;
}

void aluno_set_nome(Aluno *aluno, char *nome)
{
  strcpy(aluno->nome, nome);
}

void aluno_set_notas(Aluno *aluno, float notas[3])
{
  aluno->notas[0] = notas[0];
  aluno->notas[1] = notas[1];
  aluno->notas[2] = notas[2];
}

void aluno_set_faltas(Aluno *aluno, int faltas)
{
  aluno->faltas = faltas;
}

int aluno_get_matricula(Aluno *aluno)
{
  return aluno->matricula;
}

char *aluno_get_nome(Aluno *aluno)
{
  return aluno->nome;
}

void aluno_get_notas(Aluno *aluno, float notas[3])
{
  notas[0] = aluno->notas[0];
  notas[1] = aluno->notas[1];
  notas[2] = aluno->notas[2];
}

int aluno_get_faltas(Aluno *aluno)
{
  return aluno->faltas;
}

char aluno_get_conceito(Aluno *aluno)
{
  if (aluno->faltas > 18)
    return 'F';
  else
  {
    float media = (aluno->notas[0] + aluno->notas[1] + aluno->notas[2]) / 3;
    if (media < 6)
      return 'R';
    else if (media < 7.5)
      return 'C';
    else if (media < 9)
      return 'B';
    else
      return 'A';
  }
}
