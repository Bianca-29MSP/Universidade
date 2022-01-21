#include <stdio.h>

int main()
{
  double nota = 0, i = 0, calculaNota = 0;
  while (i < 2){
    nota = 0;
  while (nota == 0) {
    scanf("%lf", &nota);
    if(nota < 0 || nota > 10){
      printf("nota invalida\n");
      nota = 0;
    }
    else{
      calculaNota += nota;
      nota++;
      i++;
    }
  }
}
    printf("media = %.2lf\n", calculaNota/2);
  return 0;
}
