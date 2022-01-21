#include "jokempo.h"

struct game
{
  Players **players;
  Moves **moves;
  int rounds;
};

Game *createJogo()
{
  Game *aux = (Game *)malloc(sizeof(Game));
  if (aux == NULL)
  {
    printf("Memória insuficiente.\n");
    exit(1);
  }
  aux->rounds = 0;
  aux->players = createPlayers(2);
  setPointsPlayer(aux->players[0], 0);
  setPointsPlayer(aux->players[1], 0);
  aux->moves = createMoves(5);
  return aux;
}

void setGameRounds(Game *game)
{
  game->rounds += 1;
}

void playerPlay(int *jogadaJogador)
{
  do
  {
    scanf("%d", jogadaJogador);
  } while (*jogadaJogador < 0 || *jogadaJogador > 2);
}

int machinePlay()
{
  return rand() % 3;
}

void setGamePoints(Game *game, int resultado)
{
  if (resultado == 1)
    setPointsPlayer(game->players[0], getPointsPlayer(game->players[0]) + 1);
  else if (resultado == -1)
    setPointsPlayer(game->players[1], getPointsPlayer(game->players[1]) + 1);
}

void setGameMoves(Game *game, int player, int machine)
{
  setMoves(game->moves, player, machine, game->rounds);
}

void getGamePointsPlayers(Game *game)
{
  int j = getPointsPlayer(game->players[0]);
  int c = getPointsPlayer(game->players[1]);
  printf("%d %d\n", j, c);
}

int getGameMoveMachine(Game *game)
{
  return getMovesMachine(game->moves[game->rounds]);
}

int checkToWin(Game *game)
{
  // 0 para pedra, 1 para papel ou 2 para tesoura
  // 0 para empate, 1 caso o usuário tenha vencido ou −1 caso o usuário tenha perdido
  if (getMovesPlayer(game->moves[game->rounds]) == PEDRA)
  {
    if (getMovesMachine(game->moves[game->rounds]) == TESOURA)
      return 1;
    else if (getMovesMachine(game->moves[game->rounds]) == PAPEL)
      return -1;
    else
      return 0;
  }

  else if (getMovesPlayer(game->moves[game->rounds]) == PAPEL)
  {
    if (getMovesMachine(game->moves[game->rounds]) == PEDRA)
      return 1;
    else if (getMovesMachine(game->moves[game->rounds]) == TESOURA)
      return -1;
    else
      return 0;
  }

  else if (getMovesPlayer(game->moves[game->rounds]) == TESOURA)
  {
    if (getMovesMachine(game->moves[game->rounds]) == PAPEL)
      return 1;
    else if (getMovesMachine(game->moves[game->rounds]) == PEDRA)
      return -1;
    else
      return 0;
  }

  return 0;
}

void setMoreMoves(Game *game)
{
  game->moves = reallocMoves(game->moves, game->rounds);
  for (int i = game->rounds; i < (game->rounds + 2); i++)
    game->moves[i] = createMove();
}

void checkWinner(Game *game)
{
  int j = getPointsPlayer(game->players[0]);
  int c = getPointsPlayer(game->players[1]);
  if (j > c)
    printf("Você ganhou!\n");
  else if (c > j)
    printf("Você perdeu!\n");
  else
    printf("Empatou!\n");
}

void freeGame(Game **game)
{
  freePlayers(&(*game)->players);
  freeMoves(&(*game)->moves);
  free(*game);
  *game = NULL;
}
