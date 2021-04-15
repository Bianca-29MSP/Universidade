#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "quickSort.h"
#include "insertionSort.h"

int main()
{
  srand(time(NULL));
  int op;
  int m, n;
  int *arr;
  printf("1 - Aleatório.\n2 - Crescente.\n3 - Decrescente\n");
  scanf("%d", &op);

  scanf("%d", &m);
  scanf("%d", &n);

  for (int i = 0; i < m; i++)
  {
    arr = malloc(sizeof(int) * n);

    if (op == 1)
    {
      for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
    }
    else if (op == 2)
    {
      int j = rand() % 10;
      for (int i = 0; i < n; i++)
      {
        arr[i] = j;
        j += rand() % 20;
      }
    }
    else if (op == 3)
    {
      int j = rand() % 50 + 900;
      for (int i = 0; i < n; i++)
      {
        arr[i] = j;
        j -= rand() % 20;
      }
    }

    for (int i = 0; i < n; i++)
      printf("%d ", arr[i]);
    printf("\n");

    free(arr);
  }

  return 0;
}