#include "arvoreB.h"

void inicializa(TipoApontador *arv)
{
  *arv = NULL;
}

//imprime em encaminhamento tipo pré-ordem
void imprimeB(TipoApontador arv)
{
  int i = 0;
  if (arv == NULL)
    return;

  while (i <= arv->n)
  {
    imprimeB(arv->p[i]);

    if (i != arv->n)
      printf("%d ", arv->r[i].chave.chave);
    i++;
  }
}

//Retorna 1 caso o item seja encontrado e 0 caso não seja encontrado
int pesquisaB(TipoChave *x, TipoApontador ap, Analise *analise)
{
  long i = 1;
  if (ap == NULL)
  {
    printf("TipoRegistro nao esta presente na arvore\n");
    return 0;
  }

  //verifica qual posição o item está na página
  while (i < ap->n && x->chave > ap->r[i - 1].chave.chave)
  {
    updateComparacoes_pos(analise, 1);
    i++;
  }

  //Verifica se o item em questão é o desejado
  if (x->chave == ap->r[i - 1].chave.chave)
  {
    updateComparacoes_pos(analise, 1);
    *x = ap->r[i - 1].chave;
    return 1;
  }

  //verifica para qual apontador caminhar dentro da árvore para achar o item
  updateComparacoes_pos(analise, 1);
  if (x->chave < ap->r[i - 1].chave.chave)
  {
    return pesquisaB(x, ap->p[i - 1], analise);
  }
  else
    return pesquisaB(x, ap->p[i], analise);
  return 0;
}

//Função inicial para inserir o iteem na página
void insereArvB(TipoRegistro *reg, TipoApontador *ap, Analise *analise)
{

  short cresceu; // Variável para verificar se a árvore subiu nível
  TipoRegistro regRetorno;
  TipoPagina *apRetorno, *apTemp;
  ins(*reg, *ap, &cresceu, &regRetorno, &apRetorno, analise);
  if (cresceu)
  {
    apTemp = (TipoPagina *)malloc(sizeof(TipoPagina));
    apTemp->n = 1;
    apTemp->r[0] = regRetorno;
    apTemp->p[1] = apRetorno;
    apTemp->p[0] = *ap;
    *ap = apTemp;
  }
}

void insereNaPagina(TipoApontador ap, TipoRegistro reg, TipoApontador apDir)
{
  int k;
  int NaoAchouPosicao;

  k = ap->n;
  NaoAchouPosicao = k > 0; //verifica se a página é vazia. Caso seja, apenas insere na pagina (linha 103)
  while (NaoAchouPosicao) //analisa onde colocar o registro dentro da pagina
  {
    if (reg.chave.chave >= ap->r[k - 1].chave.chave) //caso seja maior que o ultimo item, sai do laço e é adicionado na posição seguinte à ultima;
    {
      NaoAchouPosicao = 0;
      break;
    }
    //move o registros para posição da frente para liberar espaço para o novo registro ser inserido de forma ordenada
    ap->r[k] = ap->r[k - 1];
    ap->p[k + 1] = ap->p[k];

    k--;
    if (k < 1)
      NaoAchouPosicao = 0;
  }
  ap->r[k] = reg;
  ap->p[k + 1] = apDir;
  ap->n++;
}


