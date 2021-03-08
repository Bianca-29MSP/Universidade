#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAZIO ' '
#define X 'x'
#define O 'o'

void game();

char **createCleanBoard(int row, int column);

void displayBoard(char **board);

void playerPlaying(char **board, int *linha, int *coluna);

int checkForWinner(char **board);

void move(char **board, int row, int column, char marker);

int checkBestPosition(int *positions);

void pickBestPositionInBoard(int *bestPosition, int *machineRow, int *machineColumn);

void machinePlaying(char **board, int *machineRow, int *machineColumn);

int checkRows(char **board, int row, char marker);

int checkColumns(char **board, int column, char marker);

int checkDiagonal(char **board, int row, int column, char marker);

int checkWin(char **board, int row, int column, char marker);

int checkNearPositions(char **board, int row, int column, char marker);
