/*
* main.c
* Enya L. G. Santos
* 19.2.4201
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "lista.h"

int main()
{
  srand(time(NULL));
  Lista *listaA = lstAlloca();
  Lista *listaB = lstAlloca();

  for (int i = 0; i < 6; i++) //Gera números aleatorios para adicionar à lista A
    lstPushOrdenado(listaA, rand() % 100);

  for (int i = 0; i < 10; i++) //Gera números aleatorios para adicionar à lista B
    lstPushOrdenado(listaB, rand() % 100);

  lstImprime(listaA);
  lstImprime(listaB);

  Lista *listaC = lstConcatena(listaA, listaB);
  lstImprime(listaC);

  lstFree(&listaC);

  return 0;
}