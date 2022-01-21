#include "arvoreBEstrela.h"

//Funções
void InicializaBEstr(TipoApontadorBEstr *ap)
{
  *ap = NULL;
}

int liberarArvoreBEstr(TipoApontadorBEstr ap)
{
  int i = 0;
  if (ap == NULL)
    return 0;

  if (ap->pt == Interna)
  { //Verifico se a página é interna
    while (i <= ap->UU.U0.ni)
    { // Procuro o item mais à esquerda por meio da recursividade
      liberarArvoreBEstr(ap->UU.U0.pi[i]);
      i++;
    }
    free(ap);
  }
  else //Libero as páginas externas
    free(ap);

  return 1;
}

bool arvoreBEstrela(TipoChaveBEstr *chave, Analise *analise)
{
  iniciaAnalise(analise);

  TipoApontadorBEstr ap;
  InicializaBEstr(&ap);
  TipoRegistroBEstr registros[QTD_DADOS];

  FILE *arq = fopen("data.bin", "rb");
  if (arq == NULL)
  {
    printf("❗- Erro na abertura do arquivo");
    exit(1);
  }

  iniciaContagemTempo(analise);

  while (fread(registros, sizeof(TipoRegistroBEstr), QTD_DADOS, arq))
  {
    updateTranferencias_pre(analise, 1);
    for (int i = 0; i < QTD_DADOS; i++)
      InsereBEstr(registros[i], &ap, analise);
  }
  fclose(arq);

  finalizaContagemTempo(analise);
  updateTempo_pre(analise);

  iniciaContagemTempo(analise);

  if (PesquisaBEstr(chave, &ap, analise))
  {
    finalizaContagemTempo(analise);
    updateTempo_pos(analise);
    liberarArvoreBEstr(ap);
    return true;
  }
  else
  {
    finalizaContagemTempo(analise);
    updateTempo_pos(analise);
    liberarArvoreBEstr(ap);
    return false;
  }
}

void ImprimeBEstr(TipoApontadorBEstr ap)
{
  int i = 0;
  if (ap == NULL)
    return;

  if (ap->pt == Interna)
  { //Verificação se a pag é interna
    while (i <= ap->UU.U0.ni)
    {
      ImprimeBEstr(ap->UU.U0.pi[i]); //Chamada recursiva da função
      i++;
    }
  }
  else
  {
    printf("[ ");
    while (i < ap->UU.U1.ne)
    {
      printf("%d ", ap->UU.U1.re[i].chave.chave); //Imprimo os itens da pagina folha
      i++;
    }
    printf("] ");
  }
  return;
}

//Função que cria a raiz ou chama a função de buscar a posição p/ inserir
void InsereBEstr(TipoRegistroBEstr reg, TipoApontadorBEstr *ap, Analise *analise)
{
  short cresceu;
  TipoRegistroBEstr regRetorno;
  TipoPaginaBEstr *apRetorno, *apTemp;

  if (*ap == NULL)
  { //Inserção do primeiro item
    apTemp = (TipoApontadorBEstr)malloc(sizeof(TipoPaginaBEstr));
    apTemp->pt = Externa;
    apTemp->UU.U1.ne = 1;

    apTemp->UU.U1.re[0] = reg;
    *ap = apTemp;
    return;
  }
  else
  { //Busca posição
    InsBEstr(reg, *ap, &cresceu, &regRetorno, &apRetorno, analise);

    if (cresceu)
    { //arvore cresce na altura pela raiz
      apTemp = (TipoApontadorBEstr)malloc(sizeof(TipoPaginaBEstr));
      apTemp->pt = Interna;
      apTemp->UU.U0.ni = 1;

      apTemp->UU.U0.ri[0] = regRetorno.chave;
      apTemp->UU.U0.pi[1] = apRetorno;
      apTemp->UU.U0.pi[0] = *ap;
      *ap = apTemp;
    }
  }
}

