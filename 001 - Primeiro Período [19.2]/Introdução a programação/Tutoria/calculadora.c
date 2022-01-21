#include <stdio.h>

void operacao(double, double, char);

int main()
{
	double num1, num2;
	char operador;
	scanf("%c", &operador);
	scanf("%lf %lf", &num1, &num2);	
	operacao(num1, num2, operador);
	
	return 0;
}

void operacao(double num1, double num2, char op)
{
	double resultado;
	switch (op)
	{
		case '+':
			resultado = num1 + num2;
			printf("%.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
			break;
		case '-':
			resultado = num1 - num2;
			printf("%.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
			break;
		case '*':
			resultado = num1 * num2;
			printf("%.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
			break;
		case '/':
			resultado = num1 / num2;
			printf("%.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
			break;
		default:
			printf("Erro!! Operador invalido.\n");

	}
}
