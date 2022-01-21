/*
* ENYA LUÍSA GOMES DOS SANTOS
* 19.2.4201
* BCC201 - TURMA 32
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numAlunos;
    double *v1, *v2, *v3;
    printf("Digite o número de alunos: ");
    scanf("%d", &numAlunos);
    v1 = malloc(numAlunos * sizeof(double));
    v2 = malloc(numAlunos * sizeof(double));
    v3 = malloc(numAlunos * sizeof(double));
    printf("Notas 1: ");
    for(int i = 0; i < numAlunos; i++)
        scanf("%lf", &v1[i]);
    printf("Notas 2: ");
    for(int i = 0; i < numAlunos; i++)
        scanf("%lf", &v2[i]);
    for(int i = 0; i < numAlunos; i++)
            v3[i] = ((v1[i] * 4 + v2[i] * 6) / 10);
    for(int i = 0; i < numAlunos; i++)
            printf("%.1lf ", v3[i]);
    printf("\n");
    free(v1);
    free(v2);
    free(v3);
    return 0;
}