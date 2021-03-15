#include <stdio.h>

int main(){
  int n, binario[8];
  scanf("%d", &n);
  for (int i = 0; i < 8; i++) {
      binario[i] = n % 2;
      n = n / 2;
  }

  for (int i = 7; i >= 0; i--) {
    printf("%d ", binario[i]);
  }
  return 0;
}
