#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "quickSort.h"
#include "insertionSort.h"

int main()
{
  srand(time(NULL));
  int op;
  int n;
  scanf("%d", &n);

  printf("1 - Aleatório.\n2 - Crescente.\n3 - Decrescente\n");

  int *arr = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100;

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}