/*
* ENYA LUÍSA GOMES DOS SANTOS
* 19.2.4201
*/

#include <stdio.h>
#include <stdlib.h>

#define ITENSPAGINA 8
#define QTDITENS 1000

typedef struct
{
  int chave;
  long int preco;
  char titulo[10];
} tipoItem;

typedef struct
{
  int posicao;
  int chave;
} tipoIndice;

int pesquisa(tipoIndice tab[], int tam, tipoItem *item, FILE *arq);

int main()
{
  tipoItem item;
  FILE *arqAux = fopen("arqSequencial.txt", "r");
  FILE *arq = fopen("arqSequencial.bin", "wb");
  if (arqAux == NULL || arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  while (fscanf(arqAux, "%d %ld %[A-Z a-z]", &item.chave, &item.preco, item.titulo) != EOF)
    fwrite(&item, sizeof(item), 1, arq);

  fclose(arqAux);
  fclose(arq);

  int maxTabela = QTDITENS / ITENSPAGINA;
  tipoIndice tabela[maxTabela];
  tipoItem itens[ITENSPAGINA];
  int pos = 0;

  if ((arq = fopen("arqSequencial.bin", "rb")) == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  while (fread(&itens, sizeof(tipoItem), ITENSPAGINA, arq) == ITENSPAGINA)
  {
    tabela[pos].chave = itens[0].chave;
    tabela[pos].posicao = pos + 1;
    pos++;
  }

  printf("Código do item desejado: ");
  scanf("%d", &item.chave);

  if (pesquisa(tabela, pos, &item, arq))
    printf("Item [%d] - %s - R$ %ld.00 foi localizado.\n", item.chave, item.titulo, item.preco);
  else
    printf("Item de código %d nao foi localizado.\n", item.chave);

  fclose(arq);

  return 0;
}

int pesquisa(tipoIndice tab[], int tam, tipoItem *item, FILE *arq)
{
  tipoItem pagina[ITENSPAGINA];
  int i = 0, quantitens;
  long desloc;

  while (i < tam && tab[i].chave <= item->chave)
    i++;

  if (i == 0)
    return 0;
  else
  {
    if (i < tam)
      quantitens = ITENSPAGINA;
    else
    {
      fseek(arq, 0, SEEK_END);
      quantitens = (ftell(arq) / sizeof(tipoItem)) % ITENSPAGINA;
      if (quantitens == 0)
        quantitens = ITENSPAGINA;
    }

    desloc = (tab[i - 1].posicao - 1) * ITENSPAGINA * sizeof(tipoItem);
    fseek(arq, desloc, SEEK_SET);
    fread(&pagina, sizeof(tipoItem), quantitens, arq);

    for (i = 0; i < quantitens; i++)
    {
      if (pagina[i].chave == item->chave)
      {
        *item = pagina[i];
        return 1;
      }
    }
    return 0;
  }
}