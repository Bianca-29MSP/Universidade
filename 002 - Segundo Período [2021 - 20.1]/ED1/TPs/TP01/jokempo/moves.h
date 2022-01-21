#ifndef moves_h
#define moves_h

typedef struct moves Moves;

Moves **createMoves(int n);

Moves *createMove();

Moves **reallocMoves(Moves **moves, int n);

void freeMoves(Moves ***moves);

void setMoves(Moves **moves, int player, int machine, int i);

int getMovesPlayer(Moves *moves);

int getMovesMachine(Moves *moves);

#endif