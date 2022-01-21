/*
* arvore.h
* Trabalho pratico 2 de EDI (BCC202) - Árvore de expressão   
* Enya Luísa Gomes dos Santos - 19.2.4201                          17/04/2021            
*/
#include "pilha.h"

typedef int TChave;
typedef char TElemento;

typedef struct arvoreNo ArvoreNo;

/*
* ÁRVORE BINÁRIA
* Funções básicas de uma estrutura de árvore binária
*/
ArvoreNo *arvoreInicializa();

ArvoreNo *arvoreAdicionaNo(ArvoreNo *, ArvoreNo *);

ArvoreNo *arvoreCriaNovoNo(TElemento, TChave);

void arvorePrintSimples(ArvoreNo *);

void arvoreLibera(ArvoreNo **);

int arvoreEhVazia(ArvoreNo *);

int arvoreNumeroNos(ArvoreNo *);

void arvorePrintGrafico(ArvoreNo *);

void arvorePrintGraficoArquivo(ArvoreNo *, FILE *);

/*
*FUNÇÃO: calculadoraPosOrdem
*OBJETIVO: Realizar o caminho pós-ordem da pilha e para cada elemento chamar
            a função constroiPilhaPosFixada(Pilha *, char), para dessa forma,
            calcular a árvore.
*IN: Ponteiro para uma árvore e ponteiro para uma pilha.                        
*OUT: void
*/
void arvorePosOrdem(ArvoreNo *, Pilha *);
