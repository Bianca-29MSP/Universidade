#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char codigo[10];
    char nome[100];
    double valor;
} Produtos;
 

int main(){
    FILE *arq = fopen("produtos.dat", "rb");
    // move para o indicador de posição para o final do arquivo
    fseek(arq , 0, SEEK_END);    
    // captura a posição atual (em bytes)
    long int tamanho = ftell(arq);

    long int tamanho_S = sizeof(Produtos);

    int n = tamanho / tamanho_S;

    Produtos *produto;
    produto = malloc(n * sizeof(Produtos));

    fseek(arq , 0, SEEK_SET);

    fread(produto, sizeof(Produtos), n, arq);

    for(int i = 0; i < n; i++){
        printf("Produto %d \n", i + 1);
        printf("%s\n",  produto[i].codigo);
        printf("%s\n",  produto[i].nome);
        printf("%lf\n", produto[i].valor);
    } 
    
    fclose(arq);
    free(produto);
    
}