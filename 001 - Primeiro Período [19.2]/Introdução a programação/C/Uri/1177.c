#include <stdio.h>

int main(){
  int n[1000], i;
  int v;
  int num;
  scanf("%d", &v);
  for(i = 0; i < 1000; i++){
    for(num = 0; num < v; num++){
       n[i] = num;
          i++;
     }
  }

  for(i = 0; i < 10; i++){
    printf("N[%d] = %d\n", i, n[i]);
  }

  return 0;
}
