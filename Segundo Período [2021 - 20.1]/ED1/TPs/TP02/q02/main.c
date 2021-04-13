#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arvore_expressao.h"

#define MAXTAM 100

char **leArquivo(int *nExp);

int main()
{
  char expressao[MAXTAM];
  char **expressoes;

  int n, opEntrada, opSaida;

  printf("1 - Expressões via terminal.\n2 - Expressões  via arquivo [expressoes.txt].\n");
  scanf("%d", &opEntrada);

  if (opEntrada == 1)
  {
    printf("Número de expressões a serem lidas: ");
    scanf("%d", &n);
  }
  else if (opEntrada == 2)
  {
    expressoes = leArquivo(&n);
  }

  printf("1 - Resultado(s) via terminal.\n2 - Resultado(s) via arquivo .txt\n3 - Resultado(s) em ambas opções.\n");
  scanf("%d", &opSaida);

  if (opSaida == 2 || opSaida == 3)
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
    if (opEntrada == 1)
    {
      scanf("\n%100[^\n]s", expressao);
      calculaArvExpressao(expressao, opSaida);
    }
    else if (opEntrada == 2)
    {
      calculaArvExpressao(expressoes[i], opSaida);
      free(expressoes[i]);
    }
  }

  if (opEntrada == 2)
    free(expressoes);
  return 0;
}

char **leArquivo(int *nExp)
{
  FILE *arq = fopen("./arquivos/expressoes.txt", "r");

  if (arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  char aux[MAXTAM];
  int n;

  fscanf(arq, "%s", aux);
  n = atoi(aux);

  char **arr = malloc(sizeof(char **) * n);
  for (int i = 0; i < n; i++)
    arr[i] = malloc(sizeof(char) * 100);

  int i = 0;

  while (fgets(aux, sizeof(aux), arq))
  {
    fputs(aux, arq);
    aux[strcspn(aux, "\n")] = 0; /*removendo \n*/
    if (strlen(aux) > 1)
      strcpy(arr[i++], aux);
  }

  *nExp = n;

  fclose(arq);

  return arr;
}