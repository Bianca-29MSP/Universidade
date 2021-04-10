#include "arvore.h"

typedef struct pilhaArvore PilhaArvore;

typedef ArvoreNo *Chave;

PilhaArvore *PilhaArvore_Inicia(int);

int PilhaArvore_EhVazia(PilhaArvore *);

int PilhaArvore_Push(PilhaArvore *, Chave);

Chave PilhaArvore_Pop(PilhaArvore *);

int PilhaArvore_Tamanho(PilhaArvore *);

Chave PilhaArvore_Top(PilhaArvore *);

void PilhaArvore_Libera(PilhaArvore **);
