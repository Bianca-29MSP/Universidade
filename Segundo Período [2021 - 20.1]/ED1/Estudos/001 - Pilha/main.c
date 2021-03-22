/*
* main.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

void systemPause()
{
  printf("\nPressione qualquer tecla para continuar... \n");
  getchar();
}

int main()
{
  Pilha *p = inicializaPilha();

  imprimePilha(p);
  systemPause();

  for (int i = 0; i < 6; i++)
  {
    empilha(p, i);
  }

  imprimePilha(p);
  systemPause();

  pilhaUnstack(p);
  systemPause();
  imprimePilha(p);

  for (int i = 0; i < 2; i++)
  {
    printf("%d\n", desempilha(p));
  }

  imprimePilha(p);
  systemPause();

  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", desempilha(p));
  }

  return 0;
}
