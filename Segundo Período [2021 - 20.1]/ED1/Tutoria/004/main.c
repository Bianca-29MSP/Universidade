/*
* Enya Luísa Gomes dos Santos
* 19.2.42.01
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

int main()
{
  Lista *pessoas = lst_cria();
  int idade;
  char nome[100];
  int nIdade;
  char nNome[100];
  int op = 0;
  int count = 0;

  while (op != -1)
  {
    printf("Opção: ");
    scanf("%d", &op);
    switch (op)
    {
    case 0:
      count += 1;
      lst_liberar(&pessoas);
      break;
    case 1:
      scanf("%s %d", nome, &idade);
      lst_insere_inicio(pessoas, nome, idade);
      break;
    case 2:
      scanf("%s %d", nome, &idade);
      lst_insere_fim(pessoas, nome, idade);
      break;
    case 3:
      scanf("%s %d", nome, &idade);
      lst_insere_ordenado(pessoas, nome, idade);
      break;
    case 4:
      scanf("%s %d", nome, &idade);
      lst_retira(pessoas, nome, idade);
      break;
    case 5:
      scanf("%s", nome);
      printf("%d\n", lst_pertence(pessoas, nome));
      break;
    case 6:
      lst_imprime(pessoas);
      break;
    case 7:
      scanf("%s %d", nome, &idade);
      scanf("%s %d", nNome, &nIdade);
      lstNo_altera(pessoas, nome, idade, nNome, nIdade);
      break;
    default:
      op = -1;
      break;
    }
  }

  if (count == 0)
    lst_liberar(&pessoas);

  return 0;
}
