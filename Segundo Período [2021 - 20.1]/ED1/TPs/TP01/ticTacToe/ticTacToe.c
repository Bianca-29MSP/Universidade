#include "ticTacToe.h"

void game()
{
  char **board;
  int playerRow, playerColumn;
  int machineRow, machineColumn;
  int result = 1;
  int playerPoints = 0, machinePoints = 0;
  char op = 'c';
  int rounds = 3;

  while (op == 'c')
  {
    playerPoints = 0;
    machinePoints = 0;

    for (int i = 0; i < rounds; i++)
    {
      printf("\t\t\t\t NOVO JOGO\n");

      board = createCleanBoard(3, 3);
      result = 1;

      while (result <= -1 || result >= 1)
      {
        machineRow = -1;
        machineColumn = -1;

        displayBoard(board);

        playerPlaying(board, &playerRow, &playerColumn);

        move(board, playerRow, playerColumn, X);

        result = checkForWinner(board);

        if (result == 1)
        {
          playerPoints += 1;
          break;
        }
        else if (result == 0)
        {
          break;
        }

        machinePlaying(board, &machineRow, &machineColumn);
        move(board, machineRow, machineColumn, O);
        printf("Computador: %d %d\n", machineRow, machineColumn);

        result = checkForWinner(board);

        if (result == -1)
        {
          machinePoints += 1;
          break;
        }
      }

      displayBoard(board);
      free(board);

      if (result == -1)
      {
        printf("%d - Você perdeu!\n", result);
      }
      else if (result == 0)
      {
        printf("%d - Velha!\n", result);
      }
      else if (result == 1)
      {
        printf("%d - Você ganhou!\n", result);
      }
    }

    printf("Placar: %d %d\n", playerPoints, machinePoints);
    printf("Digite 'c' para iniciar um novo jogo\n");
    scanf("\n%c", &op);
    rounds = 2;
  }
}

char **createCleanBoard(int row, int column)
{
  char **aux;
  aux = malloc(sizeof(char *) * row);

  for (int i = 0; i < column; i++)
    aux[i] = malloc(sizeof(char));

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      aux[i][j] = VAZIO;
  return aux;
}

void displayBoard(char **board)
{
  printf("\n\n");
  for (int i = 0; i < 3; i++)
  {
    printf("\t\t\t\t %c \u2503 %c \u2503 %c \n",
           board[i][0], board[i][1], board[i][2]);
    if (i < 2)
      printf("\t\t\t\t\u2501\u2501\u2501\u254B\u2501\u2501\u2501\u254B\u2501\u2501\u2501\n");
  }
  printf("\n\n");
}

void playerPlaying(char **board, int *playerRow, int *coluna)
{
  do
  {
    printf("Jogador: ");
    scanf("%d %d", playerRow, coluna);
  } while (board[*playerRow][*coluna] != VAZIO || *playerRow > 2 || *playerRow < 0 || *coluna > 2 || *coluna < 0);
}

int checkForWinner(char **board)
{
  // 1 - Ganhou; -1 - Perdeu; 0 - Velha; > 0 - Sem resultado

  //Linnhas & Colunas
  for (int i = 0; i < 3; i++)
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
    {
      if (board[i][0] == X)
        return 1;
      else if (board[i][0] == O)
        return -1;
    }
    else if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
    {
      if (board[0][i] == X)
        return 1;
      else if (board[0][i] == O)
        return -1;
    }

  //Diagonais
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
  {
    if (board[0][0] == X)
      return 1;
    else if (board[0][0] == O)
      return -1;
  }

  else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
  {
    if (board[0][2] == X)
      return 1;
    else if (board[0][2] == O)
      return -1;
  };

  int count = 0;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (board[i][j] == VAZIO)
        count++;
  return count;
}

/*
* Mais 01 ponto se a posição estiver nos quatro cantos da matriz;
* Mais 02 pontos se a posição for a central;
* Mais 02 pontos, se já houver uma ou mais peças do adversário na mesma linha, coluna ou diagonal onde a posição se encontra;
* Mais 02 pontos, se já houver uma ou mais peças amigavel na mesma linha, coluna ou diagonal onde a posição se encontra;
* Mais 04 pontos se a posição impedir a vitória do adversário;
* Mais 08 pontos se a posição levar a uma vitória;
*/

