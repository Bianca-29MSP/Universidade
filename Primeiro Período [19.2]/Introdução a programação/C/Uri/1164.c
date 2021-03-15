#include <stdio.h>

int main(){
  int n, i, x, j = 1, divisores = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &x);
    for(j = 0; j < x; j++){
      if(6 % (j - 1) == 0)
        divisores += (j-1);
    }
    if(divisores == x)
      printf("%d eh perfeito\n", x);
    else
      printf("%d nao eh perfeito\n", x);
    divisores = 0;
  }
    return 0;
}