//Função que insere na página 
void InsereNaPaginaBEstr(TipoApontadorBEstr ap, TipoRegistroBEstr reg, TipoApontadorBEstr apDir, Analise *analise)
{
  int k;
  short naoAchou;

  if (ap->pt == Interna)
  { //Inserindo registro na página interna
    k = ap->UU.U0.ni;
    naoAchou = k > 0;

    while (naoAchou)
    { //enquanto nao tiver achado a posição
      updateComparacoes_pre(analise, 1);
      if (reg.chave.chave >= ap->UU.U0.ri[k - 1].chave) //se for maior que o último item (k-1), saio e adiciono na próxima posição dps da ultima
      {
        naoAchou = false;
        break;
      }
      ap->UU.U0.ri[k] = ap->UU.U0.ri[k - 1];
      ap->UU.U0.pi[k + 1] = ap->UU.U0.pi[k];
      k--;
      if (k < 1)
        naoAchou = false;
    }
    // achou posição
    ap->UU.U0.ri[k] = reg.chave;
    ap->UU.U0.pi[k + 1] = apDir;
    ap->UU.U0.ni++;
    return;
  }
  else
  { // Externa
    k = ap->UU.U1.ne;
    naoAchou = k > 0;

    while (naoAchou)
    { //enquanto não tiver achado posição
      updateComparacoes_pre(analise, 1);
      if (reg.chave.chave >= ap->UU.U1.re[k - 1].chave.chave) //se for maior que o último item (k-1), saio e adiciono na próxima posição dps da ultima
      {
        naoAchou = false;
        break;
      }

      ap->UU.U1.re[k] = ap->UU.U1.re[k - 1];
      k--;
      if (k < 1)
        naoAchou = false;
    }
    //achou posição
    ap->UU.U1.re[k] = reg;
    ap->UU.U1.ne++;
  }
}

//Função que busca a posição correta para inserir o registro
void InsBEstr(TipoRegistroBEstr reg, TipoApontadorBEstr ap, short *cresceu, TipoRegistroBEstr *regRetorno, TipoApontadorBEstr *apRetorno, Analise *analise)
{
  long i = 1, j;
  TipoApontadorBEstr apTemp;

  if (ap->pt == Interna)
  { //Página interna
    updateComparacoes_pre(analise, 1);
    while (i < ap->UU.U0.ni && reg.chave.chave > ap->UU.U0.ri[i - 1].chave)
    {
      updateComparacoes_pre(analise, 1);
      i++;
    }

    updateComparacoes_pre(analise, 1);
    if (reg.chave.chave == ap->UU.U0.ri[i - 1].chave)
    {
      *cresceu = false;
      return;
    }

    updateComparacoes_pre(analise, 1);
    if (reg.chave.chave < ap->UU.U0.ri[i - 1].chave)
      i--; //Caso a chave buscada seja menor, devo caminhar para a esquerda, caso contrário, para direita

    InsBEstr(reg, ap->UU.U0.pi[i], cresceu, regRetorno, apRetorno, analise);

    if (!*cresceu)
      return;
    if (ap->UU.U0.ni < MMESTRELA)
    { //pagina tem espaco
      InsereNaPaginaBEstr(ap, *regRetorno, *apRetorno, analise);
      *cresceu = false;
      return;
    }

    //overflow: página tem que ser dividida
    apTemp = (TipoApontadorBEstr)malloc(sizeof(TipoPaginaBEstr));
    apTemp->pt = Interna;
    apTemp->UU.U0.ni = 0;
    apTemp->UU.U0.pi[0] = NULL;

    TipoRegistroBEstr rAux;

  
    //Vejo se  devo inserir o item na primeira metade da página, se ele estiver na primeira metade, pego o último item,
    //transfiro pra  página temporária para ter espaço p/ adicionar o novo registro
    if (i < MESTRELA + 1)
    {
      rAux.chave = ap->UU.U0.ri[MMESTRELA - 1];
      InsereNaPaginaBEstr(apTemp, rAux, ap->UU.U0.pi[MMESTRELA], analise);
      ap->UU.U0.ni--;
      InsereNaPaginaBEstr(ap, *regRetorno, *apRetorno, analise);
    }
    else
      InsereNaPaginaBEstr(apTemp, *regRetorno, *apRetorno, analise);

    //Inserindo a segunda metade na temporária
    for (j = MESTRELA + 2; j <= MMESTRELA; j++)
    {
      rAux.chave = ap->UU.U0.ri[j - 1];
      InsereNaPaginaBEstr(apTemp, rAux, ap->UU.U0.pi[j], analise);
    }

    ap->UU.U0.ni = MESTRELA;
    apTemp->UU.U0.pi[0] = ap->UU.U0.pi[MESTRELA + 1];
    regRetorno->chave = ap->UU.U0.ri[MESTRELA];

    *apRetorno = apTemp;
  }
  else
  { // Página externa
    updateComparacoes_pre(analise, 1);
    while (i < ap->UU.U1.ne && reg.chave.chave > ap->UU.U1.re[i - 1].chave.chave)
    {
      updateComparacoes_pre(analise, 1);
      i++;
    }

    updateComparacoes_pre(analise, 1);
    if (reg.chave.chave == ap->UU.U1.re[i - 1].chave.chave)
    {
      *cresceu = false;
      return;
    }

    updateComparacoes_pre(analise, 1);
    if (reg.chave.chave < ap->UU.U1.re[i - 1].chave.chave)
      i--;

    if (ap->UU.U1.ne < MM2)
    { //pagina tem espaco
      *regRetorno = reg;
      InsereNaPaginaBEstr(ap, *regRetorno, *apRetorno, analise);
      *cresceu = false;
      return;
    }

    //overflow: página tem que ser dividida
    apTemp = (TipoApontadorBEstr)malloc(sizeof(TipoPaginaBEstr));
    apTemp->pt = Externa;
    apTemp->UU.U1.ne = 0;

    *apRetorno = NULL;
    *regRetorno = reg;

    //Vejo se  devo inserir o item na primeira metade da página, se ele estiver na primeira metade, pego o último item,
    //transfiro pra  página temporária para ter espaço p/ adicionar o novo registro
    if (i < MESTRELA + 1)
    {
      InsereNaPaginaBEstr(apTemp, ap->UU.U1.re[MM2 - 1], ap->UU.U0.pi[MMESTRELA], analise);
      ap->UU.U1.ne--;
      InsereNaPaginaBEstr(ap, *regRetorno, *apRetorno, analise);
    }
    else
      InsereNaPaginaBEstr(apTemp, *regRetorno, *apRetorno, analise);

    //Movendo as chaves
    for (j = 1; j <= MESTRELA; j++)
      InsereNaPaginaBEstr(apTemp, ap->UU.U1.re[MM2 - j], *apRetorno, analise);

    *cresceu = true;
    ap->UU.U1.ne = MESTRELA + 1;
    *regRetorno = ap->UU.U1.re[MESTRELA + 1];

    *apRetorno = apTemp;
  }
}

