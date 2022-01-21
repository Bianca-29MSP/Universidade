#include "insertionSort.h"

void insertionSort(ITEM *arr, int n)
{
  ITEM aux = aluno_Aloca();
  int j;
  for (int i = 1; i < n; i++)
  {
    aux = arr[i];
    j = i - 1;
    while (j >= 0 && aluno_getMedia(aux) > aluno_getMedia(arr[j]))
    {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = aux;
  }
}