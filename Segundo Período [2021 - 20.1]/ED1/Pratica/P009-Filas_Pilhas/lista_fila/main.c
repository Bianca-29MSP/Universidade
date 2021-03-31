#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "fila.h"

int main()
{
  Fila *fila;
  Item x;
  Fila_Inicia(&fila);

  Fila_EhVazia(fila) ? printf("Fila está vazia\n") : printf("Fila não esta vazia.\n");

  for (int i = 0; i < 15; i++)
    Fila_Enfileira(fila, i);

  Fila_EhVazia(fila) ? printf("Fila está vazia\n") : printf("Fila não esta vazia.\n");
  Fila_imprime(fila);

  printf("Desenfileirado(s): ");
  for (int i = 0; i < 5; i++)
  {
    Fila_Desenfileira(fila, &x);
    printf("%d ", x);
  }
  printf("\n");

  Fila_imprime(fila);

  printf("Desenfileirado(s): ");
  for (int i = 0; i < 10; i++)
  {
    Fila_Desenfileira(fila, &x);
    printf("%d ", x);
  }
  printf("\n");

  Fila_EhVazia(fila) ? printf("Fila está vazia\n") : printf("Fila não esta vazia.\n");

  Fila_Libera(&fila);

  return 0;
}
