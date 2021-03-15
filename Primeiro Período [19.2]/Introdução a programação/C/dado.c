#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int soma, x;
	scanf("%d", &x);
	srand(time(NULL)); 
	
	soma = ((rand() % 6) + 1) + ((rand() % 6) + 1); // x recebe um nro aleatório

	if(soma == x)
		printf("Resposta correta!! %d  %d\n", soma, x);

	else
		printf("Resposta errada!! %d  %d\n", soma, x);

	return 0;
}