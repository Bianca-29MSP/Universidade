/*
*	ENYA L. G. DOS SANTOS
*	19.2.4201
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "selectionsort.h"
#include "insertionsort.h"

int main()
{
  /* LEITURA DOS DADOS DO ARQUIVO 'dados.txt' E PASSAGEM DESSES DADOS PARA UM ARRAY   */
  FILE *arqLe = fopen("../arquivos/dados.txt", "r");
  if (arqLe == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  char c[6];
  int n, i = 0;

  fscanf(arqLe, "%s", c);
  n = atoi(c);

  int *arr = malloc(n * sizeof(int));
  int *aux = malloc(n * sizeof(int));

  while (!feof(arqLe))
  {
    fscanf(arqLe, "%s", c);
    arr[i++] = atoi(c);
  }

  for (int i = 0; i < n; i++)
    aux[i] = arr[i];

  selectionsort(arr, n);
  insertionsort(aux, n);

  fclose(arqLe);
  printf("Dados do arquivo 'dados.txt' foi armazenado com sucesso!\n");

  /* ESCRITA DO ARRAY ORDENADO PELO SELECTIONSORT E INSERTIONSORT NO ARQUIVO 'ordenado.txt' */
  FILE *arqOrdenado = fopen("../arquivos/ordenado.txt", "w");

  if (arqOrdenado == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  fprintf(arqOrdenado, "%s", "SelectionSort: ");
  for (i = 0; i < n; i++)
    fprintf(arqOrdenado, "%d ", arr[i]);

  fprintf(arqOrdenado, "%c", '\n');

  fprintf(arqOrdenado, "%s", "InsertionSort: ");
  for (i = 0; i < n; i++)
    fprintf(arqOrdenado, "%d ", aux[i]);

  fclose(arqOrdenado);

  printf("Arquivo 'ordenado.txt' foi criado com sucesso!\n");

  free(arr);

  return 0;
}
