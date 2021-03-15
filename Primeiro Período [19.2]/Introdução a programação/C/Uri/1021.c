#include <stdio.h>

int main()
{
	float vMonetario;
	int cem, cinquenta, vinte, dez, cinco, dois;
	float resto;
	int um, cinquentaCents, vinteCincoCents, dezCents, cincoCents, umCents;

	scanf("%f", &vMonetario);

	vMonetario = vMonetario + 0.001;

	cem = vMonetario /  100;

	cinquenta = (vMonetario - (cem * 100)) / 50;

	vinte = (vMonetario - (cem * 100) - (cinquenta * 50)) / 20;

	dez = (vMonetario - (cem * 100) - (cinquenta * 50) - (vinte * 20)) / 10;

	cinco = (vMonetario - (cem * 100) - (cinquenta * 50) - (vinte * 20) - (dez * 10)) / 5;

	dois = (vMonetario - (cem * 100) - (cinquenta * 50) - (vinte * 20) - (dez * 10) - (cinco * 5)) / 2;

	um = (vMonetario - (cem * 100) - (cinquenta * 50) - (vinte * 20) - (dez * 10) - (cinco * 5) - (dois * 2)) / 1;


	resto = (vMonetario - (cem * 100) - (cinquenta * 50) - (vinte * 20) - (dez * 10) - (cinco * 5) - (dois * 2));

	cinquentaCents = (resto - (um * 1)) / 0.50;

	vinteCincoCents = (resto - (um * 1) - (cinquentaCents * 0.50)) / 0.25;

	dezCents =  (resto - (um * 1) - (cinquentaCents * 0.50) - (vinteCincoCents * 0.25)) / 0.10;

	cincoCents = (resto - (um * 1) - (cinquentaCents * 0.50) - (vinteCincoCents * 0.25) - (dezCents * 0.10)) / 0.05;

	umCents = (resto - (um * 1) - (cinquentaCents * 0.50) - (vinteCincoCents * 0.25) - (dezCents * 0.10) - (cincoCents * 0.05)) / 0.01;


	printf("NOTAS:\n");

	printf("%d nota(s) de R$ 100.00\n", cem);

	printf("%d nota(s) de R$ 50.00\n", cinquenta);

	printf("%d nota(s) de R$ 20.00\n", vinte);

	printf("%d nota(s) de R$ 10.00\n", dez);

	printf("%d nota(s) de R$ 5.00\n", cinco);

	printf("%d nota(s) de R$ 2.00\n", dois);

	printf("MOEDAS:\n");

	printf("%d moeda(s) de R$ 1.00\n", um);

	printf("%d moeda(s) de R$ 0.50\n", cinquentaCents);

	printf("%d moeda(s) de R$ 0.25\n", vinteCincoCents);

	printf("%d moeda(s) de R$ 0.10\n", dezCents);

	printf("%d moeda(s) de R$ 0.05\n", cincoCents);

	printf("%d moeda(s) de R$ 0.01\n", umCents);

	return 0;
}
