#include "pilha.h"

typedef int Chave;
typedef char Elemento;

typedef struct arvoreNo ArvoreNo;

/*==================================================================================*/
/* ARVORE INICIALIZA - FUNCAO RESPONSAVEL POR INICIALIZAR UMA ARVORE                */
/* IN = NONE                                                             OUT = VOID */
/*==================================================================================*/
ArvoreNo *arvoreInicializa();

ArvoreNo *arvoreAdicionaNo(ArvoreNo *, ArvoreNo *);

ArvoreNo *arvoreCriaNovoNo(Elemento, Chave);

void arvorePrintSimples(ArvoreNo *);

void arvorePosOrdem(ArvoreNo *, Pilha *);

void arvoreLibera(ArvoreNo **);

int arvoreEhVazia(ArvoreNo *);

int arvoreNumeroNos(ArvoreNo *);

void arvorePrintGrafico(ArvoreNo *);

void arvorePrintGraficoArquivo(ArvoreNo *, FILE *);
