#include <stdio.h>
#include <stdlib.h>
#include "analise.h"

void iniciaAnalise(Analise *analise)
{
  analise->tranferencias = 0;
  analise->comparacoes = 0;
}

void iniciaContagemTempo(Analise *analise)
{
  analise->iniTempo = clock();
}

void finalizaContagemTempo(Analise *analise)
{
  analise->fimTempo = clock();
}

void updateTransferencias(Analise *analise, int n)
{
  analise->tranferencias += n;
}

void updateComparacoes(Analise *analise, int n)
{
  analise->comparacoes += n;
}

void updateTempo(Analise *analise)
{
  //calculando e convertendo tempo total para milissegundos
  analise->tempo = ((double)(analise->fimTempo - analise->iniTempo) * 1000 / CLOCKS_PER_SEC);
}

void imprimirAnalise(Analise *analise)
{
  printf("🕗  - Tempo de execução: %.4lfms\n", analise->tempo);
  printf("💫  - Quantidade de comparação(ões): %d\n", analise->comparacoes);
  printf("🖇️   - Quantidade de transferencia(s): %d\n", analise->tranferencias);
}