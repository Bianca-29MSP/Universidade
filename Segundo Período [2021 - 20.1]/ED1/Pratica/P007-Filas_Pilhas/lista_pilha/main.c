#include <stdio.h>
#include "pilha.h"
#include "lista.h"

int calcula(char op, Pilha *pilha);

int main()
{
  int operando;
  char entrada;

  Pilha *pilha;

  Pilha_Inicia(&pilha);

  while (entrada != '=')
  {
    entrada = getchar();

    if ((int)entrada >= 48 && (int)entrada <= 57)
    {
      operando = (int)entrada - 48;
      Pilha_Push(pilha, operando);
    }
    else if (entrada != '\n')
      if (Pilha_Tamanho(pilha) >= 2)
        if (entrada == '+' ||
            entrada == '-' ||
            entrada == '*' ||
            entrada == '/')
          Pilha_Push(pilha, calcula(entrada, pilha));
  }

  if (Pilha_EhVazia(pilha) || Pilha_Tamanho(pilha) > 1)
    printf("Entrada inconsistente.\n");
  else if (entrada == '=')
    Pilha_imprime(pilha);

  Pilha_Libera(&pilha);

  return 0;
}

int calcula(char op, Pilha *pilha)
{
  int valor1, valor2;
  Pilha_Pop(pilha, &valor2);
  Pilha_Pop(pilha, &valor1);

  switch (op)
  {
  case '+':
    return valor1 + valor2;
    break;
  case '-':
    return valor1 - valor2;
    break;
  case '*':
    return valor1 * valor2;
    break;
  case '/':
    return valor1 / valor2;
    break;
  }

  return 0;
}
