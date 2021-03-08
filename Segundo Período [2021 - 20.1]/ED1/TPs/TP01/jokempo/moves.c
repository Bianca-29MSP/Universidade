#include <stdio.h>
#include <stdlib.h>
#include "moves.h"

struct moves
{
  int player;
  int machine;
};

Moves **createMoves(int n)
{
  Moves **aux = (Moves **)malloc(sizeof(Moves *) * n);
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }
  for (int i = 0; i < n; i++)
    aux[i] = createMove();

  return aux;
}

Moves *createMove()
{
  Moves *aux = (Moves *)malloc(sizeof(Moves));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }
  return aux;
}

void setMoves(Moves **moves, int player, int machine, int i)
{
  moves[i]->player = player;
  moves[i]->machine = machine;
}

void getMoves(Moves *moves)
{
  printf("%d %d\n", moves->player, moves->machine);
}

int getMovesPlayer(Moves *moves)
{
  return moves->player;
}

int getMovesMachine(Moves *moves)
{
  return moves->machine;
}

Moves **reallocMoves(Moves **moves, int n)
{
  Moves **aux = (Moves **)realloc(moves, (n + 2) * sizeof(Moves *));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }
  return aux;
}

void freeMoves(Moves ***moves)
{
  free(**moves);
  **moves = NULL;
}