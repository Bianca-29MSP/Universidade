//Vatores
#include <stdio.h>
#define TAM 3

int main(){

	int vetor[TAM], i;

	//passando valores para o vetor

	//contagem começa do 0
	vetor[0] = 5;
	vetor[1] = 10;
	vetor[2] = 15;

	//imprimindo o vetor 
	printf("Posicao 0: %d\n", vetor[0]);
	printf("Posicao 0: %d\n", vetor[1]);
	printf("Posicao 0: %d\n", vetor[2]);

	//imprimindo o vetor em um laço de repetição
	for(i = 0; i < TAM; i ++){
		printf("Posicao %d: %d\n", i, vetor[i]);
	}

	//lendo tres valores para o vetor
	for(i = 0; i < TAM; i ++){
		scanf("%d", &vetor[i]);
	}

	//imprimindo em um laço de repetição os valores lidos
	for(i = 0; i < TAM; i ++){
		printf("Posicao %d: %d\n", i, vetor[i]);
	}
}