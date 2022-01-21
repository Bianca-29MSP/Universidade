#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "analise.h"

void iniciaAnalise(Analise *analise)
{
  analise->tranferencias_pos = 0;
  analise->comparacoes_pos = 0;

  analise->tranferencias_pre = 0;
  analise->comparacoes_pre = 0;
}

void iniciaContagemTempo(Analise *analise)
{
  analise->iniTempo = clock();
}

void finalizaContagemTempo(Analise *analise)
{
  analise->fimTempo = clock();
}

void updateTranferencias_pos(Analise *analise, int n)
{
  analise->tranferencias_pos += n;
}

void updateTranferencias_pre(Analise *analise, int n)
{
  analise->tranferencias_pre += n;
}

void updateComparacoes_pos(Analise *analise, int n)
{
  analise->comparacoes_pos += n;
}

void updateComparacoes_pre(Analise *analise, int n)
{
  analise->comparacoes_pre += n;
}

void updateTempo_pre(Analise *analise)
{
  //calculando e convertendo tempo total para milissegundos
  analise->tempo_pre = ((double)(analise->fimTempo - analise->iniTempo) * 1000 / CLOCKS_PER_SEC);
}

void updateTempo_pos(Analise *analise)
{
  //calculando e convertendo tempo total para milissegundos
  analise->tempo_pos = ((double)(analise->fimTempo - analise->iniTempo) * 1000 / CLOCKS_PER_SEC);
}

void imprimirDados(Analise *analise)
{
  printf("Dados da execução pré-processamento:\n");
  printf("🕗  - Tempo de execução: %.4lfms\n", analise->tempo_pre);
  printf("💫  - Quantidade de comparação(ões): %d\n", analise->comparacoes_pre);
  printf("🖇️  - Quantidade de transferencia(s): %d\n", analise->tranferencias_pre);

  printf("Dados da execução pós-processamento:\n");
  printf("🕗  - Tempo de execução: %.4lfms\n", analise->tempo_pos);
  printf("💫  - Quantidade de comparação(ões): %d\n", analise->comparacoes_pos);
  printf("🖇️  - Quantidade de transferencia(s): %d\n", analise->tranferencias_pos);
}
