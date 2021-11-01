#include <iostream>
#include "../include/gamestate.h"
using namespace std;
#ifndef SPRITE_H
#define SPRITE_H
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
#endif