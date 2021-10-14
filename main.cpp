#include <iostream>
#include <fstream>
#include "include/player.h"
#include "include/board.h"
#include "include/function.h"
#include "include/gamestate.h"

using namespace std;

int main() {
  bool gameFlag = true;
  char option;

  Board board;
  Player player = Player(0,0,7,3,30);
  Character monster = Character(0,0,5,3,20);
  Gem gem = Gem(8,5);;
  board = Board();

  while (gameFlag){
    switch(gameState) {
      case Adventure:
        drawBoard(board,player,gem);
        break;
      case Menu:
        drawMenu(player);
        break;
      case Stats:
        statMenu(player);
        break;
      case Items:
        printf("\033c");
        printf("Your Items Are: ");
        printf("\nPress M for Menu or Q to Adventure");
        cin >> option;
        if ((toupper(option) == 'M')){
          gameState = Menu;
        }
        else if ((toupper(option) == 'Q')) {
          gameState = Adventure;
        }
      case Fighting:
        fightMonster(player,monster);
        break;
      default:
        break;
    }
  }
}

/*
STORY:

ROBOT Crash lands on Earth - Is damaged and ship is low
on fuel.

Collects Diamonds to increase ROBOT strength
and 100,000 Diamonds for escape.

The forest is dangerous as many dangerous monsters lurk
in the woods.
*/

/*
TODO:
Improve Fight Mech
Add Items
Add Levels
Add Escape;
*/