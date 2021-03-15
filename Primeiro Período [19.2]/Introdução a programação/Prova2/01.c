#include <stdio.h>

int main(){
  int alunos[5][2];
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 2; j++)
      scanf("%d", &alunos[i][j]);
  }
  int cont = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 2; j++)
      if(alunos[i+1][j+1] > 20)
        cont++;
  }
  printf("%d \n", cont);
  return 0;
}
