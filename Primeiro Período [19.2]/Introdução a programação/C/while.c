//while enquanto .. faça
//primeiro compara e depois entra no while
#include <stdio.h>

int main(){
	int a = 1, b = 10;

	//contando até 10;
	while(a <= 10){

		//imprimindo a na tela
		printf("%d\n", a);

		//op. de incremento
		a++; //a = a + 1;
	}

	//contagem regressiva
	while(b >= 1){

		//imprimindo a na tela
		printf("%d\n", b);

		//op. de incremento
		b--; //b = b - 1;
	}
	return 0;
}