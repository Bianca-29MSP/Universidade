#include <stdio.h>

int main(){
	char frase[22];

	fgets(frase, 22, stdin);

	for(int i = 0; i < 20; i++){
		if(frase[i] != ' ')
			frase[i] = ((int)frase[i] + 3) - 32;
	}

	printf("%s\n", frase);
	
	return 0;
}