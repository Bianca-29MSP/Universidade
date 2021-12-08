#ifndef QUICKSORTEEXTERNO_H
#define QUICKSORTEEXTERNO_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include "dado.h"
#include "analise.h"

#define N_AREA 10

#define FALSE 0
#define TRUE 1

typedef TipoDado TipoChave;

typedef TipoChave TipoArea;


void ordenacaoQuickSortExterno(int quantidade, Analise* analise);
void binToTxt(FILE* arqBin);
void TxtToBin(char* filename, int quantidade);

void quicksortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir, Analise *analise);

void leSup(FILE **arqLEs, TipoChave *ultLido, int *ls, short *ondeLer, Analise *analise);
void leInf(FILE **arqLi, TipoChave *ultLido, int *li, short *ondeLer, Analise *analise);
void inserirArea(TipoArea *area, TipoChave *ultLido, int *nrArea, Analise *analise);
void escreverMax(FILE **arqLEs, TipoChave r, int *es, Analise *analise);
void escreverMin(FILE **arqEi, TipoChave r, int *ei, Analise *analise);
void retiraMax(TipoArea *area, TipoChave *r, int *nrArea, Analise *analise);
void retiraMin(TipoArea *area, TipoChave *r, int *nrArea, Analise *analise);

void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, TipoArea *area, int esq, int dir, int *i, int *j, Analise *analise);

void faVazia(TipoArea *area, Analise *analise);
int obterNumCelOcupadas(TipoArea *area, Analise *analise);
void retiraUltimo(TipoArea *area, TipoChave *r, Analise *analise);
void retiraPrimeiro(TipoArea *area, TipoChave *r, Analise *analise);
void insereItem(TipoChave ultLido, TipoArea *area, Analise *analise);

#endif