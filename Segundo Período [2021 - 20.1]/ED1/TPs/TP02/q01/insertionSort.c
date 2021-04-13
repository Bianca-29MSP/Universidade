#include <stdlib.h>
#include <stdio.h>

#include "insertionSort.h"

void insertionSort(ITEMINSERT *arr, int n, int *mov, int *comp)
{
  ITEMINSERT aux;
  int j;
  for (int i = 1; i < n; i++)
  {
    aux = arr[i];
    j = i - 1;

    while (j >= 0 && aux < arr[j])
    {
      arr[j + 1] = arr[j];
      *comp += 1;
      *mov += 1;
      j -= 1;
    }

    arr[j + 1] = aux;
    *mov += 1;
  }
}