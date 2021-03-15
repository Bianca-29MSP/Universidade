/*
* ENYA LUÍSA GOMES DOS SANTOS
* 19.2.4201
* BCC201 - TURMA 32
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *vet, soma = 0, cont = 0;
    double media;
    printf("Digite o número de elemetos: ");
    scanf("%d", &n);
    vet = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
        soma += vet[i];
    }
    media = soma / (double)n;
    for(int i = 0; i < n; i++){
        if(vet[i] >= media)
            cont++;
    }   
    int j = 0;
    int *vetSuperior = malloc(cont * sizeof(int));
    for(int i = 0; i < n; i++){
        if(vet[i] >= media){
            vetSuperior[j] = vet[i];
            j++;
        }
    }   
    int k = 0;
    int *vetInferior = malloc((n - cont) * sizeof(int));
    for(int i = 0; i < n ; i++){
        if(vet[i] < media){
            vetInferior[k] = vet[i];
            k++;
        }
    } 
    printf("Média = %.2lf\n", media);
    printf("vet2 com %d valores = ", cont);
    for(int i = 0; i < cont; i++)
        printf("%d ", vetSuperior[i]);
    printf("\n");
    printf("vet3 com %d valores = ", n - cont);
    for(int i = 0; i < (n - cont); i++)
        printf("%d ", vetInferior[i]);
    printf("\n");

    free(vet);
    free(vetInferior);
    free(vetSuperior);

    return 0;
}