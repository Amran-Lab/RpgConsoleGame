#include "../include/board.h"
// Initialises Object with clear Board
Board::Board(){
  initializeBoard();
}
// Prints Current Board
void Board::printBoard(){
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%s",board[i][j].c_str());
    }
    printf("\n");
  }
}
// Modify Board With New Objects
void Board::drawItem(std::string item,int posX,int posY){
  board[posY][posX] = " " + item + " ";
}
// Resets Board
void Board::initializeBoard(){
  board.clear();
  // I use this method as I believe it is faster than a for loop
  std::vector<std::string> row = {" \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "};
  board = {row,row,row,row,row,row,row,row,row,row};
}