#include <stdio.h>

struct Endereco{
    char rua[100];
    char bairro[100];
    int numero;
};

struct Aluno{
    char nome[100];
    char matricula[20];
    char curso[50];
    struct Endereco end;
};

struct UFOP{
    struct Aluno alunos[100];
};

int main()
{
    struct UFOP aluno;
    int numAlunos;
    scanf("%d", &numAlunos);
    for(int i = 0; i < numAlunos; i++){
        printf("Aluno %d\n", i + 1);
        printf("Nome: ");
        scanf(" ");
        fgets(aluno.alunos[i].nome, 101, stdin);
        printf("Matrícula: ");
        scanf(" ");
        scanf("%s", aluno.alunos[i].matricula);
        printf("Curso: ");
        scanf(" ");
        scanf("%s", aluno.alunos[i].curso);
        printf("Rua: ");
        scanf(" ");
        fgets(aluno.alunos[i].end.rua, 101, stdin);
        printf("Bairro: ");
        scanf(" ");
        fgets(aluno.alunos[i].end.bairro, 101, stdin);
        printf("Número: ");
        scanf("%d", &aluno.alunos[i].end.numero);
    }
     for(int i = 0; i < numAlunos; i++){
        printf("\n");
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s", aluno.alunos[i].nome);
        printf("Matrícula: %s\n", aluno.alunos[i].matricula);
        printf("Curso: %s\n", aluno.alunos[i].curso);
        printf("Rua: %s", aluno.alunos[i].end.rua);
        printf("Bairro: %s", aluno.alunos[i].end.bairro);
        printf("Número: %d\n", aluno.alunos[i].end.numero);
    }
    return 0;
}