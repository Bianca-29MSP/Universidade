#include <time.h>
#include "dados.h"
#include "analise.h"
#include "geradorArq.h"
#include "sequencialIndexado.h"
#include "arvBinExterna.h"
#include "arvoreB.h"
#include "arvoreBEstrela.h"

int main(int argc, char *argv[])
{
  Dados item;
  Analise analise;
  char comando[10];
  int metodo;
  int quantidade;
  int situacao;
  int chave;
  int op = 0;

  if (argc < 6)
  {
    printf("❗- Erro: comandos não informados\n");
    exit(1);
  }

  strcpy(comando, argv[1]);
  metodo = atoi(argv[2]);
  quantidade = atoi(argv[3]);
  situacao = atoi(argv[4]);
  chave = atoi(argv[5]);
  if (argc == 7 && strcmp(argv[5], "[-P]"))
    op = 1;

  if (strcmp(comando, "pesquisa"))
  {
    printf("❗- Comando inválido.\n");
    exit(1);
  }

  if (quantidade <= 0)
  {
    printf("❗- Arquivo não possui dados.\n");
    exit(1);
  }

  // Situação
  geradorArq(quantidade, situacao);
  printf("📁 Arquivo gerado!\n");
  dados_setChave(&item, chave);

  //Metodos
  if (metodo == 1) //Acesso sequencial indexado
  {
    if (!sequencial_indexado(quantidade, &item, situacao, &analise))
    {
      printf("❗- Dado não encontrado!!!\n");
      imprimirDados(&analise);
      exit(1);
    }
  }
  else if (metodo == 2)
  {
    if (!arvoreBinariaExterna(&item, &analise, situacao))
    {
      printf("❗- Dado não encontrado!!!\n");
      imprimirDados(&analise);
      exit(1);
    }
  }
  else if (metodo == 3)
  {
    if (!arvoreB(&item, &analise))
    {
      printf("❗- Dado não encontrado!!!\n");
      imprimirDados(&analise);
      exit(1);
    }
  }
  else if (metodo == 4)
  {
    if (!arvoreBEstrela(&item, &analise))
    {
      printf("❗- Dado não encontrado!!!\n");
      imprimirDados(&analise);
      exit(1);
    }
  }
  else
  {
    printf("❗- Metodo invalido.\n");
    exit(1);
  }

  printf("Dado Encontrado!! \n");
  if (op)
    printf("🎉 - [%d] - %ld - %s - %s\n", dados_getChave(&item), dados_getDado1(&item), dados_getDado2(&item), dados_getDado3(&item));

  
  imprimirDados(&analise);
  return 0;
}

