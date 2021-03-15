#include <stdio.h>

int main(){
  int vet[10], somaImpar = 0;
  for(int i = 0; i < 10; i++){
    scanf("%d", &vet[i]);
    if(vet[i] % 2 == 1)
      somaImpar += vet[i];
  }
  printf("%d\n", somaImpar);
  return 0;
}
