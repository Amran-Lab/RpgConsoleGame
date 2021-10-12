#include <iostream>
#include <vector>
using namespace std;
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
      std::vector<std::string> row = {" x "," x "," x "," x "," x "," x "," x "," x "," x "," x "};
      board = {row,row,row,row,row,row,row,row,row,row};
    }

};