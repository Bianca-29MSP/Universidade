#include "pilha.h"
#include "pilha_arvore.h"
#include "arvore.h"

int calculaArvExpressao(char *expressao);

ArvoreNo *geraArvoreExpressao(char *expressao);

ArvoreNo *gereSubarvoreExpressao(char *inf, int ini, int fim);

void trataString(char *expressao, int n);

int contemEspaco(char *expressao, int n);

int operadorPrincipal(char *expressao, int ini, int fim);

int ehOperador(char c);

int ehOperando(char c);

int calculaArvore(ArvoreNo **raiz);