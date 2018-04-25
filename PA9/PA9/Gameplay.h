#pragma once

#include "Window.h"
#include "Scoreboard.h"

void insertRandom(Square *squares[4][4]);
bool boardFull(Square *squares[4][4]);

void moveUp(Square *squares[4][4], Scoreboard *score);
void moveDown(Square *squares[4][4], Scoreboard *score);
void moveLeft(Square *squares[4][4], Scoreboard *score);
void moveRight(Square *squares[4][4], Scoreboard *score);
