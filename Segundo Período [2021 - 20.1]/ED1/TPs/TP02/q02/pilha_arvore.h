#include "arvore.h"

typedef struct pilhaArvore PilhaArvore;

typedef ArvoreNo *Arvore;

PilhaArvore *pilhaArvoreInicia(int);

int pilhaArvoreEhVazia(PilhaArvore *);

int pilhaArvorePush(PilhaArvore *, Arvore);

Arvore pilhaArvorePop(PilhaArvore *);

int pilhaArvoreTamanho(PilhaArvore *);

Arvore pilhaArvoreTop(PilhaArvore *);

void pilhaArvoreLibera(PilhaArvore **);
