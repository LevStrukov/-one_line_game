#ifndef GAME_H
#define GAME_H

struct Point
{
   int x, y;
};

bool isConnected(int, int);
bool isVisited(int, int);
int getPointIndex(int, int);
void drawPoints();
void drawEdges();
void drawVisitedEdges();
bool allVisited();
bool loadLevel(const char *);
void game();


#endif