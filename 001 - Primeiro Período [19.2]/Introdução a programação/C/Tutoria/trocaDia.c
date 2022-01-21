/*Escreva uma função que tem como parâmetros de entrada três números: dia, mês e ano, representando uma data, e modifica esses inteiros
de forma que eles representem o dia seguinte.*/

#include <stdio.h>

void diaSeguinte(int *dia, int *mes, int *ano);

int main(){
  int dia, mes, ano;
  scanf("%d %d %d", &dia, &mes, &ano);

  diaSeguinte(&dia, &mes, &ano);

  printf("%d/%d/%d\n", dia, mes, ano);
  return 0;
}

void diaSeguinte(int *dia, int *mes, int *ano){

  if(*mes == 12){
    *dia = 1;
    *mes = 1;
    *ano = *ano + 1;
  }

  else if(*mes == 2){
    if(*dia == 28){
      *dia = 1;
      *mes = *mes + 1;
    }
    else{
      *mes = *mes + 1;
      *dia = *dia +1;
    }
  }
  else if(*dia == 30){
    *dia = 1;
    *mes = *mes + 1;
  }
  else{
    *dia = *dia + 1;
    *mes = *mes + 1;
  }


}
