#include <stdio.h>

#include<math.h>

int main()
{

	double n, parteinteira,partedecimal;

	scanf("%lf",&n);

	parteinteira = floor(n);
	partedecimal = n - parteinteira;

	printf("numero %.3lf parte inteira = %.0lf parte decimal %.3lf ", n, parteinteira, partedecimal );

return 0;
}