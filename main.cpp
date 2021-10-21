#include <iostream>
#include <fstream>
#include "include/player.h"
#include "include/board.h"
#include "include/function.h"
#include "include/gamestate.h"

using namespace std;


std::vector<Armour> shopItems;


int main() {
  char start;
  bool gameFlag = true;
  char option;
  std::string output = "";
  
  Board board;
  Player player = Player(0,0,5,5,50);
  Character monster = Character(0,0,5,5,50);
  Gem gem = Gem(8,5);;
  board = Board();

  shopItems = {{"Full Helm",true,5,25,false},{"Platebody",true,10,25,false},{"Platelegs",true,12,25,false},{"Kiteshield",true,5,25,false},{"Iron Sword",false,5,25,false},{"Mithril Sword",false,10,100},{"Adamant Sword",false,40,500,false}};

  printf("A robot crash lands on earth.\nThe ship and robot are both damaged and low on fuel.\nCollect gems by defeating monsters and finding gems\nUse the gems to refuel and repair yourself and the ship.\nPress Any Key to Start: ");
  cin >> start;

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
      case ChangeLevel:
        drawLevel(player);
        break;
      case EndGame:
        printf("\033c");
        printf("Congrats - The Game Has Finished");
        gameFlag = false;
        break;
      default:
        break;
    }
  }
}


/**
* TODO:
*   1.Add Into And End Screen - Done
*   2.Monster Level Changes
*   3.Buy Alterns For Poison
*   4.Different Biomes For Diff Levels
*   5.Monster Movement
*   6.Make Board Static
*/