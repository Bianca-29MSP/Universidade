/*
* ENYA LUÍSA GOMES DOS SANTOS
* 19.2.4201
* BCC201 - TURMA32
*/
#include <stdio.h>

typedef struct 
{
    char comida[100];
    double peso;
    double numCalorias;
} Dieta;

void arquivo(Dieta elementos[100], char nomeArq[100], int *n)
{
    FILE *arq = fopen(nomeArq, "r");
    fscanf(arq, "%d", n);
    for(int i = 0; i < *n; i++){
        fscanf(arq, "%s" , elementos[i].comida);
        fscanf(arq, "%lf" , &elementos[i].peso);
        fscanf(arq, "%lf" , &elementos[i].numCalorias);
    }
}
int main()
{
    Dieta elementos[100];
    char nomeArq[100];
    int n, maior = 0, i;
    double calGrama;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    arquivo(elementos, nomeArq, &n);
    for(i = 0; i < n; i++){
        if((elementos[i].numCalorias / elementos[i].peso) > maior)
            maior = elementos[i].numCalorias / elementos[i].peso;
    }
    printf("Alimento \t\t cal/grama\n");
    printf("----------------------------------\n");
    for(int j = 0; j < n; j++){
        calGrama = elementos[j].numCalorias / elementos[j].peso;
        printf("%s \t %.2lf", elementos[j].comida, calGrama);
        if(calGrama == maior)
            printf("*");
            printf("\n");
        
    }

}