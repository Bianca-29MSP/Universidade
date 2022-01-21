#ifndef analise_h
#define analise_h

#include <time.h>

typedef struct
{
  int tranferencias_pre;
  int comparacoes_pre;
  double tempo_pre;

  int tranferencias_pos;
  int comparacoes_pos;
  double tempo_pos;

  clock_t iniTempo, fimTempo;
} Analise;

void iniciaAnalise(Analise *analise);

void iniciaContagemTempo(Analise *analise);

void finalizaContagemTempo(Analise *analise);

void imprimirDados(Analise *analise);

void updateTranferencias_pre(Analise *analise, int n);

void updateComparacoes_pre(Analise *analise, int n);

void updateTempo_pre(Analise *analise);

void updateTranferencias_pos(Analise *analise, int n);

void updateComparacoes_pos(Analise *analise, int n);

void updateTempo_pos(Analise *analise);

#endif