/*
* hybridsort.c
* Trabalho pratico 2 de EDI (BCC202) - Quicksort combinado com insertionsort   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/

#include <stdio.h>
#include <stdlib.h>
#include "hybridsort.h"

/* Variavel global do tipo ponteiro para contador */
Contador *count;

/* Valor de k */
#define K 20

/* Zerar o contador para ser iniciado novamente */
void zeraContador()
{
  count->compInsertion = 0;
  count->movInsertion = 0;
  count->movQuick = 0;
  count->compQuick = 0;
}

/* Realizar a troca entre duas posições do vetor */
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

void hybridsort(Item *v, int l, int r, int op)
{
  if (l < r)
  { /*Se o tamanho do vetor for maior que K o quicksort é usado, 
    caso contrario, o insertionsort é usado */
    if ((r - l) > K)
    {
      Item q = partition(v, l, r, op);
      hybridsort(v, l, q - 1, op);
      hybridsort(v, q + 1, r, op);
    }
    else
      insertionsort(v, l, r + 1);
  }
}

void hybridsortInicia(Item *v, int n, Contador *c, int op)
{
  count = c;
  zeraContador();
  hybridsort(v, 0, n, op);
}

int partition(Item *v, int l, int r, int op)
{
  if (op == 2)
    pivoMedianaDeTres(v, l, r); /* Escolha do pivô por meio da mediana de três*/
  Item x = v[r];                //x é o pivô
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
  for (int i = l + 1; i < r; i++)
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