//([0,25], (25,50], (50,75], (75,100])

#include <stdio.h>


int main()
{
	double x;

	scanf("%lf", &x);

	if(x >= 0 )
	{
	if(x <= 25)
		printf("Intervalo [0,25]\n");

	else if(x <= 50)
		printf("Intervalo (25,50]\n");

	else if(x <= 75)
		printf("Intervalo (50,75]\n");

	else if(x <= 100)
		printf("Intervalo (75,100]\n");

	else
		printf("Fora de intervalo\n");
    }
    else
		printf("Fora de intervalo\n");

	return 0;
}