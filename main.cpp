#include <iostream>
#include <fstream>
#include "include/player.h"
#include "include/board.h"
#include "include/function.h"
#include "include/gamestate.h"

using namespace std;


std::vector<Armour> shopItems;


int main() {
  bool gameFlag = true;
  char option;
  string output = "";
  
  Board board;
  Player player = Player(0,0,5,5,50);
  Character monster = Character(0,0,5,5,50);
  Gem gem = Gem(8,5);;
  board = Board();

  shopItems = {{"Full Helm",true,5,25,false},{"Platebody",true,10,25,false},{"Platelegs",true,12,25,false},{"Kiteshield",true,5,25,false},{"Iron Sword",false,5,25,false},{"Mithril Sword",false,10,100},{"Adamant Sword",false,40,500,false}};


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
        printf("                  SHOP:\n");
        displayStats(player);
        displayShop();
        printf("%s",output.c_str());
        output = "";
        cin >> option;
        output = pickItem(player,option);
        break;
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