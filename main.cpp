#include <iostream>
#include "include/player.h"
#include "include/board.h"

void drawBoard(void);
void drawMenu(void);

using namespace std;

Board board;
Player player;
Player gem;

int main() {
  bool gameFlag = true;
  char option;

  board = Board();
  player = Player(0,0);
  gem = Player(8,5);

  while (gameFlag){
    drawBoard();
    printf("\nType WASD To move character or M for Menu: ");
    cin >> option;
    if ((toupper(option) == 'M')){
      drawMenu();
    }
    else{
    player.movePlayer(option);
    if (gem.collision(player.getPosX(), player.getPosY())){
      player.upScore();
    }
    }

  }

}

void drawBoard(void){
    board.drawItem("\u25CF", player.getPosX(), player.getPosY());
    board.drawItem("\u2666", gem.getPosX(), gem.getPosY());
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    printf("Number of Gems: %d\n", player.getScore());
    board.printBoard();
    board.initiliazeBoard();
}

void drawMenu(void){
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    printf("Number of Gems: %d\n", player.getScore());
    bool menuFlag = true;
    char option;
    while (menuFlag){
      printf("\nPress A to change Weapon and Armour");
      printf("\nPress S to Increase Stats ");
      printf("\nPres Q to quit: ");
      cin >> option;
      switch(option) {
        case 'A':
        case 'a':
          printf("Your Items Are");
          break;
        case 'S':
        case 's':
          printf("Your Stats Are");
          // code block
          break;
        case 'Q':
        case 'q':
          menuFlag = false;
          break;
        default:
          menuFlag = false;
          
      }

    }

}