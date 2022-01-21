#define VAZIO "!!!!!!!!!\0"
#define N 10 // tamanho da chave (string)
#define M 11

typedef char TChave[N];

typedef struct
{
  /* outros componentes */
  TChave chave;
} TItem;

typedef TItem TDicionario[M];

int hash(TChave, int);

void TDicionario_Inicia(TDicionario);

int TDicionario_Pesquisa(TDicionario dic, TChave chave, int p);

int TDicionario_Insere(TDicionario dic, TItem x, int p);

int TDicionario_Retira(TDicionario dic, TItem *x, int p);

void TDicionario_Imprimir(TDicionario dic);