#include "heapsort.h"

void heapRefaz(TItem *v, int esq, int dir, int *comp, int *mov)
{
  int i = esq;
  int j = i * 2 + 1;

  TItem aux = v[i];

  while (j <= dir)
  {
    if (j < dir && v[j] < v[j + 1])
    {
      *comp += 1;
      j += 1;
    }
    if (aux >= v[j])
    {
      *comp += 1;
      break;
    }
    v[i] = v[j];
    i = j;
    j = i * 2 + 1;
    *mov += 1;
  }

  v[i] = aux;
}

void heapConstroi(TItem *v, int n, int *comp, int *mov)
{
  int esq = (n / 2) - 1;
  while (esq >= 0)
  {
    heapRefaz(v, esq, n - 1, comp, mov);
    esq -= 1;
  }
}

void heapSort(TItem *v, int n, int *comp, int *mov)
{
  TItem aux;
  heapConstroi(v, n, comp, mov);
  while (n > 1)
  {
    aux = v[n - 1];
    v[n - 1] = v[0];
    v[0] = aux;
    n -= 1;
    heapRefaz(v, 0, n - 1, comp, mov);
  }
}