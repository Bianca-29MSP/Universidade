/*
*   UFOP - Universidade Federal de Ouro Preto
*   Estrutura de dados
*   Trabalho Prático 01 - Questão 02
*   Enya Luísa Gomes dos Santos
*   19.2.4201
*/

#include <time.h>
#include "jokempo.h"

int main()
{
  // 0 - Pedra; 1 - Papel; 2 - Tesoura
  srand(time(NULL));

  Game *game = createJogo();
  int jogadaJogador = -1;
  int jogadaComputador;
  int resultado;

  int numRodadas = 5;

  char op;

  while (numRodadas > 0)
  {
    playerPlay(&jogadaJogador);

    jogadaComputador = machinePlay();

    setGameMoves(game, jogadaJogador, jogadaComputador);

    resultado = checkToWin(game);

    setGamePoints(game, resultado);

    jogadaComputador = getGameMoveMachine(game);

    printf("%d %d\n", jogadaComputador, resultado);

    setGameRounds(game);

    numRodadas -= 1;
    if (numRodadas == 0)
    {
      getGamePointsPlayers(game);
      scanf("\n%c", &op);
      if (op == 'c')
      {
        numRodadas = 2;
        setMoreMoves(game);
      }
      if (op == 'p')
      {
        checkWinner(game);
        freeGame(&game);
      }
    }
  }

  return 0;
}