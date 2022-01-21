#include <stdio.h>

int main(){
  int n[5], cont;
  for(int i = 0; i < 5; i ++){
    scanf("%d", &n[i]);
  }

  for(int j = 0; j < 5; j ++){
    if(n[j] % 2 == 0)
      cont++;
  }
  printf("%d valores pares\n", cont);
  return 0;
}
