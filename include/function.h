#include "../include/player.h"
#include "../include/board.h"
#include "../include/constants.h"
#ifndef FUNCTION_H
#define FUNCTION_H

void drawBoard(Board &board,Player &player, Gem &gem);

void drawMenu(Player &player);

void displayStats(Player &player);

void statMenu(Player &player);

bool encounterMonster(Player &player);

void fightMonster(Player &player, Character &monster);

void displayShop(void);

std::string pickItem(Player &player, char option);

std::string drawLevel(Player &player, Character &monster);

void showLevel(Player &player);

bool nextLevel(Player &player,Character &monster);
#endif