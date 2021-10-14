#include <iostream>
#include <vector>
using namespace std;
#ifndef BOARD_H
#define BOARD_H
class Board {
  private:
  std::vector<std::vector<std::string>> board;
  public:
    Board(){
      initiliazeBoard();
    }

    void printBoard(){
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          printf("%s",board[i][j].c_str());
        }
        printf("\n");
      }
    }

    void drawItem(string item,int posX,int posY){
      board[posY][posX] = " " + item + " ";
    }
    void initiliazeBoard(){
      board.clear();
      std::vector<std::string> row = {" \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "," \U0001F333 "};
      board = {row,row,row,row,row,row,row,row,row,row};
    }

};
#endif
/*
TO DO:
MAYBE REFERENCE WRAP GEM/PLAYER/MONSTER CONTAIN
IN BOARD 
*/