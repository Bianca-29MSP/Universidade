#include <stdio.h>
#include <stdlib.h>

int quadradoMagico(int **mat, int n);

int liberaMatriz(int **mat, int n);

int main()
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    int **mat = malloc( n * sizeof(int*));
    for(int i = 0; i < n; i++)
        mat[i] =  malloc(n * sizeof(int));
    printf("Digite os valores da matriz n x n: ");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    }
    int resp = quadradoMagico(mat, n);
    if(resp == 1)
        printf("Esta matriz não é um quadro mágico!\n");
    else
        printf("Esta matriz é um quadrado mágico!\n");
    liberaMatriz(mat, n);
    return 0;
}

int quadradoMagico(int **mat, int n)
{
    int *vetLin = malloc(n * sizeof(int));
    int *vetCol= malloc(n * sizeof(int));
    int diagonalP = 0, diagonalS = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = i + 1; k < n; k++)
                for(int l =  j + 1; k < n; k++)
                    if(mat[i][j] == mat[k][l])
                        return 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            vetLin[i] += mat[i][j];
            vetCol[i] += mat[j][i];
            if(i == j)
                diagonalP += mat[i][j];
            if((n - 1) == (i + j))
                diagonalS += mat[i][j];
        }
 
    if(diagonalS != diagonalP)
        return 1;
    
    for(int i = 1; i <= n; i++){
        if(vetLin[i] != vetCol[i])
            return 1;
    }
    
    if((vetCol[0] != diagonalS))
        return 1;
  
    free(vetLin);
    free(vetCol);
    return 0;
}

int liberaMatriz(int **mat, int n)
{
    for(int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}