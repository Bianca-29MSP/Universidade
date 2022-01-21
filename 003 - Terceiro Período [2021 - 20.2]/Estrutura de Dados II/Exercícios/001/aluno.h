#ifndef aluno_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *aluno_cria();

Aluno **aluno_cria_array(int);

void aluno_set_matricula(Aluno *, int);

void aluno_set_nome(Aluno *, char *);

void aluno_set_notas(Aluno *, float[3]);

void aluno_set_faltas(Aluno *, int);

int aluno_get_matricula(Aluno *);

char *aluno_get_nome(Aluno *);

void aluno_get_notas(Aluno *, float[3]);

int aluno_get_faltas(Aluno *);

char aluno_get_conceito(Aluno *);

#endif