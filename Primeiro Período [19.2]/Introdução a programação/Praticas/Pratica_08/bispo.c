#include <stdio.h>

int main(){
  int i = 0, j = 0, l, c;
  printf("Movimentos de um Bispo no xadrez!\n");
  printf("Digite a linha em que o Brispo se encontra: ");
  scanf("%d", &l);
  printf("Digite a linha em que o Brispo se encontra: ");
  scanf("%d", &c);

  printf("    1  2  3  4  5  6  7  8\n");
  printf("   -----------------------\n");
  while(i < 8){//linha
    printf("%d | ", i + 1);
    while( j < 8){//coluna
      if((l-1-i) == (c-1-j) || (l-1-i) == (j + 1-c))
        printf("x  ");
        else
          printf("-  ");
      j++;
    }
    printf("\n");
    j = 0;
    i++;
  }
  return 0;
}
