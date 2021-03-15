#include <stdio.h>

int main(){
  int p,r;
  char caminho;
  scanf("%d %d", &p, &r);

  if(p == 0){
    caminho = 'C';
  }
  else if(p == 1){
    if(r == 0)
      caminho = 'B';
    else
      caminho = 'A';
  }

  printf("%c\n", caminho);
  return 0;
}
