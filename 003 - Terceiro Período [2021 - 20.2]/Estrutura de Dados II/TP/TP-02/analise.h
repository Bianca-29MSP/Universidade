#ifndef analise_h
#define analise_h

#include <time.h>

typedef struct
{
  int tranferencias;
  int comparacoes;
  double tempo;

  clock_t iniTempo, fimTempo;
} Analise;

void iniciaAnalise(Analise *analise);

void iniciaContagemTempo(Analise *analise);

void finalizaContagemTempo(Analise *analise);

void imprimirAnalise(Analise *analise);

void updateTransferencias(Analise *analise, int n);

void updateComparacoes(Analise *analise, int n);

void updateTempo(Analise *analise);

#endif