
#include "diretorio.h"

int main()
{
  int n;
  char filename[50];
  char extensao[10];
  float file_size;

  char current_name[50];
  char new_name[20];

  Diretorio *diretorio;

  int dir_max_arquivos;
  char dir_nome[20];

  scanf("%s %d", dir_nome, &dir_max_arquivos);
  diretorio = dir_create_one(dir_nome, dir_max_arquivos);

  int op = 0;
  int count = 0;

  while (op != 10)
  {
    scanf("%d", &op);
    switch (op)
    {
    case 2: //Liberar memoria do diretório e seus arquivos.
      dir_free(&diretorio);
      count = 1;
      break;

    case 3: //Adicionar novo(s) arquivo(s)
      scanf("%d", &n);
      for (int i = 0; i < n; i++)
      {
        scanf("%s %s %f", filename, extensao, &file_size);
        dir_set_new_file(diretorio, filename, extensao, file_size);
      }
      break;

    case 4: //Remover arquivo
      scanf("%s", current_name);
      printf("%d\n", dir_destroy_file(diretorio, current_name));
      break;

    case 5: //Ler tamanho do diretório
      printf("%f\n", dir_get_size(diretorio));
      break;

    case 6: //Ler nome do diretório
      printf("%s\n", dir_get_name(diretorio));
      break;

    case 7: //Renomear diretorio
      scanf("%s", new_name);
      dir_set_name(diretorio, new_name);
      break;

    case 8: //Renomear um arquivo
      scanf("%s %s", current_name, new_name);
      printf("%d\n", dir_rename_file(diretorio, current_name, new_name));
      break;

    case 9: //Listar os nomes de todos os arquivos do diretório
      dir_index_files(diretorio);
      break;

    default: //Sair
      op = 10;
    }
  }
  if (!count) //Garante que a memória será liberada ao final do programa
    dir_free(&diretorio);

  //printf("%p\n", diretorio);

  return 0;
}
