#include <stdio.h>
#include <stdlib.h>

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q);

int liberaMatriz(int **mat, int n);

int main()
{
    int n, m;
    int p, q;
    int **R;
    printf("Digite os tamanhos de matriz A: ");
    scanf("%d %d", &n, &m);
    int **A = malloc( n * sizeof(int*));
    for(int i = 0; i < n; i++)
        A[i] =  malloc(m * sizeof(int));
    printf("Digite os dados da matriz A: ");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    printf("Digite os tamanhos de matriz B: ");
    scanf("%d %d", &p, &q);
    int **B = malloc( p * sizeof(int*));
    for(int i = 0; i < p; i++)
        B[i] =  malloc(q * sizeof(int));

    printf("Digite os dados da matriz B: ");
    for(int i = 0; i < p; i++)
        for(int j = 0; j < q; j++)
            scanf("%d", &B[i][j]);

    int verif = multiplicaMatrizes(&R, A, n, m, B, p, q);
    if(verif == 0)
        printf("Não é possivel multiplicar as matrizes A x B.\n");
    else{
        printf("Resultado de A x B\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < q; j++)
                printf("%d ",R[i][j]);
            printf("\n");
        }
        liberaMatriz(R, n);
    }
    liberaMatriz(A, n);
    liberaMatriz(B, p);
    return 0;
}

int multiplicaMatrizes(int *** R, int ** A, int n, int m, int ** B, int p, int q)
{
    if(m != p)
        return 0;
    else{
        *R = malloc( n * sizeof(int*));
        for(int i = 0; i < n; i++)
            (*R)[i] =  malloc(q * sizeof(int));

        int soma = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < q; j++){
            for(int k = 0; k < p; k++){
                soma += A[i][k] * B[k][j];
            }
            (*R)[i][j]  = soma;
            soma = 0;
            }
        }
        return 1;
    }
    return 0;
}

int liberaMatriz(int **mat, int n)
{
    for(int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}
