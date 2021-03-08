#include <stdio.h>
#include <stdlib.h>
#include "players.h"

struct players
{
  int points;
};

Players **createPlayers(int n)
{
  Players **aux = (Players **)malloc(n * sizeof(Players *));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }
  for (int i = 0; i < n; i++)
    aux[i] = createPlayer();
  return aux;
}

Players *createPlayer()
{
  Players *aux = (Players *)malloc(sizeof(Players));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }

  return aux;
}

int getPointsPlayer(Players *player)
{
  return player->points;
}

void setPointsPlayer(Players *players, int n)
{
  players->points = n;
}

void freePlayers(Players ***players)
{
  free(**players);
  **players = NULL;
}
