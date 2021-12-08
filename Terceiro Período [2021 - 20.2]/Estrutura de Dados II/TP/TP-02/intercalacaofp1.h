#ifndef INTERCALACAOFP1_H
#define INTERCALACAOFP1_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "analise.h"
#include "heap.h"

#define FITASIN 19

typedef enum _tape Tape;

const char *balanceadafp1caminhos(const char *filename, int qtd, Analise *primeiraFase, Analise *segundaFase);
void criablocosOrdenadosfp1(TipoHeap *heap, const char *filename, int qtd, const char **filesIn, int *nBlocos, Analise *analise);
void insereDadofp1(TipoHeap *heap, TipoChave dado, const char **filesIn, int *fita, int *nBlocos, Analise *analise);
void intercalafp1(TipoHeap *heap, FILE **arqsIn, const char *fileOut, int *nBlocos, int *fita, Analise *analise);
void transfOutToIn(const char **filesIn, FILE *arqOut, int *nBlocos, int *fita, Analise *analise);

#endif