#include <stdio.h>

int main(){
  int vet1[10], vet2[10];

  printf("Primeiro vetor: ");
  for(int i = 0; i < 10; i++)
      scanf("%d", &vet1[i]);

  printf("Segundo vetor: ");
  for(int i = 0; i < 10; i++)
      scanf("%d", &vet2[i]);


  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++)
      if(vet1[i] == vet2[j])
      printf("%d ", vet1[i]);
   }

  return 0;
}
