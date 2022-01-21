#include <stdio.h>

int main()
{
  double nota = 0, i = 0, calculaNota = 0;
  int j = 0;
  while(j != 2){
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
              if(i == 2)
                 printf("media = %.2lf\n", calculaNota/2);
          }
     }
     calculaNota = 0;
         printf("novo calculo (1-sim 2-nao)\n");
         scanf("%d", &j);
     if(j == 1)
         i = 0;


}

  return 0;
}
