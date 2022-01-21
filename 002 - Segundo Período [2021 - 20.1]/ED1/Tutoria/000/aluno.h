#ifndef aluno_h
#define aluno_h
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno **aluno_create_array(int n);

Aluno *aluno_create(int matricula, char *nome, float *notas, int falta);

void aluno_destroy(Aluno **aluno);

void aluno_set_conceito(Aluno *aluno);

void aluno_get(Aluno *aluno);

void aluno_get_all(Aluno **aluno, int n);

#endif
