#include <stdio.h>

int main(){
	int lados[4], i, aux=0;
	for(i = 0; i < 4; i++)
		scanf("%d", &lados[i]);


	for(i = 0; i < 4; i++){
		if(lados[i+1]<lados[i]){
			aux=lados[i];
			lados[i]=lados[i+1];
			lados[i+1]=aux;
		}

	}
 
	if(lados[0]+lados[1]>lados[2] || lados[1]+lados[2]>lados[3] || lados[0]+lados[2]>lados[3])
		printf("S\n");
	else
		printf("N\n");

	return 0;
}
