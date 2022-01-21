#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    int n, maior = INT_MIN, menor = INT_MAX, cont = 0, somaIm = 0;
    printf("Tamanho: ");
    scanf("%d", &n);
    int *vet = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &vet[i]);
        if(vet[i] > maior)
            maior = vet[i];
        if(vet[i] < menor)
            menor = vet[i];
        if(vet[i] % 2 == 1){
            cont++;
            somaIm += vet[i];
        }
    }
    int *impar = malloc(cont * sizeof(int));
    int j = 0;
    for(int i = 0; i < n; i++){
        if(vet[i] % 2 == 1){
            impar[j] = vet[i];
            j++;
        }
    }

    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d\n", maior);
    printf("Impares: ");
    for(int i = 0; i < cont; i++)
        printf("%d ", impar[i]);
    printf("\n");
    printf("Soma dos impares: %d\n", somaIm);
    return 0;
}