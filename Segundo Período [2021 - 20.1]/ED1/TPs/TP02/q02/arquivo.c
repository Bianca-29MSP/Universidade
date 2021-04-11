#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100

char **leArquivo(int *nExp)
{
  char nomeArq[60];

  printf("Nome do arquivo a ser lido [sem a extensão]: ");
  scanf("%s", nomeArq);

  strcat(nomeArq, ".txt");

  FILE *arq = fopen(nomeArq, "r");

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

void criaArquivo(int n)
{
  FILE *arq = fopen("resultados.txt", "w");

  if (arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  fprintf(arq, "%d\n", n);

  fclose(arq);
}

void escreveResultado(char *exp, int resultado, int nExp)
{
  FILE *arq = fopen("resultados.txt", "a");
  if (arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  fprintf(arq, "%s = %d\n", exp, resultado);

  fclose(arq);
}
