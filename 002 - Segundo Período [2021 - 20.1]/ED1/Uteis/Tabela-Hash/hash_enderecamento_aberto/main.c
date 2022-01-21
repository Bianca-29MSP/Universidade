#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashing.h"

int main()
{
  TDicionario dic;
  TItem item;
  char s[M];
  int op = 0;

  TDicionario_Inicia(dic);

  printf("1 - Inserir um item.\n2 - Pesquisar um item.\n3 - Retirar um item.\n4 - Imprimir tabela hash.\n");

  while (op != -1)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      scanf("%s", item.chave);
      TDicionario_Insere(dic, item, strlen(item.chave));
      break;
    case 2:
      scanf("%s", s);
      printf("%d\n", TDicionario_Pesquisa(dic, s, strlen(s)));
      break;
    case 3:
      scanf("%s", item.chave);
      printf("%d\n", TDicionario_Retira(dic, &item, strlen(item.chave)));
      break;
    case 4:
      TDicionario_Imprimir(dic);
      break;
    default:
      op = -1;
      break;
    }
  }

  return 0;
}
