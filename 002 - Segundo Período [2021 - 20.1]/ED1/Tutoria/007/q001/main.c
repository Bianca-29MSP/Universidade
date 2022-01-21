/*
*	ENYA L. G. DOS SANTOS
*	19.2.4201
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int n;
  FILE *arq = fopen("../arquivos/dados.txt", "w");
  srand(time(NULL));

  if (arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  scanf("%d", &n);

  fprintf(arq, "%d\n", n);
  for (int i = 0; i < n; i++)
  {
    fprintf(arq, "%d\n", rand() % 1000);
  }

  fclose(arq);

  printf("Arquivo 'dados.txt' foi criado com sucesso!\n");

  return 0;
}
