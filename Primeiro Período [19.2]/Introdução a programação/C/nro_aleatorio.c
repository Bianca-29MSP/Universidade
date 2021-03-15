#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL)); // seleciona a semente para geração de nros aleatórios, nesse caso de acordo com o segundo atual

	int x = rand(); // x recebe um nro aleatório

	printf("%d\n", x);


	return 0;
}