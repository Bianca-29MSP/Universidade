/* referencia: https://youtu.be/IPLzxX1Vibo */
#define TAM 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pilha.h"
#include "arvore.h"

/* o q resolver primeiro */

int posfixa(char *inf);

int calcula(ArvoreNo **raiz);

int main()
{
  char expressao[TAM];

  scanf("\n%100[^\n]s", expressao);

  posfixa(expressao);

  return 0;
}

int posfixa(char *inf)
{
  int n = strlen(inf);
  // char *p = (char *)malloc(n * sizeof(char));
  char *posf = (char *)malloc(n * sizeof(char));
  Pilha *p = Pilha_Inicia(n);
  //Pilha *posf = Pilha_Inicia(n);
  ArvoreNo *raiz = inicializa();

  int j = 0;

  for (int i = 0; i < n; i++)
  {
    switch (inf[i])
    {
    case '(':
      Pilha_Push(p, inf[i]);
      break;
    case ')':
      while (Pilha_top(p) != '(')
      {
        posf[j++] = Pilha_Pop(p);
      }
      Pilha_Pop(p); /* Remove o '(' */
      break;
    case '+':
    case '-':
      while (Pilha_top(p) != '(' && Pilha_Tamanho(p) > 0)
      {
        posf[j++] = Pilha_Pop(p);
      }
      Pilha_Push(p, inf[i]);

      break;
    case '*':
    case '/':
      while (Pilha_top(p) != '(' &&
             Pilha_top(p) != '+' &&
             Pilha_top(p) != '-' &&
             Pilha_Tamanho(p) > 0)
      {
        posf[j++] = Pilha_Pop(p);
      }
      Pilha_Push(p, inf[i]);

      break;
    default:
      if (inf[i] != ' ')
      {
        posf[j++] = inf[i];
      }
    }
  }

  if (Pilha_Tamanho(p) == 1)
    posf[j++] = Pilha_Pop(p);

  /*Pilha já vai estar vazia */
  printf("$ %s\n", posf);

  // exibirArvore(raiz, 0);
  // printf("\n");

  //int resultado = calcula(&raiz);
  //printf("%d\n", resultado);
  //(A * (B * C + D))
  //(A-(B*C+D))
}

int calcula(ArvoreNo **raiz)
{
  int nNos = numeroNos(*raiz);

  Pilha *pilha = Pilha_Inicia(nNos);
  pos_ordem(*raiz, pilha);

  if (Pilha_Tamanho(pilha) == 1)
  {
    return Pilha_Pop(pilha);
  }
  else
  {
    return -1;
  }
}