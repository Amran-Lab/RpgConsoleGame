#include <iostream>
#include "include/player.h"
#include "include/board.h"

void drawBoard(Board &board,Player &player, Player &gem);
void drawMenu(Board &board,Player &player);

using namespace std;

enum State { Adventure, Menu};
State gameState;

int main() {
  bool gameFlag = true;
  char option;

  Board board;
  Player player;
  Player gem;
  
  board = Board();
  player = Player(0,0);
  gem = Player(8,5);
  gameState = Adventure;

  while (gameFlag){
    switch(gameState) {
      case Adventure:
        drawBoard(board,player,gem);
        //printf("%c%c%c%c",  0xF0,0x9F,0xA4,0x96);
        printf("\nType WASD To move character or M for Menu: ");
        cin >> option;
        if ((toupper(option) == 'M')){
          gameState = Menu;
        }
        else {
          player.movePlayer(option);
          if (gem.collision(player.getPosX(), player.getPosY())){
            player.upScore();
          }
        }
        break;
      case Menu:
        drawMenu(board,player);
        break;
      default:
        break;

      
    }

  }

}

void drawBoard(Board &board,Player &player, Player &gem){
    board.drawItem("\U0001F916", player.getPosX(), player.getPosY());
    board.drawItem("\U0001F48E", gem.getPosX(), gem.getPosY());
    printf("\033c"); // erases previous board
    printf("Number of Gems: %d\n", player.getScore());
    board.printBoard();
    board.initiliazeBoard(); // resets board - removes previous artifacts
}

void drawMenu(Board &board,Player &player){
    printf("\nNumber of Gems: %d", player.getScore());
    char option;
    printf("\nPress A to change Weapon and Armour");
    printf("\nPress S to Increase Stats ");
    printf("\nPres Q to quit: ");
    cin >> option;
    switch(option) {
      case 'A':
      case 'a':
      // goes up 3 erases them line by line then goes back up 2 lines
        printf("\x1b[3A\33[2K\n\33[2K\n\33[2K\x1b[2A"); 
        printf("Your Items Are: \n");
        break;
      case 'S':
      case 's':
        printf("\x1b[3A\33[2K\n\33[2K\n\33[2K\x1b[2A");
        printf("Your Stats Are: \n");
        break;
      case 'Q':
      case 'q':
        gameState = Adventure;
        break;
      default:
        gameState = Adventure; 
    }

}