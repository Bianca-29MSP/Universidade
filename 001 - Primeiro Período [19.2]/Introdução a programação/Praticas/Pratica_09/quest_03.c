/*
* Enya Luísa Gomes dos Santos
* 19.2.4201
* BCC201 - Turma 32
*/
#include <stdio.h>

int main(){
  int vetor[5], n;
  printf("Digite o numero de posicoes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
      scanf("%d", &vetor[i]);

  for (int i = 0; i < n; i++) {
      for(int j = 0; j < vetor[i]; j++)
          printf("*");
      if(i != n-1)
          printf("\n");
    }

  return 0;
}
