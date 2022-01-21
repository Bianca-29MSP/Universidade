/*
* Enya Luísa Gomes dos Santos
* 19.2.4201
* BCC201 - Turma 32
*/
#include <stdio.h>

int main(){
  int vetor[10];
  vetor[0] = 1;
  vetor[1] = 1;
  for (int i = 1; i < 10; i++) {
    vetor[i+1] = vetor[i] + vetor[i-1];
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", vetor[i]);
  }
  return 0;
}
