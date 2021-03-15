#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[51];
    double nota;
    double freq;
} Aluno;

void arqBinario(int n, Aluno *alunos, char *nomeArq)
{
    FILE *arq = fopen(nomeArq, "wb");
    fwrite(&n, sizeof(int), 1, arq );
    fwrite(alunos, sizeof(Aluno), n, arq );
    fclose(arq);
}

int main()
{
    Aluno *alunos;
    int n;
    char nomeArq[50];
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    alunos =  malloc(n * sizeof(Aluno));
    for(int i = 0; i < n; i++){
        printf("Nome: ");
        scanf("%s", alunos[i].nome);
        printf("Nota: ");
        scanf("%lf", &alunos[i].nota);
        printf("Frequência: ");
        scanf("%lf", &alunos[i].freq);
    }
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    arqBinario(n, alunos, nomeArq);
    
    free(alunos);
    return 0;
}