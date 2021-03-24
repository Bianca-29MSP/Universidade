/*
* main.c
*
* É uma árvore binária em que, a cada nó, todos os registros com chave menores que 
* a deste nó estão na subárvore da esquerda, enquanto que os registros com chaves maiores 
* estão na subárvore da direita.
*/

#include <stdlib.h>
#include <stdio.h>

#define true 1
#define false -1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux
{
  TIPOCHAVE chave;
  struct aux *esq, *dir;
} NO;

typedef NO *PONT;

PONT inicializa()
{
  return NULL;
}

/* Não há duplicação*/
/*
* Lógica:
* Se a raiz for null, inserimos lá
* Senão:
*   Se a chave do elemento a ser inserido for menos que a da raiz:
*     insere na subárvore da esquerda
*   Senão:
*     insere na subárvore da direita
*/
PONT adiciona(PONT raiz, PONT no)
{
  if (raiz == NULL)
    return no;
  if (no->chave < raiz->chave)
    raiz->esq = adiciona(raiz->esq, no);
  else
    raiz->dir = adiciona(raiz->dir, no);
  /* Ignorando chave igual */
  return raiz;
}

PONT criaNovoNo(TIPOCHAVE ch)
{
  PONT nNo = (PONT)malloc(sizeof(NO));
  nNo->esq = NULL;
  nNo->dir = NULL;
  nNo->chave = ch;
  return nNo;
}

PONT contem(TIPOCHAVE ch, PONT raiz)
{
  if (raiz == NULL)
    return NULL;
  if (raiz->chave == ch)
    return raiz;
  if (raiz->chave > ch)
    return contem(ch, raiz->esq);
  return contem(ch, raiz->dir);
}

/*
* subárvore esquerda - raiz - subárvore direita 
* [inorder traversal, varresuda infixa ou varredura central]
*/
int numeroNos(PONT raiz)
{
  if (!raiz)
    return 0;
  return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

/*
* raiz - subárvore esquerda - subárvore direita
*/
void exibirArvore(PONT raiz)
{
  if (raiz != NULL)
  {
    printf("%i", raiz->chave);
    printf("(");
    exibirArvore(raiz->esq);
    exibirArvore(raiz->dir);
    printf(")");
  }
}

/*
* Busca binária nn recursiva. Devolve o ponteiro do nó buscado.
* Abastace pai com o ponteiro para o nó pai deste
*/
PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT *pai)
{
  PONT atual = raiz;
  *pai = NULL;
  while (atual)
  {
    if (atual->chave == ch)
      return atual;
    *pai = atual;
    if (ch < atual->chave)
      atual = atual->esq;
    else
      atual = atual->dir;
  }
  return NULL;
}

/*
* O nó mais a direita da subárvore da esquerda ou
* O nó mais a esquerda da subárvore da direira
*/
PONT removeNo(TIPOCHAVE ch, PONT raiz)
{
  PONT pai, no, p, q;
  no = buscaNo(raiz, ch, &pai);
  if (no == NULL)
    return raiz;
  if (!no->esq || !no->dir) /* Caso o nó tenha um único filho */
  {
    if (!no->esq)
      q = no->dir;
    else
      q = no->esq;
  }
  else /* Ou ter dois */
  {
    p = no;
    q = no->esq;
    while (q->dir)
    {
      p = q;
      q = q->dir;
    }
    if (p != no) /* Caso do pai substituto ser ou não o nó removido */
    {
      p->dir = q->esq;
      q->esq = no->esq;
    }
    q->dir = no->dir;
  }
  if (!pai) /* Caso o nó removido seja a raiz */
  {
    free(no);
    return q;
  }
  if (ch < pai->chave) /* O nó removido não sendo a raiz */
    pai->esq = q;
  else
    pai->dir = q;
  free(no);
  return raiz;
}

int main()
{
  PONT r = inicializa();
  PONT noA = criaNovoNo(23);
  PONT noB = criaNovoNo(12);
  PONT noC = criaNovoNo(25);
  PONT noD = criaNovoNo(8);
  PONT noE = criaNovoNo(15);

  r = adiciona(r, noA);
  r = adiciona(r, noB);
  r = adiciona(r, noC);
  r = adiciona(r, noD);
  r = adiciona(r, noE);

  PONT p = contem(12, r);
  printf("%i\n", p->chave);

  printf("%d\n", numeroNos(r));

  exibirArvore(r);
  printf("\n");

  removeNo(8, r);

  exibirArvore(r);
  printf("\n");

  return 0;
}