#include <stdio.h>

int main()
{
  int n, x, y, i = 0, soma = 0;;
  scanf("%d", &n);
  while (i < n){
      scanf("%d %d", &x, &y);
      if(x == y || y == x + 1 || x == y + 1)
        printf("0\n");

      else if(x > y){
        while(y < (x - 1)){
          if((y + 1) % 2 != 0)
            soma += (y + 1);
          y++;
        }
        printf("%d\n", soma);
      }

      else if(y > x){
          while(x  <  (y - 1)){
            if((x + 1)  %  2 !=0)
            soma += (x + 1) ;
          x++;
        }
        printf("%d\n", soma);
      }
      soma = 0;
      i++;
  }

  return 0;
}
