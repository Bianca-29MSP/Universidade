#include <stdio.h>

int main(){
  int num, razao, numTermos, i = 1, resultado;
  printf("Primeiro termo: ");
  scanf("%d", &num);
  printf("Razao: ");
  scanf("%d", &razao);
  printf("Nº de termos: ");
  scanf("%d", &numTermos);
  printf("PA: ");
  while(i <= numTermos){
    resultado = num + (i - 1) * razao;
    printf("%d, ", resultado);
    i++;
  }
  printf("\n");
    return 0;
}
