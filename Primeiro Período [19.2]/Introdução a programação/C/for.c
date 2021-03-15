//FOR, para
#include <stdio.h>


int main(){
	int i;

	//contando até dez
	for(i = 1; i <= 10; i++){
		printf("%d\n", i);
	}

	//tabuada de 5
	for(i = 1; i <= 10; i++){
		printf("5 X %d = %d\n", i, 5 * i);
	}

	//contar de 2 em 2
	for(i = 0; i <= 10; i = i + 2){
		printf("%d\n", i);
	}

	//contagem regressiva
	for(i = 10; i > 0; i--){
		printf("%d\n", i);
	}
}