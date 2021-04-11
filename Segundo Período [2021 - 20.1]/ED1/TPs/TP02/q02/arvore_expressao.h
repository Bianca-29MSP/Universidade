#include "pilha.h"
#include "pilha_arvore.h"
#include "arvore.h"

int calculaArvExpressao(char *, int);

ArvoreNo *geraArvoreExpressao(char *);

ArvoreNo *geraSubarvoreExpressao(char *, int, int);

void trataString(char *, int);

int contemEspaco(char *, int);

int buscaOperadorPrincipal(char *, int, int);

int ehOperador(char);

int ehOperando(char);

int calculadoraArvore(ArvoreNo **);