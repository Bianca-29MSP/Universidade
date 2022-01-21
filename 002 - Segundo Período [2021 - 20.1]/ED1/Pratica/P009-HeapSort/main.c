#include <stdio.h>
#include <stdlib.h>

#include "heapsort.h"

void printVetor(int *vet, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", vet[i]);
  printf("\n");
}

void preencheVetor(int *vet, int n)
{
  for (int i = 0; i < n; i++)
    scanf("%d", &vet[i]);
}

int main()
{
  int k, n;
  scanf("%d", &k);
  int **vet = malloc(sizeof(int *) * k);

  int *tamVet = malloc(sizeof(int) * k);

  int *comp = malloc(sizeof(int) * k);
  int *mov = malloc(sizeof(int) * k);

  if (vet == NULL || tamVet == NULL || comp == NULL || mov == NULL)
  {
    printf("Erro na alocação de memória!\n");
    exit(1);
  }

  for (int i = 0; i < k; i++)
  {
    comp[i] = 0;
    mov[i] = 0;

    scanf("%d", &n);

    vet[i] = malloc(sizeof(int) * n);
    if (vet[i] == NULL)
    {
      printf("Erro na alocação de memória!\n");
      exit(1);
    }

    preencheVetor(vet[i], n);
    heapSort(vet[i], n, &comp[i], &mov[i]);
    tamVet[i] = n;
  }

  for (int i = 0; i < k; i++)
  {
    printVetor(vet[i], tamVet[i]);
    free(vet[i]);
  }

  char espacos[3] = {' ', ' ', ' '};
  printf("Vetor%s|Comparações%s|Movimentaçoes\n", espacos, espacos);
  for (int i = 0; i < k; i++)
  {
    printf("%d%s    |%d%s          |%d\n", i + 1, espacos, comp[i], espacos, mov[i]);
  }

  free(vet);
  free(tamVet);
  free(comp);
  free(mov);

  return 0;
}