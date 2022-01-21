/*
*   main.c
*   ENYA L. G. DOS SANTOS
*   19.2.4201
*/

#include <stdlib.h>
#include <stdio.h>
#include "clinica.h"

void menu()
{
  printf("\t\t\tMENU\n");
  printf("\t\t\t1  - ADICIONAR NOVA CONSULTA.\n");
  printf("\t\t\t2  - MOSTRAR AS PROXIMAS CONSULTAS.\n");
  printf("\t\t\t3  - REMOVER UMA CONSULTA.\n");
  printf("\t\t\t4  - REMOVER TODAS AS CONSULTAS.\n");
  printf("\t\t\t5  - MOSTRAR A PROXIMA CONSULTA.\n");
  printf("\t\t\t-1 - ENCERRAR PROGRAMA.\n");
}

int main()
{
  Fila *clientes = Fila_Inicia();
  int op = 0;
  char nome[64];
  char descricao[100];

  menu();

  while (op != -1)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 1:
      scanf("\n%50[^\n]s", nome);
      scanf("\n%50[^\n]s", descricao);
      Fila_Enfileira(clientes, nome, descricao);
      break;
    case 2:
      Fila_Imprime(clientes);
      break;
    case 3:
      Fila_Desenfileira(clientes);
      break;
    case 4:
      Fila_Libera(&clientes);
      break;
    case 5:
      Fila_Primeiro(clientes, nome, descricao);
      printf("Paciente: %s\n", nome);
      printf("Descricao: %s\n", descricao);
      break;
    case -1:
      printf("Fim da execucao!\n");
      break;
    default:
      break;
    }
  }

  return 0;
}