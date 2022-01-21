#include <stdio.h>

int main(){
  int mat1[2][2], mat2[2][2], matSoma[2][2], determinante;
  printf("Primeira matriz: ");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++)
      scanf("%d", &mat1[i][j]);
  }
  printf("Segunda matriz: ");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++)
      scanf("%d", &mat2[i][j]);
  }

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++)
      matSoma[i][j] = mat1[i][j] + mat2[i][j];
   }

    determinante = matSoma[0][0] * matSoma[1][1] - matSoma[0][1] * matSoma[1][0];

    printf("Valor do eterminante: %d\n", determinante);


  return 0;
}
