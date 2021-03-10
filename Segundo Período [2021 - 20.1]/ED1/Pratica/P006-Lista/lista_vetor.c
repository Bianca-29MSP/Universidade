#include "lista.h"
#include "stdlib.h"
#include "stdio.h"

#define MAXTAM 100

typedef struct lista_vetor ListaVetor;

struct lista
{
  ListaVetor *prim;
};

struct lista_vetor
{
  int vet[MAXTAM];
  int n; /* número de elementos de fato armazenados */
};

int buscaBinaria(int *array, int begin, int end, int valor) //O(log n)
{
  if (begin <= end)
  {
    int m = (begin + end) / 2;
    if (array[m] == valor)
      return m;
    if (valor < array[m])
      return buscaBinaria(array, begin, m - 1, valor);
    else
      return buscaBinaria(array, m + 1, end, valor);
  }

  return -1;
}

Lista *lst_cria()
{
  Lista *aux = (Lista *)malloc(sizeof(Lista));
  aux->prim = NULL;
  return aux;
}

void lst_imprime(Lista *l)
{
  ListaVetor *aux = l->prim;
  for (int i = 0; i < aux->n; i++)
    printf("%d ", aux->vet[i]);

  printf("\n");
}

int lst_pertence(Lista *l, int valor)
{
  ListaVetor *aux = l->prim;

  if (aux == NULL)
    return 0;

  return buscaBinaria(aux->vet, 0, (aux->n - 1), valor);
}

void lst_organiza(int *array, int begin, int end, int valor)
{
  int valorAux = array[begin];
  int prox;

  for (int i = begin; i < end; i++)
  {
    prox = array[i + 1];
    array[i + 1] = valorAux;
    valorAux = prox;
  }

  array[begin] = valor;
}

int lst_busca_index(int *array, int left, int rigth, int valor)
{
  while (left < rigth)
  {
    if (valor > array[left])
      left += 1;
    else if (valor < array[rigth - 1])
      rigth -= 1;
  }

  return left;
}

void lst_insere_ordenado(Lista *l, int valor)
{
  ListaVetor *aux = l->prim;

  if (aux == NULL)
  {
    aux = (ListaVetor *)malloc(sizeof(ListaVetor));
    l->prim = aux;
    aux->vet[0] = valor;
    aux->n = 1;
    return;
  }

  int index = lst_busca_index(aux->vet, 0, aux->n, valor);

  lst_organiza(aux->vet, index, aux->n, valor);
  aux->n += 1;
}

void lst_retira(Lista *l, int valor)
{
  ListaVetor *aux = l->prim;

  if (aux == NULL)
    return;

  for (int i = 0; i < aux->n; i++)
  {
    if (aux->vet[i] == valor)
    {
      for (int j = i; j < aux->n; j++)
      {
        aux->vet[j] = aux->vet[j + 1];
        aux->vet[j + 1] = -1;
      }
      aux->n -= 1;
      return;
    }
  }
}

void lst_liberar(Lista *l)
{
  ListaVetor *aux = l->prim;
  free(aux);
  free(l);
}
