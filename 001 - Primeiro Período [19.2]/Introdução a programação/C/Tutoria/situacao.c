#include <stdio.h>

char situacao(double p1, double p2, double p3, int faltas, int aulas, double *media);

int main(){
  double p1, p2, p3, media;
  int faltas, aulas;
  scanf("%lf %lf %lf", &p1, &p2, &p3);
  scanf("%d %d", &faltas, &aulas);

  char sit = situacao(p1, p2, p3, faltas, aulas, &media);

  switch(sit){
    case 'A':
      printf("Aprovado\n");
      break;
    case 'R':
      printf("Reprovado\n");
      break;
    case 'F':
      printf("Reprovado por faltas\n");
      break;
  }
  return 0;
}

char situacao(double p1, double p2, double p3, int faltas, int aulas, double *media){
  *media = (p1 + p2 + p3) / 3;
  int falta = (100 * faltas) / aulas;
  if(*media >= 6 && falta <= 25)
    return 'A';
  else if(*media < 6 && falta <= 25)
    return 'R';
  else //if(falta > 25)
    return 'F';

}
