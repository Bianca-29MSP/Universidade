#ifndef funcionario_h
#define funcionario_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct funcionario Funcionario;

Funcionario *func_create_one(char *nome, char *email, int idade);

Funcionario **func_create_array(int n);

void func_get(Funcionario *func);

int func_get_by_nome(Funcionario **func, char *nome, int n);

void func_set_nome(Funcionario *func, char *nome);

void func_free(Funcionario ***func);

#endif