#include <stdio.h>
#include <math.h>

int main(){
  double a, b, c, aux;
  scanf("%lf %lf %lf", &a, &b, &c);

  if (a <= b && a <= c){
        aux = c;
        c = a;
        if(aux <= b){
          a = b;
          b = aux;
        }
        else if(b < aux)
          a = aux;
  }
  else if(b <= a && b <= c){
      aux = c;
      c = b;
      if(aux <= a)
        b = aux;
      else if(a < aux){
        b = a;
        a = aux;
      }
  }
  else{
      if(b >= a){
        aux = a;
        a = b;
        b = aux;
    }
  }

  if(a >= b + c){
    printf("NAO FORMA TRIANGULO\n");
  }

  else{
    if (pow(a,2) == (pow(b,2) + pow(c,2)))
      printf("TRIANGULO RETANGULO\n");

    if( pow(a,2) > (pow(b,2) + pow(c,2)))
      printf("TRIANGULO OBTUSANGULO\n");

    if(pow(a,2) < (pow(b,2) + pow(c,2)))
      printf("TRIANGULO ACUTANGULO\n");

    if(a == b && b == c)
      printf("TRIANGULO EQUILATERO\n");

    if( (a == b && b != c) || (b == c && c != a) || (c == a && a != b))
      printf("TRIANGULO ISOSCELES\n");
  }

  return 0;
}