void machinePlaying(char **board, int *machineRow, int *machineColumn) //Heuristica
{
  int positions[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int count = 0;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      if (board[i][j] == VAZIO)
      {
        if (i == 1 && j == 1)
          positions[count] += 2;
        if ((i == 0 && j == 0) ||
            (i == 0 && j == 2) ||
            (i == 2 && j == 0) ||
            (i == 2 && j == 2))
          positions[count] += 1;
        if ((checkRows(board, i, X) != 0) ||
            (checkColumns(board, j, X) != 0) ||
            checkDiagonal(board, i, j, X) != 0)
          positions[count] += 2;
        if (checkNearPositions(board, i, j, O) == 1)
        {
          positions[count] += 2;
        }
        if (checkWin(board, i, j, X) == 1)
          positions[count] += 4;
        if (checkWin(board, i, j, O) == 1)
          positions[count] += 8;
      }
      count++;
    }

  int bestPosition = checkBestPosition(positions);
  pickBestPositionInBoard(&bestPosition, machineRow, machineColumn);
}

void pickBestPositionInBoard(int *bestPosition, int *machineRow, int *machineColumn)
{
  if (*bestPosition >= 0 && *bestPosition <= 2)
  {
    *machineRow = 0;
    *machineColumn = *bestPosition;
  }
  else if (*bestPosition <= 5)
  {
    *machineRow = 1;
    if (*bestPosition == 3)
      *machineColumn = 0;
    if (*bestPosition == 4)
      *machineColumn = 1;
    if (*bestPosition == 5)
      *machineColumn = 2;
  }
  else if (*bestPosition <= 8)
  {
    *machineRow = 2;
    if (*bestPosition == 6)
      *machineColumn = 0;
    if (*bestPosition == 7)
      *machineColumn = 1;
    if (*bestPosition == 8)
      *machineColumn = 2;
  }
}

int checkBestPosition(int positions[9])
{
  int bestPositionValue = positions[0];
  int bestPositionIndex = 0;

  for (int i = 0; i < 9; i++)
  {
    if (positions[i] > bestPositionValue)
    {
      bestPositionValue = positions[i];
      bestPositionIndex = i;
    }
  }

  return bestPositionIndex;
}

int checkRows(char **board, int row, char marker)
{
  int count = 0;
  for (int i = 0; i < 3; i++)
  {
    if (board[row][i] == marker)
      count++;
  }
  return count;
}

int checkColumns(char **board, int column, char marker)
{
  int count = 0;
  for (int i = 0; i < 3; i++)
  {
    if (board[i][column] == marker)
      count++;
  }
  return count;
}

int checkDiagonal(char **board, int row, int column, char marker)
{
  int count = 0;

  if (row == column)
  {
    if (row == 0)
    {
      if (board[row + 1][column + 1] == marker)
        count++;
      if (board[row + 2][column + 2] == marker)
        count++;
    }
    if (row == 1)
    {
      if (board[row - 1][column - 1] == marker)
        count++;
      if (board[row + 1][column + 1] == marker)
        count++;
      if (board[row - 1][column + 1] == marker)
        count++;
      if (board[row + 1][column - 1] == marker)
        count++;
    }
    if (row == 2)
    {
      if (board[row - 1][column - 1] == marker)
        count++;
      if (board[row - 2][column - 2] == marker)
        count++;
    }
  }
  else
  {
    if (row == 0 && column == 2)
    {
      if (board[row + 1][column - 1] == marker)
        count++;
      if (board[row + 2][column - 2] == marker)
        count++;
    }
    else if (row == 2 && column == 0)
    {
      if (board[row - 1][column + 1] == marker)
        count++;
      if (board[row - 2][column + 2] == marker)
        count++;
    }
  }

  return count;
}

int checkWin(char **board, int row, int column, char marker)
{
  if (checkRows(board, row, marker) == 2)
  {
    return 1;
  }
  else if (checkColumns(board, column, marker) == 2)
  {
    return 1;
  }
  else if (checkDiagonal(board, row, column, marker) >= 2)
  {
    return 1;
  }

  return 0;
}

int checkNearPositions(char **board, int row, int column, char marker)
{
  if (checkRows(board, row, marker) >= 1)
  {
    return 1;
  }
  else if (checkColumns(board, column, marker) >= 1)
  {
    return 1;
  }

  return 0;
}

void move(char **board, int row, int column, char marker)
{
  board[row][column] = marker;
}
