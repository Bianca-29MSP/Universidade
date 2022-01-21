/*
*	ENYA L. G. DOS SANTOS
*	19.2.4201
*/

#include <stdlib.h>
#include "selectionsort.h"

void selectionsort(int *arr, int n)
{
  int min;
  for (int i = 0; i < n; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    if (i != min)
    {
      int aux = arr[i];
      arr[i] = arr[min];
      arr[min] = aux;
    }
  }
}
