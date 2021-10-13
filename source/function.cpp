#include "../include/function.h"
#include "../include/player.h"
#include "../include/board.h"
#include "../include/gamestate.h"
#include <iostream>
#include <fstream>

State gameState = Adventure;
Level level = Lvl_1;

void drawBoard(Board &board,Player &player, Gem &gem){
    board.drawItem("\U0001F48E", gem.getPosX(), gem.getPosY());
    board.drawItem("\U0001F916", player.getPosX(), player.getPosY());
    printf("\033c"); // erases previous board
    printf("Number of Gems: %d\n", player.getScore());
    board.printBoard();
    board.initiliazeBoard(); // resets board - removes previous artifacts
}

void drawMenu(Player &player){
    printf("\033c");
    printf("Number of Gems: %d", player.getScore());
    char option;
    printf("\nPress A to change Weapon and Armour");
    printf("\nPress S to Increase Stats ");
    printf("\nPres Q to quit: ");
    cin >> option;
    switch(option) {
      case 'A':
      case 'a':
        gameState = Items;
        break;
      case 'S':
      case 's':
        gameState = Stats;
        break;
      case 'Q':
      case 'q':
        gameState = Adventure;
        break;
      default:
        gameState = Adventure; 
        break;
    }
}

void displayStats(Player &player){
  char option;
  printf("\033c");
  printf("Number of Gems: %d", player.getScore());
  printf("\nYour Stats Are: ");
  printf("\nAttack: %d", player.getAtk());
  printf("\nDefence: %d", player.getDef());
  printf("\nSpend Gems to increase stats");
  printf("\nPress 1 to Increase Attack");
  printf("\nPress 2 to Increase Defence");
  printf("\nPress M for Menu or Q to Adventure: ");
  cin >> option;
  switch(option) {
    case 'M':
    case 'm':
      gameState = Menu;
      break;
    case 'Q':
    case 'q':
      gameState = Adventure;
      break;
    case '1':
      player.upAtk();
      break;
    case '2':
      player.upDef();
      break;
    default:
      break;
  }
}

bool encounterMonster(void){
  int chance = (rand() % 100) + 1;
  if (chance <= 20){
    printf("You Encountered A Monster: FIGHT\n");
    string myText;

    // Read from the text file
    std::ifstream f("ascii.txt");

    // Use a while loop together with the getline() function to read the file line by line
    if (f.is_open())
        std::cout << f.rdbuf();
    return true;
  }
  return false;
}