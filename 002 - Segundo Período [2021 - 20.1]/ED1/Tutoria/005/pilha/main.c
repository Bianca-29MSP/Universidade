/*
* main.c
* Enya L. G. Santos
* 19.2.4201
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void menu(Pilha *p);

int main()
{
  Pilha *p = pilhaAloca();
  menu(p);
  return 0;
}

void menu(Pilha *p)
{
  int op;
  int n;
  while (op != -1)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      pilhaRead(p);
      break;
    case 2:
      scanf("%d", &n);
      pilhaPush(p, n);
      break;
    case 3:
      pilhaPop(p, &n);
      printf("%d\n", n);
      break;
    case 4:
      pilhaUnstack(p);
      break;
    default:
      op = -1;
      break;
    }
  }
}
