#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "quickSort.h"
#include "insertionSort.h"

int main()
{
  srand(time(NULL));
  int m, n, op;
  int contagem[4];
  int *arr;

  printf("1 - Entrada pelo terminal.\n2 - Entrada por arquivo.\n");
  scanf("%d", &op);
  if (op == 1)
  {
    printf("[QUANTIDADE DE ARRAY] [TAMANHO DESSES ARRAYs]: ");
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
    {
      arr = malloc(sizeof(int) * n);

      for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

      quicksortAndInsetionsort(arr, n, contagem);

      printf("\n");
      for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
      printf("\n");

      printf("\tMovimentações | Comparações\n");
      printf("QuickSort: %d %d\n", contagem[0], contagem[1]);
      printf("InsertionSort: %d %d\n", contagem[2], contagem[3]);
      printf("Total: %d %d\n", contagem[0] + contagem[2], contagem[1] + contagem[3]);

      free(arr);
    }
  }
  else if (op == 2)
  {
    char nomeArq[50];
    printf("Nome do arquivo sem extensão: ");
    scanf("%s", nomeArq);

    strcat(nomeArq, ".txt");
    FILE *arq = fopen(nomeArq, "r");

    if (arq == NULL)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(1);
    }

    fscanf(arq, "%d %d", &m, &n);
    printf("%d %d\n", m, n);

    for (int i = 0; i < m; i++)
    {
      arr = malloc(sizeof(int) * n);

      for (int i = 0; i < n; i++)
        fscanf(arq, "%d", &arr[i]);

      quicksortAndInsetionsort(arr, n, contagem);

      printf("\n");
      // for (int i = 0; i < n; i++)
      //   printf("%d ", arr[i]);
      // printf("\n");

      printf("\tMovimentações | Comparações\n");
      printf("QuickSort: %d %d\n", contagem[0], contagem[1]);
      printf("InsertionSort: %d %d\n", contagem[2], contagem[3]);
      printf("Total: %d %d\n", contagem[0] + contagem[2], contagem[1] + contagem[3]);

      free(arr);
    }

    fclose(arq);
  }

  return 0;
}