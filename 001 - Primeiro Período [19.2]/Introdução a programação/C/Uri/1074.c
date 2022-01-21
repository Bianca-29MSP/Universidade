#include <stdio.h>

int main()
{
  int n, x, i = 0;
  scanf("%d", &n);
  while(i < n){
    scanf("%d", &x);
    if(x != 0){
        if(x % 2 == 0)
          printf("EVEN ");
        else
          printf("ODD ");
        if(x > 0)
          printf("POSITIVE\n");
        else
          printf("NEGATIVE\n");
    }
    else
        printf("NULL\n");
    i++;
  }

  return 0;
}
