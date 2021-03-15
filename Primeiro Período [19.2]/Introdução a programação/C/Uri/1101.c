#include <stdio.h>

int main(){
  int n = 1, m = 1, soma = 0;

  while(n != 0  || m != 0){
      scanf("%d %d", &n, &m);
      if(n <= 0 || m <= 0)
        break;
      else{
        if(n > m){
        while(m <= n){
        printf("%d ", m);
        soma += m;
        m++;
      }
      }
        else if(m > n){
          while(n <= m){
          printf("%d ", n);
          soma += n;
          n++;  
        }
      }
    }
      printf("Sum=%d\n", soma);
      soma = 0;
    }

  return 0;
}
