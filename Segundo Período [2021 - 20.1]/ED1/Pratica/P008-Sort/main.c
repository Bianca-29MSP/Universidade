#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;

struct aluno
{
  int matricula;
  double prova;
  double trabPratico;
  double media;
};

typedef Aluno ITEM;

Aluno *alocaVetor(int n);

void freeMat(ITEM **mat, int t);

void insertionSort(ITEM *arr, int n);

void selectionSort(ITEM *arr, int n);

void bubbleSort(ITEM *arr, int n);

void merge(ITEM *vet, int ini, int meio, int fim);

void mergesort(ITEM *v, int ini, int fim);

int main()
{
  int t, n;
  scanf("%d", &t);
  Aluno **mat = (Aluno **)malloc(t * sizeof(Aluno *));

  for (int i = 0; i < t; i++)
  {
    scanf("%d", &n);
    mat[i] = alocaVetor(n);
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &mat[i][j].matricula);
      scanf("%lf", &mat[i][j].prova);
      scanf("%lf", &mat[i][j].trabPratico);
      mat[i][j].media = ((mat[i][j].prova * 0.7) + (mat[i][j].trabPratico * 0.3)) / (0.7 + 0.3);
    }
    //insertionSort(mat[i],n);
    //selectionSort(mat[i],n);
    //bubbleSort(mat[i], n);

    mergesort(mat[i], 0, n);
  }

  printf("\n");
  for (int i = 0; i < t; i++)
  {
    int j = 0;
    while (mat[i][j].matricula)
    {
      printf("%d %.2lf\n", mat[i][j].matricula, mat[i][j].media);
      j += 1;
    }
    printf("\n");
  }

  freeMat(mat, t);

  return 0;
}

Aluno *alocaVetor(int n)
{
  Aluno *aux = (Aluno *)malloc(n * sizeof(Aluno));
  return aux;
}

void freeMat(ITEM **mat, int t)
{
  for (int i = 0; i < t; i++)
  {
    free(mat[i]);
  }
  free(mat);
}

void insertionSort(ITEM *arr, int n)
{
  Aluno aux;
  int j;
  for (int i = 1; i < n; i++)
  {
    aux = arr[i];
    j = i - 1;
    while (j >= 0 && aux.media > arr[j].media)
    {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = aux;
  }
}

void selectionSort(ITEM *arr, int n)
{
  int min;
  for (int i = 0; i < n; i++)
  {
    min = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j].media > arr[min].media)
        min = j;
    }
    if (i != min)
    {
      Aluno aux = arr[i];
      arr[i] = arr[min];
      arr[min] = aux;
    }
  }
}
void bubbleSort(ITEM *arr, int n)
{
  int troca;
  for (int i = 0; i < n; i++)
  {
    troca = 0;
    for (int j = 1; j < (n - i); j++)
    {
      if (arr[j].media > arr[j - 1].media)
      {
        Aluno aux = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = aux;
        troca += 1;
      }
    }
    if (troca == 0)
      break;
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

  //Armazenam de forma ordenada o vetor vet em w até que não haja mais elemento em um dos dois vetores
  while (i < meio && j < fim)
  {
    if (vet[i].media >= vet[j].media)
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