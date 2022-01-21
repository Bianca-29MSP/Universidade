#include <stdio.h>


int main()
{
	int codigo, quant;
	double total;

	scanf("%d %d", &codigo, &quant);

	switch(codigo)
	{
		case 1:
			total = quant * 4.00;
			break;
		case 2:
			total = quant * 4.50;
			break;
		case 3:
			total = quant * 5.00;
			break;
		case 4:
			total = quant * 2.00;
			break;
		case 5:
			total = quant * 1.50;
			break;
	}

	printf("Total: R$ %.2lf\n", total);

	return 0;
}