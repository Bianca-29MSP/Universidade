#include <stdio.h>

long long fat(int n);

int main(){
  int n;
  printf("Digite o valor de n: \n");
  scanf("%d", &n);

  long long result = fat(n);
  printf("%d! = %lld\n", n, result);
  return 0;
}

long long fat(int n){
  int i = 0;
  int f = 1;
  while(i < n){
    f = (n - i) * f;
    i++;
  }
  return f;
}
