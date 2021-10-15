#include "../include/player.h"
#include "../include/board.h"
#include "../include/gamestate.h"
#ifndef FUNCTION_H
#define FUNCTION_H

void drawBoard(Board &board,Player &player, Gem &gem);
void drawMenu(Player &player);
void displayStats(Player &player);
void statMenu(Player &player);
bool encounterMonster(Player &player);
void fightMonster(Player &player, Character &monster);
void displayShop(void);
void pickItem(Player &player,char option);

#endif