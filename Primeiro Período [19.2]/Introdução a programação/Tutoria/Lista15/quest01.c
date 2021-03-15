#include <stdio.h>
#include <stdlib.h>

void desaloca(int **mat, int l)
{      
    for(int i = 0; i < l; i++)
            free(mat[i]);
    free(mat);
}

int main()
{
    int lin, col;
    printf("Dimensões: ");
    scanf("%d %d", &lin, &col);
    int **mat1 = malloc(lin * sizeof(int*));
    int **mat2 = malloc(lin * sizeof(int*));
    int **soma = malloc(lin * sizeof(int*));

    for(int i = 0; i < lin; i++){
        mat1[i] = malloc(col * sizeof(int));
        mat2[i] = malloc(col * sizeof(int));
        soma[i] = malloc(col * sizeof(int));
    }

    printf("Matriz 1: ");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Matriz 2: ");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &mat2[i][j]);
        }
    }

    printf("Matriz resultante: ");
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            soma[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ", soma[i][j]);
        }
        printf("\n");
    }

    desaloca(mat1, lin);
    desaloca(mat2, lin);
    desaloca(soma, lin);

    return 0;
}

