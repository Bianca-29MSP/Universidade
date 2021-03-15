/*
* ENYA LUÍSA GOMES DOS SANTOS
* 19.2.4201
* BCC201 - TURMA32
*/
#include <stdio.h>

typedef struct 
{
    char nome[100];
    double nota;
    int freq;
}Aluno;

void recebeAluno(Aluno aluno[100], int n){
    FILE *arq = fopen("alunos.txt", "w");
    fprintf(arq, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(arq, "%s", aluno[i].nome);
        fprintf(arq, "%.2lf\n", aluno[i].nota);
        fprintf(arq, "%d\n\n", aluno[i].freq);
    }
    fclose(arq);
}


int main()
{
    int n;
    Aluno aluno[100];
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
     for(int i = 0; i < n; i++){
        scanf(" ");
        fgets(aluno[i].nome, 100, stdin);
        scanf("%lf", &aluno[i].nota);
        scanf("%d", &aluno[i].freq);
    }
    recebeAluno(aluno, n);
    return 0;
}