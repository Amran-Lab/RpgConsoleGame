#include <iostream>
#include <vector>
#ifndef BOARD_H // Only define Once
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