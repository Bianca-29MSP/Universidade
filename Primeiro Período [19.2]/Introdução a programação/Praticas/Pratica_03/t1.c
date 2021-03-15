#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char codigo[10];
    char nome[100];
    double valor;
} Produtos;

int main(){
    Produtos *produto;
    int n;
    printf("Quantidade de produtos que deseja registrar: ");
    scanf("%d", &n);
    produto = malloc(n * sizeof(Produtos));
    for(int i = 0; i < n; i++){
        printf("Produto %d \n", i + 1);
        scanf("%s", produto[i].codigo);
        scanf("%s", produto[i].nome);
        scanf("%lf", &produto[i].valor);
    }

    FILE *arq = fopen("produtos.dat", "wb");
    fwrite(produto, sizeof(Produtos), n, arq);
}