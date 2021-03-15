#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int num;

	int x = rand() % 101; // x recebe um nro aleatório de 0 até 100
	printf("Adivinhe o nro: ");
	scanf("%d", &num);

	while (num != x)
	{
	printf("Errado, digite novamente: ");
	scanf("%d", &num);

	if(num > x)
		printf("O nro eh menor\n");
	else if(num < x)
		printf("O nro eh maior\n");
	else if(num == x)
		printf("O nro eh correto\n Num = %d", x);
	}


	return 0;
}