#include <stdio.h>

int main(){
  int x, i;
  do{
    scanf("%d", &x);
    if(x != 0){
      for(i = 1; i <= x; i++){
        printf("%d", i);
        if(i <= (x - 1))
          printf(" ");
        if(i == x && x != 0)
          printf("\n");
        }
    }
  }while(x != 0);
  return 0;
}
