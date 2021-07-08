#include "sequencialIndexado.h"

struct tipoIndice
{
  int posicao;
  int chave;
};

int sequencial_indexado(int qtdItens, TipoItem *item, int situacao, Analise *analise)
{
  FILE *arq;

  int maxTabela = (qtdItens / ITENSPAGINA) + 1;
  TipoIndice *tabela = (TipoIndice *)malloc(maxTabela * sizeof(TipoIndice));
  TipoItem *itens = dados_cria_array(ITENSPAGINA);
  int pos = 0;
  int res = 0;

  if ((arq = fopen("data.bin", "rb")) == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }
  iniciaAnalise(analise);
  iniciaContagemTempo(analise);
  while (fread(itens, sizeof(Dados), ITENSPAGINA, arq))
  {
    tabela[pos].chave = dados_getChave(&itens[0]);
    tabela[pos].posicao = pos + 1;
    pos++;
    updateTranferencias_pre(analise, 1);
  }
  finalizaContagemTempo(analise);
  updateTempo_pre(analise);

  iniciaContagemTempo(analise);
  if (pesquisa_sequencial(tabela, pos, item, arq, situacao, analise))
    res = 1;
  else
    res = 0;
  fclose(arq);
  free(tabela);
  finalizaContagemTempo(analise);
  updateTempo_pos(analise);

  return res;
}

int pesquisa_sequencial(TipoIndice *tab, int tam, TipoItem *item, FILE *arq, int situacao, Analise *analise)
{
  TipoItem *pagina = dados_cria_array(ITENSPAGINA);
  int i = 0, quantitens;
  long desloc;

  if (situacao == 1)
    while (i < tam && tab[i].chave <= dados_getChave(item))
    {
      i++;
      updateComparacoes_pos(analise, 1);
    }
  else if (situacao == 2)
    while (i < tam && tab[i].chave >= dados_getChave(item))
    {
      i++;
      updateComparacoes_pos(analise, 1);
    }

  if (i == 0)
    return 0;
  else
  {
    if (i < tam)
      quantitens = ITENSPAGINA;
    else
    {
      fseek(arq, 0, SEEK_END);
      quantitens = (ftell(arq) / sizeof(TipoItem)) % ITENSPAGINA;
      if (quantitens == 0)
        quantitens = ITENSPAGINA;
    }

    desloc = (tab[i - 1].posicao - 1) * ITENSPAGINA * sizeof(TipoItem);
    fseek(arq, desloc, SEEK_SET);
    fread(pagina, sizeof(TipoItem), quantitens, arq);
    updateTranferencias_pos(analise, 1);

    if (ITENSPAGINA < 25)
    {
      for (i = 0; i < quantitens; i++)
      {
        updateComparacoes_pos(analise, 1);
        if (dados_getChave(&pagina[i]) == dados_getChave(item))
        {
          *item = pagina[i];
          return 1;
        }
      }
    }
    else
    {
      i = buscaBinaria(pagina, 0, quantitens - 1, dados_getChave(item), situacao, analise);
      if (i == -1)
        return 0;
      *item = pagina[i];
      return 1;
    }
  }
  return 0;
}

int buscaBinaria(TipoItem *itens, int ini, int fim, int elemento, int situacao, Analise *analise)
{
  if (situacao == 1)
  {
    int metade = (fim + ini) / 2;
    updateComparacoes_pos(analise, 1);
    if (elemento > itens[fim].chave)
    {

      return -1;
    }
    else if (elemento < itens[ini].chave)
    {
      updateComparacoes_pos(analise, 1);
      return -1;
    }
    else if (elemento == itens[metade].chave)
    {
      updateComparacoes_pos(analise, 2);
      return metade;
    }
    else if (elemento > itens[metade].chave)
    {
      updateComparacoes_pos(analise, 3);
      return buscaBinaria(itens, (metade + 1), fim, elemento, situacao, analise);
    }
    else
    {
      updateComparacoes_pos(analise, 4);
      return buscaBinaria(itens, ini, (metade - 1), elemento, situacao, analise);
    }
  }
  else
  {
    int metade = (fim + ini) / 2;
    updateComparacoes_pos(analise, 1);
    if (elemento < itens[fim].chave)
    {
      return -1;
    }
    else if (elemento > itens[ini].chave)
    {
      updateComparacoes_pos(analise, 1);
      return -1;
    }
    else if (elemento == itens[metade].chave)
    {
      updateComparacoes_pos(analise, 2);
      return metade;
    }
    else if (elemento > itens[metade].chave)
    {
      updateComparacoes_pos(analise, 3);
      return buscaBinaria(itens, ini, (metade - 1), elemento, situacao, analise);
    }
    else
    {
      updateComparacoes_pos(analise, 4);
      return buscaBinaria(itens, (metade + 1), fim, elemento, situacao, analise);
    }
  }
}