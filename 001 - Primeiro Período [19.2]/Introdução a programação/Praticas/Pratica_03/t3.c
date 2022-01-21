#include <stdio.h>
#include <stdlib.h>


int main(){
    char frase[100];
    FILE *arq = fopen("teste.txt", "r");
    fgets(frase, 100, arq);
    printf("%s\n", frase);
}