#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM 100

char *infix2posfix(char *inf)
{
  int n = strlen(inf);
  char *posf; // expressão pósfixa
  posf = malloc((n + 1) * sizeof(char));
  int i;   // percorre infixa
  int j;   // percorre posfixa
  char *s; // pilha
  int t;   // topo da pilha
  // inicializa a pilha
  s = malloc(n * sizeof(char));
  t = 0;
  for (i = j = 0; inf[i] != '\0'; i++)
  {
    switch (inf[i])
    {
      char x; // auxiliar para item do topo da pilha
    case '(':
      s[t++] = inf[i]; // empilha
      break;
    case ')':
      x = s[--t]; // desempilha
      while (x != '(')
      {
        posf[j++] = x;
        x = s[--t]; // desempilha
      }
      break;
    case '+':
    case '-':
      // desempilha enquanto pilha não for vazia e não encontrar '('
      while (t > 0 && s[t - 1] != '(')
      {
        posf[j++] = s[--t]; // desempilha
      }
      s[t++] = inf[i]; // empilha
      break;
    case '*':
    case '/':
      // desempilha enquanto não encontrar início do bloco ou operador de menorprecedência na pilha
      while (t > 0 && (x = s[t - 1]) != '(' && x != '+' && x != '-')
      {
        posf[j++] = s[--t]; // desempilha
      }
      s[t++] = inf[i];
      break;
    default:
      if (inf[i] != ' ')
        posf[j++] = inf[i];
    }
  }
  // desempilha o que sobrou na pilha
  while (t > 0)
    posf[j++] = s[--t];
  posf[j] = '\0';
  free(s);
  return posf;
}

void trataString(char *expressao)
{
  char *aux = malloc(strlen(expressao) * sizeof(char));
  for (int j = 0, i = 0; i < strlen(expressao); i++)
  {
    if (expressao[i] != ' ')
    {
      aux[j] = expressao[i];
      j++;
    }
  }
  strcpy(expressao, aux);
  free(aux);
}

int main()
{
  char expressao[TAM];

  scanf("\n%100[^\n]s", expressao);

  trataString(expressao);

  printf("%s\n", infix2posfix(expressao));

  return 0;
}
