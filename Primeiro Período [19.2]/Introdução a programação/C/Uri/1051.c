#include <stdio.h>

int main(){
  float renda, dif, imposto;
  scanf("%f", &renda);

  if(renda >= 0 && renda <= 2000){
    printf("Isento\n");
  }

  else if( renda <= 3000){
    dif = renda - 2000;
    imposto = dif * 0.08;
    printf("R$ %.2f\n", imposto);
  }

  else if(renda <= 4500){
    dif = (renda - 3000) * 0.18;
    imposto = dif + (1000 * 0.08);
    printf("R$ %.2f\n", imposto);
  }

  else if(renda > 4500){
    dif = (renda - 4500) * 0.28;
    imposto = dif + (1000 * 0.08) + (1500 * 0.18);
    printf("R$ %.2f\n", imposto);
  }

  return 0;
}
