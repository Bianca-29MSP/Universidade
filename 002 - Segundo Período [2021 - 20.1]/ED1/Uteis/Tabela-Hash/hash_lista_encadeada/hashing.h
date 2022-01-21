#define N 16 // tamanho da chave (string)
#include "lista.h"

typedef char TChave[N];

typedef struct
{
  TChave chave;
} TItem;

typedef struct
{
  int n;          // numero de itens na hash
  int nro_listas; // tamanho do array de listas
  int nro_pesos;  // tamanho do array de pesos
  int *p;         // array de pesos
  TLista *v;      // array de listas
} THash;

void THash_Inicia(THash *hash, int nro_listas, int nro_pesos);
int THash_H(THash *hash, TChave chave);
int THash_Pesquisa(THash *hash, TChave chave, TItem *x);
TCelula *THash_PesquisaCelula(THash *hash, TChave chave);
int THash_Insere(THash *hash, TItem x);
int THash_Remove(THash *hash, TItem *x);