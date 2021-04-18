/*
* main.c
* Trabalho pratico 2 de EDI (BCC202) - Quicksort combinado com insertionsort   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "hybridsort.h"

int main()
{
  srand(time(NULL));
  int m, n, opEntrada, opPivo;
  int *arr;
  Contador contador;

  printf("1 - Entrada pelo terminal.\n2 - Entrada por arquivo.\n");
  scanf("%d", &opEntrada);

  if (opEntrada == 1)
  {
    printf("[QUANTIDADE DE ARRAY] [TAMANHO DESSES ARRAYs]: ");
    scanf("%d %d", &m, &n);
    printf("1 - Pivô aleatório.\n2 - Pivô pela mediana de três.\n");
    scanf("%d", &opPivo);

    for (int i = 0; i < m; i++)
    {
      arr = malloc(sizeof(int) * n);

      for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

      hybridsortInicia(arr, n - 1, &contador, opPivo);

      printf("\n");
      for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
      printf("\n");

      printf("\t\tMovimentações | Comparações\n");
      printf("QuickSort: \t%d \t%d\n", contador.movQuick, contador.compQuick);
      printf("InsertionSort: \t%d \t%d\n", contador.movInsertion, contador.movInsertion);
      printf("Total: \t\t%d \t%d\n", contador.movInsertion + contador.movQuick, contador.compInsertion + contador.compQuick);

      free(arr);
    }
  }
  else if (opEntrada == 2)
  {
    char aux[50];
    char nomeArq[70] = "./arquivos/";
    printf("Nome do arquivo sem extensão: ");
    scanf("%s", aux);

    strcat(aux, ".txt");
    strcat(nomeArq, aux);

    FILE *arq = fopen(nomeArq, "r");

    if (arq == NULL)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(1);
    }

    printf("1 - Pivô aleatório.\n2 - Pivô pela mediana de três.\n");
    scanf("%d", &opPivo);

    fscanf(arq, "%d %d", &m, &n);
    printf("%d %d\n", m, n);

    for (int i = 0; i < m; i++)
    {
      arr = malloc(sizeof(int) * n);

      for (int i = 0; i < n; i++)
        fscanf(arq, "%d", &arr[i]);

      hybridsortInicia(arr, n - 1, &contador, opPivo);

      printf("\n");
      for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
      printf("\n");

      printf("\t\tMovimentações | Comparações\n");
      printf("QuickSort: \t%d \t\t%d\n", contador.movQuick, contador.compQuick);
      printf("InsertionSort: \t%d \t\t%d\n", contador.movInsertion, contador.movInsertion);
      printf("Total: \t\t%d \t\t%d\n", contador.movInsertion + contador.movQuick, contador.compInsertion + contador.compQuick);

      free(arr);
    }

    fclose(arq);
  }

  return 0;
}