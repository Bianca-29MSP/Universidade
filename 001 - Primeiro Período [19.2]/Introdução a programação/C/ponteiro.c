/*Crie um programa com uma variavel inteira chamada num e dois ponteiros para int, chamados ptr e ptr2. 
Atribua um valor a num e faça com que ptr aponte para num. 
Atribua o endereço apontado por ptr2 a ptr, de forma que os dois apontem para 
o mesmo endereço.
Altere o conteudo apontado por cada um dos apontadores e analise o que acontece com a variavel num.*/

#include <stdio.h>

int main()
{
	int num = 84;
	int *ptr, *ptr2;
	ptr = &num;
	ptr2 =  ptr;

	printf("%p %p\n", ptr, ptr2);

	*ptr = 56;

	printf("%d\n", num);
	return 0;
}