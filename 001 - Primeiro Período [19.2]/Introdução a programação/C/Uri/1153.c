#include <stdio.h>

int main(){
  int f, i, resp = 1;
  scanf("%d", &f);

  for(i = 1; f >= i; f--){
    resp *= f;
  }

  printf("%d\n", resp);
  return 0;
}
