/* https://www.blogcyberini.com/2018/08/quicksort-mediana-de-tres.html#quicksortm3_pivo*/
#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
#include "insertionSort.h"

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

void quicksort(ITEMQUICK *v, int l, int r, int *mov, int *comp)
{
  if (l < r)
  {
    // if ((r - l) > 20)
    // {
    //   ITEMQUICK q = partition(v, l, r, mov, comp);
    //   quicksort(v, l, q - 1, mov, comp);
    //   quicksort(v, q + 1, r, mov, comp);
    // }
    // else
    // {
    //   insertionSort(v, r);
    // }
    ITEMQUICK q = partition(v, l, r, mov, comp);
    quicksort(v, l, q - 1, mov, comp);
    quicksort(v, q + 1, r, mov, comp);
  }
}

int partition(ITEMQUICK *v, int l, int r, int *mov, int *comp)
{
  //pivoMedianaDeTres(v, l, r);
  ITEMQUICK x = v[r]; //x é o pivô
  int i = l - 1;

  for (int j = l; j < r; j++)
  {
    *comp += 1;
    if (v[j] <= x)
    {
      i += 1;
      swap(v, i, j);
      *mov += 1;
    }
  }

  swap(v, i + 1, r);
  *mov += 1;

  return i + 1;
}