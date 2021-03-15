#include <stdio.h>
#include <math.h>


int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int x = a % 2 == 0 ? pow(a,2) + b : a + pow(b,2); // x recebe pow(a,2) + b se a % 2 == 0 for verdadeira, caso contrario a + pow(b,2)



	printf("%d\n", x );

	printf("\a"); //BEEP

	return 0;
}