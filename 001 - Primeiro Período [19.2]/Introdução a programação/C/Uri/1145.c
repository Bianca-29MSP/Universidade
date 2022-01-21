#include <stdio.h>

int main(){
 int x, y, i = 1, j = 0;
 scanf("%d %d", &x, &y);

 while(i <= y){
     printf("%d", i);
     j++;
     if(j <= (x - 1))
      printf(" ");
     if(j == x){
       printf("\n");
       j = 0;
     }
    i++;
 }

return 0;
}
