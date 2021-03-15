#include <stdio.h>

void maiorNota(double, double, double);

int main()
{
	double nota1, nota2, nota3;

	scanf("%lf %lf %lf", &nota1, &nota2, &nota3);

	maiorNota(nota1, nota2, nota3);

	return 0;
}

void maiorNota(double nota1, double nota2, double nota3)
{

	if (nota1 > nota2 && nota1 >nota3)
		printf("Maior nota = %.2lf\n", nota1);

	else if (nota2 > nota1 && nota2 >nota3)
		printf("Maior nota = %.2lf\n", nota2);

	else if (nota3 > nota1 && nota3 >nota1)
		printf("Maior nota = %.2lf\n", nota3);
	
	else if (nota1 == nota2 && nota2 == nota3)
		printf("Notas iguais\n");
}
