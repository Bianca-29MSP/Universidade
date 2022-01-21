#include "carro.h"

int main()
{
  int n;
  Carro **carro;

  char modelo[50];
  char cor[50];
  int ano;
  float preco;
  float quilometragem_rodada;

  scanf("%d", &n); /* Quantidade de carros a ser adicionada */
  carro = car_create_array(n);

  for (int i = 0; i < n; i++)
  {
    scanf("%s %s %d %f %f", modelo, cor, &ano, &preco, &quilometragem_rodada);
    carro[i] = car_create(modelo, cor, ano, preco, quilometragem_rodada);
  }

  char modelo_search[50];
  char cor_search[50];
  int ano_search;

  int op = 0;
  while (op != 1)
  {
    scanf("%d", &op); /*Opção para o menu */
    switch (op)
    {
    case 2: //Listar de carro
      get_carros(carro, n);
      break;

    case 3:                                                                      /*Atualizar o carro */
      scanf("%s %s %d", modelo_search, cor_search, &ano_search);                 /* Dados do carro a procurar */
      scanf("%s %s %d %f %f", modelo, cor, &ano, &preco, &quilometragem_rodada); /* Dados do carro a atualizar */
      Carro *aux = car_create(modelo, cor, ano, preco, quilometragem_rodada);    /* Cria uma variavel auxiliar do tipo Carro com os dados atualizados */
      car_update(carro, aux, modelo_search, cor_search, ano_search, n);
      free(aux);
      break;

    case 4:                                                      /* Buscar carro especifico */
      scanf("%s %s %d", modelo_search, cor_search, &ano_search); /* Dados do carro a procurar */
      mostrar_carro_especifico(carro, modelo_search, cor_search, ano_search, n);
      break;

    case 5:                                                      /* Deleta carro especifico*/
      scanf("%s %s %d", modelo_search, cor_search, &ano_search); /* Dados do carro a procurar */
      if (car_delete(carro, modelo_search, cor_search, ano_search, n))
        n -= 1;
      break;

    default:
      op = 1;
      break;
    }
  }

  car_destroy(carro);

  return 0;
}