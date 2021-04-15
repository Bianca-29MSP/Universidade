#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
#include "insertionSort.h"

unsigned int mov = 0;
unsigned int comp = 0;

unsigned int movInsert = 0;
unsigned int compInsert = 0;

void swap(ITEMQUICK *v, int i, int j)
{
  ITEMQUICK temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void pivoMedianaDeTres(ITEMQUICK *v, int l, int r)
{
  int metade = (l + r) / 2;
  ITEMQUICK ini = v[l];
  ITEMQUICK meio = v[metade];
  ITEMQUICK fim = v[r];
  int medianaIndice;
  if (ini < meio)
  {
    if (meio < fim)
      medianaIndice = metade;
    else
    {
      if (ini < fim)
        medianaIndice = r;
      else
        medianaIndice = l;
    }
  }
  else
  {
    if (fim < meio)
      medianaIndice = metade;
    else
    {
      if (fim < ini)
        medianaIndice = r;
      else
        medianaIndice = l;
    }
  }

  swap(v, medianaIndice, r);
}

void quicksort(ITEMQUICK *v, int l, int r, int min)
{
  if (l < r)
  {
    if ((r - l) > min)
    {
      ITEMQUICK q = partition(v, l, r);
      quicksort(v, l, q - 1, min);
      quicksort(v, q + 1, r, min);
    }
    else
    {
      insertionSort(v, l, r, &movInsert, &compInsert);
    }
  }
}

void quicksortAndInsetionsort(ITEMQUICK *v, int n, int min, int *count)
{
  mov = 0;
  comp = 0;
  movInsert = 0;
  compInsert = 0;
  quicksort(v, 0, n - 1, min);
  count[0] = mov;
  count[1] = comp;
  count[2] = movInsert;
  count[3] = compInsert;
}

int partition(ITEMQUICK *v, int l, int r)
{
  //pivoMedianaDeTres(v, l, r);
  ITEMQUICK x = v[r]; //x é o pivô
  int i = l - 1;

  for (int j = l; j < r; j++)
  {
    comp += 1;
    if (v[j] <= x)
    {
      i += 1;
      swap(v, i, j);
      mov += 1;
    }
  }

  swap(v, i + 1, r);
  mov += 1;

  return i + 1;
}