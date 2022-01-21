#include <stdio.h>

int main()
{
	int nFuncionario, horas;
	double valorHora;
	double salario;

	scanf("%d", &nFuncionario);
	scanf("%d", &horas);
	scanf("%lf", &valorHora);

	salario = horas * valorHora;

	printf("NUMBER = %d\n", nFuncionario);
	printf("SALARY = U$ %.2lf\n", salario);

	return 0;
}