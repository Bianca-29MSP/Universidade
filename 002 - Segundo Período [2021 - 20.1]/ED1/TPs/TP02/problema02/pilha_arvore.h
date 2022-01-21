/*
* pilha_arvore.h
* Trabalho pratico 2 de EDI (BCC202) - Árvore de expressão   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/
#include "arvore.h"

typedef struct pilhaArvore PilhaArvore;

typedef ArvoreNo *Arvore;

/*
* PILHA DINÂMICA
* Funções básicas de uma estrutura de pilha de endereço do nó da árvore
*/
PilhaArvore *pilhaArvoreInicia();

int pilhaArvoreEhVazia(PilhaArvore *);

int pilhaArvorePush(PilhaArvore *, Arvore);

Arvore pilhaArvorePop(PilhaArvore *);

int pilhaArvoreTamanho(PilhaArvore *);

void pilhaArvoreUnstack(PilhaArvore **);
