#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void mergesort(ITEM *v, int ini, int fim)
{
  if (ini < fim - 1)
  {
    int meio = (ini + fim) / 2;
    mergesort(v, ini, meio);
    mergesort(v, meio, fim);
    merge(v, ini, meio, fim);
  }
}

void merge(ITEM *vet, int ini, int meio, int fim)
{
  int i, j, k;
  int size_w = fim - ini;
  ITEM *w = aluno_AlocaVetor(size_w);
  i = ini;
  j = meio;
  k = 0;

  while (i < meio && j < fim)
  {
    if (aluno_getMedia(vet[i]) >= aluno_getMedia(vet[j]))
      w[k++] = vet[i++];
    else
      w[k++] = vet[j++];
  }

  while (i < meio)
  {
    w[k++] = vet[i++];
  }
  while (j < fim)
  {
    w[k++] = vet[j++];
  }

  for (i = ini; i < fim; i++)
    vet[i] = w[i - ini];

  free(w);
}