#ifndef sequenciaIndexado_h
#define sequenciaIndexado_h
#include "dados.h"
#include "analise.h"

#define ITENSPAGINA 26

typedef Dados TipoItem;

typedef struct tipoIndice TipoIndice;

int pesquisa_sequencial(TipoIndice *tab, int tam, TipoItem *item, FILE *arq, int situacao, Analise *analise);

int buscaBinaria(TipoItem *itens, int ini, int fim, int elemento, int situacao, Analise *analise);

int sequencial_indexado(int qtdItens, TipoItem *item, int situacao, Analise *analise);

#endif