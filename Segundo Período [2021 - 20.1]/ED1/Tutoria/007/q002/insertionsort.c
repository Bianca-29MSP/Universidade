/*
*	ENYA L. G. DOS SANTOS
*	19.2.4201
*/

#include <stdlib.h>
#include "insertionsort.h"

void insertionsort(int *arr, int n)
{
  int aux, j;
  for (int i = 1; i < n; i++)
  {
    aux = arr[i];
    j = i - 1;
    while (j >= 0 && aux < arr[j])
    {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = aux;
  }
}
