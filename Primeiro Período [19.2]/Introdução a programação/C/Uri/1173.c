#include <stdio.h>

int main(){
  int n[10], i;
  int v;
  scanf("%d", &v);
  int result = v;
  for(i = 0; i < 10; i++){
    n[i] = result;
    result *= 2;
  }

  for(i = 0; i < 10; i++){
    printf("N[%d] = %d\n", i, n[i]);
  }

  return 0;
}
