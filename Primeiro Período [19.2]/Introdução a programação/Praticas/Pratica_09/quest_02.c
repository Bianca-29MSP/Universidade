/*
* Enya Luísa Gomes dos Santos
* 19.2.4201
* BCC201 - Turma 32
*/
#include <stdio.h>

int main(){
  int vetor[7], num, cont = 0;
  for (int j = 0; j < 7; j++) {
    scanf("%d", &vetor[j]);
  }
  printf("Digite um numero: ");
  scanf("%d", &num);
  for (int i = 0; i < 7; i++) {
       if(vetor[i] == num){
        cont++;
        break;
      }
  }

  if(cont > 0)
    printf("O numero %d encontrado no vetor.\n", num);
  else
    printf("Numero %d nao encontrado no vetor.\n", num);
  return 0;
}
