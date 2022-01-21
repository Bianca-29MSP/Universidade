#include <stdio.h>
#include <math.h>

double delta(double, double, double);

int main()
{
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);
	double resultado = delta(a, b, c);
	printf("Delta = %.2lf\n", resultado);

	return 0;
}

double delta(double a, double b, double c)
{
	return pow(b,2) - (4 * a * c);


}
