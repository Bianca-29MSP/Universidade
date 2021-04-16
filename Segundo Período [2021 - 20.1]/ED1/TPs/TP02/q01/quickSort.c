#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
#include "insertionSort.h"

int mov;
int comp;
int movInsert;
int compInsert;

#define MIN 50

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
  int medianaIndice = -1;

  if ((ini > meio && ini < fim) || (ini > fim && ini < meio))
    medianaIndice = l;
  else if ((meio > ini && meio < fim) || (meio > fim && meio < ini))
    medianaIndice = metade;
  else if ((fim > ini && fim < meio) || (fim > meio && fim < ini))
    medianaIndice = r;

  swap(v, medianaIndice, r);
}

void quicksort(ITEMQUICK *v, int l, int r)
{
  if (l < r)
  {
    if ((r - l) > MIN)
    {
      ITEMQUICK q = partition(v, l, r);
      quicksort(v, l, q - 1);
      quicksort(v, q + 1, r);
    }
    else
    {
      insertionSort(v, l, r, &movInsert, &compInsert);
    }
  }
}

void quicksortAndInsetionsort(ITEMQUICK *v, int n, int *count)
{
  mov = 0;
  comp = 0;
  movInsert = 0;
  compInsert = 0;

  quicksort(v, 0, n - 1);

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