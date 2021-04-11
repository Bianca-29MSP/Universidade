#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "arvore_expressao.h"
#include "arquivo.h"

#define MAXTAM 100

int main()
{
  int op;
  char expressao[MAXTAM];

  printf("MENU\n1 - Digitar expressao\n2 - Ler expressão(ões) através de um arquivo .txt [expressoes.txt]\n");
  scanf("%d", &op);

  if (op == 1)
  {
    int resultado;
    int n;

    printf("Número de expressões a serem lidas: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
      scanf("\n%100[^\n]s", expressao);

      resultado = calculaArvExpressao(expressao);
      printf("%s = %d\n", expressao, resultado);
      if (n > 1 && i < (n - 1))
        printf("--------------------------------------------------\n");
    }
  }
  else if (op == 2)
  {
    int n, resultado;
    char **expressoes = leArquivo(&n);

    criaArquivo(n);

    for (int i = 0; i < n; i++)
    {
      resultado = calculaArvExpressao(expressoes[i]);
      escreveResultado(expressoes[i], resultado);
      printf("%s = %d\n", expressoes[i], resultado);
      if (n > 1)
        printf("--------------------------------------------------\n");
      free(expressoes[i]);
    }

    free(expressoes);
  }

  return 0;
}
