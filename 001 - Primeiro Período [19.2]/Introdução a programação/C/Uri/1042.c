#include <stdio.h>

int main(){
  int num[3], aux;

  for(int i = 0; i < 3; i ++){
		scanf("%d", &num[i]);
	}
  int a = num[0], b = num[1], c = num[2];

	for(int j = 0; j < 3; j++){
    for(int k = j; k < 3; k++){
      if(num[j] > num[k]){
        aux = num[j];
        num[j] = num[k];
        num[k] = aux;
      }
    }
  }

  for(int i = 0; i < 3; i++){
    printf("%d\n", num[i]);
  }
  printf("\n%d\n", a);
  printf("%d\n", b);
  printf("%d\n", c);

  return 0;
}
