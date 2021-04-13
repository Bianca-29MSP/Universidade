#include "pilha.h"
#include "pilha_arvore.h"
#include "arvore.h"

float calculaArvExpressao(char *, int);

ArvoreNo *geraArvoreExpressao(char *);

ArvoreNo *geraSubarvoreExpressao(char *, int, int);

int buscaOperadorPrincipal(char *, int, int);

float calculadoraArvore(ArvoreNo **);

void trataString(char *, int);

int contemEspaco(char *, int);

int ehOperador(char);

int ehOperando(char);