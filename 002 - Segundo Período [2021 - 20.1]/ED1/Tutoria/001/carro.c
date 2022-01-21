#include "carro.h"

struct carro
{
  char modelo[50];
  char cor[50];
  int ano;
  float preco;
  float quilometragem_rodada;
};

Carro **car_create_array(int n)
{
  Carro **aux = (Carro **)malloc(sizeof(Carro) * n);

  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  return aux;
}

Carro *car_create(char *modelo, char *cor, int ano, float preco, float quilometragem_rodada)
{
  Carro *aux = (Carro *)malloc(sizeof(Carro));

  if (aux == NULL)
  {
    printf("Memória insuficiente!\n");
    exit(1);
  }

  stpcpy(aux->modelo, modelo);
  stpcpy(aux->cor, cor);
  aux->ano = ano;
  aux->preco = preco;
  aux->quilometragem_rodada = quilometragem_rodada;
  return aux;
}

void car_destroy(Carro **carro)
{
  free(carro);
}

void car_update(Carro **carro, Carro *attz_carro, char *modelo, char *cor, int ano, int n)
{
  int index = buscar_carro(carro, modelo, cor, ano, n);
  if (index != -1)
  {
    stpcpy(carro[index]->modelo, attz_carro->modelo);
    stpcpy(carro[index]->cor, attz_carro->cor);
    carro[index]->ano = attz_carro->ano;
    carro[index]->preco = attz_carro->preco;
    carro[index]->quilometragem_rodada = attz_carro->quilometragem_rodada;
  }
  else
    printf("Carro não encontrado.\n");
}

int buscar_carro(Carro **carro, char *modelo, char *cor, int ano, int n)
{
  int index = -1;
  for (int i = 0; i < n; i++)
    if (!strcmp(carro[i]->modelo, modelo))
      if (!strcmp(carro[i]->cor, cor))
        if (carro[i]->ano == ano)
        {
          index = i;
          break;
        }

  return index;
}

void mostrar_carro_especifico(Carro **carro, char *modelo, char *cor, int ano, int n)
{
  int index = buscar_carro(carro, modelo, cor, ano, n);
  if (index != -1)
    printf("%s %s %d %.2f %.2f\n", carro[index]->modelo, carro[index]->cor, carro[index]->ano, carro[index]->preco, carro[index]->quilometragem_rodada);
  else
    printf("Carro não encontrado.\n");
}

void get_carros(Carro **carro, int n)
{
  for (int i = 0; i < n; i++)
    printf("%s %s %d %.2f %.2f\n", carro[i]->modelo, carro[i]->cor, carro[i]->ano, carro[i]->preco, carro[i]->quilometragem_rodada);
}

int car_delete(Carro **carro, char *modelo, char *cor, int ano, int n)
{
  int index = buscar_carro(carro, modelo, cor, ano, n);
  if (index != -1)
  {
    for (int i = index; i < n; i++)
    {
      if (carro[i + 1] != NULL)
      {
        carro[i] = carro[i + 1];
        carro[i + 1] = NULL;
      }
    }
    free(carro[n + 1]);
    return 1;
  }
  else
    printf("Carro não encontrado.\n");
  return 0;
}
