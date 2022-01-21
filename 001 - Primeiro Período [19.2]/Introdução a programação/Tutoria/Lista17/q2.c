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
    char marca[100], modelo[100], placa[50];
    int ano;
    int n;
    
    FILE *arq = fopen("carros.bin", "rb");
    fread(n, sizeof(int), 1, arq);
    car = malloc(n * sizeof(Carro));
    fread(car, sizeof(Carro), n, arq);
   



    for(int i = 0; i < n; i++){
        printf("Marca: %s", car[i].marca);
        printf("Modelo: %s", car[i].modelo);
        printf("Ano: %d", car[i].ano);
        printf("Placa: %s", car[i].placa);
    }
    fclose(arq);
    return 0;
}