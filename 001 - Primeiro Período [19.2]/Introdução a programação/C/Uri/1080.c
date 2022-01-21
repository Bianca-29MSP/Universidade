#include <stdio.h>
#include <limits.h>
int main(){
  int i, maiorNum = INT_MIN, num, posicao;
  for(i = 0; i < 5; i++){
    scanf("%d", &num);
    if(num > maiorNum){
      maiorNum = num;
      posicao = i + 1;
    }
  }
  printf("%d\n", maiorNum);
  printf("%d\n", posicao);
  return 0;
}
