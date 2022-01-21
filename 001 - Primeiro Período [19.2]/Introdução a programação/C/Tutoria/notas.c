#include <stdio.h>

int main(){
  int num, i = 0;
  double nota , notaMaior = 0, notaMenor = 0, total = 0;
  scanf("%d", &num);

  while (i < num) {
    printf("Nota do anulo %d: ", i + 1);
    scanf("%lf", &nota);
    total += nota;
    if(nota > notaMaior)
      notaMaior = nota;
    if(nota < 10)
      notaMenor = nota;
    i++;
  }
    printf("Media da turma = %.2lf\n", total / i);
    printf("Maior nota = %.2lf\n", notaMaior);
    printf("Menor nota = %.2lf\n", notaMenor);

    return 0;
}
