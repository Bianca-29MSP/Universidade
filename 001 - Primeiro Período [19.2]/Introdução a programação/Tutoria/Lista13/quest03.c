#include <stdio.h>

int main(){
   int numAlunos;
   char nome[100], matricula[10], endereco[100];
   scanf("%d", &numAlunos);
   FILE *arq = fopen("aluno.txt", "w");
   for(int i = 0; i < numAlunos; i++){
     printf("Nº de alunos %d\n", i+1);
     printf("Nome: ");
     scanf(" ");
     fgets(nome, 100, stdin);
     //scanf(" ");
     printf("Matrícula: ");
     scanf("%s", matricula);
     printf("Endereço: ");
     scanf(" ");
     fgets(endereco, 100, stdin);
     fprintf(arq, "Aluno %d\n", i+1);;
     fprintf(arq, "Nome: %s\n", nome);
     fprintf(arq, "Matrícula: %s\n", matricula);
     fprintf(arq, "Endereço: %s\n", endereco);
     }
   fclose(arq);
   return 0;
}
