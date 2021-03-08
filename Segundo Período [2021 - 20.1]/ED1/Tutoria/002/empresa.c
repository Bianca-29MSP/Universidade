#include "empresa.h"
#include "funcionario.h"

struct empresa
{
  char nome[50];
  char cidade[50];
  int max_funcionarios;
  int quantidade_funcionarios;
  Funcionario **funcionarios;
};

Empresa *emp_create(char *nome, char *cidade)
{
  Empresa *aux = (Empresa *)malloc(sizeof(Empresa));
  if (aux == NULL)
  {
    printf("Não há mamória suficiente.\n");
    exit(1);
  }
  strcpy(aux->nome, nome);
  strcpy(aux->cidade, cidade);
  return aux;
}

void emp_set_funcionarios(Empresa *empresa, int n)
{
  empresa->funcionarios = func_create_array(n);
}

void emp_set_funcionario(Empresa *empresa, int i, char *nome, char *email, int idade)
{
  empresa->funcionarios[i] = func_create_one(nome, email, idade);
}

void emp_get_funcionarios(Empresa *empresa, int n)
{
  for (int i = 0; i < n; i++)
  {
    func_get(empresa->funcionarios[i]);
  }
}

void emp_set_nome(Empresa *empresa, char *nome)
{
  strcpy(empresa->nome, nome);

  printf("Nome da empresa alterado.\n");
}

char *emp_get_nome(Empresa *empresa)
{
  return empresa->nome;
}

char *emp_get_cidade(Empresa *empresa)
{
  return empresa->cidade;
}

void emp_free(Empresa **empresa)
{
  func_free(&(**empresa).funcionarios);
  free(*empresa);
  *empresa = NULL;
}

void emp_set_func_nome(Empresa *empresa, int n, char *nome, char *n_nome)
{
  int index = func_get_by_nome(empresa->funcionarios, nome, n);
  func_set_nome(empresa->funcionarios[index], n_nome);

  printf("Nome do funcionário alterado.\n");
}

void emp_destoy_func_nome(Empresa *empresa, int *n, char *nome)
{
  int index = func_get_by_nome(empresa->funcionarios, nome, *n);
  for (int i = index; i < *n; i++)
  {
    empresa->funcionarios[i] = NULL;
    if (empresa->funcionarios[i + 1] != NULL)
      empresa->funcionarios[i] = empresa->funcionarios[i + 1];
  }

  free(empresa->funcionarios[*n]);

  *n -= 1;

  printf("Funcioário removido.\n");
}