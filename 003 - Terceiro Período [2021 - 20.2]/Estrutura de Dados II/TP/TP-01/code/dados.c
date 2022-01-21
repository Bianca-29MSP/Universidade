#include "dados.h"

// struct dados
// {
//   int chave;
//   long int dado1;
//   char dado2[500];
//   char dado3[3000];
// };

Dados *dados_cria_array(int n)
{
  Dados *aux = (Dados *)malloc(n * sizeof(Dados));

  if (aux == NULL)
  {
    printf("Não há mamória suficiente.\n");
    exit(1);
  }

  // for (int i = 0; i < n; i++)
  //   aux[i] = dados_cria();
  return aux;
}

void dados_setChave(Dados *d, int ch)
{
  d->chave = ch;
}

void dados_setDado1(Dados *d, long int dt)
{
  d->dado1 = dt;
}

void dados_setDado2(Dados *d, char *str)
{
  strcpy(d->dado2, str);
}

void dados_setDado3(Dados *d, char *str)
{
  strcpy(d->dado3, str);
}

int dados_getChave(Dados *d)
{
  return d->chave;
}

long int dados_getDado1(Dados *d)
{
  return d->dado1;
}

char *dados_getDado2(Dados *d)
{
  return d->dado2;
}

char *dados_getDado3(Dados *d)
{
  return d->dado3;
}
