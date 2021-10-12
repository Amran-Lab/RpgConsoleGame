#include <iostream>
#include "include/player.h"
#include "include/board.h"

using namespace std;


int main() {
  bool gameFlag = true;
  char option;
  Board board;
  board = Board();
  Player player;
  player = Player(0,0);
  Player gem;
  gem = Player(8,5);

  while (gameFlag){
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
    board.drawItem("\u25CF", player.getPosX(), player.getPosY());
    board.drawItem("\u2666", gem.getPosX(), gem.getPosY());
    printf("Number of Gems: %d\n", player.getScore());
    board.printBoard();
    board.initiliazeBoard();
    printf("\nType WASD To move character: ");
    cin >> option;
    player.movePlayer(option);
    if (gem.collision(player.getPosX(), player.getPosY())){
      player.upScore();
    }

  }

}