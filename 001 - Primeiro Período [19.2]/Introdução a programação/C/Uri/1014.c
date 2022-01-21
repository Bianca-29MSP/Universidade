#include <stdio.h>

int main()
{
	int X;
	double Y;

	scanf("%d", &X);

	scanf("%lf", &Y);

	double consumoMedio = X / Y;

	printf("%.3lf km/l\n", consumoMedio);

	return 0;
}