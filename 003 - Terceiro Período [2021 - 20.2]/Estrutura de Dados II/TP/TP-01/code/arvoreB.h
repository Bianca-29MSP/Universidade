#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "analise.h"

typedef int bool;
#define True 1;
#define False 0;

#define M 2
#define MM (2 * M)

typedef Dados TipoChave;

typedef struct TipoRegistro
{
  TipoChave chave;
  /* outros componentes */
} TipoRegistro;

typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina
{
  short n;
  TipoRegistro r[MM];      //Chaves
  TipoApontador p[MM + 1]; //Filhos
} TipoPagina;

void inicializa(TipoApontador *arv);

void imprime(TipoApontador arv);

int pesquisaB(TipoChave *x, TipoApontador ap, Analise *analise);

void insereArvB(TipoRegistro *reg, TipoApontador *ap, Analise *analise);

void ins(TipoRegistro reg, TipoApontador ap, short *cresceu, TipoRegistro *regRetorno, TipoApontador *apRetorno, Analise *analise);

void insereNaPagina(TipoApontador ap, TipoRegistro reg, TipoApontador apDir);

int arvoreB(TipoChave *ch, Analise *analise);

int liberarArvore(TipoApontador ap);