#include <iostream>
#include "include/player.h"
#include "include/board.h"

void drawBoard(Board &board,Player &player, Gem &gem);
void drawMenu(Player &player);
void displayStats(Player &player);
bool encounterMonster(void);

using namespace std;

enum State { Adventure, Menu, Stats, Items};
State gameState;

int main() {
  bool gameFlag = true;
  char option;

  Board board;
  Player player = Player(0,0,3,3);
  Gem gem = Gem(8,5);;
  board = Board();
  gameState = Adventure;

  while (gameFlag){
    switch(gameState) {
      case Adventure:
        drawBoard(board,player,gem);
        printf("\nType WASD To move character or M for Menu: \n");
        if (gem.collision(player.getPosX(), player.getPosY())){
            player.upScore();
            printf("You Gained A Gem\n");
        }
        encounterMonster();
        cin >> option;
        if ((toupper(option) == 'M')){
          gameState = Menu;
        }
        else {
          player.movePlayer(option);
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
    printf("SCARY MONSTER");
    return true;
  }
  return false;
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