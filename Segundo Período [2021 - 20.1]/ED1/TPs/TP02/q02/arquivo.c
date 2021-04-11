#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTAM 100

char **leArquivo(int *nExp)
{
  FILE *arqLe = fopen("expressoes.txt", "r");

  if (arqLe == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  char aux[MAXTAM];
  int n;

  fscanf(arqLe, "%s", aux);
  n = atoi(aux);

  char **arr = malloc(sizeof(char **) * n);
  for (int i = 0; i < n; i++)
    arr[i] = malloc(sizeof(char) * 100);

  int i = 0;

  while (fgets(aux, sizeof(aux), arqLe))
  {
    fputs(aux, arqLe);
    aux[strcspn(aux, "\n")] = 0; /*removendo \n*/
    if (strlen(aux) > 1)
      strcpy(arr[i++], aux);
  }

  // for (int i = 0; i < n; i++)
  //   printf("$ %d => %s", i, arr[i]);

  //printf("%d\n", n);
  *nExp = n;

  fclose(arqLe);

  return arr;
}