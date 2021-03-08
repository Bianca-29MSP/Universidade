#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "players.h"
#include "moves.h"

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2

typedef struct game Game;

Game *createJogo();

void playerPlay(int *jogadaJogador);

int machinePlay();

int checkToWin(Game *game);

void setGamePoints(Game *game, int resultado);

void setGameMoves(Game *game, int player, int machine);

void setGameRounds(Game *game);

void getGamePointsPlayers(Game *game);

int getGameMoveMachine(Game *game);

void checkWinner(Game *game);

void freeGame(Game **game);

void setMoreMoves(Game *game);
