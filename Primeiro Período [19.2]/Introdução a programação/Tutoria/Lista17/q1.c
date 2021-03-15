#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char marca[50];
    char modelo[50];
    char placa[9];
    int ano;
} Carro;

int main()
{
    Carro *car;
    int n;
    printf("Número de carros: ");
    scanf("%d", &n);
    car = malloc(n * sizeof(Carro));
    FILE *arq = fopen("carros.bin", "wb");
    for(int i = 0; i < n; i++){
        printf("Marca: ");
        scanf("%s", car[i].marca);
        printf("Modelo: ");
        scanf("%s", car[i].modelo);
        printf("Ano: ");
        scanf("%d", &car[i].ano);
        printf("Placa: ");
        scanf("%s", car[i].placa);
    }

    fwrite(&n, sizeof(int), 1, arq);
    fwrite(car, sizeof(Carro), n, arq);
    
    fclose(arq);
    free(car);
    return 0;
}