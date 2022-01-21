#include "aluno.h"

int main()
{
  int n;
  Aluno **aluno;

  int matricula;
  char nome[50];
  float notas[3];
  int falta;

  scanf("%d", &n);
  aluno = aluno_create_array(n);

  for (int i = 0; i < n; i++)
  {
    scanf("%d %s %f %f %f %d", &matricula, nome, &notas[0], &notas[1], &notas[2], &falta);
    aluno[i] = aluno_create(matricula, nome, notas, falta);
    aluno_set_conceito(aluno[i]);
  }

  aluno_get_all(aluno, n);

  aluno_destroy(aluno);

  return 0;
}