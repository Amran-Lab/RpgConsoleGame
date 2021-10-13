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
  Player player = Player(0,0,3,3);
  Gem gem = Gem(8,5);;
  board = Board();

  while (gameFlag){
    switch(gameState) {
      case Adventure:
        drawBoard(board,player,gem);
        printf("\nType WASD To move character or M for Menu: \n");
        // encounterMonster();
        cin >> option;
        if ((toupper(option) == 'M')){
          gameState = Menu;
        }
        else {
          player.movePlayer(option);
          if (gem.collision(player.getPosX(), player.getPosY())){
            player.upScore();
            printf("You Gained A Gem\n");
        }
        }
        break;
      case Menu:
        drawMenu(player);
        break;
      case Stats:
        displayStats(player);
        break;
      case Items:
        printf("\033c");
        printf("Your Items Are: ");
        printf("\nPress M for Menu or Q to Adventure");
        cin >> option;
        if ((toupper(option) == 'M')){
          gameState = Menu;
        }
        else {
          gameState = Adventure;
        }
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
Add Monsters and their Events:
Add Fighting Capability
Split Player Obj ->
Item/Gem -> Monster -> Player
*/