#include <stdio.h>

int main()
{
	double peso, x;
	int p;
	scanf("%lf", &peso);

	printf("Escolha o planeta:\n1 - Marte\n2 - Urano\n3 - Saturno\n4 - Venus\n5 - Mercurio\n");
	scanf("%d", &p);

	switch(p)
	{
		case 1:
			x = (peso / 10) * 0.38;
			break;
		case 2:
			x = (peso / 10) * 1.17;
			break;
		case 3:
			x = (peso / 10) * 1.15;
			break;
		case 4:
			x = (peso / 10) * 0.88;
			break;
		case 5:
			x = (peso / 10) * 0.37;
			break;
		default:
			x = 0;
	}
		if(x == 0)
			printf("Erro\n");
		else
			printf("%.2lf\n", x);

	return 0;
}