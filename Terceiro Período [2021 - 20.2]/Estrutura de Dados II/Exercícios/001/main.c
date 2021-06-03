#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

int qtd_linhas_arquivo(char *namefile);

void le_arq_alunos(Aluno **alunos);

void cria_arq_conceito_txt(Aluno **alunos, int n);

void cria_arq_alunos_bin(Aluno **alunos, int n);

void le_arq_alunos_bin(Aluno **alunos, int n);

int main()
{
  Aluno **alunos;
  int qtd_alunos = qtd_linhas_arquivo("alunos.txt");
  alunos = aluno_cria_array(qtd_alunos);
  le_arq_alunos(alunos);
  cria_arq_conceito_txt(alunos, qtd_alunos);

  cria_arq_alunos_bin(alunos, qtd_alunos);

  Aluno **alunos_bin = aluno_cria_array(qtd_alunos);
  le_arq_alunos_bin(alunos_bin, qtd_alunos);
  for (int i = 0; i < qtd_alunos; i++)
  {
    printf("%d %s %d\n", aluno_get_matricula(alunos_bin[i]), aluno_get_nome(alunos_bin[i]), aluno_get_faltas(alunos_bin[i]));
  }
  //cria_arq_conceito_txt(alunos_bin, qtd_alunos);
  return 0;
}

int qtd_linhas_arquivo(char *namefile)
{
  FILE *arq = fopen(namefile, "r");
  if (arq == NULL)
  {
    printf("Arquivo não pode ser aberto.\n");
    exit(1);
  }
  int linhas = 0;
  char aux[60];

  while (fgets(aux, 60, arq) != NULL)
    linhas += 1;

  fclose(arq);
  return linhas;
}

void le_arq_alunos(Aluno **alunos)
{
  int matricula;
  char nome[30];
  float notas[3];
  int faltas;

  FILE *arq = fopen("alunos.txt", "r");
  if (arq == NULL)
  {
    printf("Arquivo não pode ser aberto.\n");
    exit(1);
  }

  for (int i = 0;
       fscanf(arq, "%d %[A-Z a-z ã ç] %f %f %f %d",
              &matricula, nome, &notas[0], &notas[1], &notas[2], &faltas) != EOF;
       i++)
  {
    aluno_set_matricula(alunos[i], matricula);
    aluno_set_nome(alunos[i], nome);
    aluno_set_notas(alunos[i], notas);
    aluno_set_faltas(alunos[i], faltas);
  }
  fclose(arq);
}

void cria_arq_conceito_txt(Aluno **alunos, int n)
{

  FILE *arq = fopen("conceitos.txt", "w");
  int matricula;
  char nome[30];
  char conceito;

  for (int i = 0; i < n; i++)
  {
    matricula = aluno_get_matricula(alunos[i]);
    strcpy(nome, aluno_get_nome(alunos[i]));
    conceito = aluno_get_conceito(alunos[i]);

    fprintf(arq, "%d %s  %c\n", matricula, nome, conceito);
  }

  fclose(arq);
}

void cria_arq_alunos_bin(Aluno **alunos, int n)
{
  FILE *arq = fopen("alunos.bin", "wb");

  fwrite(alunos, sizeof(alunos), 1, arq);

  fclose(arq);
}

void le_arq_alunos_bin(Aluno **alunos, int n)
{
  FILE *arq = fopen("alunos.bin", "rb");

  fread(alunos, sizeof(alunos), 1, arq);

  fclose(arq);
}
