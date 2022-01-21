#include <stdio.h>

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);
  int cont = 0;
  if(x > y){
    while(y <= x){
      if(y % 13 != 0)
        cont += y;
      y++;
    }
  }
  else if(y > x){
    while(x <= y){
      if(x % 13 != 0)
        cont += x;
      x++;
    }
  }
printf("%d\n", cont);

  return 0;
}
