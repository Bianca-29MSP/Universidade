#include "empresa.h"

int main()
{

  Empresa *empresa;
  int n = 0;
  char emp_nome[50], emp_cidade[50];

  scanf("%[^\n]s", emp_nome);
  scanf("\n%[^\n]s", emp_cidade);

  empresa = emp_create(emp_nome, emp_cidade);

  char func_nome[50], func_n_nome[50];
  char func_email[100];
  int func_idade;

  int op = -1;
  int count = 0;

  while (op != 0)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 0:
      op = 0;
      break;
    case 1:
      emp_get_funcionarios(empresa, n);
      break;
    case 2:
      emp_free(&empresa);
      count = 1;
      break;
    case 3:
      scanf("%d", &n);
      emp_set_funcionarios(empresa, n);
      for (int i = 0; i < n; i++)
      {
        scanf("%s %s %d", func_nome, func_email, &func_idade);
        emp_set_funcionario(empresa, i, func_nome, func_email, func_idade);
      }
      break;
    case 4:
      if (n > 0)
      {
        scanf("%s", func_nome);
        emp_destoy_func_nome(empresa, &n, func_nome);
      }
      else
        printf("Nenhum funcioário cadastrado.\n");
      break;
    case 5:
      printf("%s\n", emp_get_nome(empresa));
      break;
    case 6:
      printf("%s\n", emp_get_cidade(empresa));
      break;
    case 7:
      scanf("\n%50[^\n]s", emp_nome);
      emp_set_nome(empresa, emp_nome);
      break;
    case 8:
      if (n > 0)
      {
        scanf("%s %s", func_nome, func_n_nome);
        emp_set_func_nome(empresa, n, func_nome, func_n_nome);
      }
      else
        printf("Nenhum funcioário cadastrado.\n");
      break;
    default:
      op = 0;
      break;
    }
  }

  if (count != 1)
    emp_free(&empresa);

  return 0;
}