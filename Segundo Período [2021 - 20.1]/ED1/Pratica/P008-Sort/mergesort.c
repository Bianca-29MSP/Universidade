typedef int ITEM;

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
  ITEM *w = alocaVetor(size_w);
  i = ini;
  j = meio;
  k = 0;

  //Armazena de forma ordenada o vetor vet em w até que não haja mais elemento em um dos dois lados do vetor
  while (i < meio && j < fim)
  {
    if (vet[i] >= vet[j])
      w[k++] = vet[i++];
    else
      w[k++] = vet[j++];
  }

  //Armazena os valores restantes de vet em w
  while (i < meio)
  {
    w[k++] = vet[i++];
  }
  while (j < fim)
  {
    w[k++] = vet[j++];
  }

  //Copia os valores ordenados que está em w para vet
  for (i = ini; i < fim; i++)
    vet[i] = w[i - ini];

  free(w);
}