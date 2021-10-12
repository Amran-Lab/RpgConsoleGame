#include <iostream> 
using namespace std;


class Player {
  private:
    int posX,posY;
    int atk, def;
    int score = 0;

  public:
    Player(int initPosX,int initPosY){
      posX = initPosX;
      posY = initPosY;

    }
    Player(){
    }

};