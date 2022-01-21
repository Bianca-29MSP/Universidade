//Se B for maior do que C 
//E se D for maior do que A
//E a soma de C com D for maior que a soma de A e B 
//E se C e D, ambos, forem positivos 
//E e se a variável A for par 

#include <stdio.h>


int main()
{
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	if( (b > c) && (d > a) && (c + d > a + b) && (c >= 0) && (d >=0) && (a%2 == 0))
		printf("Valores aceitos\n");
	else
		printf("Valores nao aceitos\n");
	return 0;
}