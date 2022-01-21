/*
* Enya Luísa Gomes dos Santos
* 19.2.4201
* BCC201 - Turma 32
*/
#include <stdio.h>

int main(){
  int prova1[15], prova2[15];
  for (int i = 0; i < 15; i++) {
      scanf("%d", &prova1[i]);
      scanf("%d", &prova2[i]);
  }
  for (int i = 0; i < 15; i++) {
      if( (prova1[i] + prova2[i]) / 2 >= 60)
          printf("Aluno %d - aprovado\n", i+1);
      else
          printf("Aluno %d - reprovado\n", i+1);
  }
  return 0;
}
