#include "../include/board.h"
Board::Board(){
  initiliazeBoard();
}

void Board::printBoard(){
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%s",board[i][j].c_str());
    }
    printf("\n");
  }
}

void Board::drawItem(std::string item,int posX,int posY){
  board[posY][posX] = " " + item + " ";
}
void Board::initiliazeBoard(){
  board.clear();
  std::vector<std::string> row = {" \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "};
  board = {row,row,row,row,row,row,row,row,row,row};
}