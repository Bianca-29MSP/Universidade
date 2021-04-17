#include <stdio.h>
#include <stdlib.h>
#include "hybridsort.h"
//#include "insertionsort.h"

int mov;
int comp;
int movInsert;
int compInsert;

Contador *count;

#define MIN 20

void zeraContador()
{
  count->compInsertion = 0;
  count->movInsertion = 0;
  count->movQuick = 0;
  count->compQuick = 0;
}

void swap(Item *v, int i, int j)
{
  Item temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void pivoMedianaDeTres(Item *v, int l, int r)
{
  int metade = (l + r) / 2;
  Item ini = v[l];
  Item meio = v[metade];
  Item fim = v[r];
  int medianaIndice = -1;

  if (ini < meio)
  {
    if (meio < fim)
    {
      medianaIndice = metade;
    }
    else
    {
      if (ini < fim)
      {
        medianaIndice = r;
      }
      else
      {
        medianaIndice = l;
      }
    }
  }
  else
  {
    if (fim < meio)
    {
      medianaIndice = metade;
    }
    else
    {
      if (fim < ini)
      {
        medianaIndice = r;
      }
      else
      {
        medianaIndice = l;
      }
    }
  }

  swap(v, medianaIndice, r);
}

void hybridsort(Item *v, int l, int r)
{
  if (l < r)
  {
    if ((r - l) > MIN)
    {
      Item q = partition(v, l, r);
      hybridsort(v, l, q - 1);
      hybridsort(v, q + 1, r);
    }
    else
      insertionsort(v, l, r);
  }
}

void hybridsortInicia(Item *v, int n, Contador *c)
{
  count = c;
  zeraContador();
  hybridsort(v, 0, n);
}

int partition(Item *v, int l, int r)
{
  pivoMedianaDeTres(v, l, r);
  Item x = v[r]; //x é o pivô
  int i = l - 1;

  for (int j = l; j < r; j++)
  {
    count->compQuick += 1;
    if (v[j] <= x)
    {
      i += 1;
      swap(v, i, j);
      count->movQuick += 1;
    }
  }

  swap(v, i + 1, r);
  count->movQuick += 1;

  return i + 1;
}

void insertionsort(Item *arr, int l, int r)
{
  Item aux;
  int j;
  int n = (r - l) + 1;
  for (int i = l; i < n; i++)
  {
    aux = arr[i];
    j = i - 1;

    count->compInsertion += 1;
    while (j >= 0 && aux < arr[j])
    {
      arr[j + 1] = arr[j];
      count->compInsertion += 1;
      count->movInsertion += 1;
      j -= 1;
    }

    arr[j + 1] = aux;
  }
}