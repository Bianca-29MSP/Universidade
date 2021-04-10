#include <stdio.h>
#include <stdlib.h>

#include "insertionSort.h"
#include "aluno.h"

typedef Aluno *TIPOITEM;

void imprimeResultado(TIPOITEM *mat, int n);

int main()
{
  int t, n;
  scanf("%d", &t);
  int matricula;
  double prova, trabPratico, media;

  for (int i = 0; i < t; i++)
  {
    scanf("%d", &n);
    TIPOITEM *vet = aluno_AlocaVetor(n);

    for (int j = 0; j < n; j++)
    {
      scanf("%d", &matricula);
      scanf("%lf", &prova);
      scanf("%lf", &trabPratico);

      aluno_setMatricula(vet[j], matricula);
      aluno_setProva(vet[j], prova);
      aluno_setTrabPratico(vet[j], trabPratico);
      media = aluno_CalculaMedia(vet[j], 0.7, 0.3);
      aluno_setMedia(vet[j], media);
    }

    insertionSort(vet, n);

    imprimeResultado(vet, n);
    aluno_Libera(&vet, n);
    printf("\n");
  }

  return 0;
}

void imprimeResultado(TIPOITEM *vet, int n)
{
  printf("\n");
  for (int i = 0; i < n; i++)
    printf("%d %.2lf\n", aluno_getMatricula(vet[i]), aluno_getMedia(vet[i]));
  printf("\n");
}