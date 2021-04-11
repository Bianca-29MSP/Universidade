#include "pilha.h"

#define true 1
#define false 0

// typedef int bool;
typedef char TIPOCHAVE;

typedef struct arvoreNo ArvoreNo;

/*==================================================================================*/
/* ARVORE INICIALIZA - FUNCAO RESPONSAVEL POR INICIALIZAR UMA ARVORE                */
/* IN = NONE                                                             OUT = VOID */
/*==================================================================================*/
ArvoreNo *inicializa();

ArvoreNo *adiciona(ArvoreNo *raiz, ArvoreNo *no);

ArvoreNo *criaNovoNo(TIPOCHAVE ch, int prioridade);

void exibirArvore(ArvoreNo *raiz);

void pos_ordem(ArvoreNo *raiz, Pilha *pilha);

int numeroNos(ArvoreNo *raiz);

TIPOCHAVE exibiRaiz(ArvoreNo *raiz);

void arv_libera(ArvoreNo **a);

int arv_vazia(ArvoreNo *a);

void exibirArvore2(ArvoreNo *raiz);
