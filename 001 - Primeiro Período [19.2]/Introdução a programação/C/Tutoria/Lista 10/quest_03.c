#include <stdio.h>

int main(){
  int n, cont = 0;
  scanf("%d", &n);
  printf("1 ");
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++){
      if(i % j == 0)
        cont++;
    }
        if(cont == 2)
          printf("%d ",i);
      cont = 0;
    }

  return 0;
}
