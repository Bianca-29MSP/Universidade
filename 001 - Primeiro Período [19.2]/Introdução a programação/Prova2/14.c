#include <stdio.h>
#include <limits.h>

int main(){
	int n, vet[10000], maior = INT_MIN, menor = INT_MAX;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &vet[i]);
		if(vet[i] > maior)
			maior = vet[i];
	    if(vet[i] < menor)
	    	menor = vet[i];
	}

	printf("Maior %d\n", maior);
	printf("Menor %d\n", menor);

	return 0;
}