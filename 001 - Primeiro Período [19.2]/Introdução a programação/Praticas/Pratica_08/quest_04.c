#include <stdio.h>

void tabuleiroXadrez(char tab[10][10]);

int main(){
  char tab[10][10] =
  {
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'},
  {'-', '-', '-', '-', '-', '-', '-', '-'}
  };

  int l, c;
  printf("Movimentos de um Bispo no xadrez\n");
  printf("Digite a linha que o Bispo se encontra: ");
  scanf("%d",&l );
  printf("Digite a coluna que o Bispo se encontra: ");
  scanf("%d",&c );

  l = l - 1;
  c = c -1;
  tab[l-1][c-1] = 'X';

  int i = 0, j = 1;

  while(i <= 8){
    while(j <=  (8 - c)){
      tab[l-j][c+j] = 'X';
      tab[l+j][c-j] = 'X';
      tab[l+j][c+j] = 'X';
      j++;
    }
    j = 0;
    i++;
  }

  tabuleiroXadrez(tab);

  return 0;
}

void tabuleiroXadrez(char tab[10][10]){
  printf("    1  2  3  4  5  6  7  8\n");
  printf("   -----------------------\n");
  printf("1 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[0][0], tab[0][1], tab[0][2], tab[0][3],
                                                 tab[0][4],tab[0][5], tab[0][6], tab[0][7]);

  printf("2 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[1][0], tab[1][1], tab[1][2], tab[1][3],
                                                 tab[1][4],tab[1][5], tab[1][6], tab[1][7]);

  printf("3 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[2][0], tab[2][1], tab[2][2], tab[2][3],
                                                 tab[2][4],tab[2][5], tab[2][6], tab[2][7]);

  printf("4 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[3][0], tab[3][1], tab[3][2], tab[3][3],
                                                 tab[3][4],tab[3][5], tab[3][6], tab[3][7]);

  printf("5 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[4][0], tab[4][1], tab[4][2], tab[4][3],
                                                 tab[4][4],tab[4][5], tab[4][6], tab[4][7]);

  printf("6 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[5][0], tab[5][1], tab[5][2], tab[5][3],
                                                 tab[5][4],tab[5][5], tab[5][6], tab[5][7]);

  printf("7 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[6][0], tab[6][1], tab[6][2], tab[6][3],
                                                 tab[6][4],tab[6][5], tab[6][6], tab[6][7]);

  printf("8 | %c  %c  %c  %c  %c  %c  %c  %c\n", tab[7][0], tab[7][1], tab[7][2], tab[7][3],
                                                 tab[7][4],tab[7][5], tab[7][6], tab[7][7]);
}