void ins(TipoRegistro reg, TipoApontador ap, short *cresceu, TipoRegistro *regRetorno, TipoApontador *apRetorno, Analise *analise)
{
  long i = 1;
  long j;
  TipoApontador apTemp;

  //Verifica se a pagina é nula. Ou chegou na página folha, ou a árvore é nula; 
  if (ap == NULL)
  {
    *cresceu = 1;
    *regRetorno = reg;
    *apRetorno = NULL;
    return;
  }

  updateComparacoes_pre(analise, 1);
  //Verifica em qual posição a chave desejada está dentro da página (ou entre quais valores a chave está)
  while (i < ap->n && reg.chave.chave > ap->r[i - 1].chave.chave)
  {
    i++;
    updateComparacoes_pre(analise, 1);
  }

  updateComparacoes_pre(analise, 1);

  //Verifica se foi encontrada a chave
  if (reg.chave.chave == ap->r[i - 1].chave.chave)
  {
    *cresceu = False;
    return;
  }

  //Verificação para saber qual dos filhos da página deve ser analisado, esq ou dir.
  updateComparacoes_pre(analise, 1);
  if (reg.chave.chave < ap->r[i - 1].chave.chave)
    i--;
  ins(reg, ap->p[i], cresceu, regRetorno, apRetorno, analise);

  //Controla a continuidade do código para tratar quando é encontrado uma folha
  if (!*cresceu)
    return;

  //Insere na página caso haja espaço
  if (ap->n < MM)
  {
    insereNaPagina(ap, *regRetorno, *apRetorno);
    *cresceu = False;
    return;
  }

  /*Overflow - pagina precisa ser dividida*/
  apTemp = (TipoApontador)malloc(sizeof(TipoPagina));
  apTemp->n = 0;
  apTemp->p[0] = NULL;

  //Verifica se o item será inserido na primeira metade da página; Caso for, insere na nova pagina temporaria
  //o ultimo item da pagina atual e libera 1 espaço para inserção do item na pagina
  if (i < M + 1)
  {
    insereNaPagina(apTemp, ap->r[MM - 1], ap->p[MM]);
    ap->n--;
    insereNaPagina(ap, *regRetorno, *apRetorno);
  }
  else //Caso esteja na segunda metade da pagina, ele é inserido direto na nova pagina temporaria;
    insereNaPagina(apTemp, *regRetorno, *apRetorno);

  //Insere toda o resto da segunda metadee na pagina temporaria
  for (j = M + 2; j <= MM; j++)
    insereNaPagina(apTemp, ap->r[j - 1], ap->p[j]);

  ap->n = M; //Atualiza a quantidade de itens que ficaram na página (depois da transferencia da segunda metade)
  apTemp->p[0] = ap->p[M + 1];
  *regRetorno = ap->r[M];
  *apRetorno = apTemp;
}

int arvoreB(TipoChave *ch, Analise *analise)
{
  iniciaAnalise(analise);
  TipoApontador arv = NULL;
  TipoRegistro itens[QTD_DADOS];
  FILE *arq = fopen("data.bin", "rb");
  if (arq == NULL)
  {
    printf("Erro na abertura do arquivo.\n");
    exit(1);
  }

  iniciaContagemTempo(analise);
  updateTranferencias_pre(analise, 1);
  while (fread(&itens, sizeof(TipoRegistro), QTD_DADOS, arq)) //faz a leitura e transferencia de 15 dados de uma vez para memoria principal
  {
    updateTranferencias_pre(analise, 1);
    for (int i = 0; i < QTD_DADOS; i++)
      insereArvB(&itens[i], &arv, analise); //insere cada um dos dados na árvore em memória principal
  }
  fclose(arq);

  finalizaContagemTempo(analise);
  updateTempo_pre(analise);

  iniciaContagemTempo(analise);

  if (pesquisaB(ch, arv, analise)) //Pesquisa a chave dentro da árvore lida a partir do arquivo;
  {
    finalizaContagemTempo(analise);
    updateTempo_pos(analise);
    liberarArvore(arv);
    return 1;
  }
  else
  {
    finalizaContagemTempo(analise);
    updateTempo_pos(analise);
    liberarArvore(arv);
    return 0;
  }
}

int liberarArvore(TipoApontador ap) // Desaloca a memória alocada para árvore
{
  int i = 0;
  if (ap == NULL)
    return 0;

  while (i <= ap->n)
  {
    liberarArvore(ap->p[i]);
    i++;
  }
  free(ap);
  return 1;
}
