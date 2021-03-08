#include "diretorio.h"

struct diretorio
{
  Arquivo **arquivos;
  char nome[20];
  float tamanho_total;
  int qtd_arquivos;
  int max_arquivos;
};

Diretorio *dir_create_one(char *nome, int max_arquivos)
{
  Diretorio *aux = (Diretorio *)malloc(sizeof(Diretorio));
  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }
  aux->tamanho_total = 0;
  strcpy(aux->nome, nome);
  aux->max_arquivos = max_arquivos;
  aux->arquivos = file_create_array(max_arquivos);
  return aux;
}

float dir_get_size(Diretorio *diretorio)
{
  return diretorio->tamanho_total;
}

char *dir_get_name(Diretorio *diretorio)
{
  return diretorio->nome;
}

void dir_set_name(Diretorio *diretorio, char *nome)
{
  strcpy(diretorio->nome, nome);
}

void dir_free(Diretorio **diretorio)
{
  file_free(&(*diretorio)->arquivos);
  free(*diretorio);
  *diretorio = NULL;
}

void dir_index_files(Diretorio *diretorio)
{
  for (int i = 0; i < diretorio->max_arquivos; i++)
    if (diretorio->arquivos[i] != NULL)
      printf("%s\n", file_get_name(diretorio->arquivos[i]));
}

int dir_rename_file(Diretorio *diretorio, char *current_name, char *new_name)
{
  int result = 0;
  for (int i = 0; i < diretorio->max_arquivos; i++)
    if (diretorio->arquivos[i] != NULL)
    {
      char *filename = file_get_name(diretorio->arquivos[i]);
      if (!strcmp(filename, current_name))
      { // 0 se igual
        result = file_set_name(diretorio->arquivos[i], new_name);
        break;
      }
    }
  return result;
}

void dir_set_new_file(Diretorio *diretorio, char *nome, char *extensao, float tamanho)
{
  Arquivo *aux = file_set_values(nome, extensao, tamanho);
  for (int i = 0; i < diretorio->max_arquivos; i++)
    if (diretorio->arquivos[i] == NULL)
    {
      diretorio->arquivos[i] = aux;
      diretorio->tamanho_total += tamanho;
      break;
    }
}

int dir_destroy_file(Diretorio *diretorio, char *nome)
{
  int result = 0;
  for (int i = 0; i < diretorio->max_arquivos; i++)
    if (diretorio->arquivos[i] != NULL)
    {
      char *filename = file_get_name(diretorio->arquivos[i]);
      if (!strcmp(filename, nome))
      {
        diretorio->tamanho_total -= file_get_size(diretorio->arquivos[i]);
        diretorio->arquivos[i] = NULL;
        result = 1;
        for (int j = i; j < diretorio->max_arquivos; j++)
          if (diretorio->arquivos[j + 1] != NULL)
            file_relloc(diretorio->arquivos[j], diretorio->arquivos[j + 1]);
        break;
      }
    }
  return result;
}
