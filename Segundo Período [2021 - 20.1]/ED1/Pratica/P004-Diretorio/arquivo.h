
#ifndef arquivo_h
#define arquivo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arquivo Arquivo;

Arquivo *file_set_values(char *nome, char *extensao, float tamanho);

Arquivo **file_create_array(int n);

void file_free(Arquivo ***arqv);

char *file_get_name(Arquivo *arqv);

float file_get_size(Arquivo *arqv);

int file_set_name(Arquivo *arqv, char *nome);

void file_relloc(Arquivo *arqv1, Arquivo *arqv2);

#endif
