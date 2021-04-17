

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "hybridSort.h"

void zeraContador(Contador *contador)
{
  contador->compInsertion = 0;
  contador->movInsertion = 0;
  contador->movQuick = 0;
  contador->compQuick = 0;
}

int main()
{
  srand(time(NULL));
  int m, n, op;
  int *arr;
  Contador contador;

  printf("1 - Entrada pelo terminal.\n2 - Entrada por arquivo.\n");
  scanf("%d", &op);
  if (op == 1)
  {
    printf("[QUANTIDADE DE ARRAY] [TAMANHO DESSES ARRAYs]: ");
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++)
    {
      zeraContador(&contador);
      arr = malloc(sizeof(int) * n);

      for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

      hybridSort(arr, 0, n, &contador);

      printf("\n");
      for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
      printf("\n");

      printf("\t\tMovimentações | Comparações\n");
      printf("QuickSort: %d \t%d\n", contador.movQuick, contador.compQuick);
      printf("InsertionSort: %d \t%d\n", contador.movInsertion, contador.movInsertion);
      printf("Total: %d \t%d\n", contador.movInsertion + contador.movQuick, contador.compInsertion + contador.compQuick);

      free(arr);
    }
  }
  else if (op == 2)
  {
    char aux[50];
    char nameArq[62] = "./arquivos/";
    printf("Nome do arquivo sem extensão: ");
    scanf("%s", aux);

    strcat(aux, ".txt");
    strcat(nameArq, aux);

    FILE *arq = fopen(nameArq, "r");

    if (arq == NULL)
    {
      printf("Erro na abertura do arquivo.\n");
      exit(1);
    }

    fscanf(arq, "%d %d", &m, &n);
    printf("%d %d\n", m, n);

    for (int i = 0; i < m; i++)
    {
      zeraContador(&contador);
      arr = malloc(sizeof(int) * n);

      for (int i = 0; i < n; i++)
        fscanf(arq, "%d", &arr[i]);

      hybridSort(arr, 0, n, &contador);

      printf("\n");
      for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
      printf("\n");

      printf("\t\tMovimentações | Comparações\n");
      printf("QuickSort: \t%d \t\t%d\n", contador.movQuick, contador.compQuick);
      printf("InsertionSort: \t%d \t\t%d\n", contador.movInsertion, contador.movInsertion);
      printf("Total: \t\t%d \t\t%d\n", contador.movInsertion + contador.movQuick, contador.compInsertion + contador.compQuick);

      //free(arr);
    }

    fclose(arq);
  }

  return 0;
}