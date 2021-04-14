#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "quickSort.h"
#include "insertionSort.h"

int main()
{
  srand(time(NULL));
  int n;
  scanf("%d", &n);

  int compQuick = 0, movQuick = 0;
  int compInsert = 0, movInsert = 0;

  int *arr = malloc(sizeof(int) * n);
  int *aux = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 100;
    aux[i] = arr[i];
  }

  quicksort(arr, 0, n - 1, &compQuick, &movQuick, &movInsert, &compInsert);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  printf("QuickSort: %d %d %d\n", n, movQuick, compQuick);
  printf("InsertionSort: %d %d %d\n", n, movInsert, compInsert);

  free(arr);
  free(aux);

  return 0;
}