//Retorna true caso a chave tenha sido encontrada e false caso não
bool PesquisaBEstr(TipoChaveBEstr *x, TipoApontadorBEstr *ap, Analise *analise)
{
  int i;
  TipoApontadorBEstr pag;
  pag = *ap;
  // Caminhando na página Interna
  if ((*ap)->pt == Interna)
  {
    i = 1;
    //Caminhando dentro da página interna
    updateComparacoes_pos(analise, 1);
    while (i < pag->UU.U0.ni && x->chave > pag->UU.U0.ri[i - 1].chave)
    {
      updateComparacoes_pos(analise, 1);
      i++;
    }
    // Pesquisa recursiva até encontrar uma página externa, caminho para a esquerda ou direita na árvore
    updateComparacoes_pos(analise, 1);
    if (x->chave < pag->UU.U0.ri[i - 1].chave)
      return PesquisaBEstr(x, &pag->UU.U0.pi[i - 1], analise);
    else
      return PesquisaBEstr(x, &pag->UU.U0.pi[i], analise);
  }
  //Pesquisa na página externa (folha)
  i = 1;
  updateComparacoes_pos(analise, 1);
  while (i < pag->UU.U1.ne && x->chave > pag->UU.U1.re[i - 1].chave.chave)
  {
    i++;
    updateComparacoes_pos(analise, 1);
  }
  updateComparacoes_pos(analise, 1);
  if (x->chave == pag->UU.U1.re[i - 1].chave.chave)
  {                                  //Verifico se a chave foi encontrada ou não
    *x = pag->UU.U1.re[i - 1].chave; //Passo o registro da chave para que eu possa retorná-lo
    return true;
  }
  else
    return false;
}
