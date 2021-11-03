#include <iostream>
#include <fstream>
#include "include/sprite.h"
#include "include/gem.h"
#include "include/character.h"
#include "include/player.h"
#include "include/board.h"
#include "include/function.h"
#include "include/constants.h"
using namespace std;

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

  printf("A robot crash lands on earth.\nThe ship and robot are both damaged and low on fuel.\nCollect gems by defeating monsters and finding gems\nUse the gems to refuel and repair yourself and the ship.\nPress Any Key to Start: ");
  cin >> start;
  // Game Loop - All the Game Happens Here
  while (gameFlag){
    switch(gameState) {
      case Adventure: // Adventure Happens Here
        drawBoard(board,player,gem);
        break;
      case Menu:  // Main Menu
        drawMenu(player);
        break;
      case Stats: // Increase Stats
        statMenu(player);
        break;
      case Items: // Buy Armour
        printf("\033c");
        printf("                  SHOP:\n");
        displayStats(player);
        displayShop();
        printf("%s",output.c_str());
        output = "";
        cin >> option;
        output = pickItem(player, option);
        break;
      case Fighting:  // Fighting A Monster
        fightMonster(player, monster);
        break;
      case ChangeLevel: // Go to Next Level / End Game
        drawLevel(player, monster);
        break;
      case EndGame:
        printf("\033c");
        printf("Congrats - The Game Has Finished");
        gameFlag = false; // End Game - Break Loop
        break;
      default:
        break;
    }
  }
}