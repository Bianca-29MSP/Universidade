#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
  Fila *f = inicializaFila();

  // printf("FILA ESTATICA\n");

  // for (int i = 0; i < 4; i++)
  //   enfileira(f, i);

  // imprimeFila(f);

  // printf("%d\n", desenfileira(f));
  // printf("%d\n", desenfileira(f));

  // imprimeFila(f);

  // limpaFila(f);

  // imprimeFila(f);

  // for (int i = 0; i < 7; i++)
  //   enfileira(f, i);

  // imprimeFila(f);

  // liberaFila(&f);

  printf("FILA DINAMICA \n");

  for (int i = 0; i < 10; i++)
    enfileira(f, rand() % 100);

  imprimeFila(f);

  printf("%d\n", desenfileira(f));

  limpaFila(f);

  imprimeFila(f);

  enfileira(f, rand() % 100);

  imprimeFila(f);

  liberaFila(&f);

  return 0;
}