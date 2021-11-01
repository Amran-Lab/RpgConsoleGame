#include <iostream>
#include "../include/gamestate.h"
#include "../include/sprite.h"
using namespace std;
#ifndef GEM_H
#define GEM_H

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
#endif