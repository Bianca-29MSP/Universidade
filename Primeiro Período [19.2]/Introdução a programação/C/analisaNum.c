#include <stdio.h>

void analisaNum(double *var);


int main()
{
	double num;
	scanf("%lf", &num);

	analisaNum(&num);

	printf("%lf\n", num);

	return 0;
		
}

void analisaNum(double *var)
{
	*var = var % 2 == 0 ? var + 5 : var + 8;
}