#include <iostream> 
using namespace std;
class Sprite {
  protected:
  int posX,posY;
  public:
  Sprite(int initPosX,int initPosY){
    posX = initPosX;
    posY = initPosY;
  }
  int getPosX(void){return posX;}
  int getPosY(void){return posY;}
  void setPos(int x,int y){posX = x;posY =y;}
};

class Gem: public Sprite {
  public:
  Gem(int initPosX,int initPosY) :Sprite(initPosX,initPosY){

  }
  bool collision(int x,int y){
      if ((posX == x ) && (posY==y)){
        setPos(rand() % 10,rand() % 10);
        return true;
      }
      return false;
  }
};

class Character: public Sprite {
  public:
    Character(int initPosX,int initPosY) : Sprite(initPosX,initPosY){
      
    }
  protected:
    int atk = 1;
    int def = 1;
};

class Player: public Character {
  private:

    int score = 0;

  public:
    Player(int initPosX,int initPosY,int initAtk,int initDef) : Character(initPosX,initPosY){
      atk = initAtk;
      def = initDef;
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

    int getAtk(void){return atk;}
    int getDef(void){return def;}
    void upAtk(void){
      if (score > 0){atk++;
      score--;
      }
      else{
        printf("Not Enough Gems");
      }
    }
    void upDef(void){
      if (score > 0){
        score--;
        def++;
      }
      else{
        printf("Not Enough Gems");
      }
    }
    
    void upScore(void){score++;}
    int getScore(void){return score;}

};