#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[51];
    double nota;
    double freq;
} Aluno;

int main()
{
    Aluno *alunos;
    int n;
    char nomeArq[50];
    double notaMedia;
    double freqMedia;
    double aprovacao;
    int contAprovados = 0;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    FILE *arq = fopen(nomeArq, "rb");
    fread(&n, sizeof(int), 1, arq);
    alunos =  malloc(n * sizeof(Aluno));
    fread(alunos, sizeof(Aluno), n, arq);
    for(int i = 0; i < n; i++){
        notaMedia += alunos[i].nota;
        freqMedia += alunos[i].freq;
        if(alunos[i].nota >= 6 && alunos[i].freq >= 75)
            contAprovados++;
    }
    notaMedia /= n;
    freqMedia /= n;
    aprovacao = (contAprovados * 1.0 / n) * 100;

    printf("Nota média: %.2lf\n", notaMedia);
    printf("Frequência média: %.1lf%%\n", freqMedia);
    printf("Percentual de aprovação: %.lf%%\n", aprovacao);
    printf("Nomes dos alunos com nota acima da média: \n");

    for(int i = 0; i < n; i++)
        if(alunos[i].nota >= notaMedia)
            printf("%s\n", alunos[i].nome);
    
    fclose(arq);
    free(alunos);
    return 0;
}