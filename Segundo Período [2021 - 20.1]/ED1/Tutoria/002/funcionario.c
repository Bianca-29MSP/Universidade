#include "funcionario.h"

struct funcionario
{
  char nome[50];
  char email[100];
  int idade;
};

Funcionario *func_create_one(char *nome, char *email, int idade)
{
  Funcionario *aux = (Funcionario *)malloc(sizeof(Funcionario));
  if (aux == NULL)
  {
    printf("Não há mamória suficiente.\n");
    exit(1);
  }
  aux->idade = idade;
  strcpy(aux->nome, nome);
  strcpy(aux->email, email);
  return aux;
}

Funcionario **func_create_array(int n)
{
  Funcionario **aux = (Funcionario **)malloc(sizeof(Funcionario) * n);
  if (aux == NULL)
  {
    printf("Não há mamória suficiente.\n");
    exit(1);
  }
  return aux;
}

void func_get(Funcionario *func)
{
  printf("%s %s %d\n", func->nome, func->email, func->idade);
}

void func_free(Funcionario ***func)
{
  free(**func);
  **func = NULL;
}

void func_set_nome(Funcionario *func, char *nome)
{
  strcpy(func->nome, nome);
}

int func_get_by_nome(Funcionario **func, char *nome, int n)
{
  for (int i = 0; i < n; i++)
    if (!strcmp(func[i]->nome, nome))
      return i;

  return -1;
}
