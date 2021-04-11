#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arvore_expressao.h"

#define MAXTAM 100

int main()
{
  char expressao[MAXTAM];

  int n, op;

  printf("Número de expressões a serem lidas: ");
  scanf("%d", &n);

  printf("1 - Resultado(s) via terminal.\n2 - Resultado(s) via arquivo .txt\n3 - Resultado(s) em ambas opções.\n");
  scanf("%d", &op);

  if (op == 2 || op == 3)
  {
    FILE *arq = fopen("resultados.txt", "w");
    if (arq == NULL)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(1);
    }
    fclose(arq);
  }

  for (int i = 0; i < n; i++)
  {
    scanf("\n%100[^\n]s", expressao);
    calculaArvExpressao(expressao, op);
  }

  return 0;
}
