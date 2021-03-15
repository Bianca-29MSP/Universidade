#include <stdio.h>

int main(){
  int n, i;
  scanf("%d", &n);
  int iccanobif[n];
  iccanobif[0] = 1;
  iccanobif[1] = 1;
  iccanobif[2] = 2;
  for(i = 2; i < n; i++){
    iccanobif[i+1] = iccanobif[i] + iccanobif[i - 1];
  }
  for(i = (n - 1); i >= 0; i--){
    printf("%d",iccanobif[i]);
    if(i != 0)
      printf(" ");
  }
    printf("\n");
    return 0;
}
