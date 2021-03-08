#ifndef players_h
#define players_h

typedef struct players Players;

Players **createPlayers(int n);

Players *createPlayer();

int getPointsPlayer(Players *player);

void freePlayers(Players ***players);

void setPointsPlayer(Players *players, int n);

#endif