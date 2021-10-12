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
    void movePlayer(char option){
      switch(option) {
        case 'W':
        case 'w':
          if (posY > 0){
            posY--;
          }
          break;
        case 'A':
        case 'a':
          if (posX > 0){
            posX--;
          }
          break;
          break;
        case 'S':
        case 's':
          if (posY < 9){
            posY++;
          }
          // code block
          break;
        case 'D':
        case 'd':
          if (posX < 9){
            posX++;
          }
          break;
        default:
          printf("Incorrect Input");
          
      }
    }

    int getPosX(void){return posX;}
    int getPosY(void){return posY;}
    void setPos(int x,int y){posX = x;
    posY =y;}
    bool collision(int x,int y){
      if ((posX == x ) && (posY==y)){
        setPos(rand() % 10,rand() % 10);
        return true;
      }
      return false;
    }
    void upScore(void){score++;}
    int getScore(void){return score;}

};