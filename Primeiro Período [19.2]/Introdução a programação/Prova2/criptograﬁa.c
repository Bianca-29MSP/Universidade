#include <stdio.h>

int main(){
	char frase[22];

	fgets(frase, 22, stdin);

	for(int i = 0; i < 20; i++){
		frase[i] = (int)ffrase[i] + 3;
	}

	printf("%s\n", frase);
	
	return 0;
}