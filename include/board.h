#include <iostream>
#include <vector>
#ifndef BOARD_H
#define BOARD_H
class Board {
  private:
  std::vector<std::vector<std::string>> board;
  public:
    Board();

    void printBoard();

    void drawItem(std::string item,int posX,int posY);

    void initializeBoard();
};
#endif
/*
TO DO:
MAYBE REFERENCE WRAP GEM/PLAYER/MONSTER CONTAIN
IN BOARD 
*/