#include <iostream>
#include "../include/gamestate.h"
using namespace std;
#ifndef PLAYER_H
#define PLAYER_H
class Sprite { // Abstract
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
    Character(int initPosX,int initPosY,int initAtk,int initDef, int initHp) : Sprite(initPosX,initPosY){
      atk = initAtk;
      def = initDef;
      hp = initHp;
      liveHp = initHp;
    }
    void resetLiveHp(){liveHp = hp;}
    void hpDamage(float damage){liveHp -= damage;}
    int getAtk(void){return atk;}
    int getDef(void){return def;}
    float getLiveHp(void){return liveHp;}

  protected:
    int atk = 1;
    int def = 1;
    int hp = 10;
    float liveHp;
};

class Player: public Character {

  private:
    int fightState = 0;  // 0 = NoFight 1 = WIn, 2= Loss
    int score = 800;
    int poisonCounter = 0;
    float damReduct = 0.00;
    float damInc = 0.00;
    int gemMultiplier = 1;
    Level level = level_1;

  public:
    Player(int initPosX,int initPosY,int initAtk,int initDef, int initHp) : 
    Character(initPosX,initPosY,initAtk,initDef,initHp){
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

    int getHp(void){return hp;}
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
    void upHp(void){
      if (score > 0){
        score--;
        hp++;
      }
      else{
        printf("Not Enough Gems");
      }
    }
    
    void upScore(int plus){score += plus*gemMultiplier;}
    bool downScore(int minus){
      if ((score - minus)>= 0 ){
        score -=minus;
        return true;
      }
      return false;
    }
    int getScore(void){return score;}
    
    void fightOutcome(int state){fightState = state;}
    int getFight(void){return fightState;}
    
    void addPoison(int poison){poisonCounter += poison;}
    bool downPoison(void){
      if (poisonCounter > 0){
        poisonCounter--;
        return true;
      }
      return false;
    }
    void resetPoison(void){poisonCounter=0;}
    float getDamReduct(){return damReduct;}
    float getDamInc(){return damInc;}
    void setDamReduct(float red){damReduct += red;}
    void setDamInc(float inc){damInc += inc;}

    int getMulitplier(void){return gemMultiplier;}
    void showLevel(void){
      printf("\nCurrent Gem Multiplier %d",gemMultiplier);
      switch(level) {
        case level_1:
          printf("\nYou Are in Level 1\nPay %d Gem to go to Level 2",Level::level_2);
          break;
        case level_2:
          printf("\nYou Are in Level 2\nPay %d Gem to go to Level 3",Level::level_3);
          break;
        case level_3:
           printf("\nYou Are in Level 3\nPay %d Gem to go to Level 4",Level::level_4);
          break;
        case level_4:
          printf("\nYou Are in Level 4\nPay %d Gem to end game",Level::end_game);
          break;
        default:
          break;
      }
    }

    bool nextLevel(void){
      switch(level) {
        case level_1:
          if(downScore(Level::level_2)){
            level = level_2;
            gemMultiplier = 10;
            return true;
          }
          return false;
          break;
        case level_2:
          if(downScore(Level::level_3)){
            level = level_3;
            gemMultiplier = 100;
            return true;
          }
          return false;
          break;
        case level_3:
          if(downScore(Level::level_4)){
            level = level_4;
            gemMultiplier = 10000;
            return true;
          }
          return false;
          break;
        case level_4:
          if(downScore(Level::end_game)){
            level = end_game;
            gameState = EndGame;
            gemMultiplier = 1;
            return true;
          }
          return false;
          break;
        case end_game:
          level = level_1;
          gameState = Adventure;
          return true;
          break;
        default:
          break;
    }
  }

};
#endif