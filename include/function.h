#include "../include/player.h"
#include "../include/board.h"
#include "../include/gamestate.h"
#ifndef FUNCTION_H
#define FUNCTION_H

void drawBoard(Board &board,Player &player, Gem &gem);
void drawMenu(Player &player);
void displayStats(Player &player);
bool encounterMonster(void);

#endif