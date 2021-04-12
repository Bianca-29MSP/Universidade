#include "arvore.h"

typedef struct pilhaArvore PilhaArvore;

typedef ArvoreNo *Arvore;

PilhaArvore *PilhaArvore_Inicia(int);

int PilhaArvore_EhVazia(PilhaArvore *);

int PilhaArvore_Push(PilhaArvore *, Arvore);

Arvore PilhaArvore_Pop(PilhaArvore *);

int PilhaArvore_Tamanho(PilhaArvore *);

Arvore PilhaArvore_Top(PilhaArvore *);

void PilhaArvore_Libera(PilhaArvore **);
