#include <stdio.h>

int main(){
  int n, i, caixas[100000], j, k, aux;
  char ehPossivel;
  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &caixas[i]);

  for(j = 0; j < n; j++){
    for (k = j; k < n; k++){
      if(caixas[j] > caixas[k]){
        aux = caixas[j];
        caixas[j] = caixas[k];
        caixas[k] = aux;
      }
    }
  }

  for(j = 0; j < n; j++){
      if(caixas[j+1] - caixas[j] < 8 && caixas[0] <= 8 && caixas[j+1] != caixas[j])
        ehPossivel = 'S';
      else
        ehPossivel = 'N';
  }

		printf("%c\n", ehPossivel);
    return 0;
}
