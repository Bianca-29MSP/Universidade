#include <stdio.h>

int ehPrimo(int n);

int main(){
  int n;
  printf("Digite um numero: ");
  scanf("%d", &n);
  int result = ehPrimo(n);
  if(result == 0)
    printf("%d NAO eh um numero primo!\n", n);
  else
    printf("%d eh um numero primo!\n", n);

  return 0;
}

int ehPrimo(int n){
  int i = 2;
  int cont = 0;
  while(i < n)
    if(n % i == 0){
      cont ++;
    i++;
  }

  if(cont == 0)
    return 1;
  else
    return 0;
}
