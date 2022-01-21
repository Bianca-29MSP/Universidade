#ifndef empresa_h
#define empresa_h

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct empresa Empresa;

Empresa *emp_create(char *nome, char *cidade);

void emp_set_funcionarios(Empresa *empresa, int n);

void emp_set_funcionario(Empresa *empresa, int i, char *nome, char *email, int idade);

void emp_get_funcionarios(Empresa *empresa, int n);

void emp_set_nome(Empresa *empresa, char *nome);

char *emp_get_nome(Empresa *empresa);

char *emp_get_cidade(Empresa *empresa);

void emp_set_func_nome(Empresa *empresa, int n, char *nome, char *n_nome);

void emp_destoy_func_nome(Empresa *empresa, int *n, char *nome);

void emp_free(Empresa **empresa);

#endif