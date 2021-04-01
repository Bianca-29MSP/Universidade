/*
*   main.c
*   ENYA L. G. DOS SANTOS
*   19.2.4201
*/

#include <stdlib.h>
#include <stdio.h>
#include "entregador.h"

void menu()
{
  printf("\t\t\tMENU\n");
  printf("\t\t\t1  - ADICIONAR NOVA PIZZA.\n");
  printf("\t\t\t2  - REMOVER PIZZA.\n");
  printf("\t\t\t3  - MOSTRAR PIZZAS.\n");
  printf("\t\t\t-1 - ENCERRAR PROGRAMA.\n");
}

int main()
{
  Pilha *pizzas = Pilha_Inicia();
  int op = 0;
  char pizza[100];

  menu();

  while (op != -1)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      scanf("\n%50[^\n]s", pizza);
      Pilha_Push(pizzas, pizza);
      break;
    case 2:
      Pilha_Pop(pizzas);
      break;
    case 3:
      Pilha_Imprime(pizzas);
      break;
    case -1:
      Pilha_Libera(&pizzas);
      printf("Fim da execucao!\n");
      break;
    default:
      break;
    }
  }

  return 0;
}