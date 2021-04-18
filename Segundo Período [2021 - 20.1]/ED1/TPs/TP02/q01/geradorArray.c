/*
* geradorArray.c
* Trabalho pratico 2 de EDI (BCC202) - Quicksort combinado com insertionsort   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  int op;
  int m, n;
  int *arr;
  printf("1 - Aleatório.\n2 - Crescente.\n3 - Decrescente\n");
  scanf("%d", &op);

  printf("[Quantidade de arrays] [Tamanho dos arrays]: ");
  scanf("%d %d", &m, &n);

  for (int i = 0; i < m; i++)
  {
    arr = malloc(sizeof(int) * n);

    if (op == 1)
    { /* Gerar array aleatório */
      for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
    }
    else if (op == 2)
    { /* Gerar array crescrente */
      int j = rand() % 10;
      for (int i = 0; i < n; i++)
      {
        arr[i] = j;
        j += rand() % 20;
      }
    }
    else if (op == 3)
    { /* Gerar array decrescrente */
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