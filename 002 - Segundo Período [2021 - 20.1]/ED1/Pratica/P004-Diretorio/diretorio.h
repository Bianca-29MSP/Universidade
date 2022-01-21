
#ifndef diretorio_h
#define diretorio_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

typedef struct diretorio Diretorio;

Diretorio *dir_create_one(char *nome, int max_arquivos);

float dir_get_size(Diretorio *diretorio);

char *dir_get_name(Diretorio *diretorio);

void dir_set_name(Diretorio *diretorio, char *nome);

void dir_free(Diretorio **diretorio);

void dir_index_files(Diretorio *diretorio);

int dir_rename_file(Diretorio *diretorio, char *current_name, char *new_name);

void dir_set_new_file(Diretorio *diretorio, char *nome, char *extensao, float tamanho);

int dir_destroy_file(Diretorio *diretorio, char *nome);

#endif
