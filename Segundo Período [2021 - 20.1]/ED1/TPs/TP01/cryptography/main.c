/*
*   UFOP - Universidade Federal de Ouro Preto
*   Estrutura de dados
*   Trabalho Prático 01 - Questão 03
*   Enya Luísa Gomes dos Santos
*   19.2.4201
*/

#include "crypto.h"

int main()
{
  int n;
  char word[104];

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    getchar();
    scanf("%[^\n]s", word);
    crypto(word);
    printf("%s\n", word);
  }

  return 0;
}
