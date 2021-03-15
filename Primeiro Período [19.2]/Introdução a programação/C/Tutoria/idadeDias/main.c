#include <stdio.h>
#include "idadeDias.h"

int main()
{
	int dia, mes, ano, diaAtual, mesAtual, anoAtual;
	printf("Data de nascimento: ");
	scanf("%d %d %d", &dia, &mes, &ano);
	printf("Data atual: ");
	scanf("%d %d %d", &diaAtual, &mesAtual, &anoAtual);

	int idadeD = idadeDias(dia, mes, ano, diaAtual, mesAtual, anoAtual);

	printf("Sua idade me dias eh: %d\n", idadeD);

	return 0;
}