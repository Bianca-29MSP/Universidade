//Crie uma função que receba um número e o imprima na ordem inversa. ( 0 < n < 10000)

#include <stdio.h>

int main(){
  int n, a, b, c, d;
  scanf("%d", &n);

  if(n < 100){
    a = n % 10;
    b = (n - a) / 10;
    printf("%d%d\n",a,b);
  }

  else if(n < 1000 ){
    a = n % 100 % 10;
    b = (n - a) % 100 / 10;
    c = (n - (a + b * 10))  / 100;
    printf("%d%d%d\n",a,b,c);
  }

  else if(n < 10000){
    a = n % 100 % 1000 % 10;
    b = (n - a) % 1000 % 100 / 10;
    c = (n - (a + b * 10)) % 1000 / 100;
    d = (n - (a + (b * 10) + (c * 100))) / 1000;
    printf("%d%d%d%d\n",a,b,c,d);
  }

  else if(n == 100)
      printf("001\n");

  else if(n == 1000)
      printf("0001\n");

  else if(n == 10000)
      printf("00001\n");

  return 0;
}
