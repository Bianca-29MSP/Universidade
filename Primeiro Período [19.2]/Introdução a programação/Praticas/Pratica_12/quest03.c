/*
* ENYA LUÍSA GOMES DOS SANTOS
* 19.2.4201
* BCC201 - TURMA32
*/
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nome[100];
    double nota;
    int freq;
}Aluno;

int main()
{
    Aluno alunos[100];
    int numAlunos, aprovacao = 0;
    double notaTotal = 0, freqTotal = 0;
    char nomeArq[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);
    FILE *arq = fopen(nomeArq, "r");
    fscanf(arq, "%d", &numAlunos);
    for(int i = 0; i <= numAlunos; i++){
        fgets(alunos[i].nome, 100, arq);
        fscanf(arq, "%lf", &alunos[i].nota);
        fscanf(arq, "%d", &alunos[i].freq);
        if(alunos[i].nota >= 6 && alunos[i].freq >= 75){
            aprovacao += 1;
        }
        notaTotal += alunos[i].nota;
        freqTotal += alunos[i].freq;
        fscanf(arq, "\n");
    }
    printf("Nota média: %.2lf\n", notaTotal/numAlunos);
    printf("Frequência média: %.2lf%%\n", freqTotal/numAlunos);
    printf("Percentual de aprovação: %d%%\n", aprovacao*100/numAlunos);
    printf("Nomes dos alunos que tiveram a nota acima da média: \n");
    fclose(arq);
    for(int i = 0; i <= numAlunos; i++){
        if(alunos[i].nota >= (notaTotal/numAlunos))
            printf("%s", alunos[i].nome);
    }
    return 0;
}