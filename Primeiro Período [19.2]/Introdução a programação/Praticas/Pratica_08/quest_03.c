#include <stdio.h>
//cd Documents/UFOP/Praticas/Pratica_08
int main()
{
  int x,y;
  int i = 0, j = 0;
  printf("Digite os valores de x e y: ");
  scanf("%d %d", &x, &y);

  while(x % 2 == 1 || y % 2 ==1 ){
    printf("Apenas numeros pares são aceitos.\n");
    printf("Digite os valores de x e y:");
    scanf("%d %d", &x, &y);
  }

  while( x > y){
    printf("Erro: x deve ser menor que y.\n");
    printf("Digite os valores de x e y:");
    scanf("%d %d", &x, &y);
  }
//7
  int cont = 0;
  //Numero de linhas
  while(x <= y){
    //espaços
    while(j < ((y - x)/2)){
      printf(" ");
      j++;
      cont ++;
    }
    //Numero de asteriscos
    while (i < x) {
      printf("*");
      i++;
    }
    j = 0;
    i = 0;
    x += 2;
    printf("\n");
  }


  return 0;
}
