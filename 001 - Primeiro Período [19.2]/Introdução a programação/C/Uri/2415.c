#include <stdio.h>

int main(){
  int n, x, i, cont = 0, num = 0, maiorSequencia = 0;
  scanf("%d", &x);
  for(i = 0; i < x; i++){
    scanf("%d", &n);
    if(n == num){
      cont++;
    }else{
    if(cont + 1 > maiorSequencia){
       maiorSequencia = cont + 1;
    }
      cont = 0;
  }
    num = n;
  }
  if(cont + 1 > maiorSequencia){
     maiorSequencia = cont + 1;
  }
  printf("%d\n", maiorSequencia);
  return 0;
}
